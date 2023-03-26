
# 2_filter.py

In this exercise, you will implement the system matrix F, process noise covariance Q and the measurement matrix H for a linear Kalman filter.

## Your Task

Please implement and return the system matrix `F()`, process noise covariance `Q()` and the measurement matrix `H()` in the `Filter` class for a constant velocity motion model. We use a 4D state vector with 2D position and 2D velocity in this exercise and a 2D lidar measurement. Please use the prepared attributes `dt` and `q` in the Filter class.

To run the code, run `python 2_filter.py` in the console. Note that if you run the code from the original terminal, you will also need to click the "Desktop" button in the bottom right to be able to see the visualization window.

## Desired Result

Running the script should show an animation where the green Kalman filter results approximate the gray ground truth.