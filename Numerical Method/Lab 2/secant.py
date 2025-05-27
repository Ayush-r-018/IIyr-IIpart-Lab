def f(x):
    return x*x*x - 5*x -9
error=0.001
x1=float(input("Enter the first guess x1 : "))
x2=float(input("Enter the second guess x2 : "))
Iteration=0
print(f'Iterartion           x1              x2              x3')
while abs(x2-x1)>error:
    x3 = (x1*f(x2) - x2*f(x1)) / (f(x2) - f(x1))
    print(f'{Iteration}                   {x1:3f}         {x2:3f}         {x3:3f}')
    Iteration+=1
    x1=x2
    x2=x3
print("The root is : ",x3)