## SLAM

The objective of this project is to generate an accurate 3D point cloud map of the simulated environment by continuously scanning with a virtual lidar mounted on an autonomous vehicle simulator. The collected scans are added to the map as the vehicle moves, and the goal is to match new scans with the map using ICP to estimate the vehicle's pose with less than 1.2m pose error.

![image](https://user-images.githubusercontent.com/21034990/224929968-73220ddb-86b6-4f68-9aa4-ecf80cabc70e.png)

## Scan Matching

This project involved the development of a scan matching system using 1.)ICP from scratch and 2.NDT, aided by helper functions from Open PCL libraries. The system enables detection of changes in location and direction, and facilitates the localization of a robot or autonomous system.

### ICP

The resulting output showcases a map represented by big square with blue dots, depicting the LiDAR signal after the first scan at starting pose(left). After moving by an unknown distance and angle, the next LiDAR scan is represented by red dots. Our goal is to estimate the new location of the robot using the source LiDAR cloud points derived from the red dots.

After ICP, we are able to estimate the transformations between these 2 LiDAR scans, and the result is shown as the green dots.  We applied the same transformation to the last pose of the robot, and now we are able to know the location of the robot.<br>
<img src="https://user-images.githubusercontent.com/21034990/224862200-fa355a20-67ec-45bd-83a8-5b2a0c9a219a.png" width=310>
<img src="https://user-images.githubusercontent.com/21034990/224862141-7786ff2e-fc79-40a0-8d9c-f06718d10e2b.png" width=300>
<img src="https://user-images.githubusercontent.com/21034990/224860354-206b992a-625a-4eb8-b3f5-102bf7a50049.png" width=280>

The lines between blue and green dots show the associated points matched by ICP.<br>
<img src="https://user-images.githubusercontent.com/21034990/224856271-8f8a0d00-a21d-49e7-8ae8-cd7abdc6b909.png" width=300>

### NDT
The creation of NDT involves creating a probability density function from a target point cloud and then using newton's method to find a transform that maximizes the overall summation of source point values within that probability field.  To create the probability density function the grid space is discretized into cells, and each cell has it's own 2D Gaussian from the target cloud's points.   The 2D Gaussian represents the probability of finding a point throughout the cell region and is calculated based on mean and covariance of the points inside the cell.   The cell will be a region from 0 to 10 in both x and y directions.

<img src="https://user-images.githubusercontent.com/21034990/224888074-979f38d3-f160-4e36-bb3b-3c01adbee5b4.png" width=400 align="top"> <img src="https://user-images.githubusercontent.com/21034990/224888183-de7868a2-f50e-48d6-bbd3-7cc6c8116257.png" width=500>

### ICP and NDP Alignment
This task compare PCL's ICP(left) and NDP(right) function to align a lidar input scan with a point cloud map.  From the image below we can see the starting pose (green box with red scan) is behind the actual pose (red box). The goal is to provide transformations that minimize this offset and get the green box to overlap with the red.

<img src="https://user-images.githubusercontent.com/21034990/224895071-899c520e-eff8-40b7-91b3-4612519b90ad.png" width=470> <img src="https://user-images.githubusercontent.com/21034990/224895243-c28390e9-49ea-4173-97ef-bd98cca708cc.png" width=500> 
<img src="https://user-images.githubusercontent.com/21034990/224895454-2f0aa3e8-4154-445e-8f4c-e42fe8840fe4.png" width=500> <img src="https://user-images.githubusercontent.com/21034990/224900303-3300bc9a-be45-4561-a08a-87e1e2f646c4.png" width=500 align="top"> 

### ICP and NDP Pose Error
If the pose derivate a lot, the system may not be able to make a good correction.<br>
<img src="https://user-images.githubusercontent.com/21034990/224904519-91641cce-5825-4ad8-9739-939122a9b8cd.png" width=440> <img src="https://user-images.githubusercontent.com/21034990/224904844-71e07752-3afe-4e01-a4bd-4ef9dfda4586.png" width=460> 

<img src="https://user-images.githubusercontent.com/21034990/224901120-6ba0edd2-f2d9-4b49-9d74-e5f5c8b16abe.png" width=450> <img src="https://user-images.githubusercontent.com/21034990/224904797-33a64240-8321-44a0-86e0-ed6dd023d8b0.png" width=450>

### Carla Simulator
Now with the scan matchings and point cloud alignment, the simulated car could be driving with information given by LiDAR in the Carla simulator. 
![image](https://user-images.githubusercontent.com/21034990/224914231-576346ca-97b4-4f32-b029-9035bc1f8ece.png)

