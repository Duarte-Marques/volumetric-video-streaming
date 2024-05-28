# NOTES

## Work Log
* Install ZED SDK
* Install CUDA
* Justify the use of C++? CMake?
* Reference GStreamer?
* Precision Time Protocol (didn't work) [link](https://www.stereolabs.com/docs/video/multi-camera#configure-the-ptp-service-to-synchronize-the-devices)
* NTP setup to synchronize PC clocks
* ifstats package to check bandwidth usage

## Dissertation Chapters
1. State of the art
1. Design/Implementation
   - Environment setup
     - ZED SDK
     - CUDA
     - C++, CMake
   - Detail ZED (Capture, display and streaming)
   - Setup codebase (volumetric-video-streaming)
   - Setup experiences
   - Evaluation Metrics
     - FPS (zed)
     - Latency (Zed + NTP) (PTP didn't work)
     - Bandwidth (ifstats)
1. Experiments
   - Streaming configurations
   - Subjects
   - Outputs (csv, ply, log)
1. Results
   - Shadows on playback. Connect to the need of multiple cameras.
1. Conclusion
1. Future works
   - Setup for connecting multiple cameras

## TODO

1. Getting Results
	  - Record video on the sender and send the output file to the receiver [Recording](https://www.stereolabs.com/docs/video/recording) 
	  - Record video on sender while broadcasting (is it possible)
	  - Comparing screenshots

1. Isolate parameters for different cases
	  - 1080, 720
	  - fps 15, 30, 60
	  - bitrate ~10.000 (estudar melhor)
   - Better understanding of parameters

1. Test scenarios
   - Static
   - Low movement
   - Constant movement
