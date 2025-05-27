#include <iostream>
#define MAXSIZE 5
using namespace std;

class stack
{
    int data[MAXSIZE], bos, item, i;

public:
    stack()
    {
        bos = 0;
    }

    void push()
    {
        if (bos == MAXSIZE)
        {
            cout << "Stack is full" << endl;
        }

        else
        {
            cout << "Enter the elements of stack:" << endl;
            cin >> item;
            for (int i = bos; i > 0; i--)
            {
                data[i] = data[i - 1];
            }
            data[0] = item;
            bos++;
        }
    }

    void pop()
    {
        if (bos == 0)
        {
            cout << "Stack is empty" << endl;
        }
        else
        {
            int item = data[0];

            for (i = 0; i < bos; i++)
            {
                data[i] = data[i + 1];
            }
            bos--;
            cout << "The popped item is:" << item << endl;
        }
    }

    void display()
    {
        for (int i = 0; i < bos; i++)
        {
            cout << data[i] << endl;
        }
    }
};

int main()
{
    int choice;
    stack st;

    do
    {
        cout << "Menu" << endl;
        cout << "1.PUSH" << endl;
        cout << "2.POP" << endl;
        cout << "3.DISPLAY" << endl;
        cout << "4.EXIT" << endl;
        cout << "Enter your choice:";
        cin >> choice;

        switch (choice)
        {
        case 1:
            st.push();
            break;
        case 2:
            st.pop();
            break;

        case 3:
            st.display();
            break;

        case 4:
            return 0;
        }
    } while (choice != 4);
}