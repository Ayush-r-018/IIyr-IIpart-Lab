#include <iostream>
using namespace std;
#define MAXSIZE 5

class stack
{

    int data[MAXSIZE], i, bos, item;

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
            cout << "Enter the elements of stack:";
            cin >> item;
            for (int i = bos; i > 0; i--)
            {
                data[i] = data[i - 1];
            }
            data[0] = item;
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
            item = data[0];

            for (i = 0; i < bos; i++)
            {
                data[i] = data[i + 1];
            }
            bos--;
            cout << "The popped item:" << item << endl;
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
    stack st;
    int choice;
    do
    {
        cout << "Menu" << endl;
        cout << "1.push" << endl;
        cout << "2.pop" << endl;
        cout << "3.display" << endl;
        cout << "4.exit" << endl;
        cout << "Enter choice:" << endl;
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