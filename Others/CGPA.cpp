#include <iostream>
using namespace std;

int cgpa(int n)
{
  string name, IG, EG;
  int credit, I, E;

  if (n == 0)
    return 0;

  cout << "SUBJECT : ";
  cin >> name;
  cout << "CREDIT : ";
  cin >> credit;
  cout << "INTERNAL GRADE :";
  cin >> IG;

  if (IG == "A" || IG == "a")
    I = 7.5;
  else if (IG == "A-" || IG == "a-")
    I = 6.75;
  else if (IG == "B" || IG == "b")
    I = 6;
  else if (IG == "B-" || IG == "b-")
    I = 5.25;
  else if (IG == "C" || IG == "c")
    I = 4.5;
  else if (IG == "C-" || IG == "c-")
    I = 3.75;
  else if (IG == "D" || IG == "d")
    I = 3;
  else if (IG == "D-" || IG == "d-")
    I = 2.25;
  else if (IG == "E" || IG == "e")
    I = 1.5;
  else if (IG == "E-" || IG == "e-")
    I = 0.75;
  else if (IG == "F" || IG == "f")
    I = 0;
  else
  {
    cout << "WRONG INPUT";
    break;
  }

  cout << "EXTERNAL GRADE :";
  cin >> EG;

  if (EG == "A" || EG == "a")
    E = 2.5;
  else if (EG == "A-" || EG == "a-")
    E = 2.25;
  else if (EG == "B" || EG == "b")
    E = 2;
  else if (EG == "B-" || EG == "b-")
    E = 1.75;
  else if (EG == "C" || EG == "c")
    E = 1.5;
  else if (EG == "C-" || EG == "c-")
    E = 1.25;
  else if (EG == "D" || EG == "d")
    E = 1;
  else if (EG == "D-" || EG == "d-")
    E = 0.75;
  else if (EG == "E" || EG == "e")
    E = 0.5;
  else if (EG == "E-" || EG == "e-")
    E = 0.25;
  else if (EG == "F" || EG == "f")
    E = 0;
  else
  {
    cout << "WRONG INPUT";
    break;
  }

  total = total + (I + E) * credit;
  totalcredit = totalcredit + credit;

  return total / totalcredit;
}

int main()
{
  int n, marks;
  cout << "ENTER THE NO OF SUBJECTS : ";
  cin >> n;
  marks = cgpa(n, 0, 0);

  cout << "\n\tMARKS : " << marks;

  return 0;
}