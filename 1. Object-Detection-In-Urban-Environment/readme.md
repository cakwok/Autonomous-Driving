### Project overview:
The objective of this project is to build a pederstrians, vechicles, object regressing model for autonomous driving systems to understand urban scenes and road conditions.   Object detection is an critical component in self-driving car systems to make precise steering decision to ensure road safety.  SSD is implemented in this project to regress for estimated bounding box and class label.  

### Set up: 
This section contains a brief description of the steps to follow to run the code for this repository.

Start by analyzing the dataset by looking into the data structure of each frame in the video sequence. The result is showed at "Exploratory Data Analysis.ipynb" by running the display_instances() function.  

Prepare the setup by loading a pretrained SSD network by the Tf Object Detection API.

```
python edit_config.py --train_dir /home/workspace/data/train/ --eval_dir /home/workspace/data/val/ --batch_size 2 --checkpoint /home/workspace/experiments/pretrained_model/ssd_resnet50_v1_fpn_640x640_coco17_tpu-8/checkpoint/ckpt-0 --label_map /home/workspace/experiments/label_map.pbtxt
```

Train the network using the pipeline_new.config file.  The file defines training parameters such as image augumentation, learning rate, etc.
```
python experiments/model_main_tf2.py --model_dir=experiments/reference/ --pipeline_config_path=experiments/reference/pipeline_new.config
```

Evaluate prediction performances by exporting event files into TensorBoard
```
python -m tensorboard.main --logdir experiments/reference/
```

Evalute inference performance by loading the validation dataset, and peform detection by the learnt weight.

```
python experiments/model_main_tf2.py --model_dir=experiments/reference/ --pipeline_config_path=experiments/reference/pipeline_new.config --checkpoint_dir=experiments/reference/
```

Fine tune the network with data augmentations and hyperparameters experiments.  The effect of data augmentations could be viewed from "Explore augmentations Grayscale.ipynb"

There is no new requirements.txt file or a Dockerfile, as the project is run in the Udacity provided workspace.

### Dataset
Dataset Analysis: This section should contain a quantitative and qualitative description of the dataset. It should include images, charts, and other visualizations.

Cross-validation: This section should detail the cross-validation strategy and justify your approach.
Training

#### Dataset Analysis
Waymo Open Dataset is composed of real world autonomous driving images and LiDAR readings collected by Waymo in cities such as San Francisco.  In this project, we would be looking into the real time images collected as the training dataset to analysis road conditions, identify vechicles, pedestrians, cyclists, etc.

The dataset is formatted as TFRrecords. TFRrecords a binary format structure, created by protocol buffer for serialization, and communicated across platforms, cross-language library by protocol messages defined by .proto files.

#### Cross-validation
Cross validation is designed for 80/20 split of dataset into training and validation correspondingly.  In this project, the cross-validation dataset is split as 80-20 as per provided by Udacity.

### Reference experiment: 
This section should detail the results of the reference experiment. It should include training metrics, Tensorboard charts, and a detailed explanation of the algorithm's performance.
To set training before tuning as a baseline, a training is conducted with default hyperparameter setting of batch = 2, optimizier = SGD with momentum, data augumentation = random flip horizontal and random crop.  The performance result after performing 2500 steps is recorded as below.
![image](https://user-images.githubusercontent.com/21034990/221432808-0e4f55cf-5abc-47fa-b2c0-db6f15de3c92.png)<br>
![image](https://user-images.githubusercontent.com/21034990/221432815-e2771264-5198-4370-9cf7-0f5031ff4dc0.png)
![image](https://user-images.githubusercontent.com/21034990/221432824-caf40457-bfad-4371-9684-060cc76626af.png)<br>


### Improve on the reference: 
This section should highlight the different strategies you adopted to improve your model. It should contain relevant figures and details of your findings.

To improve performance of the model, 
![image](https://user-images.githubusercontent.com/21034990/221735046-a84aef7c-67a2-4585-8ba5-b0e8c56294f5.png)<br>
![image](https://user-images.githubusercontent.com/21034990/221735095-e34ce549-6c0d-4814-b728-80ce2154ff7b.png)
![image](https://user-images.githubusercontent.com/21034990/221735120-5309d295-e01e-44ad-be99-8d5f9538cc2b.png)


Once you have everything ready and have checked your deliverables against everything in the rubric, you can click the "Submit Project" button on this page.
