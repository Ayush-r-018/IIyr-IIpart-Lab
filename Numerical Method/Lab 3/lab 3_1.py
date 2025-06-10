# Gauss Jordan Method and Gauss Elimination Method

# Gauss Jordan Method

import numpy as np
n = int(input("Enter number of Equations : "))
a=np.zeros((n,n+1))
for i in range (n):
    for j in range(n+1):
        a[i][j]=float(input("Enter the Elements : "))
for j in range(n):
    pivot=a[j][j]
    for k in range(n+1):
        a[j][k]=a[j][k]/pivot
        for i in range(n):
            if(i!=j):
                factor=a[i][j]/a[j][j]
                for k in range(n+1):
                    a[i][k]=a[i][k]-factor*a[j][k]
print("Solution is : ")
for i in range(n):
    print(f'x[{i+1}]={a[i][n]}')                    


# import numpy as np
# a=np.array([1,2,3,4])
# print(a)
# print(np.__version__)

# for i in range(1, 10, 2):
#     print(i)