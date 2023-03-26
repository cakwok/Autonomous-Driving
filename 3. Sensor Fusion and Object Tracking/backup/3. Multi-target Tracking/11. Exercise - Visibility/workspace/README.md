# 2_fov.py

In this exercise, you will implement a sensor visibility check.

## Your Task

In the `Camera` class, please implement the function `in_fov()`. It takes the current state x as an input and should return true if x lies in the camera's field of view, otherwise it should return false. The `Camera` class contains a given field of view `fov` that you should use. Don't forget to transform from vehicle to sensor coordinates with the given transformation matrices.

To run the code, run `python 2_fov.py` in the console. Note that if you run the code from the original terminal, you will also need to click the "Desktop" button in the bottom right to be able to see the visualization window.

## Desired Result

If you run the script, you can see the opening angle of the camera in blue, so the visible range is in the area between the blue lines. The script generates random points and calculates whether the points lie inside the field of view. If you have implemented everything correctly, the result should be `False` for all red points outside the field of view, but the visible points in between the blue lines should be green and return `True`. 