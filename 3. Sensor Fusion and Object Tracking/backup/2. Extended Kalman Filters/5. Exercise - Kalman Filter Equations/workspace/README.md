
# 1_predict_update.py

 In this exercise, you will implement the predict and update functions of a linear Kalman filter in Python. 

## Your Task
Please implement the `predict()` and `update()` functions in the `Filter` class using the prepared `F()`, `Q()`, and `H()` functions. For matrix manipulation, I would like you to use the `numpy.matrix` format. Both functions return state and covariance.

To run the code, run `python 1_predict_update.py` in the console.

## Desired Result

After successful completion, the console output should show that the state x and covariance P get updated in every iteration. The position estimation at time 100 should be close to the true position 100, and the velocity estimation should be close to the true velocity 1. The entries of P should decrease if the filter is stabilizing.