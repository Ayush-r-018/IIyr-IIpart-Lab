#FInd Dominant Eigen value and corresponding eigen vector using Power method

import numpy as np
error=0.001
eigenvalue=0
n=int(input("Enter the size of matrix:"))
a=np.zeros((n,n))
x=np.zeros(n)
y=np.zeros(n)
print("Enter matrix elements:")
for i in range(n):
    for j in range(n):
        a[i][j]=float(input("Enter the elements:"))
print("Enter eigen vector guess:")
for i in range(n):
    x[i]=int(input("Enter elements:"))
while(True):
    for i in range(n):
        y[i]=0
        for j in range(n):
            y[i]+=a[i][j]*x[j]
    z=abs(y[0])
    for i in range(n):
        if (z<abs(y[i])):
            z=y[i]
    for i in range(n):
        x[i]=y[i]/z
    e=abs(z-eigenvalue)
    eigenvalue=z
    if(e<error):
        break
print("Eigen value is:",eigenvalue)
print("Eigen vector is:",x)
