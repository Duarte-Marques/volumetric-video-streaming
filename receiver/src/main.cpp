#include <sl/Camera.hpp>
#include "GLViewer.hpp"
#include "utils.hpp"

using namespace std;
using namespace sl;

void parseArgs(int argc, char **argv, sl::InitParameters& param, bool& record);

int main(int argc, char **argv) {
    Camera zed;

    InitParameters init_parameters;
    init_parameters.depth_mode = DEPTH_MODE::NEURAL;
    init_parameters.coordinate_system = COORDINATE_SYSTEM::RIGHT_HANDED_Y_UP;
    init_parameters.sdk_verbose = 1;

    bool record = false;

    parseArgs(argc, argv, init_parameters, record);

    auto returned_state = zed.open(init_parameters);
    if (returned_state != ERROR_CODE::SUCCESS) {
        print("Camera Open", returned_state, "Exit program.");
        return EXIT_FAILURE;
    }

    auto camera_config = zed.getCameraInformation().camera_configuration;
    float image_aspect_ratio = camera_config.resolution.width / (1.f * camera_config.resolution.height);
    int requested_low_res_w = min(720, (int)camera_config.resolution.width);
    sl::Resolution res(requested_low_res_w, requested_low_res_w / image_aspect_ratio);

    auto stream = zed.getCUDAStream();
    
    GLViewer viewer; 
    GLenum errgl = viewer.init(argc, argv, camera_config.calibration_parameters.left_cam, stream, res);
    if (errgl != GLEW_OK) {
        print("Error OpenGL: " + std::string((char*)glewGetErrorString(errgl)));
        return EXIT_FAILURE;
    }

    RuntimeParameters runParameters;
    runParameters.confidence_threshold = 100;
    runParameters.texture_confidence_threshold = 100;

    /*
    Allocation of 4 channels of float on GPU
    */
    Mat point_cloud(res, MAT_TYPE::F32_C4, sl::MEM::GPU);

    /*
    Create output CSV file and write header
    */
    std::ofstream outputFile("values.csv", std::ios::app);
    outputFile << "FPS,LATENCY (MS)" << std::endl;

    /*
    Setup recording (if enabled)
    */
    if (record) {
        RecordingParameters recording_parameters;
        recording_parameters.video_filename.set("output.svo2");
        recording_parameters.compression_mode = SVO_COMPRESSION_MODE::H264;
        returned_state = zed.enableRecording(recording_parameters);

        if (returned_state != ERROR_CODE::SUCCESS) {
            print("Recording ZED: ", returned_state);
            zed.close();
            return EXIT_FAILURE;
        }

        print("SVO is Recording, use Ctrl-C to stop.");
        SetCtrlHandler();
    }

    /*
    Main loop
    */
    while (viewer.isAvailable()) {
        if (zed.grab(runParameters) == ERROR_CODE::SUCCESS) {
            
            // Retrieve the current 3D coloread point cloud in GPU
            zed.retrieveMeasure(point_cloud, MEASURE::XYZRGBA, MEM::GPU, res);
            viewer.updatePointCloud(point_cloud);
            
            // Capture images timestamps and calculate the difference
            sl::Timestamp image_ts = zed.getTimestamp(sl::TIME_REFERENCE::IMAGE);
            sl::Timestamp current_ts = zed.getTimestamp(sl::TIME_REFERENCE::CURRENT);
            long long diff_ms = (long long)current_ts.getMilliseconds() - (long long)image_ts.getMilliseconds();
            
            // Save current FPS and Latency value to file
            outputFile << zed.getCurrentFPS() << "," << diff_ms << std::endl;
        }
    }
    
    if (record) {
        zed.disableRecording();
    }

    point_cloud.free();
    zed.close();
    return EXIT_SUCCESS;
}

void parseArgs(int argc, char **argv, sl::InitParameters& param, bool& record) {
    if (argc > 1 && string(argv[1]).find(".svo") != string::npos) {
        // SVO input mode
        param.input.setFromSVOFile(argv[1]);
        cout << "Using SVO File input: " << argv[1] << endl;

    } else if (argc > 1 && string(argv[1]).find(".svo") == string::npos) {
        string arg = string(argv[1]);
        unsigned int a, b, c, d, port;

        if (sscanf(arg.c_str(), "%u.%u.%u.%u:%d", &a, &b, &c, &d, &port) == 5) {
            // Stream input mode - IP + port
            string ip_adress = to_string(a) + "." + to_string(b) + "." + to_string(c) + "." + to_string(d);
            param.input.setFromStream(sl::String(ip_adress.c_str()), port);
            cout << "Using Stream input, IP : " << ip_adress << ", port : " << port << endl;
        
        } else if (sscanf(arg.c_str(), "%u.%u.%u.%u", &a, &b, &c, &d) == 4) {
            // Stream input mode - IP only
            param.input.setFromStream(sl::String(argv[1]));
            cout << "Using Stream input, IP : " << argv[1] << endl;
        
        } else if (arg.find("HD2K") != string::npos) {
            param.camera_resolution = RESOLUTION::HD2K;
            print("Using Camera in resolution HD2K");
        
        } else if (arg.find("HD1080") != string::npos) {
            param.camera_resolution = RESOLUTION::HD1080;
            print("Using Camera in resolution HD1080");
        
        } else if (arg.find("HD720") != string::npos) {
            param.camera_resolution = RESOLUTION::HD720;
            print("Using Camera in resolution HD720");
        
        } else if (arg.find("VGA") != string::npos) {
            param.camera_resolution = RESOLUTION::VGA;
            print("Using Camera in resolution VGA");
        }
    }

    std::vector<std::string> args(argv, argv + argc);

    for (int id = 1; id < argc; id ++) {
        std::string arg(argv[id]);

        if (args[id] == "-r") {
            record = true;
            print("Recording camera");
        }
    }
}
