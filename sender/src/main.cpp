#include <sl/Camera.hpp> 
#include <string>
#include "utils.hpp"

using namespace sl;
using namespace std;

void parse_args(int argc, char **argv, StreamingParameters& param);
void print(string msg_prefix, ERROR_CODE err_code = ERROR_CODE::SUCCESS, string msg_suffix = "");

int main(int argc, char **argv) {
    Camera zed;

    InitParameters init_parameters;
    // init_parameters.camera_resolution = sl::RESOLUTION::AUTO;
    init_parameters.depth_mode = DEPTH_MODE::NONE;
    init_parameters.sdk_verbose = 1;

    auto returned_state = zed.open(init_parameters);

    if (returned_state != ERROR_CODE::SUCCESS) {
        print("Camera Open", returned_state, "Exit program.");
        return EXIT_FAILURE;
    }

    StreamingParameters stream_params;
    parse_args(argc, argv, stream_params);

    returned_state = zed.enableStreaming(stream_params);

    if (returned_state != ERROR_CODE::SUCCESS) {
        print("Streaming initialization error: ", returned_state);
        return EXIT_FAILURE;
    }

    // Able to stop with CTRL + C
    SetCtrlHandler();

    while (!exit_app) {
        if (zed.grab() != ERROR_CODE::SUCCESS)
            sleep_ms(1);
    }

    zed.disableStreaming();
    zed.close();
    return EXIT_SUCCESS;
}

void parse_args(int argc, char **argv, StreamingParameters& param)
{
    std::vector<std::string> args(argv, argv + argc);

    for (int id = 1; id < argc; id ++) {
        std::string arg(argv[id]);

        if (arg.find("H264") != string::npos) {
            param.codec = sl::STREAMING_CODEC::H264;
            print("Using codec H264");
        } else if (arg.find("H265") != string::npos) {
            param.codec = sl::STREAMING_CODEC::H265;
            print("Using codec H265");
        }

        if (args[id] == "-b" && id + 1 < argc) {
            int bitrate = std::stoi(args[id + 1]);
            param.bitrate = bitrate;
            print("Using " + to_string(bitrate) + " bitrate");
            ++id;
        }

        if (args[id] == "-p" && id + 1 < argc) {
            int port = std::stoi(args[id + 1]);
            param.port = port;
            print("Using port " + to_string(port));
            ++id;
        }
    }
}

void print(string msg_prefix, ERROR_CODE err_code, string msg_suffix) {
    cout << "[Sample]";
    if (err_code != ERROR_CODE::SUCCESS)
        cout << "[Error] ";
    else
        cout << " ";
    cout << msg_prefix << " ";
    if (err_code != ERROR_CODE::SUCCESS) {
        cout << " | " << toString(err_code) << " : ";
        cout << toVerbose(err_code);
    }
    if (!msg_suffix.empty())
        cout << " " << msg_suffix;
    cout << endl;
}
