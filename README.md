# Volumetric Video Streaming

## Run the program
You have to run separatly two c++ codes, `sender` and `receiver`. Navigate to each of the build directories and launch the executable:

### `./sender`
* props
  * codec (H264 or H265) ex: `./sender H264`
  * -b (bitrate) [1000-60000] ex: `./sender -b 7500`
  * -fps (frames per second) ex: `/sender -fps 30`
  * -p (port) ex: `./sender -p 1234` (default 30000)

Full example:
> ./sender H265 -b 8000 -p 5200 -fps 30

### `./receiver`
* props
  * resolution (HD2K, HD1080, HD720, VGA) (default: AUTO) ex: `./receiver HD1080`
  * -ip (ip from sender) ex: `./receiver -ip 190.170.1.2:30000`
Full example:
> ./receiver HD1080 -fps 30

* To calculate bandwidth run the `bandwidth.sh` file.

192.168.1.95:30000

### Cloud compare
* run `flatpak run org.cloudcompare.CloudCompare`

## Related to ZED
 - Get the latest [ZED SDK](https://www.stereolabs.com/developers/release/)
 - Check the [Documentation](https://www.stereolabs.com/docs/)