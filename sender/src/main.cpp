#include <sl/Camera.hpp> 
#include "utils.hpp" 

using namespace sl;
using namespace std;

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

    stream_params.port = 30000;

    returned_state = zed.enableStreaming(stream_params);
    if (returned_state != ERROR_CODE::SUCCESS) {
        print("Streaming initialization error: ", returned_state);
        return EXIT_FAILURE;
    }

    print("Streaming on port " + to_string(stream_params.port));

    SetCtrlHandler();

    while (!exit_app) {
        if (zed.grab() != ERROR_CODE::SUCCESS)
            sleep_ms(1);
    }

    zed.disableStreaming();
    zed.close();
    return EXIT_SUCCESS;
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
