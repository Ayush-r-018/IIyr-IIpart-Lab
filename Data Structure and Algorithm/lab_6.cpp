// Implementation of Tower of Hanoi using recursion

#include <iostream>
#include <conio.h>

using namespace std;

void towerOfHanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }
    towerOfHanoi(n - 1, source, auxiliary, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main()
{
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    cout << "The sequence of moves involved in the Tower of Hanoi are:" << endl;
    towerOfHanoi(n, 'A', 'B', 'C'); // A, B and C are names of rods

    getch();
    return 0;
}