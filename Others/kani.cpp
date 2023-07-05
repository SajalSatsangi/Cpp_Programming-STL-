#include <iostream>
using namespace std;

int main()
{
  int i = 1, n, sum = 0, j = 1, k = 1;

  cout << "Enter the value of n : ";
  cin >> n;

  for (j = 1; j <= n; j++)
  {
    sum = sum + k;
    i = i + 2;
    k = i * (-1);
  }

  cout << "Sum : " << sum;
  return 0;
}