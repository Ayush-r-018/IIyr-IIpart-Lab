# Integration using the Simpson's 3/8 rule

def f(x):
    return 1/(x**2 + 1)
def simpsons_1_3_rule():
    a = float(input("Enter the lower limit of integration: "))
    b = float(input("Enter the upper limit of integration: "))
    n = int(input("Enter the number of subintervals (must be even): "))
    if n % 2 != 0:
        print("Error: n must be even")
        return
    h = (b - a) / n
    sum = f(a) + f(b)
    for i in range(1, n, 2):
        sum += 4 * f(a + i * h)
    for i in range(2, n-1, 2):
        sum += 2 * f(a + i * h)
    integration = (h / 3) * sum
    print("The approximate value of the integration is : ", integration)
simpsons_1_3_rule()