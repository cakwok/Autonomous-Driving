## 4_gating.py

In this exercise, you will implement a gating function and a track-measurement-association.

### Your Task

First, please implement the `gating()` function based on the inverse cumulative chi-square-distribution. The function should return `True` if the measurement lies inside the gate, otherwise `False`. You can use a gating threshold of 0.95, for example.

Second, please implement the function called `get-closest-track-and-meas()`, which should return the closest track and measurement for the next update. You have to search the association matrix for the smallest entry. If the association matrix only contains infinity as entries, please return `numpy.nan`. Otherwise, you should delete the row and column of the minimum entry from the matrix and get the right track number and measurement number from the lists `unassigned_tracks` and `unassigned_measurements`, respectively. Finally, please delete the corresponding entries from the lists `unassigned_tracks` and `unassigned_measurements` and return the track and the measurement.

To run the code, run `python 4_gating.py` in the console. Note that if you run the code from the original terminal, you will also need to click the "Desktop" button in the bottom right to be able to see the visualization window.

### Desired Result

If you run the script initially, all track-measurement-combinations are plotted with gray lines. After completion, there should be less gray lines, unlikely associations should have been removed. Also, blue lines should show which track got associated to which measurement.

You can also see in the console output how the initial 3x3 association matrix is decreases step by step until it is empty.