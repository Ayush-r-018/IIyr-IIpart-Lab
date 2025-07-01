# Integration Using the Trapezoidal Rule

import numpy as np
def f(x):
    return np.sin(x)
def trapezoidal_rule(a, b, n):
    a = float(input("Enter the lower limit of integration: "))
    b = float(input("Enter the upper limit of integration: "))
    n = int(input("Enter the number of subintervals: "))
    h = (b - a) / n
    integral = 0.5 * (f(a) + f(b))
    for i in range(1, n):
        integral += f(a + i * h)
    integral *= h
    print("The approximate value of the integration is : ", integral)
def main():
    a = 0  # Lower limit
    b = np.pi  # Upper limit
    n = 100  # Number of subintervals
    result = trapezoidal_rule(a, b, n)
    print(f"The integral of sin(x) from {a} to {b} using the trapezoidal rule with {n} subintervals is: {result}")
main()