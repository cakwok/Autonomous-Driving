#### Coordinate Accent

Coordinate accent is one of the key take-away from this module.  The objective is to locate the optimal control gain parameters for PID control.

The algorithm iterate each parameter (P, I, D) while the sum of probing is larger than a tolerance.  In each iteration, the parameter would be increased with or decreased by a small value, check if a better error until it is no longer moving.  Then the parameter value would be updated accordingly.

#### Project Summary
In the previous project I have built a path planner for the autonomous vehicle. The objective in this project is to build the steer and throttle controller using PID controller, so that the car follows the trajectory.   The result is simulater with the CARLA simulator.

![image](https://user-images.githubusercontent.com/21034990/227677040-d2c6a13e-592f-4516-ab59-d3f5f6cd2783.png)



