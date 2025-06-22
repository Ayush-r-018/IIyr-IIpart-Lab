#include <iostream>
#include <stack>
#include <string>
#include <conio.h>

using namespace std;

int evaluatePostfix(string exp)
{
    stack<float> st;

    for (int i = 0; i < exp.length(); i++)
    {
        char ch = exp[i];

        if (ch >= '0' && ch <= '9')
        {
            st.push(ch - '0');
        }
        else
        {
            float num2 = st.top();
            st.pop();
            float num1 = st.top();
            st.pop();

            switch (ch)
            {
            case '+':
                st.push(num1 + num2);
                break;
            case '-':
                st.push(num1 - num2);
                break;
            case '*':
                st.push(num1 * num2);
                break;
            case '/':
                st.push(num1 / num2);
                break;
            default:
                cout << "Invalid operator encountered!" << endl;
                return -1;
            }
        }
    }
    return st.top();
}

int main()
{
    string postfixExp;
    cout << "Enter a postfix expression: ";
    getline(cin, postfixExp);

    int result = evaluatePostfix(postfixExp);
    cout << "Result: " << result << endl;

    getch();
    return 0;
}