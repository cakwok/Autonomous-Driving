### Project overview:
The objective of this project is to build a pederstrians, vechicles, object regressing model for autonomous driving systems to understand urban scenes and road conditions.   Object detection is an critical component in self-driving car systems to make precise steering decision to ensure road safety.  SSD is implemented in this project to regress for estimated bounding box and class label.  

### Set up: 
This section should contain a brief description of the steps to follow to run the code for this repository.

In this project, I have firstly analysised the Waymo Open Dataset by delving data structure of each frame in the video sequence. The result is showed at "Exploratory Data Analysis.ipynb" by running the display_instances() function.  I have also evaluated the Tf Object Detection API, to prepare for the setup with a pretrained SSD  network.  Then I conducted a training, and evaluated the prediction performances of the model by TensorBoard using the API, and finally fine tuned the network with data augmentations and hyperparameters experiments.

### Dataset
Dataset Analysis: This section should contain a quantitative and qualitative description of the dataset. It should include images, charts, and other visualizations.

Cross-validation: This section should detail the cross-validation strategy and justify your approach.
Training

#### Dataset Analysis
Waymo Open Dataset is composed of a real world autonomous driving images and LiDAR readings collected by Waymo.  In this project, we would be looking into the real time images collected as the training dataset to analysis road conditions, identify vechicles, pedestrians, cyclists, etc.

The dataset is formatted as TFRrecords. TFRrecords a binary format structure, created by protocol buffer for the reason of serialization.

#### Cross-validation

### Reference experiment: 
This section should detail the results of the reference experiment. It should include training metrics, Tensorboard charts, and a detailed explanation of the algorithm's performance.
![image](https://user-images.githubusercontent.com/21034990/221397452-c12e2917-ca92-4f78-95e3-539695696ea3.png)<br>
![image](https://user-images.githubusercontent.com/21034990/221397412-134acef8-e87e-4612-9021-f0020ec6e693.png)![image](https://user-images.githubusercontent.com/21034990/221397417-d4841291-4dc6-409f-abcc-478a636f6b26.png)


### Improve on the reference: 
This section should highlight the different strategies you adopted to improve your model. It should contain relevant figures and details of your findings.

Image Augumentation
![image](https://user-images.githubusercontent.com/21034990/221432614-13a1275e-eecb-445f-9191-b612743a973a.png)br>
![image](https://user-images.githubusercontent.com/21034990/221432629-f294a980-374d-4a98-9108-4d83bf4e5c49.png)
![image](https://user-images.githubusercontent.com/21034990/221432530-edee2ef9-ca2a-4bad-9616-3b00d3a0ca1e.png)<br>


Once you have everything ready and have checked your deliverables against everything in the rubric, you can click the "Submit Project" button on this page.
