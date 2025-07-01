# Integration using the Simpson's 3/8 rule

def f(x):
    return 1/(x**2 + 1)
def simpsons_3_8_rule():
    a = float(input("Enter the lower limit of integration: "))
    b = float(input("Enter the upper limit of integration: "))
    n = int(input("Enter the number of subintervals (must be a multiple of 3): "))
    if n % 3 != 0:
        print("Error: n must be a multiple of 3")
        return
    sum = 0 
    h=(b-a)/n
    for i in range(1, n):
        k = a + i * h
        if i % 3 == 0:
            sum += 2 * f(k)
        else:
            sum += 3 * f(k)
    integration = (3 * h / 8) * (f(a) + f(b) + sum)
    print("The approximate value of the integration is : ", integration)
simpsons_3_8_rule()