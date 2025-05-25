#include <iostream>
#include <conio.h>

using namespace std;

const int MAX_SIZE = 5;

// Top-varying stack implementation
class TopVaryingStack
{
private:
    int top;
    int arr[MAX_SIZE];

public:
    TopVaryingStack()
    {
        top = -1; // Initialize top to -1 indicating empty stack
    }

    bool push(int value)
    {
        if (top >= MAX_SIZE - 1)
        {
            cout << "Stack Overflow (Top)" << endl;
            return false;
        }
        arr[++top] = value;
        cout << value << " pushed to top-varying stack" << endl;
        return true;
    }

    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow (Top)" << endl;
            return -1;
        }
        int value = arr[top--];
        return value;
    }

    bool isEmpty()
    {
        return (top < 0);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Top-varying stack is empty" << endl;
            return;
        }
        cout << "Top-varying stack elements: " << endl;
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Bottom-varying stack implementation
class BottomVaryingStack
{
private:
    int bottom;
    int arr[MAX_SIZE];

public:
    BottomVaryingStack()
    {
        bottom = 0; // Initialize bottom to 0 indicating empty stack
    }

    bool push(int value)
    {
        if (bottom >= MAX_SIZE)
        {
            cout << "Stack Overflow (Bottom)" << endl;
            return false;
        }
        arr[bottom++] = value;
        cout << value << " pushed to bottom-varying stack" << endl;
        return true;
    }

    int pop()
    {
        if (bottom <= 0)
        {
            cout << "Stack Underflow (Bottom)" << endl;
            return -1;
        }
        int value = arr[--bottom];
        return value;
    }

    bool isEmpty()
    {
        return (bottom <= 0);
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Bottom-varying stack is empty" << endl;
            return;
        }
        cout << "Bottom-varying stack elements: ";
        for (int i = 0; i < bottom; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    cout << "Stack Implementation using Array" << endl;
    cout << "1. Top-varying Stack" << endl;
    cout << "2. Bottom-varying Stack" << endl;
    cout << "Enter your choice (1 or 2): ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        TopVaryingStack stack;
        int option, value;

        do
        {
            cout << "\nTop-varying Stack Operations:" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Display" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your option: ";
            cin >> option;

            switch (option)
            {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                value = stack.pop();
                if (value != -1)
                    cout << value << " popped from stack" << endl;
                break;

            case 3:
                stack.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option" << endl;
            }
        } while (option != 4);
    }

    else if (choice == 2)
    {
        BottomVaryingStack stack;
        int option, value;

        do
        {
            cout << "\nBottom-varying Stack Operations:" << endl;
            cout << "1. Push" << endl;
            cout << "2. Pop" << endl;
            cout << "3. Display" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your option: ";
            cin >> option;

            switch (option)
            {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2:
                value = stack.pop();
                if (value != -1)
                    cout << value << " popped from stack" << endl;
                break;

            case 3:
                stack.display();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid option" << endl;
            }
        } while (option != 4);
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    getch();
    return 0;
}