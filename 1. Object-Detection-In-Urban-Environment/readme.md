Project overview: This section should contain a brief description of the project and what we are trying to achieve. Why is object detection such an important component of self-driving car systems?


### Project overview:
The objective of this project is to build a pederstrians, vechicles, object regressing model for autonomous driving systems to understand urban scenes and road conditions.   Object detection is an critical component in self-driving car systems to make precise steering decision to ensure road safety.  SSD is implemented in this project to regress for estimated bounding box and class label.  

### Set up: 
This section should contain a brief description of the steps to follow to run the code for this repository.

In this project, I have firstly analysised the Waymo Open Dataset by delving data structure of each frame in the video sequence. I have also evaluated the Tf Object Detection API, to prepare for the setup with a pretrained SSD  network.  Then I conducted a training, and evaluated the prediction performances of the model by TensorBoard, and finally fine tuned the network with data augmentations and hyperparameters experiments.

### Dataset
Dataset Analysis: This section should contain a quantitative and qualitative description of the dataset. It should include images, charts, and other visualizations.

Cross-validation: This section should detail the cross-validation strategy and justify your approach.
Training

#### Dataset Analysis
, one of the state-of-the-art framework to detect multiple objects in video frames with the real world autonomous driving dataset collected by Waymo.  Firstly we would be looking into exploratory data analysis, to delve the information the dataset provides.  Secondly I would be sharing comparing and tuning training performance, evaluation performance, analysis on hyperparameters tuning.

#### Cross-validation

### Reference experiment: 
This section should detail the results of the reference experiment. It should include training metrics, Tensorboard charts, and a detailed explanation of the algorithm's performance.

<img src="https://user-images.githubusercontent.com/21034990/221380143-e6e7400f-7773-426a-ab0e-e2c226c94df0.png" width=400><br>
<img src="https://user-images.githubusercontent.com/21034990/221380153-b6b1e8ef-6b9d-46dd-bf15-22b0d2b4fa43.png" width=400><br>
<img src="https://user-images.githubusercontent.com/21034990/221380157-82d80f83-a4f5-460a-9144-e5699ee2774d.png" width=200>
<img src="https://user-images.githubusercontent.com/21034990/221380163-87554253-6aae-4040-9ead-27dae359715a.png" width=200><br>


### Improve on the reference: 
This section should highlight the different strategies you adopted to improve your model. It should contain relevant figures and details of your findings.

learning rate change from 0.04 to 0.1
![image](https://user-images.githubusercontent.com/21034990/221390913-ca672dd0-f331-4a98-8095-c97e752d0d2e.png)
![image](https://user-images.githubusercontent.com/21034990/221390930-cbb4f43f-2daa-4ef7-9623-008c0ec3d9f1.png)
![image](https://user-images.githubusercontent.com/21034990/221390938-2f91e741-7dcd-4688-ae85-5990fa594ee0.png)


Once you have everything ready and have checked your deliverables against everything in the rubric, you can click the "Submit Project" button on this page.
