#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int SIZE = 5;  // Set the size of the string array to 5
    string arr[SIZE];    // Declare a string array of size 5

    // Loop to take input from the user and store it in the array
    for (int i = 0; i < SIZE; i++)
    {
        cout << "Enter string " << i + 1 << ": ";
        getline(cin, arr[i]);
    }

    // Display the elements of the string array
    cout << endl << "The elements of the string array are: " << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << "String " << i + 1 << ": " << arr[i] << endl;
    }

    return 0;
}
