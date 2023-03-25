#### Coordinate Accent

Coordinate accent is one of the key take-away from this module.  The objective is to locate the optimal control gain parameters for PID control.

The algorithm iterate each parameter (P, I, D) while the sum of probing is larger than a tolerance.  In each iteration, the parameter would be increased with or decreased by a small value, check if a better error until it is no longer moving.  Then the parameter value would be updated accordingly.

#### Project Summary
The goal is to design a PID controller to perform vehicle trajectory tracking and simulate on the CARLA simulator.
