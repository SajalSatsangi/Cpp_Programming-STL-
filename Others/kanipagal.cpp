#include <iostream>
using namespace std;

int main()
{
  char arr[10];
  int i;

  for (int i = 0; i < 10; i++)
  {
    cin >> arr[i];
  }

  cout << "Array Elements : ";
  for (int i = 0; i < 10; i++)
  {
    cout << arr[i];
  }

  return 0;
}