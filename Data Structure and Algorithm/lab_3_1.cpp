#include <iostream>
#include <conio.h>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front, rear;

public:
    Queue(int n)
    {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool IsEmpty()
    {
        return front == -1;
    }

    bool IsFull()
    {
        return rear == size - 1;
    }

    void enqueue(int value)
    {
        if (IsFull())
        {
            cout << "Queue Overflow.\n";
            return;
        }
        if (IsEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = value;
        cout << "Enqueued " << value << " into the queue.\n";
    }

    void dequeue()
    {
        if (IsEmpty())
        {
            cout << "Queue Underflow.\n";
            return;
        }
        cout << "Dequeued " << arr[front] << " from the queue.\n";
        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }
    }

    int start()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty.\n";
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queue q(size);
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. View Front Element\n";
        cout << "4. Display All Elements\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            if (!q.IsEmpty())
            {
                cout << "Element at front: " << q.start() << endl;
            }
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Program Terminated." << endl;
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    getch();
    return 0;
}