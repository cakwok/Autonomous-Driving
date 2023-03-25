### PID Control Project
The objective in this project is to develop steer and throttle controller by PID controller, to enable autonomous vehicles to natvate a given trajectory while avoiding collisions with other vehciles.   The result is simulated with CARLA as shown below -

![image](https://user-images.githubusercontent.com/21034990/227677040-d2c6a13e-592f-4516-ab59-d3f5f6cd2783.png)

#### PID controller for throttle and steer
PID (proportional–integral–derivative) controller is a control loop feedback system to regulate a processes.   It calculates error functions between the desired and actual variables, and regulates the output by weighting a proportional factor of the error(proportional), accumlated error over time(integral), and rate of change of the errors(derivative).

The error function of throttle is about the vehicle velocity which is defined as

```
error_throttle = actual speed - desired speed
```

and the error function for steering angle is defined similarly as 
```
error_steer = actual steer angle - desired angle
```
and the actual steer angle could be obtained by arc tangent of 2 points, ie atan2(y2-y1, x2-x1).

#### Evaluate PID efficiency
In this project, the PID controllers are implemented with static PID parameters and initiated as 

```
pid_steer.Init(0.5, 0.005, 0.3, 1.2, -1.2);
pid_throttle.Init(0.20,0.001,0.02, 1, -1);
```

After running simulation for about 90 loops, the vehicle has successfully follow the trajectory, steered away from other vehicles and stopped at stop line.  However, the tragetory path is not smooth;  the vehicle steered itself even there was no vehicle ahead.

The plot of actual and desired values are as shown below.   "error steer" represents the discrepancy between actual and desired steer angle.  "steering output" represents the actual output.  The PID controller has -

- regulated the output between 1.2 to -1.2
- regulated the peak and bottom values less fluctated than the error function
- in synchronization with error function

![image](https://user-images.githubusercontent.com/21034990/227737543-80fca415-8a48-46ef-8839-8a3e2d92baf8.png)![image](https://user-images.githubusercontent.com/21034990/227737557-dbc24f11-c2ab-4f57-a3d1-33923c19a320.png)

The oscillating pattern looks matching with the simulated behavior.  However, the PID controller did in fact smooth out flunctations.  The result looks fine, we might need to trace if the oscillation is arised from the planner itself.

The second plot shows the similar plotting to evaluate throttling.  In general, the PID controller output matches the trend of error throttle, but since at the beginning of the simulation, the vehicle has just started acceleration, which created some outliners at the beginning.

(raw data of the plots)<br>
![image](https://user-images.githubusercontent.com/21034990/227737609-225bdebd-04e8-430b-826d-d843037bf1c7.png)

#### Coordinate Ascent

In contrast to implement static PID parameters we have been experimenting in the above tasks, Coordinate ascent alogrithm is an automatic way to locate optimal control gain parameters.

The algorithm iterates each parameter while the sum of delta changes of these parameters is no smaller than the tolerance.  In each iteration, the parameters would be increased with or decreased by a small value, check if there exists a better error until it is no longer moving.   

PID controllers are model-free, meaning that they do not rely on a mathematical model of the system being controlled to adjust their parameters. Instead, they use feedback from the system itself to adjust their output in real-time. It is relatively simple to implement, adoptable to different usage and systems, but because of this generalization in nature, we may not be able to optimize the best in specific systems, and tuning could be difficult.

#### Running the controller
```
cd nd013-c6-control-starter/project
./install-ubuntu.sh
cd pid_controller/
rm -rf rpclib
git clone https://github.com/rpclib/rpclib.git
cmake .
make
```

#### Running the simulator
```
su - student // Will say permission denied, ignore and continue
cd /opt/carla-simulator/
SDL_VIDEODRIVER=offscreen ./CarlaUE4.sh -opengl
```
main.cpp - main code
pid_controller.cpp - Code to return PID objects, update and compute total errors
