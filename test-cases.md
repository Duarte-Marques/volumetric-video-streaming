# TEST CASES

### STREAMING_CODEC
* H264 - AVCHD/H264 encoding 
* H265 - HEVC/H265 encoding 
> stream_params.codec = sl::STREAMING_CODEC::H264; // Can be H264 or H265

### RESOLUTION (FPS AVAILABLE)
* HD2K (15)
* HD1080 (15,30)
* HD720 (15,30,60)
* VGA (15,30,60,100)
> init_params.camera_resolution = RESOLUTION::HD1080;
> init_params.camera_fps = 30;

### BITRATE
* Available range: [1000 - 60000]
> stream_params.bitrate = 8000;

https://www.stereolabs.com/docs/video/streaming

https://www.stereolabs.com/docs/video/camera-controls#selecting-a-resolution

https://www.stereolabs.com/docs/api/structsl_1_1StreamingParameters.html#details