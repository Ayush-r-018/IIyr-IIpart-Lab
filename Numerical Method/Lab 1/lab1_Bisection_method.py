def f(s):
    return s * s * s - 4 * s + 1
error = 0.001
while(True):
    x1 = float (input("Enter the value for x1 : "))
    x2 = float (input("Enter the value for x2 : "))

    if (f(x1) * f(x2) < 0):
        break
    else:
        print("The initial guess doesn't include the root, guess again")
while(abs(x1-x2)>error):
    x0=(x1+x2)/2
    if (f(x1) * f(x0)<0):
        x2=x0
    else:
        x1=x0
        print("The root is ", x0)