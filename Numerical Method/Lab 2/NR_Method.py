def f(x):
    return x*x*x- 5*x - 9
def g(x):
    return 3*x*x-5
error=0.0001
while (True):
    x1=float(input("Enter the guess x1 : "))
    if g(x1)!=0:
        break
while (True):
    x2 = x1 - ((f(x1))/(g(x1)))
    err=abs(x2-x1)
    x1=x2
    if err<error:
        break
print("The root is : ",x1)