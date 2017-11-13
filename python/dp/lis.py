def lis(arr):
    n = len(arr)
 
    # Declare the list (array) for LIS and initialize LIS
    # values for all indexes
    lis = [1]*n
 
    # Compute optimized LIS values in bottom up manner
    for i in range (1 , n):
        for j in range(0 , i):
            if arr[i] > arr[j] and lis[i]< lis[j] + 1 :
                lis[i] = lis[j]+1
 
    # Initialize maximum to 0 to get the maximum of all
    # LIS
    maximum = 0
 
    # Pick maximum of all LIS values
    for i in range(n):
        maximum = max(maximum , lis[i])
    return maximum
