### Abstract

Despite Kalman filter was published dated back to 1960, the algorithm is still regarded as the current state of the art of predicting state, commonly adapted in the domain of autonomous driving to predict velocity of the next timestamp with sensor fusion.  In this project, I have studied multi dimensional and extended Kalman Filter in details, the application to autonomous driving, the methodology behind to estimate hidden velocity state solely from LiDAR sensor measurement of distance, and come up with a simulation of estimates of state versus measurement (inspired by Udacity).

Introduction and prior work: 

Inspired by Markov Chain hidden sequence from lecture materials such as "Hidden Markov Models for Speech Recognition" papers, I am interested in learning details about Kalman Filter.  Therefore, the work in this project is mainly based on RE Kalman's paper "New Approach to Linear Filtering and Prediction Problems".

### Methods:

Measurement readings from sensors such as LiDAR or camera are expected to come with stochastic noises, errors or acceleration factors.  Therefore the actual readings falls into a probability distribution, where the actual measurement should fall into.  Combining with a predicted probability, the intersection of these 2 probabilities distribution gives another Gaussian with higher peak, less covariance and higher confidence by Bayes rules.  Therefore, applying this resulted Gaussian improves overall measurement, and is able to predict location and velocity of the next state.  In Kalman filter's terminology, this process forms a cycle of 2-step update and predict, similar to EM algorithm and KNN.

In order to estimate velocity of a detected vehicle or pedestrian of the next timestamp, we firstly define the estimated state x as follows, where Px represents position x, Vx represents velocity x, and likewise for the y direction.

![image](https://user-images.githubusercontent.com/21034990/222509524-e55b22e9-8e37-4676-91bb-01f5275db989.png)
  
Since distance can infer velocity over time t, Pxt = Pxt-1 + delta time * Vx, Vxt = Vxt-1 + Vxt, we arrive at a state matrix F, and x of the predicted next state becomes 

![image](https://user-images.githubusercontent.com/21034990/222509563-1ae4d747-2460-47fb-99e0-5ec90fc6c9bb.png)

and takes stochastic noises/errors/acceleration into consideration, it comes up covariance matrix Q.  The smaller the covariance, the higher confidence of the model.

![image](https://user-images.githubusercontent.com/21034990/222509952-8f2fb1ac-2709-4cf1-80c8-fc4c0b3bfb9d.png)

and approximating Q over time, Q becomes

![image](https://user-images.githubusercontent.com/21034990/222510111-ecc2ae1b-8415-4fcd-92bf-b9454988420c.png)

So the predict step has become

xt = F * xt-1

noise Pt = F * Pt-1 * FT + Q.



Next step is to update the model/prediction with actual measurement. 

Measurement in this context is the readings from LiDAR, which provides the value of Px and Py in 2 dimensional fashion with no velocity information, so now we define a H matrix to carry these Px Py location values 

![image](https://user-images.githubusercontent.com/21034990/222510182-1dd58a6d-0aad-4097-946c-30448dab37a5.png)

The update step would then become

Eq1: y = z - H * x                     Error y = ground truth z (measurement of x, y) - H * xt.  Since H is 2D but x is 4D, this step projects the predict space into measurement space.  

Eq2: S = H * P * HT + R          Total covariance of predicted uncertainty covariance + measurement noise, named residuals S in this context

Eq3: K = P * HT * S-1               Kalman gain K, determines the weighting given prediction state covariance/(predict covariance + measurement covariance)).  Denominator is from eq 2.

Eq4: x = x + K * y                    Update x.  The higher the Kalman gain, the higher the weighting of error y

Eq5: P = (identity matrix - K * H) * P           Update P, the process covariance weighted by Kalman gain, by (1 - KH) * P



Results: 

Below shows an animated plot of 3 states per loop - the estimated state (Vx and Vy position), simulated measurement reading with random noise added, and simulated measurement reading of ground truth.  We can see from the result that the predictions lie very closely with measurement.

![image](https://user-images.githubusercontent.com/21034990/222510357-fea6c08d-6eb5-4d27-99b1-02a8a3fd1934.png)
