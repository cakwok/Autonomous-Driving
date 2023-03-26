

```python
# Write a program that will predict your new mean
# and variance given the mean and variance of your 
# prior belief and the mean and variance of your 
# motion. 

def update(mean1, var1, mean2, var2):
    new_mean = (var2 * mean1 + var1 * mean2) / (var1 + var2)
    new_var = 1/(1/var1 + 1/var2)
    return [new_mean, new_var]

def predict(mean1, var1, mean2, var2):
    new_mean = 0 # TODO: Update this!
    new_var = 0 # TODO: Update this!
    return [new_mean, new_var]

print(predict(10., 4., 12., 4.))
```


```python
# Run this cell to test your code when you are satisfied with your results!
import tester

tester.test(predict)
```
