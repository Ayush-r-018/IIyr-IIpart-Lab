// Implementation of List using Array

#include <iostream>
#include <conio.h> // For getch()
using namespace std;

class ArrayList
{
private:
    int *arr;     // Pointer to array storing list elements
    int capacity; // Maximum capacity of the list
    int size;     // Current number of elements in the list

    // Helper function to resize the array when needed
    void resize()
    {
        int newCapacity = capacity * 2;
        int *newArr = new int[newCapacity];

        // Copy existing elements
        for (int i = 0; i < size; i++)
        {
            newArr[i] = arr[i];
        }

        delete[] arr; // Free old memory
        arr = newArr; // Point to new array
        capacity = newCapacity;

        cout << "List resized to capacity " << capacity << endl;
    }

public:
    // Constructor
    ArrayList(int initialCapacity = 10)
    {
        capacity = initialCapacity;
        arr = new int[capacity];
        size = 0;
    }

    // Destructor
    ~ArrayList()
    {
        delete[] arr;
    }

    // Insert element at the beginning of the list
    void insertAtFirst(int x)
    {
        if (size == capacity)
        {
            resize();
        }

        // Shift all elements to the right
        for (int i = size; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[0] = x;
        size++;
        cout << x << " inserted at the beginning.\n";
    }

    // Insert element at the end of the list
    void insertAtEnd(int y)
    {
        if (size == capacity)
        {
            resize();
        }

        arr[size] = y;
        size++;
        cout << y << " inserted at the end.\n";
    }

    // Delete element from the beginning of the list
    void deleteAtFirst()
    {
        if (size == 0)
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        cout << arr[0] << " deleted from the beginning.\n";

        // Shift all elements to the left
        for (int i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        size--;
    }

    // Delete element from the end of the list
    void deleteAtEnd()
    {
        if (size == 0)
        {
            cout << "List is empty. Cannot delete.\n";
            return;
        }

        cout << arr[size - 1] << " deleted from the end.\n";
        size--;
    }

    // Display all elements in the list
    void display()
    {
        if (size == 0)
        {
            cout << "List is empty.\n";
            return;
        }

        cout << "List elements: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Get current size of the list
    int getSize()
    {
        return size;
    }

    // Get current capacity of the list
    int getCapacity()
    {
        return capacity;
    }
};

int main()
{
    int initialSize;
    cout << "Enter initial capacity of the list: ";
    cin >> initialSize;

    ArrayList list(initialSize);
    int choice, value;

    do
    {
        cout << "\nMenu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete from beginning\n";
        cout << "4. Delete from end\n";
        cout << "5. Display list\n";
        cout << "6. Get current size\n";
        cout << "7. Get current capacity\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert at beginning: ";
            cin >> value;
            list.insertAtFirst(value);
            break;
        case 2:
            cout << "Enter value to insert at end: ";
            cin >> value;
            list.insertAtEnd(value);
            break;
        case 3:
            list.deleteAtFirst();
            break;
        case 4:
            list.deleteAtEnd();
            break;
        case 5:
            list.display();
            break;
        case 6:
            cout << "Current size: " << list.getSize() << endl;
            break;
        case 7:
            cout << "Current capacity: " << list.getCapacity() << endl;
            break;
        case 8:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 8);

    getch();
    return 0;
}