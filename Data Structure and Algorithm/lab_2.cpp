#include <iostream>
#include <conio.h>

using namespace std;

const int MAX_SIZE = 5;

class Stack
{
protected:
    int arr[MAX_SIZE];
    int position;

public:
    Stack(int initPos) : position(initPos) {}

    virtual bool push(int value) = 0;
    virtual int pop() = 0;

    bool isEmpty() const
    {
        return (position == (this->isTopVarying() ? -1 : 0));
    }

    void display() const
    {
        if (isEmpty())
        {
            cout << (this->isTopVarying() ? "Top" : "Bottom")
                 << "-varying stack is empty" << endl;
            return;
        }

        cout << (this->isTopVarying() ? "Top" : "Bottom")
             << "-varying stack elements: ";

        if (this->isTopVarying())
        {
            for (int i = position; i >= 0; i--)
            {
                cout << arr[i] << " ";
            }
        }
        else
        {
            for (int i = 0; i < position; i++)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    virtual bool isTopVarying() const = 0;
};

class TopVaryingStack : public Stack
{
public:
    TopVaryingStack() : Stack(-1) {}

    bool push(int value) override
    {
        if (position >= MAX_SIZE - 1)
        {
            cout << "Stack Overflow (Top)" << endl;
            return false;
        }
        arr[++position] = value;
        cout << value << " pushed to top-varying stack" << endl;
        return true;
    }

    int pop() override
    {
        if (position < 0)
        {
            cout << "Stack Underflow (Top)" << endl;
            return -1;
        }
        return arr[position--];
    }

    bool isTopVarying() const override { return true; }
};

class BottomVaryingStack : public Stack
{
public:
    BottomVaryingStack() : Stack(0) {}

    bool push(int value) override
    {
        if (position >= MAX_SIZE)
        {
            cout << "Stack Overflow (Bottom)" << endl;
            return false;
        }
        arr[position++] = value;
        cout << value << " pushed to bottom-varying stack" << endl;
        return true;
    }

    int pop() override
    {
        if (position <= 0)
        {
            cout << "Stack Underflow (Bottom)" << endl;
            return -1;
        }
        return arr[--position];
    }

    bool isTopVarying() const override { return false; }
};

void stackOperations(Stack *stack, const string &type)
{
    int option, value;

    do
    {
        cout << "\n"
             << type << " Stack Operations:" << endl
             << "1. Push" << endl
             << "2. Pop" << endl
             << "3. Display" << endl
             << "4. Exit" << endl
             << "Enter your option: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            stack->push(value);
            break;

        case 2:
            value = stack->pop();
            if (value != -1)
                cout << value << " popped from stack" << endl;
            break;

        case 3:
            stack->display();
            break;

        case 4:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid option" << endl;
        }
    } while (option != 4);
}

int main()
{
    cout << "Stack Implementation using Array" << endl
         << "1. Top-varying Stack" << endl
         << "2. Bottom-varying Stack" << endl
         << "Enter your choice (1 or 2): ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        TopVaryingStack stack;
        stackOperations(&stack, "Top-varying");
    }
    else if (choice == 2)
    {
        BottomVaryingStack stack;
        stackOperations(&stack, "Bottom-varying");
    }
    else
    {
        cout << "Invalid choice" << endl;
    }

    getch();
    return 0;
}