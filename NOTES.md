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
1. Introduction
2. State of the art
3. Design/Implementation
   - Environment setup
     - ZED SDK - Detail ZED (Capture, display and streaming)
     - CUDA
     - C++, CMake
   - Setup codebase (volumetric-video-streaming, sender, receiver, recorder*, playback*)
   - Evaluation Metrics
     - FPS (zed)
     - Latency (Zed + NTP) (PTP didn't work)
     - Bandwidth (ifstats)
     - Record file (.SVO2)
4. Results
   - Streaming configurations
   - Scenarios
   - Outputs (csv, log, .svo2)
   - Shadows on playback. Connect to the need of multiple cameras.
6. Conclusion
7. Future works
   - Setup for connecting multiple cameras

## Updates from State of the Art Presentation
- Adicionar alguns detalhes sobre as descobertas ou resultados especificos no meu levantamento detalhes que obtive no meu levantamento
- tabela 2.1 -> anaizar tabela

## TODO
1. Getting Results
	  - Record video on the sender and send the output file to the receiver [Recording](https://www.stereolabs.com/docs/video/recording) 
	  - Record video on sender while broadcasting (is it possible)
	  - Comparing screenshots
	  
2. Evaluating video quality (State of the art) Vmaf
3. Update all diagrams to .svg
