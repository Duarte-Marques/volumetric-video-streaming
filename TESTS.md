# EXPERIMENT CASES
## 1st Generation

Static Settings:
* Codec       (**H264**, H265)
* Bitrate     (**10.000**)

Variable Settings:
* Resolution  (H2K, **HD1080**, **HD720**, VGA)
* Fps         (15, **30**, **60**)

Room:
* 2.75x4.40m (12.1m²)

### Scenario 1
* Static Camera

| Id | Resolution | FPS | .csv                                | .log                                | .SVO2 Original                        | .SVO2 Distorted                         |
|:---|:-----------|:----|:------------------------------------|:------------------------------------|:--------------------------------------|:----------------------------------------|
| 1  | HD1080     | 15  | [file](./experiments/.csv) | [file](./experiments/.log) | [file](./experiments/.svo2) | [file](./experiments/.svo2) | 
| 2  | HD1080     | 30  | [file](./experiments/.csv) | [file](./experiments/.log) | [file](./experiments/.svo2) | [file](./experiments/.svo2) | 
| 3  | HD720      | 30  | [file](./experiments/.csv) | [file](./experiments/.log) | [file](./experiments/.svo2) | [file](./experiments/.svo2) | 
| 4  | HD720      | 60  | [file](./experiments/.csv) | [file](./experiments/.log) | [file](./experiments/.svo2) | [file](./experiments/.svo2) | 

### Scenario 2
* Low movement

| Id | Resolution | FPS | .csv                                | .log                                | .SVO2 Original                         | .SVO2 Distorted                         |
|:---|:-----------|:----|:------------------------------------|:------------------------------------|:---------------------------------------|:----------------------------------------|
| 5  | HD1080     | 15  | [file](./experiments/id5-values.csv) | [file](./experiments/id5-values.log) | [file](./experiments/id5-original.svo2) | [file](./experiments/id5-distorted.svo2) | 
| 6  | HD1080     | 30  | [file](./experiments/.csv) | [file](./experiments/.log) | [file](./experiments/.svo2) | [file](./experiments/.svo2) |  
| 7  | HD720      | 30  | [file](./experiments/.csv) | [file](./experiments/.log) | [file](./experiments/.svo2) | [file](./experiments/.svo2) | 
| 8  | HD720      | 60  | [file](./experiments/.csv) | [file](./experiments/.log) | [file](./experiments/.svo2) | [file](./experiments/.svo2) | 

## Scenario 3
* Constant movement

| Id | Resolution | FPS | .csv                                 | .log                                 | .SVO2 Original                          | .SVO2 Distorted                          |
|:---|:-----------|:----|:-------------------------------------|:-------------------------------------|:----------------------------------------|:-----------------------------------------|
| 9  | HD1080     | 15  | [file](./experiments/id9-values.csv)  | [file](./experiments/id9-values.log)  | [file](./experiments/id9-original.svo2)  | [file](./experiments/id9-distorted.svo2)  |
| 10 | HD1080     | 30  | [file](./experiments/id10-values.csv) | [file](./experiments/id10-values.log) | [file](./experiments/id10-original.svo2) | [file](./experiments/id10-distorted.svo2) | 
| 11 | HD720      | 30  | [file](./experiments/id11-values.csv) | [file](./experiments/id11-values.log) | [file](./experiments/id11-original.svo2) | [file](./experiments/id11-distorted.svo2) | 
| 12 | HD720      | 60  | [file](./experiments/id12-values.csv) | [file](./experiments/id12-values.log) | [file](./experiments/id12-original.svo2) | [file](./experiments/id12-distorted.svo2) | 
