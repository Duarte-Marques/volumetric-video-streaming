#include <sl/Camera.hpp>
#include "utils.hpp"

using namespace std;
using namespace sl;

int main(int argc, char **argv) {
    Camera zed;

    InitParameters initial_params;
    initial_params.input.setFromSVOFile(argv[1]);

    if (zed.open(initial_params) != ERROR_CODE::SUCCESS) {
        cout << "Error while openning the camera.";
        return EXIT_FAILURE;
    }

    sl::Timestamp first_ts, last_ts;
    int nb_frames = zed.getSVONumberOfFrames();
    int svo_position = 0;
    zed.setSVOPosition(svo_position);

    zed.grab();
    first_ts = zed.getTimestamp(sl::TIME_REFERENCE::IMAGE);

    while (svo_position + 2 < nb_frames) {
        if (zed.grab() == ERROR_CODE::SUCCESS) {
            svo_position = zed.getSVOPosition();
            last_ts = zed.getTimestamp(sl::TIME_REFERENCE::IMAGE);
        }
    }

    cout << "Timestamp 1: " << first_ts << "\n";
    cout << "Timestamp 2: " << last_ts << "\n";

    zed.close();
    return EXIT_SUCCESS;
}