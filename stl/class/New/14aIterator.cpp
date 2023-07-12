/*STL= standard template library is a pre defined code which makes it simple to use
it containd 3 basic library as classes, iterator and container by using these we can make any kind
of program or data structure without thinking about space time complexity*/

/*components of stl
cotainer=
iterator=to access the data(like a pointer)
algorithm=functions*/

// opertaion(hindi main tutorial)

#include <iostream>
using namespace std;
#include <vector>
#include <iterator>
int main()
{
  vector<int> vt = {1, 23, 56, 34};
  vector<int>::iterator it;
  vector<int>::iterator it2;
  it = vt.begin();
  // it = vt.end() - 1;
  // cout << *it << endl;
  // for(it=vt.begin();it!=vt.end();it++)
  // {
  //   cout<<*it<<" ";
  // }
  cout << *it << endl;
  //advance(it, 3);
  it2=next(it,3);
  cout << *it << endl;
  cout << *it2 << endl;
  return 0;
}