#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
  int n;
  cout << "ENTER THE NUMBER OF SUBJECTS :";
  cin >> n;
  string name;
  string garbage;
  int roll_number;
  double marks[n];
  double total_marks = 0, total_credit = 0, percentage = 0, credit[n];
  char gradesI[n];
  char gradesG[n];
  string subjects[n];
  getline(cin, garbage);
  cout << "\n\nEnter the name of the student: ";
  getline(cin, name);

  cout << "Enter the roll number of the student: ";
  cin >> roll_number;

  cout << "\n\t~Upper case for Positive grades and lower case for Negative Grades~";
  cout << "\nEnter the grade : " << endl;
  for (int i = 0; i < n; i++)
  {
    getline(cin, garbage);
    cout << "subject :";
    getline(cin, subjects[i]);
    cout << "credit :";
    cin >> credit[i];
    cout << "INTERNAL :";
    cin >> gradesI[i];
    cout << "EXTERNAL :";
    cin >> gradesG[i];

    total_marks += (marks[i] * credit[i]);
    total_credit += credit[i];

    if (gradesI[i] == 'A')
      marks[i] = 7.5;
    else if (gradesI[i] == 'a')
      marks[i] = 6.75;
    else if (gradesI[i] == 'B')
      marks[i] = 6;
    else if (gradesI[i] == 'b')
      marks[i] = 5.25;
    else if (gradesI[i] == 'C')
      marks[i] = 4.5;
    else if (gradesI[i] == 'c')
      marks[i] = 3.75;
    else if (gradesI[i] == 'D')
      marks[i] = 3;
    else if (gradesI[i] == 'd')
      marks[i] = 2.25;
    else if (gradesI[i] == 'E')
      marks[i] = 1.5;
    else if (gradesI[i] == 'e')
      marks[i] = 0.75;
    else if (gradesI[i] == 'F' || gradesI[i] == 'f')
      marks[i] = 0;
    else
      cout << "Wrong Input";

    if (gradesG[i] == 'A')
      marks[i] = 2.5;
    else if (gradesG[i] == 'a')
      marks[i] = 2.25;
    else if (gradesG[i] == 'B')
      marks[i] = 2;
    else if (gradesG[i] == 'b')
      marks[i] = 1.75;
    else if (gradesG[i] == 'C')
      marks[i] = 1.5;
    else if (gradesG[i] == 'c')
      marks[i] = 1.25;
    else if (gradesG[i] == 'D')
      marks[i] = 1;
    else if (gradesG[i] == 'd')
      marks[i] = 0.75;
    else if (gradesG[i] == 'E')
      marks[i] = 0.5;
    else if (gradesG[i] == 'e')
      marks[i] = 0.25;
    else if (gradesG[i] == 'F' || gradesG[i] == 'f')
      marks[i] = 0;
    else
      cout << "Wrong Input";
  }

  percentage = total_marks / total_credit;

  cout << endl;
  cout << "------------------------" << endl;
  cout << "      MARKSHEET" << endl;
  cout << "------------------------" << endl;
  cout << "Name: " << name << endl;
  cout << "Roll Number: " << roll_number << endl;
  cout << endl;
  cout << "Subject\t\tInternal\tExternal" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << subjects[i] << "\t\t" << gradesI[i] << "\t" << gradesG[i] << endl;
  }

  cout << endl;
  cout << "CGPA: " << percentage << endl;
  cout << "------------------------" << endl;

  return 0;
}
