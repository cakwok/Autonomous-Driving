## SLAM

In this project, an autonomous vehicle simulator is continuously scanning the environment with a virtual lidar.  Every meter the vehicle moves and time has passed the scan gets added to the overall collected point cloud map.  The task is to match lidar scans with the map to best fit the estimation pose with the map using ICP, come up with an accurate point cloud map to visualize the simulated car's 3D scans of the environment, with less than 1.2m pose error.

![image](https://user-images.githubusercontent.com/21034990/224929968-73220ddb-86b6-4f68-9aa4-ecf80cabc70e.png)
