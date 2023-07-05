#include <iostream>
#include <math.h>
using namespace std;
int main()
{
  int a = 10, b = 20, c = 30;
  double s = (a + b + c) / 2;
  int A = sqrt(s*(s - a)*(s - b)*(s - c));

  cout << "value of A" << A << endl;
  cout << "value of s" << s << endl;
  return 0;
}