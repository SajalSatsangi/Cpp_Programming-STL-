#include <iostream>
using namespace std;

class Account
{
  string accountNumber;
  string accountName;
  string accountBalance;

public:
  Account()
  {
  }
  Account()
  {
    this->accountName = accountName;
    this->accountNumber = accountNumber;
    this->accountBalance = accountBalance;
  }
  string getaccountnumber()
  {
    return accountNumber;
  }
  string getaccountName()
  {
    return accountName;
  }
  string getaccountBalance()
  {
    return accountBalance;
  }
  bool isvalidaccountnumber(string accountNumber)
  {
    string str = accountNumber;
    long long AccountNumber = stoi(str);
    return (AccountNumber > 0 && str.length() > 4 && str.length() < 10) ? true : false;
  }

  bool isvalidaccountName(string accountName)
  {
    if (accountName.length() < 4)
      return false;

    for (int i = 0; i < accountName.length(); i++)
    {
      if (!isalpha(accountName[i]) && (accountName[i] != '-') && (accountName[i] != ' ') && (accountName[i] == ' ' && accountName[i + 1] == ' '))
        return false;
    }
    return true;
  }
  bool isvalidaccountBalance(string accountBalance)
  {
    string str = accountBalance;
    return ((str.substr(str.find('.') + 1).length()) < 3) ? true : false;
  }
  bool equals(Account obj)
  {
    return (accountName == obj.getaccountName() && accountNumber == obj.getaccountnumber() && accountBalance == obj.getaccountBalance()) ? true : false;
  }
  string toString()
  {
    return "account Name : " + accountName + "account Number : " + accountNumber + "account Balance : " + accountBalance;
  }
  bool setaccountName()
  {
    if (isvalidaccountName(accountName))
    {
      this->accountName = accountName;
      return true;
    }
    else
    {
      return false;
    }
  }
  bool setaccountNumber()
  {
    if (isvalidaccountnumber(accountNumber))
    {
      this->accountNumber = accountNumber;
      return true;
    }
    else
    {
      return false;
    }
  }
  bool setaccountBalance()
  {
    if (isvalidaccountBalance(accountBalance))
    {
      this->accountBalance = accountBalance;
      return true;
    }
    else
    {
      return false;
    }
  }
};

class Bank
{
  string bankName;
  string branchName[10];
  Account collection[100];
  int index = -1;

public:
  Bank()
  {
  }

  Bank(string bankName, string branchName[10], int length)
  {

    this->bankName = bankName;
    for (int i = 0; i < 10; i++)
    {
      this->branchName[i] = branchName[i];
      this->index = length - 1;
    }
  }
  string getbankname()
  {
    return bankName;
  }
  string *getbranchname()
  {
    return branchName;
  }
  bool isvalidbankname(string bankName)
  {
    if (bankName.length() < 8)
      return true;
    for (int i = 0; i < bankName.length(); i++)
    {
      if (!isalpha(bankName[i]) && (bankName[i] != ' ') && (bankName[i] != '&') && (!isdigit(bankName[i])) || ((bankName[i] == ' ') && (bankName[i + 1] == ' ')))

        return false;
    }
    return true;
  }
  bool isvalidbranchLocation(string branchName[])
  {

    for (int i = 0; i < 5; i++)
    {
      if (branchName[i] == "")
        return false;
    }
    return true;
  }
  bool setBankName(string bankName)
  {

    if (isvalidbankname(bankName))
    {
      this->bankName = bankName;
      return true;
    }
    return false;
  }
  bool setBranchLocations(string branchLocations[])
  {
    if (isvalidbranchLocation(branchName))
    {
      for (int i = 0; i < 5; i++)
      {
        if (this->branchName[i] == branchName[i])
          return true;
      }
    }
    return false;
  }
  Account getAccountnumber(string accountNumber)
  {
    Account obj;
    for (int i = 0; i < index; i++)
    {
      if (collection[i].getaccountnumber() == accountNumber)
        return collection[i];
    }
    return obj;
  }
};

int main()
{
}