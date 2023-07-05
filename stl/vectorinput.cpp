#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
  cout << "ENTER THE NO OF ELEMENTS";
  int n;
  cin >> n;
  int a;
  vector<int> v;

  for (int i = 0; i < n; i++)
  {
    cin >> a;
    v.push_back(a);
  }
  return 0;
}