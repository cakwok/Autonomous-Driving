#### Coordinate Ascent

Coordinate ascent is one of the key take-away from this module.  The objective is to locate the optimal control gain parameters - P, I, D for PID control.

The algorithm iterates each parameter while the sum of delta changes of these parameters is no smaller than the tolerance.  In each iteration, the parameters would be increased with or decreased by a small value, check if there exists a better error until it is no longer moving.   

#### PID Control Project Summary
In the previous project I have built a path planner for the autonomous vehicle. The objective in this project is to build the steer and throttle controller using PID controller, so that the simulated vehicle follows the trajectory.   The result is simulated with the CARLA simulator.

![image](https://user-images.githubusercontent.com/21034990/227677040-d2c6a13e-592f-4516-ab59-d3f5f6cd2783.png)

#### PID controller for throttle and steer
Despite in the lecture that PID controller accounts for controlling steering angle, the methodology applies to all control problems such as throttling.  The error function in this context is velocity and defined as

```
error_throttle = actual speed - desired speed
```
and for steering angle
```
error_steer = actual steer angle - desired angle
```

#### Evaluate PID efficiency
![image](https://user-images.githubusercontent.com/21034990/227737543-80fca415-8a48-46ef-8839-8a3e2d92baf8.png)
![image](https://user-images.githubusercontent.com/21034990/227737557-dbc24f11-c2ab-4f57-a3d1-33923c19a320.png)
![image](https://user-images.githubusercontent.com/21034990/227737609-225bdebd-04e8-430b-826d-d843037bf1c7.png)
