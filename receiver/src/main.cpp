#include <stdio.h>
#include <string.h>
#include <sl/Camera.hpp>
#include "GLViewer.hpp"
#include <opencv2/opencv.hpp>

using namespace std;
using namespace sl;

#define BUILD_MESH 1

void parse_args(int argc, char **argv,InitParameters& param, sl::Mat &roi);
void handleKeyInput(char key, sl::Camera &zed);
void switchCameraSettings();
void switchViewMode();
void printCameraSpecs(sl::Camera &zed);
void printHelp();
void print(string msg_prefix, ERROR_CODE err_code = ERROR_CODE::SUCCESS, string msg_suffix = "");

// Sample variables
VIDEO_SETTINGS camera_settings_ = VIDEO_SETTINGS::BRIGHTNESS;
VIEW view_mode = VIEW::LEFT;
string str_camera_settings = "BRIGHTNESS";
int step_camera_setting = 1;

int main(int argc, char **argv) {
    Camera zed;

    InitParameters init_parameters;
    init_parameters.depth_mode = DEPTH_MODE::NEURAL;
    init_parameters.coordinate_units = UNIT::METER
    init_parameters.coordinate_system = COORDINATE_SYSTEM::RIGHT_HANDED_Y_UP; // OpenGL's coordinate system is right_handed
    init_parameters.depth_maximum_distance = 8.;
    init_parameters.sdk_verbose = true;
    init_parameters.input.setFromStream("127.0.0.1");

    sl::Mat roi;
    cv::String win_name = "Camera Remote Control";
    cv::namedWindow(win_name);

    // Open the camera
    auto returned_state = zed.open(init_parameters);
    if (returned_state != ERROR_CODE::SUCCESS) {
        print("Camera Open", returned_state, "Exit program.");
        return EXIT_FAILURE;
    }

    printCameraSpecs(zed);
    printHelp();
    switchCameraSettings();

    // Create a Mat to store images
    Mat image;

    char key = ' ';
    while (key != 'q') {
        // Check that a new image is successfully acquired
        returned_state = zed.grab();
        if (returned_state == ERROR_CODE::SUCCESS) {
            zed.retrieveImage(image, view_mode);

            // Convert sl::Mat to cv::Mat (share buffer)
            cv::Mat cvImage(image.getHeight(), image.getWidth(), (image.getChannels() == 1) ? CV_8UC1 : CV_8UC4, image.getPtr<sl::uchar1>(sl::MEM::CPU));

            // Display image with OpenCV
            cv::imshow(win_name, cvImage);
            
        } else {
            print("Error during capture : ", returned_state);
            break;
        }

        key = cv::waitKey(5);
        // Change camera settings with keyboard
        handleKeyInput(key, zed);
    }

    zed.close();
    return EXIT_SUCCESS;
}

void handleKeyInput(char key, sl::Camera &zed) {
    int current_value;

    switch (key) {
        case 'h': // Print help
            printHelp();
            break;
    
        case 'v': // Switch to the next view mode
            switchViewMode();
            break;

        case 's': // Switch to the next camera parameter
            switchCameraSettings();
            zed.getCameraSettings(camera_settings_,current_value);
            break;

        case '+': // Increase camera settings value ('+' key)
            zed.getCameraSettings(camera_settings_,current_value);
            zed.setCameraSettings(camera_settings_, current_value + step_camera_setting);
            zed.getCameraSettings(camera_settings_,current_value);
            print(str_camera_settings+": "+std::to_string(current_value));
            break;  

        case '-': // Decrease camera settings value ('-' key)
            zed.getCameraSettings(camera_settings_,current_value);
            current_value = current_value > 0 ? current_value - step_camera_setting : 0; // take care of the 'default' value parameter:  VIDEO_SETTINGS_VALUE_AUTO
            zed.setCameraSettings(camera_settings_, current_value);
            zed.getCameraSettings(camera_settings_,current_value);
            print(str_camera_settings+": "+std::to_string(current_value));
            break;

        case 'r': // Reset to default parameters
            print("Reset all settings to default");
            for (int s = (int) VIDEO_SETTINGS::BRIGHTNESS; s <= (int) VIDEO_SETTINGS::WHITEBALANCE_TEMPERATURE; s++)
                zed.setCameraSettings(static_cast<VIDEO_SETTINGS> (s), sl::VIDEO_SETTINGS_VALUE_AUTO);
            break;

        default :
        break;
    }
}

void switchCameraSettings() {
    camera_settings_ = static_cast<VIDEO_SETTINGS> ((int) camera_settings_ + 1);

    // reset to 1st setting
    if (camera_settings_ == VIDEO_SETTINGS::LED_STATUS)
        camera_settings_ = VIDEO_SETTINGS::BRIGHTNESS;

    // select the right step
    step_camera_setting = (camera_settings_ == VIDEO_SETTINGS::WHITEBALANCE_TEMPERATURE) ? 100 : 1;

    // get the name of the selected SETTING
    str_camera_settings = string(sl::toString(camera_settings_).c_str());

    print("Switch to camera settings: ", ERROR_CODE::SUCCESS, str_camera_settings);
}

void switchViewMode() {
    print("Switching mode not avaiable");
    return;
    view_mode = static_cast<VIEW> ((int) view_mode + 1);

    // reset to 1st setting
    if (view_mode == VIEW::CONFIDENCE)
        view_mode = VIEW::LEFT;

    print("Switch to view mode: ", ERROR_CODE::SUCCESS, string(sl::toString(view_mode).c_str()));
}

void printCameraSpecs(sl::Camera &zed) {
    auto camera_info = zed.getCameraInformation();
    cout << endl;
    cout << "ZED Model                 : " << camera_info.camera_model << endl;
    cout << "ZED Serial Number         : " << camera_info.serial_number << endl;
    cout << "ZED Camera Firmware       : " << camera_info.camera_configuration.firmware_version << "/" << camera_info.sensors_configuration.firmware_version << endl;
    cout << "ZED Camera Resolution     : " << camera_info.camera_configuration.resolution.width << "x" << camera_info.camera_configuration.resolution.height << endl;
    cout << "ZED Camera FPS            : " << zed.getInitParameters().camera_fps << endl;
}

void printHelp() {
    cout << "\n\nCamera controls hotkeys:\n";
    cout << "* Increase camera settings value:  '+'\n";
    cout << "* Decrease camera settings value:  '-'\n";
    cout << "* Toggle camera settings:          's'\n";
    cout << "* Toggle view mode:                'v'\n";
    cout << "* Reset all parameters:            'r'\n";
    cout << "* Print help:                      'h'\n";
    cout << "* Exit :                           'q'\n\n";
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
