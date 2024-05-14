# NOTES

## TEST CASES

* Streaming Codec (set on sender)
  * H264 - AVCHD/H264 encoding 
  * H265 - HEVC/H265 encoding 
  * ex: `stream_params.codec = sl::STREAMING_CODEC::H264;`

* Resolution (Fps available) (set on receiver)
  * HD2K (15)
  * HD1080 (15,30)
  * HD720 (15,30,60)
  * VGA (15,30,60,100)
  * ex: `init_params.camera_resolution = RESOLUTION::HD1080;` `init_params.camera_fps = 30;`

* Bitrate (set on sender)
  * Available range: [1000 - 60000]
  * `stream_params.bitrate = 8000;`

## Work Log
* Install ZED SDK
* Install CUDA
* Justify use of C++? CMake?
* Reference GStreamer?
* Precision Time Protocol (didnt work) [link](https://www.stereolabs.com/docs/video/multi-camera#configure-the-ptp-service-to-synchronize-the-devices)
* Point Clouds (Cloud Compare)

## Dissertation Chapters
1. State of the art
1. Design/Implementation
   - Detail ZED (Capture, display and streaming)
   - Setup codebase (volumetric-video-streaming)
   - Setup experiencias
   - Evaluation Metrics (Cloudcompare)
1. Experiments
   - Streaming configurations
   - Subjects
   - Outputs (csv, ply)
   - Consume outputs and generate results
1. Results
1. Conclusion
1. Future works

## About comparing point clouds

* Open3D Library
  * Iterative closest point (easier, but pc may kabum) [implementation](https://www.open3d.org/docs/release/tutorial/pipelines/global_registration.html)
  * Distance of Chamfer (Alinhar point clouds) [align meshes](https://stackoverflow.com/questions/70160183/how-can-i-align-register-two-meshes-in-open3d-python)
  * Distance of Hausdorf (Alinhar point clouds)

* Tranforms point clouds into histograms

* https://www.cloudcompare.org/doc/wiki/index.php/Align