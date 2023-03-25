### PID Control Project
In the previous project I have built a path planner for the autonomous vehicle. The objective in this project is to build the steer and throttle controller using PID controller, so that the simulated vehicle follows the trajectory.   The result is simulated with the CARLA simulator.

![image](https://user-images.githubusercontent.com/21034990/227677040-d2c6a13e-592f-4516-ab59-d3f5f6cd2783.png)

#### PID controller for throttle and steer
Despite in the lecture that PID controller accounts for controlling steering angle, the methodology applies to all control problems such as throttling.  The error function in this context is velocity and defined as

```
error_throttle = actual speed - desired speed
```
and for steering angle, the error function is defined similarly.  Actual steer angle could be obtained by arc tangent of 2 points, ie atan2(y2-y1, x2-x1).
```
error_steer = actual steer angle - desired angle
```

#### Evaluate PID efficiency
Despite we have talked about coordinate ascent, in this project, static parameters was used, and the efficiency is plotted as below.   

```
pid_steer.Init(0.5, 0.005, 0.3, 1.2, -1.2);
pid_throttle.Init(0.20,0.001,0.02, 1, -1);
```
![image](https://user-images.githubusercontent.com/21034990/227737543-80fca415-8a48-46ef-8839-8a3e2d92baf8.png)![image](https://user-images.githubusercontent.com/21034990/227737557-dbc24f11-c2ab-4f57-a3d1-33923c19a320.png)

Observed from the Carla simulation, the vehicle has successfully steer away from objects on the road, however the tragetory path is not smooth;  the vehicle steer itself even there is no vehicle ahead.

From the plot below, "error steer" represents the discrepancy between actual and desired angle.  "steering output" represents PID controller output, being regulated between the range 1.2 to -1.2.   

The oscillating pattern looks matching with the simulated behavior.  The PID controller has in fact smoothed out the flunctation of the erros and in syncrhonization with the error steer.  Therefore, the oscillating outcome might be caused by the planner itself.

Likewise for the second plot to evaluate throttling.  In general, the PID controller output matches the trend of error throttle, but since at the beginning of the simulation, the vehicle just started acceleration, which created an outliner at the beginning of the plot.

(raw data of the plots)<br>
![image](https://user-images.githubusercontent.com/21034990/227737609-225bdebd-04e8-430b-826d-d843037bf1c7.png)

#### Coordinate Ascent

In contrast to implement static PID parameters we have been experimenting in the above tasks, Coordinate ascent alogrithm is an automatic way to locate optimal control gain parameters.

The algorithm iterates each parameter while the sum of delta changes of these parameters is no smaller than the tolerance.  In each iteration, the parameters would be increased with or decreased by a small value, check if there exists a better error until it is no longer moving.   

PID controllers are model-free, meaning that they do not rely on a mathematical model of the system being controlled to adjust their parameters. Instead, they use feedback from the system itself to adjust their output in real-time. It is relatively simple to implement, adoptable to different usage and systems, but because of this generalization in nature, we may not be able to optimize the best in specific systems.
