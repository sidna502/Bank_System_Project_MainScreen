#pragma once
#include "clsBankClient.h";
#include "clsScreen.h";


class clsWithdrawScreen : protected clsScreen
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
	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("Withdraw Screen");
		cout << "\nEnter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();
		
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Does not exist, enter another one ? ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientRecord(Client);

		cout << "\nEnter withdraw amount ? ";
		double Amount = clsInputValidate::ReadDblNumber("Invalid Number enter number again");
		char Answer = 'y';
		
		if (Client.Withdraw(Amount))
		{
			cout << "\nAre you sure do you want to perform this transaction y/n ? ";
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				cout << "\nAmount Withdrawed successfully, New balance is: " << Client.AccountBalance << endl;
			}

		}
		else
		{
			cout << "\nCannot withdraw, insuficient Amount\n";
			cout << "Amount to withdraw is: " << Amount << endl;
			cout << "Your balance is: " << Client.AccountBalance << endl;
		}
		
		
		

	}
};

