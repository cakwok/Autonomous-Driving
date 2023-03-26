# 3_measurements.py

In this exercise, you will implement the nonlinear camera measurement function h and the Jacobian H in the Camera class. 

## Your Task

In the function `get_hx()`, please implement the nonlinear measurement function h and return h(x) for the input state x. The function should return a 2x1 numpy matrix. Make sure to not divide by zero, but print an error instead. Please use the pre-defined attributes focal length f and principal point c. 

In the `get_H()` function, please calculate the Jacobian at the current state x. The function should return a 2x6 numpy matrix. Again, make sure to not divide by zero.

To run the code, run `python 3_measurements.py` in the console. Note that if you run the code from the original terminal, you will also need to click the "Desktop" button in the bottom right to be able to see the visualization window.

## Desired Result

When you run the script, the linear approximation H should be plotted as tangent to the nonlinear measurement function h at the green extension point x. 