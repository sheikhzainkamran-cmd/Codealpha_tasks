#include<iostream>
#include<string>
#include<fstream>
using namespace std;
bool exist_user(string username)
{
	ifstream file("user.txt");
	string exist_u,exist_p;
	while(file>>exist_u>>exist_p)
	{
		if(username == exist_u)
		{
			file.close();
			return true ;
		}
	}
	file.close() ;
	return false;
}
bool validate_password(string password)
{
	bool upper_letter=false;
	bool lower_letter=false;
	bool digit = false;
	if (password.length() < 8 )
	{
		cout<<"\033[31mPassword must contain at least 8 character \033[0m \n";
		return false;
	}
	for(int i=0;i<password.length() ;i++)
	{
		if (password[i]>='A'&&password[i] <='Z')
		{
			upper_letter=true;
		}
		else if (password[i]>='a' && password[i]<='z')
		{
			lower_letter=true;
		}
		else if (password[i]>='0' && password[i] <= '9')
		{
			digit = true;
		}
	}
	if (!upper_letter)
	{
		cout<<"\033[31mPassword must contain an uppercase letter \033[0m \n";
		return false ;
	}
	else if (!lower_letter)
	{
		cout<<"\033[31mPassword must contain a Lowercase letter \033[0m \n";
		return false ;
	}
	else if (!digit)
	{
		cout<<"\033[31mPassword must contain a digit \033[0m \n";
		return false ;
	}
	return true ;
	
}
void registration()
{
	string username,password;
	cout<<"\033[34m= = = = = == = = = = = = = = = = = \033[0m\n";
	cout<<"\033[34m=\033[0m   Registeration                \033[34m=\033[0m\n";
	cout<<"\033[34m= = = = = == = = = = = = = = = = =\033[0m\n";
	cout<<"Enter the Username : ";
	cin>>username;
	if(exist_user(username))
	{
		cout<<"\033[31mUsername already exist \033[0m \n";
		return;
	}
	cout<<"Enter the password : ";
	cin>>password;
	if(!validate_password(password))
	{
		return ;
	}
	ofstream file("user.txt", ios::app);

file << username << " " << password << endl;

file.close();
cout<<"\033[32mRegistration successfully\033[0m\n";
cout << "===============================\n";
	
}
void login()
{
	cout<<"\033[34m= = = = = == = = = = = = = = = = =\033[0m\n";
	cout<<"\033[34m=\033[0m          Login                 \033[34m=\033[0m\n";
	cout<<"\033[34m= = = = = == = = = = = = = = = = =\033[0m\n";
	string inpt_user,inpt_pass;
	cout<<"Enter the username :";
	cin>>inpt_user;
	cout<<"Enter the password :";
	cin>>inpt_pass;
	ifstream file("user.txt");
	string username,password;
	bool found = false;
	while (file>>username>>password)
	{
	if(inpt_user == username&&inpt_pass == password)
	{
		found = true;
		break ;
	}
}
file.close();
if (found)
{
    cout<<"\033[32mLogin successfully\033[0m\n";
	cout << "===============================\n";
}
else
{
	cout<<"\033[31mNo user  found \033[0m \n";
	cout << "===============================\n";
}

}
int main()
{
	cout<<"\033[34m= = = = = == = = = = = = = = = = = = = = = = = = = = = = = = =\033[0m\n";
	cout<<"\033[34m=\033[0m    Welcome To our Login And Registration System            \033[34m=\033[0m\n";
	cout<<"\033[34m= = = = = == = = = = = = = = = = = = = = = = = = = = = = = = = \033[0m\n";
	int nmbr;
	while(true)
	{
		
		if (nmbr == 1)
		{
			registration();
		}
		else if (nmbr == 2)
		{
			login();
		}
		else if (nmbr == 3)
		{
			
			break ;
		}
		cout << "\n========== MAIN MENU ==========\n";
		cout <<"1.Register\n";
		cout<<"2.Login\n";
		cout<<"3.Exit\n";
		cout << "===============================\n";
		cout<<"Enter a your choice : ";
		cin>>nmbr;
		if (cin.fail() )
		{
			cout<<"\033[31mEnter a valid number\033[0m \n";
			cin.clear();
			cin.ignore(1000,'\n');
		}
		else if (nmbr<=0 || nmbr>4)
		{
			cout<<"\033[31mEnter a valid number\033[0m \n";
		}
	}
}
