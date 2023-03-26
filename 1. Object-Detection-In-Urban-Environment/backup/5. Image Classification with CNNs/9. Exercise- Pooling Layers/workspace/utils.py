def check_output(output, pool_size, pool_stride):
    if pool_size == 3 and pool_stride == 3:
        assert output.shape == (1, 75, 75, 16), "Failure"
        print("Success")
    else:
        print("Try pool_size = 3 and pool_stride = 3 for testing")