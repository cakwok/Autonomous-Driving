This project involved the development of a scan matching system using ICP, aided by helper functions from Open PCL libraries. The system enables detection of changes in location and direction, and facilitates the localization of a robot or autonomous system.

The resulting output showcases a map represented by blue dots, depicting the LiDAR signal after a scan. After moving by an unknown distance and angle, the next LiDAR scan is represented by red dots. Our goal is to estimate the new location of the robot using the source LiDAR cloud points derived from the red dots.

After ICP, we are able to estimate the transformations between these 2 LiDAR scans, and the result is shown as the green dots.  <br>
<img src="https://user-images.githubusercontent.com/21034990/224862200-fa355a20-67ec-45bd-83a8-5b2a0c9a219a.png" width=310>
<img src="https://user-images.githubusercontent.com/21034990/224862141-7786ff2e-fc79-40a0-8d9c-f06718d10e2b.png" width=300>
<img src="https://user-images.githubusercontent.com/21034990/224860354-206b992a-625a-4eb8-b3f5-102bf7a50049.png" width=280>

The lines between blue and green dots show the matched points by ICP.<br>
![image](https://user-images.githubusercontent.com/21034990/224856271-8f8a0d00-a21d-49e7-8ae8-cd7abdc6b909.png)