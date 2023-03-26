# 1_initialization.py

In this exercise, you will implement a track initialization based on an unassigned measurement. 

## Your Task

In the `__init__()` function of the Track class, please initialize the 6x1 numpy matrix `x` and the 6x6 numpy matrix `P` based on the measurement input `meas`. The measurement input is an instance of the `Measurement` class. The `Measurement` class already contains the correct transformation matrix including rotation and translation from sensor to vehicle coordinates.

To run the code, run `python 1_initialization.py` in the console. Note that if you run the code from the original terminal, you will also need to click the "Desktop" button in the bottom right to be able to see the visualization window.

## Desired Result

If you run the script, the left plot contains the test measurement in sensor coordinates. We want to use this measurement to initialize a new track. The second plot shows the initialized track. Finally, the last plot shows the measurement converted to vehicle coordinates and the initialized track. If you have implemented everything correctly, the track should be initialized where the measurement lies, so the blue and red marker should align.