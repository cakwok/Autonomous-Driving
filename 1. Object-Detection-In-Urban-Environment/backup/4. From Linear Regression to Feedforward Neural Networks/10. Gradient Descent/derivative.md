```python
import tensorflow as tf
```

### Variables

Variables are tensors with fixed type and shape but their values can be changed through operations.


```python
x = tf.constant([[1.0, 2.0]])
```


```python
x
```

We can create a variable from a tensor by calling `tf.Variable`


```python
x_var = tf.Variable(x)
```

tf.Variable share attributes with tensors


```python
x_var.shape
```


```python
x_var.numpy()
```

### Gradient

`tf.Variable` allow us to calculate gradients


```python
x = tf.Variable([[1.0, 2.0]])
```

We use the `tf.GradientTape` api to calculate the gradient of a function


```python
with tf.GradientTape() as tape:
    y = x**2
    
    dy_dx = tape.gradient(y, x)
```


```python
dy_dx.numpy()
```


```python

```
