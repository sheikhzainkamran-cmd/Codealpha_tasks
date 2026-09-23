#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Customer
{
	private :
	int customer_id;
	string name;
	string phone;
	string email;
	public :
		Customer(int id,string n,string p,string e)
		{
			customer_id=id;
			name=n;
			phone=p;
			email=e;
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
			cout<<"\n========Customer Information========\n";
			cout<<"Customer ID : "<<customer_id<<endl;
			cout<<"Name :"<<name<<endl;
			cout<<"Phone :"<<phone<<endl;
			cout<<"E-mail :"<<email<<endl;
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
class Accounts 
{
	private :
		int acc_nmbr;
		string acc_type;
		double balance ;
		int customer_id;	
		public :
			
			Accounts ()
			{
				acc_nmbr=0;
				acc_type="";
				balance =0;
				customer_id=0;
			}
			Accounts (int acc_no,string type,double bal,int id)
			{
				acc_nmbr=acc_no;
				acc_type=type;
				balance=bal;
				customer_id=id;
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
		 	balance=balance + amount;
		 }
		 bool withdraw(double amount)
		 {
		 	if(balance>=amount)
		 	{
		 		balance=balance-amount;
		 		return true;
			 }
			 else 
			 {
			 	cout<<"Insufficient balance ";
			 	return false;
			 }
		 }
		 
			void displayaccount()
		{
			cout<<"\n========Account Information========\n";
			cout<<"Account number : "<<acc_nmbr<<endl;
			cout<<"Account Type :"<<acc_type<<endl;
			cout<<"Balance :"<<balance<<endl;
			cout<<"customer ID :"<<customer_id<<endl;
		 }
};
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
			cout << "\n========Transaction Information========\n";
			cout << "Transaction ID : " << transaction_id << endl;
			cout << "Account Number : " << account_number << endl;
			cout << "Transaction Type : " << transaction_type << endl;
			cout << "Amount : " << amount << endl;
		}
		bool belongsToAccount(int acc_no)
{
	return account_number == acc_no;
}
};
bool customerexist (Customer customer[],int total_customers,int id)
{
	for(int i=0;i<total_customers;i++)
	{
		if(customer[i].getcustomerid()==id)
		{
			return true;
		}
		}
		return false;
}
bool accountexist (Accounts account[],int total_accounts,int nmbr)
{
	for(int i=0;i<total_accounts;i++)
	{
		if(account[i].getaccountnumber()==nmbr)
		{
			return true;
		}
		}
		return false;
}
int find_account(Accounts account[],int total_accounts,int nmbr)
{
	for(int i=0;i<total_accounts;i++)
	{
		if(account[i].getaccountnumber()== nmbr)
		{
			return i;
		}
	}
	return -1;
}
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
void load_customers(Customer customer[], int &total_customers)
{
    ifstream file("customers.txt");

    if(!file)
    {
        return;
    }

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

        customer[total_customers] =
            Customer(id, name, phone, email);

        total_customers++;
    }

    file.close();
}
void load_accounts(Accounts accounts[], int &total_accounts)
{
    ifstream file("accounts.txt");

    if(!file)
    {
        return;
    }

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

        accounts[total_accounts] =
            Accounts(account_number, account_type,
                     balance, customer_id);

        total_accounts++;
    }

    file.close();
}
void load_transactions(Transaction transactions[],
                       int &total_transactions,
                       int &transaction_id)
{
    ifstream file("transactions.txt");

    if(!file)
    {
        return;
    }

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

        transactions[total_transactions] =
            Transaction(id, account_number, type, amount);

        total_transactions++;

        if(id >= transaction_id)
        {
            transaction_id = id + 1;
        }
    }

    file.close();
}
void addcustomers (Customer customer[],int &total_customers,int number)
{
	if(total_customers >= 100)
{
    cout << "Customer limit reached. Cannot add more customers.\n";
    return;
}
	for(int i=1;i<=number;i++)
	{
		int id;
		string name,phone,email;
		cout<<"Enter the details for customer :"<<i<<endl;
		bool input = true;
		while (input)
		{
			cout<<"Enter customer ID : ";
		cin>>id;
			if(cin.fail())
			{
			cout<<"Enter a valid id :\n";
			cin.clear();
			cin.ignore(1000,'\n'); 
				}
				else if(id<=0)
				{
					cout<<"Enter a valid id \n";
				 }
				 else input = false;
		}
		if(customerexist(customer,total_customers,id))
		{
			cout<<"Id already exist .Enter another ID\n";
			i--;
			continue ;
		}
		else
		{
			cout<<"ID available\n";
		}
		cin.ignore();

while(true)
{
    cout << "Enter the customer name : ";
    getline(cin, name);

    bool valid = true;
    bool hasLetter = false;

    if(name.empty())
    {
        valid = false;
    }

    for(int i = 0; i < name.length(); i++)
    {
        if((name[i] >= 'A' && name[i] <= 'Z') ||
           (name[i] >= 'a' && name[i] <= 'z'))
        {
            hasLetter = true;
        }
        else if(name[i] != ' ')
        {
            valid = false;
            break;
        }
    }

    if(!hasLetter)
    {
        valid = false;
    }

    if(valid)
    {
        break;
    }

    cout << "Invalid name. Use alphabets and spaces only.\n";
}
		while(true)
{
    cout << "Enter the phone number : ";
    getline(cin, phone);

    bool valid = true;

    if(phone.length() != 11)
    {
        valid = false;
    }

    for(int i = 0; i < phone.length(); i++)
    {
        if(phone[i] < '0' || phone[i] > '9')
        {
            valid = false;
            break;
        }
    }

    if(valid)
    {
        break;
    }

    cout << "Invalid phone number. Enter exactly 11 digits.\n";
}
	while(true)
{
    cout << "Enter E-mail : ";
    getline(cin, email);

    int atPosition = -1;
    int dotPosition = -1;

    for(int i = 0; i < email.length(); i++)
    {
        if(email[i] == '@')
        {
            atPosition = i;
            break;
        }
    }

    if(atPosition != -1)
    {
        for(int i = atPosition + 1; i < email.length(); i++)
        {
            if(email[i] == '.')
            {
                dotPosition = i;
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

    cout << "Invalid email address. Please try again.\n";
}
customer[total_customers] =
    Customer(id, name, phone, email);

total_customers++;
save_customers(customer, total_customers);
cout << "Customer added successfully.\n";
	}
}
void addaccount(Accounts accounts[], int &total_accounts, int number, Customer customer[], int total_customers)
{
	if(total_accounts >= 100)
{
    cout << "Account limit reached. Cannot add more accounts.\n";
    return;
}
	for(int i=1;i<=number;i++)
	{
		int customer_id,acc_nmbr;
		double balance;
		string acc_type;
		cout<<"Enter the details for Accounts :"<<endl;
		while(true)
{
    cout<<"Enter Account number : ";
    cin>>acc_nmbr;

    if(cin.fail())
    {
        cout<<"Invalid account number. Enter numbers only.\n";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else if(acc_nmbr <= 0)
    {
        cout<<"Account number must be greater than 0.\n";
    }
    else if(accountexist(accounts,total_accounts,acc_nmbr))
    {
        cout<<"Account number already exists. Enter another account number.\n";
    }
    else
    {
        cout<<"Account number available.\n";
        break;
    }
}
		cin.ignore();

while(true)
{
    cout<<"Enter the account Type (Savings/Current): ";
    getline(cin,acc_type);

    if(acc_type == "Savings" || acc_type == "savings" ||
       acc_type == "Current" || acc_type == "current")
    {
        break;
    }
    else
    {
        cout<<"Invalid account type. Enter Savings or Current.\n";
    }
}
	while(true)
{
    cout<<"Enter the Balance : ";
    cin>>balance;

    if(cin.fail())
    {
        cout<<"Invalid balance. Enter a numeric value.\n";
        cin.clear();
        cin.ignore(1000,'\n');
    }
    else if(balance < 0)
    {
        cout<<"Balance cannot be negative.\n";
    }
    else
    {
        break;
    }
}
	
	while(true)
{
    cout << "Enter Customer ID : ";
    cin >> customer_id;

    if(cin.fail())
    {
        cout << "Invalid Customer ID. Enter numbers only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else if(customer_id <= 0)
    {
        cout << "Customer ID must be greater than 0.\n";
    }
    else if(!customerexist(customer, total_customers, customer_id))
    {
        cout << "Customer ID does not exist. Enter an existing Customer ID.\n";
    }
    else
    {
        break;
    }
    cin.ignore(); 
}
		Accounts newAccount(acc_nmbr,acc_type,balance,customer_id);
		accounts[total_accounts] = newAccount;
		total_accounts++;
		save_accounts(accounts, total_accounts);
		newAccount.displayaccount();
}
}
void depositamounts(Accounts accounts[], int total_accounts,Transaction transactions[], int &total_transactions,int &transaction_id,int customer_id)
{
    int account_nmbr;
    double amount;

    int index;
if(total_transactions >= 100)
{
    cout << "Transaction limit reached. Cannot perform deposit.\n";
    return;
}
   while(true)
{
    cout << "Enter the account number: ";
    cin >> account_nmbr;

    if(cin.fail())
    {
        cout << "Invalid account number. Enter numbers only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else if(account_nmbr <= 0)
    {
        cout << "Account number must be greater than 0.\n";
    }
    else
    {
        index = find_account(accounts, total_accounts, account_nmbr);

        if(index == -1)
        {
            cout << "Account does not exist. Enter a valid account number.\n";
        }
        else if(accounts[index].getcustomerid() != customer_id)
        {
            cout << "This account does not belong to you.\n";
        }
        else
        {
            break;
        }
    }
}
    while(true)
    {
        cout << "Enter the deposit amount: ";
        cin >> amount;

        if(cin.fail())
        {
            cout << "Invalid amount. Enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(amount <= 0)
        {
            cout << "Deposit amount must be greater than 0.\n";
        }
        else
        {
            break;
        }
    }

    accounts[index].deposit(amount);

    transactions[total_transactions] =
        Transaction(transaction_id, account_nmbr, "Deposit", amount);

    total_transactions++;
    transaction_id++;
    save_accounts(accounts, total_accounts);
save_transactions(transactions, total_transactions);

    cout << "Amount deposited successfully.\n";
    accounts[index].displayaccount();
}

void withdraw_amount(Accounts accounts[], int total_accounts,Transaction transactions[],int &total_transactions,int &transaction_id,int customer_id)
{
    int account_number;
    double amount;
    int index;

    while(true)
    {
        cout << "\nEnter the account number for withdrawal: ";
        cin >> account_number;

        if(cin.fail())
        {
            cout << "Invalid account number. Enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(account_number <= 0)
        {
            cout << "Account number must be greater than 0.\n";
        }
        else
        {
            index = find_account(accounts, total_accounts, account_number);

            if(index == -1)
            {
                cout << "Account does not exist. Enter a valid account number.\n";
            }
            else if(accounts[index].getcustomerid() != customer_id)
            {
                cout << "This account does not belong to you.\n";
            }
            else
            {
                break;
            }
        }
    }

    while(true)
    {
        cout << "Enter withdrawal amount: ";
        cin >> amount;

        if(cin.fail())
        {
            cout << "Invalid amount. Enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(amount <= 0)
        {
            cout << "Withdrawal amount must be greater than 0.\n";
        }
        else
        {
            break;
        }
    }

    if(total_transactions >= 100)
    {
        cout << "Transaction limit reached. Cannot perform withdrawal.\n";
        return;
    }

    if(accounts[index].withdraw(amount))
    {
        transactions[total_transactions] =
            Transaction(transaction_id, account_number,
                        "Withdrawal", amount);

        total_transactions++;
        transaction_id++;

        save_accounts(accounts, total_accounts);
        save_transactions(transactions, total_transactions);

        cout << "Amount withdrawn successfully.\n";
        accounts[index].displayaccount();
    }
}

void view_transaction(Accounts accounts[], int total_accounts,
                      Transaction transactions[], int total_transactions,int customer_id)
{
    int account_number;
    int index;

    while(true)
    {
        cout << "\nEnter account number to view transactions: ";
        cin >> account_number;

        if(cin.fail())
        {
            cout << "Invalid account number. Enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(account_number <= 0)
        {
            cout << "Account number must be greater than 0.\n";
        }
        else
        {
            index = find_account(accounts, total_accounts, account_number);

            if(index == -1)
            {
                cout << "Account does not exist. Enter a valid account number.\n";
            }
           else if(accounts[index].getcustomerid() != customer_id)
		   {
		   cout << "This account does not belong to you.\n";
		   }
		   else
		   {
		   break;
		   }
        }
    }

    cout << "\n========Transaction History========\n";

    bool found = false;

   int count = 0;

for(int i = total_transactions - 1; i >= 0 && count < 5; i--)
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
        cout << "No transactions found for this account.\n";
    }
}
	void transfer_amount(Accounts accounts[],int total_accounts,Transaction transactions[],int &total_transactions,int &transaction_id,int customer_id)
{
    int from_account;
    int to_account;
    double amount;

    while(true)
{
    cout << "Enter sender account number: ";
    cin >> from_account;

    if(cin.fail())
    {
        cout << "Invalid account number. Enter numbers only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else if(from_account <= 0)
    {
        cout << "Account number must be greater than 0.\n";
    }
    else
{
    int from_index = find_account(accounts, total_accounts, from_account);

    if(from_index == -1)
    {
        cout << "Sender account does not exist.\n";
    }
    else if(accounts[from_index].getcustomerid() != customer_id)
    {
        cout << "You can only transfer money from your own account.\n";
    }
    else
    {
        break;
    }
}
}

    while(true)
{
    cout << "Enter receiver account number: ";
    cin >> to_account;

    if(cin.fail())
    {
        cout << "Invalid account number. Enter numbers only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else if(to_account <= 0)
    {
        cout << "Account number must be greater than 0.\n";
    }
    else if(find_account(accounts, total_accounts, to_account) == -1)
    {
        cout << "Receiver account does not exist.\n";
    }
    else
    {
        break;
    }
}
    while(true)
{
    cout << "Enter amount to transfer: ";
    cin >> amount;

    if(cin.fail())
    {
        cout << "Invalid amount. Enter numbers only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else if(amount <= 0)
    {
        cout << "Transfer amount must be greater than 0.\n";
    }
    else
    {
        break;
    }
}

    int from_index = find_account(accounts, total_accounts, from_account);
    int to_index = find_account(accounts, total_accounts, to_account);

    if(from_index == -1)
    {
        cout << "Sender account does not exist.\n";
        return;
    }

    if(to_index == -1)
    {
        cout << "Receiver account does not exist.\n";
        return;
    }

    if(from_account == to_account)
    {
        cout << "Sender and receiver accounts cannot be same.\n";
        return;
    }
    if(total_transactions + 2 > 100)
{
    cout << "Transaction limit reached. Cannot perform transfer.\n";
    return;
}

    if(accounts[from_index].withdraw(amount))
    {
        accounts[to_index].deposit(amount);

        transactions[total_transactions] =
            Transaction(transaction_id, from_account, "Transfer Sent", amount);
        total_transactions++;
        transaction_id++;

        transactions[total_transactions] =
            Transaction(transaction_id, to_account, "Transfer Received", amount);
        total_transactions++;
        transaction_id++;
        save_accounts(accounts, total_accounts);
save_transactions(transactions, total_transactions);

        cout << "Amount transferred successfully.\n";
    }
}
void delete_account(Accounts accounts[], int &total_accounts,Transaction transactions[], int &total_transactions)
{
    int account_number;

    while(true)
    {
        cout << "\nEnter account number to delete: ";
        cin >> account_number;

        if(cin.fail())
        {
            cout << "Invalid account number. Enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(account_number <= 0)
        {
            cout << "Account number must be greater than 0.\n";
        }
        else
        {
            int index = find_account(accounts, total_accounts, account_number);

            if(index == -1)
            {
                cout << "Account does not exist.\n";
            }
            else
            {
                break;
            }
        }
    }

    int index = find_account(accounts, total_accounts, account_number);

    // Account delete karne se pehle uski transactions remove karenge
    for(int i = 0; i < total_transactions; )
    {
        if(transactions[i].getaccountnumber() == account_number)
        {
            for(int j = i; j < total_transactions - 1; j++)
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

    // Accounts array mein left shift
    for(int i = index; i < total_accounts - 1; i++)
    {
        accounts[i] = accounts[i + 1];
    }

    total_accounts--;

    save_accounts(accounts, total_accounts);
    save_transactions(transactions, total_transactions);

    cout << "Account deleted successfully.\n";
    cin.ignore(1000,'\n'); 
}
void delete_customer(Customer customers[], int &total_customers,
                     Accounts accounts[], int &total_accounts,
                     Transaction transactions[], int &total_transactions)
{
    int customer_id;

    while(true)
    {
        cout << "\nEnter Customer ID to delete: ";
        cin >> customer_id;

        if(cin.fail())
        {
            cout << "Invalid Customer ID. Enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(customer_id <= 0)
        {
            cout << "Customer ID must be greater than 0.\n";
        }
        else
        {
            if(!customerexist(customers, total_customers, customer_id))
            {
                cout << "Customer does not exist.\n";
            }
            else
            {
                break;
            }
        }
    }

    // 1. Customer ke accounts aur unki transactions delete karna
    for(int i = 0; i < total_accounts; )
    {
        if(accounts[i].getcustomerid() == customer_id)
        {
            int account_number = accounts[i].getaccountnumber();

            // Is account ki transactions delete karo
            for(int j = 0; j < total_transactions; )
            {
                if(transactions[j].getaccountnumber() == account_number)
                {
                    for(int k = j; k < total_transactions - 1; k++)
                    {
                        transactions[k] = transactions[k + 1];
                    }

                    total_transactions--;
                }
                else
                {
                    j++;
                }
            }

            // Account ko delete karne ke liye left shift
            for(int j = i; j < total_accounts - 1; j++)
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

    // 2. Customer ko delete karna
    int customer_index = -1;

    for(int i = 0; i < total_customers; i++)
    {
        if(customers[i].getcustomerid() == customer_id)
        {
            customer_index = i;
            break;
        }
    }

    if(customer_index != -1)
    {
        for(int i = customer_index; i < total_customers - 1; i++)
        {
            customers[i] = customers[i + 1];
        }

        total_customers--;
    }

    // 3. Files update karo
    save_customers(customers, total_customers);
    save_accounts(accounts, total_accounts);
    save_transactions(transactions, total_transactions);

    cout << "Customer deleted successfully.\n";
}
void admin(Customer customers[],int &total_customers,Accounts accounts[],int &total_accounts,Transaction transactions[],int &total_transactions,int &transaction_id)
{
	string nmbr ;
	while (true)
	{
		cout<<"1. Add customers\n";
		cout<<"2. Add account\n";
		cout<<"3. Delete Account\n";
		cout<<"4. Delete Customer\n";
		cout<<"5. Logout\n";
		cout<<"Chose nmbr :";
		getline(cin,nmbr);
		if(nmbr == "1")
		{
		int number;

while(true)
{
    cout << "How many customers do you want to add: ";
    cin >> number;

    if(cin.fail())
    {
        cout << "Invalid input. Enter numbers only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else if(number <= 0)
    {
        cout << "Number of customers must be greater than 0.\n";
    }
    else if(total_customers + number > 100)
    {
        cout << "You can add only "<< 100 - total_customers<< " more customers.\n";
    }
    else
    {
        break;
    }
}

addcustomers(customers,total_customers,number);
		}
		else if (nmbr == "2")
		{
			int number;

while(true)
{
    cout << "How many accounts do you want to add: ";
    cin >> number;

    if(cin.fail())
    {
        cout << "Invalid input. Enter numbers only.\n";
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else if(number <= 0)
    {
        cout << "Number of accounts must be greater than 0.\n";
    }
    else if(total_accounts + number > 100)
    {
        cout << "You can add only "<< 100 - total_accounts<< " more accounts.\n";
         }
         else
          {
           break;
          }
        }
       addaccount(accounts,total_accounts,number,customers,total_customers);
		}
		else if(nmbr == "3")
        {
             delete_account(accounts, total_accounts,transactions, total_transactions);
        }
        else if(nmbr == "4")
        {
              delete_customer(customers, total_customers,accounts, total_accounts,transactions, total_transactions);
        }
        else if(nmbr == "5")
        {
            break;
        }
		else 
		cout <<"Invalid choice\n ";
	}
	}	
	void view_account(Accounts accounts[], int total_accounts)
{
    int account_number;

    while(true)
    {
        cout << "\nEnter account number: ";
        cin >> account_number;

        if(cin.fail())
        {
            cout << "Invalid account number. Enter numbers only.\n";
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else if(account_number <= 0)
        {
            cout << "Account number must be greater than 0.\n";
        }
        else
        {
            int index = find_account(accounts, total_accounts, account_number);

            if(index == -1)
            {
                cout << "Account does not exist. Enter a valid account number.\n";
            }
            else
            {
                accounts[index].displayaccount();
                break;
            }
        }
    }
}
int customer_login(Customer customer[], int total_customers)
{
    string input;

    while(true)
    {
        cout << "\nEnter Customer ID: ";
        getline(cin, input);

        bool valid = true;

        if(input.empty())
        {
            valid = false;
        }

        for(int i = 0; i < input.length(); i++)
        {
            if(input[i] < '0' || input[i] > '9')
            {
                valid = false;
                break;
            }
        }

        if(!valid)
        {
            cout << "Invalid Customer ID. Enter numbers only.\n";
            continue;
        }

        int customer_id = 0;

        for(int i = 0; i < input.length(); i++)
        {
            customer_id = customer_id * 10 + (input[i] - '0');
        }

        if(customer_id <= 0)
        {
            cout << "Customer ID must be greater than 0.\n";
        }
        else if(!customerexist(customer, total_customers, customer_id))
        {
            cout << "Customer ID does not exist.\n";
        }
        else
        {
            cout << "Customer login successful.\n";
            return customer_id;
        }
    }
}
	void customer_menu(Accounts accounts[],int total_accounts,Transaction transactions[],int &total_transactions,int &transaction_id, int customer_id)
{
    string choice;

    while(true)
    {
        cout << "\n===== CUSTOMER MENU =====\n";
        cout << "1. View Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Transfer Funds\n";
        cout << "5. View Transactions\n";
        cout << "6. Logout\n";

        cout << "Choose number: ";
        getline(cin , choice);

        if(choice == "1")
{
    bool found = false;

    cout << "\n===== YOUR ACCOUNTS =====\n";

    for(int i = 0; i < total_accounts; i++)
    {
        if(accounts[i].getcustomerid() == customer_id)
        {
            accounts[i].displayaccount();
            found = true;
        }
    }

    if(!found)
    {
        cout << "You do not have an account.\n";
    }
}
        else if(choice == "2")
        {
            depositamounts(accounts,total_accounts,
                           transactions,total_transactions,
                           transaction_id,customer_id);
        }
        else if(choice == "3")
        {
            withdraw_amount(accounts,total_accounts,
                            transactions,total_transactions,
                            transaction_id,customer_id);
        }
        else if(choice == "4")
        {
            transfer_amount(accounts,total_accounts,
                            transactions,total_transactions,
                            transaction_id,customer_id);
        }
        else if(choice == "5")
        {
            view_transaction(accounts,total_accounts,
                             transactions,total_transactions,customer_id);
        }
        else if(choice == "6")
        {
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
        }
    }
}

int main()
{
	
	Accounts accounts[100];
	Customer customer[100];
	Transaction transactions[100];
	int total_accounts =0;
	int total_customers = 0;
	int total_transactions = 0;
	int transaction_id = 1;
	load_customers(customer, total_customers);
load_accounts(accounts, total_accounts);
load_transactions(transactions, total_transactions, transaction_id);
	string nmbr;
	while(true)
	{
		cout<<"1. admin\n";
		cout<<"2. Customer\n";
		cout<<"3.Exit\n";
			cout<<"Choose number :";
		getline(cin,nmbr);
		if(nmbr == "1" )
		{
			admin(customer,total_customers,accounts,total_accounts,transactions,total_transactions,transaction_id);
		}
		else if(nmbr == "2")
        {
            int customer_id = customer_login(customer, total_customers);

               customer_menu(accounts, total_accounts,
                  transactions, total_transactions,
                  transaction_id, customer_id);
        }
		else if (nmbr == "3")
		{
		break ;
		}
		else 
		cout<<"Invalid number\n ";
	}
		
	
	

	return 0;
}

