#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <cstdlib>
using namespace std;

bool check_valid_name(string account_holder_name)
{
    for (int i = 0; i < account_holder_name.length(); i++)
    {
        if (!isalpha(account_holder_name[i]))
        {
            return false;
        }
    }
    return true;
}

int generate_account_number()
{
    // Get the current time in seconds since epoch
    time_t currentTime = time(NULL);
    // Seed the random number generator with the current time
    srand(currentTime);
    // Generate a random number between 0 and 999999
    int account_number = rand() % 1000000;
    return account_number;
}

class account
{
private:
public:
    long account_number;
    long account_balance;
    string account_holder_name;

    account(long account_number, long account_balance, string account_holder_name)
    {
        this->account_number = account_number;
        this->account_balance = account_balance;
        this->account_holder_name = account_holder_name;
    }

    string get_account_holder_name()
    {
        return account_holder_name;
    }
    void set_account_holder_name(string account_holder_name)
    {
        this->account_holder_name = account_holder_name;
    }
    long get_account_balance()
    {
        return account_balance;
    }
    long set_account_balance(int check)
    {
        if (check == 1)
        {
            // check == 1 for withdrawl
            long withdrawl_amount;
            cout << "Enter the amount to be withdrawl";
            cin >> withdrawl_amount;
            if (withdrawl_amount < 0)
            {
                cout << "Withdrawl amount can not be negative";
            }
            if (withdrawl_amount > account_balance)
            {
                cout << "Enough money not found" << endl;
                cout << "Paisa not found in your account, gareeb hai tu" << endl;
            }
            else
            {
                long account_balance = this->account_balance - withdrawl_amount;
                this->account_balance = account_balance;
                cout << "Amount has been withdrawl from the account";
            }
        }
        if (check == 0)
        {
            // check == 0 for delete
            long deposite_amount;
            cout << "Enter the amount to be deposite";
            cin >> deposite_amount;
            long account_balance = this->account_balance + deposite_amount;
            this->account_balance = account_balance;
        }
        return account_balance;
    }

    void details()
    {
        cout << "Account Details are as follows: " << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Account Holder Name: " << account_holder_name << endl;
        cout << "Account Balance: " << account_balance << endl
             << endl;
    }
};

class Bank
{
public:
    vector<account> acc;

    void add_account()
    {
        // cout<<"the size of the acc vector is " <<acc.size();
        long account_number;
        long account_balance;
        string account_holder_name;
        account_number = generate_account_number();
        cout << "Enter account holder name";
        cin >> account_holder_name;
        if ((account_holder_name.length() < 4) || (!check_valid_name(account_holder_name)))
        {
            cout << "can not create account since the name you have enterned has some issue!!";
            return;
        }
        cout << "Enter initial bank balance";
        cin >> account_balance;
        account new_account(account_number, account_balance, account_holder_name);
        acc.push_back(new_account);
    }

    void your_account_details(long account_number)
    {
        if (acc.size() == 0)
        {
            cout << "No accounts found";
            return;
        }

        auto it = acc.begin();
        for (it = acc.begin(); it < acc.end(); it++)
        {
            if (account_number == it->account_number)
            {
                it->details();
            }
        }
        if (it == acc.end())
        {
            cout << "account number not found";
        }
    }

    void details()
    {
        if (acc.size() == 0)
        {
            cout << "No accounts found";
            return;
        }
        for (auto it = acc.begin(); it < acc.end(); it++)
            it->details();
    }

    void add_balance(long account_number)
    {
        auto it = acc.begin();
        for (auto it = acc.begin(); it < acc.end(); it++)
        {
            if (account_number == it->account_number)
            {
                long account_balance = it->set_account_balance(0);
                cout << "Account balance is" << account_balance << endl;
            }
        }
        if (it == acc.end())
        {
            cout << "account number not found";
        }
    }

    void withdrawl_balance(long account_number)
    {
        auto it = acc.begin();
        for (it = acc.begin(); it < acc.end(); it++)
        {
            if (account_number == it->account_number)
            {
                long account_balance = it->set_account_balance(1);
                cout << "Account balance is" << account_balance << endl;
            }
        }
        if (it == acc.end())
        {
            cout << "account number not found";
        }
    }

    void update_name(long account_number)
    {
        auto it = acc.begin();
        for (it = acc.begin(); it < acc.end(); it++)
        {
            if (account_number == it->account_number)
            {

                cout << "Enter the new name:";
                string account_holder_name;
                cin >> account_holder_name;
                if ((account_holder_name.length() > 4) && (check_valid_name(account_holder_name)))
                {
                    it->set_account_holder_name(account_holder_name);
                }
                else
                {
                    cout << "There is a problem in the name you have input";
                }
            }
        }
        if (it == acc.end())
        {
            cout << "account number not found";
        }
    }

    void get_name(long account_number)
    {
        auto it = acc.begin();
        for (it = acc.begin(); it < acc.end(); it++)
        {
            if (account_number == it->account_number)
            {
                string account_holder_name = it->get_account_holder_name();
                cout << "account holder name is:" << account_holder_name;
            }
        }
        if (it == acc.end())
        {
            cout << "account number not found";
        }
    }

    void total_amount_in_bank()
    {
        if (acc.size() == 0)
        {
            cout << "No accounts found";
            return;
        }
        int total_amount_in_bank = 0;
        for (auto it = acc.begin(); it < acc.end(); it++)
        {
            total_amount_in_bank += it->account_balance;
        }
        cout<<"Total amount in the bank is : "<<total_amount_in_bank;
    }

    void delete_account(long account_number)
    {
        cout << "You are deleting your account";
        for (auto it = acc.begin(); it < acc.end(); it++)
        {
            if (account_number == it->account_number)
            {
                acc.erase(it);
                cout << "Your account has been successfully deleted";
            }
        }
    }
};

int main()
{

    Bank B;
    while (1)
    {
        int choice;
        long account_number;
        cout << endl;
        cout << "Enter 1: Add Account" << endl;
        cout << "Enter 2: Delete the Account" << endl;
        cout << "Enter 3: Add Balance" << endl;
        cout << "Enter 4: Withdrawl Balance" << endl;
        cout << "Enter 5: Update Bank Account Name" << endl;
        cout << "Enter 6: Display Details" << endl;
        cout << "Enter 7: Total Amount in the bank" << endl;
        cout << "Enter 8: Display Details of all the accounts in the bank" << endl;
        cout << "Enter 9: Getting the name of the account holder" << endl;
        cout << "Enter 10: For existing the bank" << endl;
        cout << "Enter your choice";
        cin >> choice;
        cout << endl;
        if (choice == 1)
        {
            cout << "Enter all the bank detials for new account" << endl;
            B.add_account();
        }
        else if (choice == 2)
        {
            cout << "Enter your account number";
            cin >> account_number;
            cout << "You are deleting your account" << endl
                 << endl;
            B.delete_account(account_number);
        }
        else if (choice == 3)
        {
            cout << "Enter your account number";
            cin >> account_number;
            B.add_balance(account_number);
        }
        else if (choice == 4)
        {
            cout << "Enter your account number";
            cin >> account_number;
            B.withdrawl_balance(account_number);
        }
        else if (choice == 5)
        {
            cout << "Enter your account number";
            cin >> account_number;
            B.update_name(account_number);
        }
        else if (choice == 6)
        {
            cout << "Enter your account number";
            cin >> account_number;
            B.your_account_details(account_number);
        }
        else if (choice == 7)
        {
            B.total_amount_in_bank();
        }
        else if (choice == 8)
        {
            B.details();
        }
        else if (choice == 9)
        {
            cout << "Enter your account number";
            cin >> account_number;
            B.get_name(account_number);
        }
        else if (choice == 10)
        {
            break;
        }
        else
        {
            cout << "Enter your choice carefully";
        }
    }
    return 0;
}