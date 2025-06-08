// Implementation of circular queue using array

#include <iostream>
#include <conio.h> // For getch()
using namespace std;

class Queue
{
private:
    int *arr;     // Array to store queue elements
    int front;    // Front index
    int rear;     // Rear index
    int capacity; // Maximum capacity
    int count;    // Current number of elements

public:
    // Constructor
    Queue(int size)
    {
        capacity = size;
        arr = new int[capacity];
        front = 0;
        rear = -1;
        count = 0;
    }

    // Destructor
    ~Queue()
    {
        delete[] arr;
    }

    // Enqueue operation
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is full. Cannot enqueue.\n";
            return;
        }

        rear = (rear + 1) % capacity;
        arr[rear] = value;
        count++;
        cout << value << " enqueued to queue.\n";
    }

    // Dequeue operation
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }

        cout << arr[front] << " dequeued from queue.\n";
        front = (front + 1) % capacity;
        count--;
    }

    // Get front element
    int start()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return -1; // Return -1 to indicate empty queue
        }
        return arr[front];
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return (count == 0);
    }

    // Check if queue is full
    bool isFull()
    {
        return (count == capacity);
    }

    // Display all elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        for (int c = 0; c < count; c++)
        {
            cout << arr[i] << " ";
            i = (i + 1) % capacity;
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
            if (!q.isEmpty())
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