#pragma once
#include "clsScreen.h";
#include "clsBankClient.h";


class clsFindClientScreen : protected clsScreen
{
	static void _PrintClientDataRecord(clsBankClient Client)
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
	static void ShowFindClientScreen()
	{
		_DrawScreenHeader("Find Client Screen");

		cout << "Enter Account Number ? ";
		string AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount not exist, enter another one ? ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		if (!Client.IsEmpty())
		{
			cout << "\nClient found\n";
			_PrintClientDataRecord(Client);
		}
		else
			cout << "\nClient not found\n";
		

	}
};

