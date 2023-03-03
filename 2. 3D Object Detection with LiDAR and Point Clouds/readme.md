## Constructing

### Compute Lidar Point-Cloud from Range Image

#### Visualize range image channels
From this image, we can see the range channel(above) and intensity channel(below) as stacked to illustrate range image.
![image](https://user-images.githubusercontent.com/21034990/222597886-9228ce0b-5dff-4f47-87f0-b39453473af6.png)

#### Visualize point-cloud by Open3D
In Open3D, a rainbow color map is a color map used to map scalar values to colors. Low scalar values are mapped to red, intermediate scalar values are mapped to green, and high scalar values are mapped to blue. 

Below shows the RGB image captured by the front camera, with the corresponding point clouds with examples of vehicles with varying degree of visiblility -

![image](https://user-images.githubusercontent.com/21034990/222808102-bc506df9-f863-4832-8f6b-085027f0bb19.png)
<img width="1109" alt="image" src="https://user-images.githubusercontent.com/21034990/222811986-c5192314-af07-4856-b8df-043daf9fe7cb.png">
<img width="1260" alt="image" src="https://user-images.githubusercontent.com/21034990/222816312-5e6e7c4f-8e00-4ee9-bdb5-cf16a3216a85.png">

Some common vehicle features that appear as stable features on most vehicles are rear bumper, tailights, side mirrors.  Using range images, we can confirm the presence of these features on most vehicles by examining the lidar intensity channel. The rear-bumper and taillights appear as bright, reflective surfaces with high intensity values, while the side mirrors appear as smaller, reflective surfaces with lower intensity values.
<img width="600" alt="image" src="https://user-images.githubusercontent.com/21034990/222823816-42f20ac8-2021-4c37-a2df-cd12f53c0878.png">
