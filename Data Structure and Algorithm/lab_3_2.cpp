#include <iostream>
#include <conio.h>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int rear;

public:
    Queue(int n)
    {
        size = n;
        arr = new int[n];
        rear = -1;
    }

    bool IsEmpty()
    {
        return rear == -1;
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
        rear++;
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

        cout << "Dequeued " << arr[0] << " from the queue.\n";

        // Shift all elements to the left
        for (int i = 1; i <= rear; i++)
        {
            arr[i - 1] = arr[i];
        }

        rear--;
    }

    void display()
    {
        if (IsEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        for (int i = 0; i <= rear; i++)
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
        cout << "3. Display All Elements\n";
        cout << "4. Exit\n";
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
            q.display();
            break;

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    getch();
    return 0;
}