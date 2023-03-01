### Project overview:
The objective of this project is to build a pederstrians, vechicles, object regressing model for autonomous driving systems to understand urban scenes and road conditions.   Object detection is an critical component in self-driving car systems to make precise steering decision to ensure road safety.  Single Shot Detection (SSD) is implemented in this project to regress for estimated bounding box and class label.  

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

Monitor prediction performances by exporting event files into TensorBoard
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
#### Dataset Analysis
Waymo Open Dataset is composed of real world autonomous driving images and LiDAR readings collected by Waymo in cities such as San Francisco.  In this project, we would be looking into the real time images collected as the training dataset to analysis road conditions, identify vechicles, pedestrians, cyclists, etc.

The dataset is formatted as TFRrecords. TFRrecords a binary format structure, created by protocol buffer for serialization and communication across platforms and language libraries by protocol messages, which is defined by .proto files.

Below shows some of the samples of the dataset, with corresponding bounding boxes and class label as ground truth -
<img width="270" alt="image" src="https://user-images.githubusercontent.com/21034990/222014879-098083d0-b608-457f-8f3a-1c75a55dcb78.png"><img width="262" alt="image" src="https://user-images.githubusercontent.com/21034990/222014911-c2c65dca-5445-4b36-8ddd-5aecd0bd349e.png"><img width="265" alt="image" src="https://user-images.githubusercontent.com/21034990/222014927-6beb09af-7174-48b0-864a-895267c9b96a.png"><img width="263" alt="image" src="https://user-images.githubusercontent.com/21034990/222014949-28d3618b-a004-4d88-b7b9-9a345a4456f1.png"><img width="264" alt="image" src="https://user-images.githubusercontent.com/21034990/222015011-ccf0253f-5aea-4c0e-b632-8f72ae4bacf8.png">

And the distribution of the class labels (identified objects) in 30000 samples.  From the bar chart below, we can identify that there are 3 objects defined in the dataset, namely vechicles, predestrains and cyclists, and most of the detected objects belongs to vechicles.  Most frames have less than 20 objects.<br><br>
<img width="429" alt="image" src="https://user-images.githubusercontent.com/21034990/222015203-0cc36ecd-eda2-44ff-b37a-22323ec20aca.png"><br>

#### Cross-validation
Cross validation is achieved by splitting the dataset into roughly 80/20 for training and validation + testing correspondingly.  80-20 splitting is a general practice in machine learning.  With large enough dataset, we can leverage as much as 95% of the dataset for training while still maintaining promising generalization results. 

### Training
### Reference experiment: 
To set up a baseline to compare training performance, a SSD in Resnet50 trainig result, before any ablation tunings, is recorded as below.   

The training is conducted with default hyperparameter settings of batch = 2, SGD with momentum, learning base rate = 0.04, warmup learning rate = 0.013333, data augumentation = random flip horizontal and random crop.  The performance result after performing 2500 steps is recorded as below.<br>
![image](https://user-images.githubusercontent.com/21034990/221432808-0e4f55cf-5abc-47fa-b2c0-db6f15de3c92.png)<br>
<img src="https://user-images.githubusercontent.com/21034990/221432815-e2771264-5198-4370-9cf7-0f5031ff4dc0.png" width = 250>
<img src="https://user-images.githubusercontent.com/21034990/221432824-caf40457-bfad-4371-9684-060cc76626af.png" width = 250><br>

As observed from the result, we can observe that 
1.  Classification loss after the training is around 0.8
2.  Localization loss seems not converging.  at the step 2.3k, the loss achieved is the same as the beginning of the training.
3.  Normalized total loss ended at around 5 which is still high
4.  Regularization loss has not reached a minima as the loss at the later steps is larger than the early steps.
5.  Total loss ended at around 5 is still high

### Improve on the reference: 
This section should highlight the different strategies you adopted to improve your model. It should contain relevant figures and details of your findings.

To improve performance of the model, extra data augmentation, random RGB to gray, random adjust contrast are added as one of the image transforms.  The goal is to provide extra varieties of the dataset to better generalise for unseen data.

Furthermore, the learning rate base has been changed from 0.04 into 0.0002, warming learning rate changed from 0.013333 to 0.000013333, to prevent large step which may have skipped the local minima.

Now we can see from the new dashboard, that the losses compared with the baseline has significantly improved in terms of both magitude, and clear trends of the 5 losses keep on decreasing for further steps. 
<br><br>
![image](https://user-images.githubusercontent.com/21034990/222018965-8081865b-554c-4bcd-92cc-ee309a4bdf47.png)<br>
<img width="250" alt="image" src="https://user-images.githubusercontent.com/21034990/222018992-3f023e46-d827-4c8e-a20e-c47226cbcae2.png"><img width="250" alt="image" src="https://user-images.githubusercontent.com/21034990/222019018-ff226b8d-6e43-4ccd-8f38-83564f7d395c.png">

Samples of new data augmentation - random RGB to gray, random adjust contrast<br>
<img width="315" alt="image" src="https://user-images.githubusercontent.com/21034990/222091142-87e7f5b4-d8cd-4aea-99ba-be010644bfa6.png">
<img width="321" alt="image" src="https://user-images.githubusercontent.com/21034990/222091309-f338628a-86c4-4ac3-8d02-77addb754a5b.png">
