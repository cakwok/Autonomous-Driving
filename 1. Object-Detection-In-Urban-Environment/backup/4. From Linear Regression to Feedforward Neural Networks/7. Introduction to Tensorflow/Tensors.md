```python
import numpy as np
import tensorflow as tf
```

## tf.Tensor vs np.array

Tensors are a type of array used by Tensorflow. They have a lot in common with numpy arrays.


```python
arr = np.array([[1, 2, 5], [5,7,3]])
```


```python
arr
```

Convert a numpy array to a Tensorflow tensor with the following line:


```python
tensor = tf.convert_to_tensor(arr)
```

Access the numpy array by using `.numpy()`


```python
tensor.numpy()
```

Tensors and array share some attributes, such as shape.


```python
arr.shape
```


```python
tensor.shape
```

## Operations on tensors

Similarly to np.arrays, we can perform operation on tensors.


```python
tensor
```

Element-wise multiplication


```python
tensor*2
```

Broadcasting rules apply.


```python
tensor*tf.constant([3, 2, 2], dtype=tf.int64)
```

## Additional attribute & methods

Find the tensor location


```python
tensor.device
```

Move tensor to the gpu by calling `tensor.gpu()`


```python

```
