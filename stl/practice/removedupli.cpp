#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
int main()
{
  //cout << "ENTER THE NO OF ELEMENTS : ";
  //int n;

  //cin >> n;
  int a;
  vector<int> v = {2,3,3,3,4,3,2,5,2,4,4,7,8,7,6};
  int n = v.size();
/*
  for (int i = 0; i < n; i++)
  {
    cout << i + 1 << " : ";
    cin >> a;
    v.push_back(a);
  }
*/

  cout << "Before Remove : ";
  for (int ele : v)
    cout << ele << " ";

  for (auto it = v.begin(); it < v.end(); it++)
  {
    for (auto it1 = v.begin(); it1 < v.end(); it1++)
    {

      if (*it1 == *it)
        v.erase(it1);
    }
  }

  cout << "After Remove : ";
  for (int ele : v)
    cout << ele << " ";

  return 0;
}