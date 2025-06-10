# Gauss Elimination Method

import numpy as np
n = int(input("Enter number of Equations : "))
a=np.zeros((n,n+1))
for i in range (n):
    for j in range(n+1):
        a[i][j]=float(input("Enter the Elements : "))
for j in range(n):
    for i in range(n):
        if(i>j):
            factor=a[i][j]/a[j][j]
            for k in range(n+1):
                a[i][k]=a[i][k]-factor*a[j][k]
x=np.zeros(n)
x[n-1]=a[n-1][n]/a[n-1][n-1]
for i in range(n-2,-1,-1):
    sum=0
    for j in range(i+1,n):
        sum=sum+a[i][j]*x[j]
    x[i]=(a[i][n]-sum)/a[i][i]
print("Solution is :")
for i in range(n):
    print(f'x[{i+1}]={x[i]}')                              