# 3D Object Detection with LiDAR and Point Clouds

## Compute Lidar Point-Cloud from Range Image

### Visualize range image channels
In the Waymo Open dataset, lidar data is stored as a range image. In a 64 x 2650 x 4 array, each cell represents range, intensity and other readings.  The image below is about extracting two of the data channels, range and intensity, and illustrated by stacking the range channel(above) and intensity channel(below).

![image](https://user-images.githubusercontent.com/21034990/222597886-9228ce0b-5dff-4f47-87f0-b39453473af6.png)

### Visualize point-cloud by Open3D
To project range image into 3D point clouds, compute the 3D sensor coordinates using the inclination, azimuth angles and range at each cell, then calibrate the results with extrinsic parameters and transform this sensor coordinates into vehicle corrdinates.  

To visualize the point clouds, Open3D uses a rainbow color map to map the vehicle z coordinates into colors. Low values are mapped to blue, intermediate values are mapped to green, and high values are mapped to red. 

The illustrations below shows the examples of 3D point clouds, and demonstrates vehicles with varying degree of visiblility -

![image](https://user-images.githubusercontent.com/21034990/222808102-bc506df9-f863-4832-8f6b-085027f0bb19.png)
<img width="1109" alt="image" src="https://user-images.githubusercontent.com/21034990/222811986-c5192314-af07-4856-b8df-043daf9fe7cb.png">
<img width="1460" alt="image" src="https://user-images.githubusercontent.com/21034990/222816312-5e6e7c4f-8e00-4ee9-bdb5-cf16a3216a85.png">

Some common vehicle features that appear as stable features on most vehicles are rear bumper, tailights, side mirrors.  Using range images, we can confirm the presence of these features on most vehicles by examining the lidar intensity channel. The rear-bumper and taillights appear as bright, reflective surfaces with high intensity values, while the side mirrors appear as smaller, reflective surfaces with lower intensity values.
<br><br>
<img width="600" alt="image" src="https://user-images.githubusercontent.com/21034990/222823816-42f20ac8-2021-4c37-a2df-cd12f53c0878.png">

## Create Birds-Eye View from Lidar PCL
Lidar point clouds are an unstructured data points which are distributed unevenly over the measurement range. The nature has imposed challenges from efficient deep network trainings.  Projection based representation, such as BEV projection, is one of the common approaches to represent point clouds into deep network.

### Convert sensor coordinates to bev-map coordinates
Base on the metric coordinates in sensor space, this task prepare the stage for 3D object detection by converting the coordinates into BEV image coordinates. <br><br>
<img src="https://user-images.githubusercontent.com/21034990/222884513-0b237d40-1135-411d-8f57-fbc93ee3f237.png" width=300>

### Compute intensity layer & height layer of the BEV map
Each channel of a BEV image represent one dimension of information, collectively height, intensity, density.  It works similarly like a RGB image, but instead of RGB color space, the colors in BEV images represent different information.

Intensity layer(left) represents the intensity of lidar signal return, whereas height layer(right) represents the z coordinates, or height of an object.<br>
<img src="https://user-images.githubusercontent.com/21034990/222941797-1259f20e-ec4a-4573-b002-9c22a2879f33.png" width=500>
<img src="https://user-images.githubusercontent.com/21034990/222941743-0a102c19-4ec6-4203-a76f-a8c6a1694461.png" width=500>

## Model-based Object Detection in BEV Image
### Extract 3D bounding boxes from SFA3D model
![image](https://user-images.githubusercontent.com/21034990/222950631-3ffa2a60-1bbd-4a43-aefa-ef73e90763fd.png)

### Compute precision and recall
precision = 0.9506578947368421, recall = 0.9444444444444444

![image](https://user-images.githubusercontent.com/21034990/223034826-dbf6b74c-02f5-4d41-9788-0acff7797c2f.png)

