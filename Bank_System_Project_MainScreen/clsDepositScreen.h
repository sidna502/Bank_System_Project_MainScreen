#pragma once
#include "clsBankClient.h";
#include "clsScreen.h";

class clsDepositScreen : protected clsScreen
{
	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << "\nClient Record:\n";
		cout << "_________________________________\n";
		cout << "First Name:  " << Client.FirstName << endl;
		cout << "Last Name :  " << Client.LastName << endl;
		cout << "Full Name :  " << Client.FullName() << endl;
		cout << "Email     :  " << Client.Email << endl;
		cout << "Phone     :  " << Client.Phone << endl;
		cout << "Acc. Num  :  " << Client.AccountNumber() << endl;
		cout << "Pin code  :  " << Client.PinCode << endl;
		cout << "Acc. Bala :  " << Client.AccountBalance << endl;
		cout << "_________________________________\n";
	}

public:
	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");
		double Amount = 0;
		cout << "Enter Account Number ? ";
		string AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account number not exist, enter another one ? ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientRecord(Client);

		cout << "\nEnter deposit amount ? ";
		Amount = clsInputValidate<double>::ReadNumber();
		
		char Answer = 'y';
		cout << "Are you sure do you want to do this transaction y/n ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			Client.Deposit(Amount);
			cout << "\nAmout deposited successfully,new balance = " << Client.AccountBalance << endl;
		}
		else
			cout << "Transaction cancelled\n";
	    
	}
};

