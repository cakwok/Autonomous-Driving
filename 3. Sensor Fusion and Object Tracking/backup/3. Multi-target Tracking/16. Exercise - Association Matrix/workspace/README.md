
# 3_association_matrix.py

In this exercise, you will implement the association matrix for a simple association problem with 3 tracks and 3 measurements. 

## Your Task

In the `Association` class, please implement the attribute `association_matrix` in the function called `associate()`. This function gets as input a list of N track indices `track_list` and a list of M measurement indices `meas_list`. The association matrix is initialized to an NxM matrix with matrix components set to infinity. Now please fill the association matrix with the respective Mahalanobis distances. To calculate these distances, please implement the `MHD()` function below that gets a track `track` and a measurement `meas` as input and returns the Mahalanobis distance. You will also have to implement the measurement function H here for a 4D state vector and a 2D lidar measurement. We neglect the height in this exercise, as well as the transformation from vehicle to sensor coordinates, so the track state is already given in sensor coordinates here.

To run the code, run `python 3_association_matrix.py` in the console. Note that if you run the code from the original terminal, you will also need to click the "Desktop" button in the bottom right to be able to see the visualization window.


## Desired Result

If you run the script, the figure contains 3 tracks in red and 3 measurements in green. If you have implemented everything correctly, the script links all associated track-measurement-pairs with gray lines and writes the calculated MHD next to it. The console output shows how the resulting association matrix looks like.