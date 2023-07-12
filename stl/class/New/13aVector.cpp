#include <iostream>
#include <vector>
using namespace std;
// In C++, vectors are sequence containers used to store elemnets of similar data types.

int main()
{
  vector<int> vt;
  int ch, ele;
  while (true)
  {
    cout << "1.Add Element at last" << endl;
    cout << "2.Display Element" << endl;
    cout << "3.Exit" << endl;
    cout << "Enter your choice : ";
    cin >> ch;

    if (ch == 1)
    {
      cout << "Enter Element: ";
      cin >> ele;

      vt.push_back(ele);
      cout << "Element successfully inserted" << endl;
    }
    else if (ch == 2)
    {
      for (int i = 0; i < vt.size(); i++)
      {
        cout << vt[i] << " ";
      }
    }
    else if (ch == 3)
    {
      break;
    }
    else
    {
      cout << "Wrong Choice" << endl;
    }
  }

  return 0;
}