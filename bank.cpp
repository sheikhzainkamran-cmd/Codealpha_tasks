#include<iostream>
#include<string>
#include<fstream>
using namespace std;

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"



bool isInteger(string input)
{
    if(input.empty())
        return false;

    int start = 0;

    if(input[0] == '-')
    {
        if(input.length() == 1)
            return false;

        start = 1;
    }

    for(int i = start; i < input.length(); i++)
    {
        if(input[i] < '0' || input[i] > '9')
            return false;
    }

    return true;
}

int stringToInt(string input)
{
    int number = 0;
    int start = 0;

    if(input[0] == '-')
        start = 1;

    for(int i = start; i < input.length(); i++)
    {
        number = number * 10 + (input[i] - '0');
    }

    if(input[0] == '-')
        number = -number;

    return number;
}

bool isDouble(string input)
{
    if(input.empty())
        return false;

    int dotCount = 0;
    int digitCount = 0;

    for(int i = 0; i < input.length(); i++)
    {
        if(input[i] >= '0' && input[i] <= '9')
        {
            digitCount++;
        }
        else if(input[i] == '.')
        {
            dotCount++;

            if(dotCount > 1)
                return false;
        }
        else if(input[i] == '-' && i == 0)
        {
            // allowed only at beginning
        }
        else
        {
            return false;
        }
    }

    if(digitCount == 0)
        return false;

    return true;
}

double stringToDouble(string input)
{
    double number = 0;
    double decimalPlace = 0.1;
    bool decimal = false;
    bool negative = false;

    int start = 0;

    if(input[0] == '-')
    {
        negative = true;
        start = 1;
    }

    for(int i = start; i < input.length(); i++)
    {
        if(input[i] == '.')
        {
            decimal = true;
        }
        else
        {
            int digit = input[i] - '0';

            if(!decimal)
            {
                number = number * 10 + digit;
            }
            else
            {
                number = number + digit * decimalPlace;
                decimalPlace = decimalPlace / 10;
            }
        }
    }

    if(negative)
        number = -number;

    return number;
}

int getInteger(string message)
{
    string input;

    while(true)
    {
        cout << message;
        getline(cin, input);

        if(isInteger(input))
        {
            return stringToInt(input);
        }

        cout << RED
             << "Invalid input. Enter numbers only."
             << RESET << endl;
    }
}

double getDouble(string message)
{
    string input;

    while(true)
    {
        cout << message;
        getline(cin, input);

        if(isDouble(input))
        {
            return stringToDouble(input);
        }

        cout << RED
             << "Invalid input. Enter a valid number."
             << RESET << endl;
    }
}

/* ========================= CUSTOMER CLASS ========================= */

class Customer
{
private:
    int customer_id;
    string name;
    string phone;
    string email;

public:

    Customer(int id, string n, string p, string e)
    {
        customer_id = id;
        name = n;
        phone = p;
        email = e;
    }

    Customer()
    {
        customer_id = 0;
        name = "";
        phone = "";
        email = "";
    }

    void displaycustomer()
    {
        cout << "\n";
        cout << CYAN;
        cout << "============================================\n";
        cout << "           CUSTOMER INFORMATION\n";
        cout << "============================================\n";
        cout << RESET;

        cout << "Customer ID : " << customer_id << endl;
        cout << "Name        : " << name << endl;
        cout << "Phone       : " << phone << endl;
        cout << "E-mail      : " << email << endl;
    }

    int getcustomerid()
    {
        return customer_id;
    }

    string getname()
    {
        return name;
    }

    string getphone()
    {
        return phone;
    }

    string getemail()
    {
        return email;
    }
};

/* ========================= ACCOUNT CLASS ========================= */

class Accounts
{
private:
    int acc_nmbr;
    string acc_type;
    double balance;
    int customer_id;

public:

    Accounts()
    {
        acc_nmbr = 0;
        acc_type = "";
        balance = 0;
        customer_id = 0;
    }

    Accounts(int acc_no, string type, double bal, int id)
    {
        acc_nmbr = acc_no;
        acc_type = type;
        balance = bal;
        customer_id = id;
    }

    int getaccountnumber()
    {
        return acc_nmbr;
    }

    int getcustomerid()
    {
        return customer_id;
    }

    double getbalance()
    {
        return balance;
    }

    string getaccounttype()
    {
        return acc_type;
    }

    void deposit(double amount)
    {
        balance = balance + amount;
    }

    bool withdraw(double amount)
    {
        if(balance >= amount)
        {
            balance = balance - amount;
            return true;
        }
        else
        {
            cout << RED
                 << "Insufficient balance."
                 << RESET << endl;

            return false;
        }
    }

    void displayaccount()
    {
        cout << "\n";
        cout << BLUE;
        cout << "+------------------------------------------+\n";
        cout << "|             ACCOUNT DETAILS              |\n";
        cout << "+------------------------------------------+\n";
        cout << RESET;

        cout << "Account Number : " << acc_nmbr << endl;
        cout << "Account Type   : " << acc_type << endl;
        cout << "Balance        : " << balance << endl;
        cout << "Customer ID    : " << customer_id << endl;
    }
};

/* ========================= TRANSACTION CLASS ========================= */

class Transaction
{
private:
    int transaction_id;
    int account_number;
    string transaction_type;
    double amount;

public:

    Transaction()
    {
        transaction_id = 0;
        account_number = 0;
        transaction_type = "";
        amount = 0;
    }

    Transaction(int id, int acc_no, string type, double amt)
    {
        transaction_id = id;
        account_number = acc_no;
        transaction_type = type;
        amount = amt;
    }

    int getaccountnumber()
    {
        return account_number;
    }

    int gettransactionid()
    {
        return transaction_id;
    }

    string gettransactiontype()
    {
        return transaction_type;
    }

    double getamount()
    {
        return amount;
    }

    void displaytransaction()
    {
        cout << "\n";
        cout << YELLOW;
        cout << "--------------------------------------------\n";
        cout << "           TRANSACTION DETAILS\n";
        cout << "--------------------------------------------\n";
        cout << RESET;

        cout << "Transaction ID   : " << transaction_id << endl;
        cout << "Account Number   : " << account_number << endl;
        cout << "Transaction Type : " << transaction_type << endl;
        cout << "Amount           : " << amount << endl;
    }

    bool belongsToAccount(int acc_no)
    {
        return account_number == acc_no;
    }
};

/* ========================= SEARCH FUNCTIONS ========================= */

bool customerexist(Customer customer[], int total_customers, int id)
{
    for(int i = 0; i < total_customers; i++)
    {
        if(customer[i].getcustomerid() == id)
            return true;
    }

    return false;
}

bool accountexist(Accounts account[], int total_accounts, int nmbr)
{
    for(int i = 0; i < total_accounts; i++)
    {
        if(account[i].getaccountnumber() == nmbr)
            return true;
    }

    return false;
}

int find_account(Accounts account[], int total_accounts, int nmbr)
{
    for(int i = 0; i < total_accounts; i++)
    {
        if(account[i].getaccountnumber() == nmbr)
            return i;
    }

    return -1;
}

/* ========================= FILE SAVE ========================= */

void save_customers(Customer customer[], int total_customers)
{
    ofstream file("customers.txt");

    for(int i = 0; i < total_customers; i++)
    {
        file << customer[i].getcustomerid() << "|"
             << customer[i].getname() << "|"
             << customer[i].getphone() << "|"
             << customer[i].getemail() << endl;
    }

    file.close();
}

void save_accounts(Accounts accounts[], int total_accounts)
{
    ofstream file("accounts.txt");

    for(int i = 0; i < total_accounts; i++)
    {
        file << accounts[i].getaccountnumber() << "|"
             << accounts[i].getaccounttype() << "|"
             << accounts[i].getbalance() << "|"
             << accounts[i].getcustomerid() << endl;
    }

    file.close();
}

void save_transactions(Transaction transactions[], int total_transactions)
{
    ofstream file("transactions.txt");

    for(int i = 0; i < total_transactions; i++)
    {
        file << transactions[i].gettransactionid() << "|"
             << transactions[i].getaccountnumber() << "|"
             << transactions[i].gettransactiontype() << "|"
             << transactions[i].getamount() << endl;
    }

    file.close();
}

/* ========================= FILE LOAD ========================= */

void load_customers(Customer customer[], int &total_customers)
{
    ifstream file("customers.txt");

    if(!file)
        return;

    int id;
    string name;
    string phone;
    string email;

    while(file >> id)
    {
        file.ignore();

        getline(file, name, '|');
        getline(file, phone, '|');
        getline(file, email);

        if(total_customers < 100)
        {
            customer[total_customers] =
                Customer(id, name, phone, email);

            total_customers++;
        }
    }

    file.close();
}

void load_accounts(Accounts accounts[], int &total_accounts)
{
    ifstream file("accounts.txt");

    if(!file)
        return;

    int account_number;
    string account_type;
    double balance;
    int customer_id;

    while(file >> account_number)
    {
        file.ignore();

        getline(file, account_type, '|');

        file >> balance;
        file.ignore();

        file >> customer_id;

        if(total_accounts < 100)
        {
            accounts[total_accounts] =Accounts(account_number,account_type,balance,customer_id);

            total_accounts++;
        }
    }

    file.close();
}

void load_transactions(Transaction transactions[],int &total_transactions,int &transaction_id)
{
    ifstream file("transactions.txt");

    if(!file)
        return;

    int id;
    int account_number;
    string type;
    double amount;

    while(file >> id)
    {
        file.ignore();

        file >> account_number;
        file.ignore();

        getline(file, type, '|');

        file >> amount;

        if(total_transactions < 100)
        {
            transactions[total_transactions] =Transaction(id,account_number,type,amount);

            total_transactions++;
        }

        if(id >= transaction_id)
            transaction_id = id + 1;
    }

    file.close();
}

/* ========================= ADD CUSTOMER ========================= */

void addcustomers(Customer customer[],int &total_customers,int number)
{
    if(total_customers >= 100)
    {
        cout << RED
             << "Customer limit reached."
             << RESET << endl;
        return;
    }

    for(int i = 1; i <= number; i++)
    {
        int id;
        string name;
        string phone;
        string email;

        cout << "\n";
        cout << CYAN
             << "========== CUSTOMER " << i << " =========="
             << RESET << endl;

        while(true)
        {
            id = getInteger("Enter Customer ID: ");

            if(id <= 0)
            {
                cout << RED
                     << "Customer ID must be greater than 0."
                     << RESET << endl;
            }
            else if(customerexist(customer,
                                   total_customers,
                                   id))
            {
                cout << RED
                     << "Customer ID already exists."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }

        while(true)
        {
            cout << "Enter Customer Name: ";
            getline(cin, name);

            bool valid = true;
            bool hasLetter = false;

            if(name.empty())
                valid = false;

            for(int j = 0; j < name.length(); j++)
            {
                if((name[j] >= 'A' && name[j] <= 'Z') ||
                   (name[j] >= 'a' && name[j] <= 'z'))
                {
                    hasLetter = true;
                }
                else if(name[j] != ' ')
                {
                    valid = false;
                    break;
                }
            }

            if(!hasLetter)
                valid = false;

            if(valid)
                break;

            cout << RED
                 << "Invalid name. Use alphabets and spaces only."
                 << RESET << endl;
        }

        while(true)
        {
            cout << "Enter Phone Number: ";
            getline(cin, phone);

            bool valid = true;

            if(phone.length() != 11)
                valid = false;

            for(int j = 0; j < phone.length(); j++)
            {
                if(phone[j] < '0' || phone[j] > '9')
                {
                    valid = false;
                    break;
                }
            }

            if(valid)
                break;

            cout << RED
                 << "Invalid phone number. Enter exactly 11 digits."
                 << RESET << endl;
        }

        while(true)
        {
            cout << "Enter E-mail: ";
            getline(cin, email);

            int atPosition = -1;
            int dotPosition = -1;

            for(int j = 0; j < email.length(); j++)
            {
                if(email[j] == '@')
                {
                    atPosition = j;
                    break;
                }
            }

            if(atPosition != -1)
            {
                for(int j = atPosition + 1;
                    j < email.length();
                    j++)
                {
                    if(email[j] == '.')
                    {
                        dotPosition = j;
                        break;
                    }
                }
            }

            if(atPosition > 0 &&
               dotPosition > atPosition + 1 &&
               dotPosition < email.length() - 1)
            {
                break;
            }

            cout << RED
                 << "Invalid email address."
                 << RESET << endl;
        }

        customer[total_customers] =
            Customer(id, name, phone, email);

        total_customers++;

        save_customers(customer, total_customers);

        cout << GREEN
             << "Customer added successfully!"
             << RESET << endl;
    }
}

/* ========================= ADD ACCOUNT ========================= */

void addaccount(Accounts accounts[],
                int &total_accounts,
                int number,
                Customer customer[],
                int total_customers)
{
    if(total_accounts >= 100)
    {
        cout << RED
             << "Account limit reached."
             << RESET << endl;
        return;
    }

    for(int i = 1; i <= number; i++)
    {
        int customer_id;
        int acc_nmbr;
        double balance;
        string acc_type;

        cout << "\n";
        cout << CYAN
             << "=========== ACCOUNT " << i << " ==========="
             << RESET << endl;

        while(true)
        {
            acc_nmbr = getInteger("Enter Account Number: ");

            if(acc_nmbr <= 0)
            {
                cout << RED
                     << "Account number must be greater than 0."
                     << RESET << endl;
            }
            else if(accountexist(accounts,
                                 total_accounts,
                                 acc_nmbr))
            {
                cout << RED
                     << "Account number already exists."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }

        while(true)
        {
            cout << "Enter Account Type (Savings/Current): ";
            getline(cin, acc_type);

            if(acc_type == "Savings" ||
               acc_type == "savings" ||
               acc_type == "Current" ||
               acc_type == "current")
            {
                break;
            }

            cout << RED
                 << "Invalid account type."
                 << RESET << endl;
        }

        while(true)
        {
            balance = getDouble("Enter Balance: ");

            if(balance < 0)
            {
                cout << RED
                     << "Balance cannot be negative."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }

        while(true)
        {
            customer_id =
                getInteger("Enter Customer ID: ");

            if(customer_id <= 0)
            {
                cout << RED
                     << "Customer ID must be greater than 0."
                     << RESET << endl;
            }
            else if(!customerexist(customer,
                                    total_customers,
                                    customer_id))
            {
                cout << RED
                     << "Customer ID does not exist."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }

        accounts[total_accounts] =
            Accounts(acc_nmbr,
                     acc_type,
                     balance,
                     customer_id);

        total_accounts++;

        save_accounts(accounts, total_accounts);

        cout << GREEN
             << "Account created successfully!"
             << RESET << endl;

        accounts[total_accounts - 1].displayaccount();
    }
}

/* ========================= DEPOSIT ========================= */

void depositamounts(Accounts accounts[],
                    int total_accounts,
                    Transaction transactions[],
                    int &total_transactions,
                    int &transaction_id,
                    int customer_id)
{
    int account_nmbr;
    double amount;
    int index;

    if(total_transactions >= 100)
    {
        cout << RED
             << "Transaction limit reached."
             << RESET << endl;
        return;
    }

    while(true)
    {
        account_nmbr =
            getInteger("Enter Account Number: ");

        if(account_nmbr <= 0)
        {
            cout << RED
                 << "Account number must be greater than 0."
                 << RESET << endl;
        }
        else
        {
            index =
                find_account(accounts,
                             total_accounts,
                             account_nmbr);

            if(index == -1)
            {
                cout << RED
                     << "Account does not exist."
                     << RESET << endl;
            }
            else if(accounts[index].getcustomerid()
                    != customer_id)
            {
                cout << RED
                     << "This account does not belong to you."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }
    }

    while(true)
    {
        amount = getDouble("Enter Deposit Amount: ");

        if(amount <= 0)
        {
            cout << RED
                 << "Deposit amount must be greater than 0."
                 << RESET << endl;
        }
        else
        {
            break;
        }
    }

    accounts[index].deposit(amount);

    transactions[total_transactions] =
        Transaction(transaction_id,
                    account_nmbr,
                    "Deposit",
                    amount);

    total_transactions++;
    transaction_id++;

    save_accounts(accounts, total_accounts);
    save_transactions(transactions, total_transactions);

    cout << GREEN
         << "Amount deposited successfully!"
         << RESET << endl;

    accounts[index].displayaccount();
}

/* ========================= WITHDRAW ========================= */

void withdraw_amount(Accounts accounts[],
                     int total_accounts,
                     Transaction transactions[],
                     int &total_transactions,
                     int &transaction_id,
                     int customer_id)
{
    int account_number;
    double amount;
    int index;

    while(true)
    {
        account_number =
            getInteger("Enter Account Number: ");

        if(account_number <= 0)
        {
            cout << RED
                 << "Account number must be greater than 0."
                 << RESET << endl;
        }
        else
        {
            index =
                find_account(accounts,
                             total_accounts,
                             account_number);

            if(index == -1)
            {
                cout << RED
                     << "Account does not exist."
                     << RESET << endl;
            }
            else if(accounts[index].getcustomerid()
                    != customer_id)
            {
                cout << RED
                     << "This account does not belong to you."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }
    }

    while(true)
    {
        amount = getDouble("Enter Withdrawal Amount: ");

        if(amount <= 0)
        {
            cout << RED
                 << "Withdrawal amount must be greater than 0."
                 << RESET << endl;
        }
        else
        {
            break;
        }
    }

    if(total_transactions >= 100)
    {
        cout << RED
             << "Transaction limit reached."
             << RESET << endl;
        return;
    }

    if(accounts[index].withdraw(amount))
    {
        transactions[total_transactions] =
            Transaction(transaction_id,
                        account_number,
                        "Withdrawal",
                        amount);

        total_transactions++;
        transaction_id++;

        save_accounts(accounts, total_accounts);
        save_transactions(transactions, total_transactions);

        cout << GREEN
             << "Amount withdrawn successfully!"
             << RESET << endl;

        accounts[index].displayaccount();
    }
}

/* ========================= VIEW TRANSACTIONS ========================= */

void view_transaction(Accounts accounts[],
                      int total_accounts,
                      Transaction transactions[],
                      int total_transactions,
                      int customer_id)
{
    int account_number;
    int index;

    while(true)
    {
        account_number =
            getInteger("Enter Account Number: ");

        if(account_number <= 0)
        {
            cout << RED
                 << "Account number must be greater than 0."
                 << RESET << endl;
        }
        else
        {
            index =
                find_account(accounts,
                             total_accounts,
                             account_number);

            if(index == -1)
            {
                cout << RED
                     << "Account does not exist."
                     << RESET << endl;
            }
            else if(accounts[index].getcustomerid()
                    != customer_id)
            {
                cout << RED
                     << "This account does not belong to you."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }
    }

    cout << "\n";
    cout << YELLOW;
    cout << "============================================\n";
    cout << "             TRANSACTION HISTORY\n";
    cout << "============================================\n";
    cout << RESET;

    bool found = false;
    int count = 0;

    for(int i = total_transactions - 1;
        i >= 0 && count < 5;
        i--)
    {
        if(transactions[i].belongsToAccount(account_number))
        {
            transactions[i].displaytransaction();

            found = true;
            count++;
        }
    }

    if(!found)
    {
        cout << RED
             << "No transactions found."
             << RESET << endl;
    }
}

/* ========================= TRANSFER ========================= */

void transfer_amount(Accounts accounts[],
                     int total_accounts,
                     Transaction transactions[],
                     int &total_transactions,
                     int &transaction_id,
                     int customer_id)
{
    int from_account;
    int to_account;
    double amount;

    while(true)
    {
        from_account =
            getInteger("Enter Sender Account Number: ");

        if(from_account <= 0)
        {
            cout << RED
                 << "Account number must be greater than 0."
                 << RESET << endl;
        }
        else
        {
            int from_index =
                find_account(accounts,
                             total_accounts,
                             from_account);

            if(from_index == -1)
            {
                cout << RED
                     << "Sender account does not exist."
                     << RESET << endl;
            }
            else if(accounts[from_index].getcustomerid()
                    != customer_id)
            {
                cout << RED
                     << "You can only transfer from your own account."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }
    }

    while(true)
    {
        to_account =
            getInteger("Enter Receiver Account Number: ");

        if(to_account <= 0)
        {
            cout << RED
                 << "Account number must be greater than 0."
                 << RESET << endl;
        }
        else if(find_account(accounts,
                              total_accounts,
                              to_account) == -1)
        {
            cout << RED
                 << "Receiver account does not exist."
                 << RESET << endl;
        }
        else if(to_account == from_account)
        {
            cout << RED
                 << "Sender and receiver cannot be same."
                 << RESET << endl;
        }
        else
        {
            break;
        }
    }

    while(true)
    {
        amount =
            getDouble("Enter Transfer Amount: ");

        if(amount <= 0)
        {
            cout << RED
                 << "Transfer amount must be greater than 0."
                 << RESET << endl;
        }
        else
        {
            break;
        }
    }

    int from_index =
        find_account(accounts,
                     total_accounts,
                     from_account);

    int to_index =
        find_account(accounts,
                     total_accounts,
                     to_account);

    if(total_transactions + 2 > 100)
    {
        cout << RED
             << "Transaction limit reached."
             << RESET << endl;
        return;
    }

    if(accounts[from_index].withdraw(amount))
    {
        accounts[to_index].deposit(amount);

        transactions[total_transactions] =
            Transaction(transaction_id,
                        from_account,
                        "Transfer Sent",
                        amount);

        total_transactions++;
        transaction_id++;

        transactions[total_transactions] =
            Transaction(transaction_id,
                        to_account,
                        "Transfer Received",
                        amount);

        total_transactions++;
        transaction_id++;

        save_accounts(accounts, total_accounts);
        save_transactions(transactions, total_transactions);

        cout << GREEN
             << "Amount transferred successfully!"
             << RESET << endl;
    }
}

/* ========================= DELETE ACCOUNT ========================= */

void delete_account(Accounts accounts[],
                    int &total_accounts,
                    Transaction transactions[],
                    int &total_transactions)
{
    int account_number;

    while(true)
    {
        account_number =
            getInteger("Enter Account Number to Delete: ");

        if(account_number <= 0)
        {
            cout << RED
                 << "Account number must be greater than 0."
                 << RESET << endl;
        }
        else
        {
            int index =
                find_account(accounts,
                             total_accounts,
                             account_number);

            if(index == -1)
            {
                cout << RED
                     << "Account does not exist."
                     << RESET << endl;
            }
            else
            {
                break;
            }
        }
    }

    int index =
        find_account(accounts,
                     total_accounts,
                     account_number);

    for(int i = 0; i < total_transactions;)
    {
        if(transactions[i].getaccountnumber()
           == account_number)
        {
            for(int j = i;
                j < total_transactions - 1;
                j++)
            {
                transactions[j] = transactions[j + 1];
            }

            total_transactions--;
        }
        else
        {
            i++;
        }
    }

    for(int i = index;
        i < total_accounts - 1;
        i++)
    {
        accounts[i] = accounts[i + 1];
    }

    total_accounts--;

    save_accounts(accounts, total_accounts);
    save_transactions(transactions, total_transactions);

    cout << GREEN
         << "Account deleted successfully!"
         << RESET << endl;
}

/* ========================= DELETE CUSTOMER ========================= */

void delete_customer(Customer customers[],
                     int &total_customers,
                     Accounts accounts[],
                     int &total_accounts,
                     Transaction transactions[],
                     int &total_transactions)
{
    int customer_id;

    while(true)
    {
        customer_id =
            getInteger("Enter Customer ID to Delete: ");

        if(customer_id <= 0)
        {
            cout << RED
                 << "Customer ID must be greater than 0."
                 << RESET << endl;
        }
        else if(!customerexist(customers,
                               total_customers,
                               customer_id))
        {
            cout << RED
                 << "Customer does not exist."
                 << RESET << endl;
        }
        else
        {
            break;
        }
    }

    for(int i = 0; i < total_accounts;)
    {
        if(accounts[i].getcustomerid()
           == customer_id)
        {
            int account_number =
                accounts[i].getaccountnumber();

            for(int j = 0; j < total_transactions;)
            {
                if(transactions[j].getaccountnumber()
                   == account_number)
                {
                    for(int k = j;
                        k < total_transactions - 1;
                        k++)
                    {
                        transactions[k] =
                            transactions[k + 1];
                    }

                    total_transactions--;
                }
                else
                {
                    j++;
                }
            }

            for(int j = i;
                j < total_accounts - 1;
                j++)
            {
                accounts[j] = accounts[j + 1];
            }

            total_accounts--;
        }
        else
        {
            i++;
        }
    }

    int customer_index = -1;

    for(int i = 0;
        i < total_customers;
        i++)
    {
        if(customers[i].getcustomerid()
           == customer_id)
        {
            customer_index = i;
            break;
        }
    }

    if(customer_index != -1)
    {
        for(int i = customer_index;
            i < total_customers - 1;
            i++)
        {
            customers[i] = customers[i + 1];
        }

        total_customers--;
    }

    save_customers(customers, total_customers);
    save_accounts(accounts, total_accounts);
    save_transactions(transactions, total_transactions);

    cout << GREEN
         << "Customer deleted successfully!"
         << RESET << endl;
}

/* ========================= ADMIN DASHBOARD ========================= */

void admin(Customer customers[],
           int &total_customers,
           Accounts accounts[],
           int &total_accounts,
           Transaction transactions[],
           int &total_transactions,
           int &transaction_id)
{
    string choice;

    while(true)
    {
        cout << "\n";
        cout << CYAN;
        cout << "============================================\n";
        cout << "              ADMIN DASHBOARD\n";
        cout << "============================================\n";
        cout << "              [ BANK ADMIN ]\n";
        cout << "============================================\n";
        cout << RESET;

        cout << "  [1] Add Customer\n";
        cout << "  [2] Add Account\n";
        cout << "  [3] Delete Account\n";
        cout << "  [4] Delete Customer\n";
        cout << "  [5] Logout\n";

        cout << "\nChoose option: ";
        getline(cin, choice);

        if(choice == "1")
        {
            int number;

            while(true)
            {
                number =
                    getInteger("How many customers do you want to add: ");

                if(number <= 0)
                {
                    cout << RED
                         << "Number must be greater than 0."
                         << RESET << endl;
                }
                else if(total_customers + number > 100)
                {
                    cout << RED
                         << "You can add only "
                         << 100 - total_customers
                         << " more customers."
                         << RESET << endl;
                }
                else
                {
                    break;
                }
            }

            addcustomers(customers,
                         total_customers,
                         number);
        }

        else if(choice == "2")
        {
            int number;

            while(true)
            {
                number =
                    getInteger("How many accounts do you want to add: ");

                if(number <= 0)
                {
                    cout << RED
                         << "Number must be greater than 0."
                         << RESET << endl;
                }
                else if(total_accounts + number > 100)
                {
                    cout << RED
                         << "You can add only "
                         << 100 - total_accounts
                         << " more accounts."
                         << RESET << endl;
                }
                else
                {
                    break;
                }
            }

            addaccount(accounts,
                       total_accounts,
                       number,
                       customers,
                       total_customers);
        }

        else if(choice == "3")
        {
            delete_account(accounts,
                           total_accounts,
                           transactions,
                           total_transactions);
        }

        else if(choice == "4")
        {
            delete_customer(customers,
                            total_customers,
                            accounts,
                            total_accounts,
                            transactions,
                            total_transactions);
        }

        else if(choice == "5")
        {
            cout << GREEN
                 << "Admin logged out successfully."
                 << RESET << endl;

            break;
        }

        else
        {
            cout << RED
                 << "Invalid choice. Select 1 to 5."
                 << RESET << endl;
        }
    }
}

/* ========================= CUSTOMER LOGIN ========================= */

int customer_login(Customer customer[],
                   int total_customers)
{
    string input;

    while(true)
    {
        cout << "\nEnter Customer ID: ";
        getline(cin, input);

        if(!isInteger(input))
        {
            cout << RED
                 << "Invalid Customer ID. Enter numbers only."
                 << RESET << endl;
            continue;
        }

        int customer_id =
            stringToInt(input);

        if(customer_id <= 0)
        {
            cout << RED
                 << "Customer ID must be greater than 0."
                 << RESET << endl;
        }
        else if(!customerexist(customer,
                                total_customers,
                                customer_id))
        {
            cout << RED
                 << "Customer ID does not exist."
                 << RESET << endl;
        }
        else
        {
            cout << GREEN;
            cout << "\n============================================\n";
            cout << "        CUSTOMER LOGIN SUCCESSFUL\n";
            cout << "============================================\n";
            cout << RESET;

            return customer_id;
        }
    }
}

/* ========================= CUSTOMER DASHBOARD ========================= */

void customer_menu(Accounts accounts[],
                   int total_accounts,
                   Transaction transactions[],
                   int &total_transactions,
                   int &transaction_id,
                   int customer_id)
{
    string choice;

    while(true)
    {
        cout << "\n";
        cout << BLUE;
        cout << "============================================\n";
        cout << "             CUSTOMER DASHBOARD\n";
        cout << "============================================\n";
        cout << "               [ CUSTOMER ]\n";
        cout << "============================================\n";
        cout << RESET;

        cout << "  [1] View My Accounts\n";
        cout << "  [2] Deposit Money\n";
        cout << "  [3] Withdraw Money\n";
        cout << "  [4] Transfer Funds\n";
        cout << "  [5] Transaction History\n";
        cout << "  [6] Logout\n";

        cout << "\nChoose option: ";
        getline(cin, choice);

        if(choice == "1")
        {
            bool found = false;

            cout << "\n";
            cout << CYAN;
            cout << "============================================\n";
            cout << "                MY ACCOUNTS\n";
            cout << "============================================\n";
            cout << RESET;

            for(int i = 0;
                i < total_accounts;
                i++)
            {
                if(accounts[i].getcustomerid()
                   == customer_id)
                {
                    accounts[i].displayaccount();
                    found = true;
                }
            }

            if(!found)
            {
                cout << RED
                     << "You do not have an account."
                     << RESET << endl;
            }
        }

        else if(choice == "2")
        {
            depositamounts(accounts,
                           total_accounts,
                           transactions,
                           total_transactions,
                           transaction_id,
                           customer_id);
        }

        else if(choice == "3")
        {
            withdraw_amount(accounts,
                            total_accounts,
                            transactions,
                            total_transactions,
                            transaction_id,
                            customer_id);
        }

        else if(choice == "4")
        {
            transfer_amount(accounts,
                            total_accounts,
                            transactions,
                            total_transactions,
                            transaction_id,
                            customer_id);
        }

        else if(choice == "5")
        {
            view_transaction(accounts,
                             total_accounts,
                             transactions,
                             total_transactions,
                             customer_id);
        }

        else if(choice == "6")
        {
            cout << GREEN
                 << "Customer logged out successfully."
                 << RESET << endl;

            break;
        }

        else
        {
            cout << RED
                 << "Invalid choice. Select 1 to 6."
                 << RESET << endl;
        }
    }
}

/* ========================= MAIN ========================= */

int main()
{
    Accounts accounts[100];
    Customer customer[100];
    Transaction transactions[100];

    int total_accounts = 0;
    int total_customers = 0;
    int total_transactions = 0;
    int transaction_id = 1;

    load_customers(customer,
                   total_customers);

    load_accounts(accounts,
                  total_accounts);

    load_transactions(transactions,
                      total_transactions,
                      transaction_id);

    string choice;

    while(true)
    {
        cout << "\n";
        cout << CYAN;
        cout << "============================================\n";
        cout << "       +----------------------------+\n";
        cout << "       |     BANK MANAGEMENT        |\n";
        cout << "       |        SYSTEM              |\n";
        cout << "       +----------------------------+\n";
        cout << "============================================\n";
        cout << RESET;

        cout << "  [1] Admin Login\n";
        cout << "  [2] Customer Login\n";
        cout << "  [3] Exit\n";

        cout << "\nChoose number: ";
        getline(cin, choice);

        if(choice == "1")
        {
            cout << GREEN
                 << "\nAdmin dashboard opened successfully.\n"
                 << RESET;

            admin(customer,
                  total_customers,
                  accounts,
                  total_accounts,
                  transactions,
                  total_transactions,
                  transaction_id);
        }

        else if(choice == "2")
        {
            int customer_id =
                customer_login(customer,
                               total_customers);

            customer_menu(accounts,
                          total_accounts,
                          transactions,
                          total_transactions,
                          transaction_id,
                          customer_id);
        }

        else if(choice == "3")
        {
            cout << GREEN
                 << "\nThank you for using Bank Management System."
                 << RESET << endl;

            break;
        }

        else
        {
            cout << RED
                 << "Invalid choice. Select 1 to 3."
                 << RESET << endl;
        }
    }

    return 0;
}
