# EXPERIMENT CASES

Static Settings:
* Codec       (**H264**, H265)
* Bitrate     (**10.000**)

Variable Settings:
* Resolution  (H2K, **HD1080**, **HD720**, VGA)
* Fps         (**15**, **30**, **60**)

Room:
* 2.75x4.40m (12.1m²)

### Scenario 1
* Static Camera

| Id | Resolution | FPS | .csv                                 | .log                                 | .SVO2 Original                          | .SVO2 Distorted                          | VMAF (DEPTH) | VMAF (RGB) |
|:---|:-----------|:----|:-------------------------------------|:-------------------------------------|:----------------------------------------|:-----------------------------------------|:-------------|:-----------|
| 1  | HD1080     | 15  | [file](./experiments/id01-values.csv) | [file](./experiments/id01-values.log) | [file](./experiments/id01-original.svo2) | [file](./experiments/id01-distorted.svo2) | 30.263133    | 93.323142  |
| 2  | HD1080     | 30  | [file](./experiments/id02-values.csv) | [file](./experiments/id02-values.log) | [file](./experiments/id02-original.svo2) | [file](./experiments/id02-distorted.svo2) | 22.101103    | 87.592539  |
| 3  | HD720      | 30  | [file](./experiments/id03-values.csv) | [file](./experiments/id03-values.log) | [file](./experiments/id03-original.svo2) | [file](./experiments/id03-distorted.svo2) | 21.363226    | 91.875843  |
| 4  | HD720      | 60  | [file](./experiments/id04-values.csv) | [file](./experiments/id04-values.log) | [file](./experiments/id04-original.svo2) | [file](./experiments/id04-distorted.svo2) | 16.387897    | 93.946867  |

### Scenario 2
* Low movement

| Id | Resolution | FPS | .csv                                 | .log                                 | .SVO2 Original                          | .SVO2 Distorted                          | VMAF (DEPTH) | VMAF (RGB) |
|:---|:-----------|:----|:-------------------------------------|:-------------------------------------|:----------------------------------------|:-----------------------------------------|:-------------|:-----------|
| 5  | HD1080     | 15  | [file](./experiments/id05-values.csv) | [file](./experiments/id05-values.log) | [file](./experiments/id05-original.svo2) | [file](./experiments/id05-distorted.svo2) | 47.053496    | 92.430888* |
| 6  | HD1080     | 30  | [file](./experiments/id06-values.csv) | [file](./experiments/id06-values.log) | [file](./experiments/id06-original.svo2) | [file](./experiments/id06-distorted.svo2) | 44.794700    | 90.261991* |
| 7  | HD720      | 30  | [file](./experiments/id07-values.csv) | [file](./experiments/id07-values.log) | [file](./experiments/id07-original.svo2) | [file](./experiments/id07-distorted.svo2) | 42.622885    | 89.790488* |
| 8  | HD720      | 60  | [file](./experiments/id08-values.csv) | [file](./experiments/id08-values.log) | [file](./experiments/id08-original.svo2) | [file](./experiments/id08-distorted.svo2) | 48.249948    | 93.218443 |

## Scenario 3 
* Constant movement

| Id | Resolution | FPS | .csv                                 | .log                                 | .SVO2 Original                          | .SVO2 Distorted                          | VMAF (DEPTH) | VMAF (RGB) |
|:---|:-----------|:----|:-------------------------------------|:-------------------------------------|:----------------------------------------|:-----------------------------------------|:-------------|:-----------|
| 9  | HD1080     | 15  | [file](./experiments/id9-values.csv)  | [file](./experiments/id9-values.log)  | [file](./experiments/id9-original.svo2)  | [file](./experiments/id9-distorted.svo2)  | 14.576213    | 55.226469* |
| 10 | HD1080     | 30  | [file](./experiments/id10-values.csv) | [file](./experiments/id10-values.log) | [file](./experiments/id10-original.svo2) | [file](./experiments/id10-distorted.svo2) | 23.970257    | 91.458413* |
| 11 | HD720      | 30  | [file](./experiments/id11-values.csv) | [file](./experiments/id11-values.log) | [file](./experiments/id11-original.svo2) | [file](./experiments/id11-distorted.svo2) | 34.321798    | 99.777714  |
| 12 | HD720      | 60  | [file](./experiments/id12-values.csv) | [file](./experiments/id12-values.log) | [file](./experiments/id12-original.svo2) | [file](./experiments/id12-distorted.svo2) | 25.406530    | 93.579574* |
