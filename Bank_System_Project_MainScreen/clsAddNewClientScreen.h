#pragma once
#include "clsBankClient.h";
#include "clsScreen.h";


class clsAddNewClientScreen : protected clsScreen
{
	static void _ReadClientRecordInfo(clsBankClient& Client)
	{
		cout << "\nEnter First Name ? ";
		Client.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Last Name ? ";
		Client.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email ? ";
		Client.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone ? ";
		Client.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter Pin Code ? ";
		Client.PinCode = clsInputValidate<string>::ReadString();

		cout << "\nEnter Account Balance ? ";
		Client.AccountBalance = clsInputValidate<float>::ReadNumber();
	}
	static void PrintClientRecord(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "___________________________________\n";
		cout << "First Name		: " << Client.FirstName << endl;;
		cout << "Last Name		: " << Client.LastName << endl;
		cout << "Full Name		: " << Client.FullName() << endl;
		cout << "Email			: " << Client.Email << endl;
		cout << "Phone			: " << Client.Phone << endl;
		cout << "Account Number : " << Client.AccountNumber() << endl;
		cout << "Pin Code       : " << Client.PinCode << endl;
		cout << "Account Balance: " << Client.AccountBalance << endl;
		cout << "___________________________________\n";
	}
public:
	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient))
		{
			return;
		}

		_DrawScreenHeader("Add New Client Screen");
		string AccountNumber = "";
		cout << "Enter AccountNumber ? ";
		AccountNumber = clsInputValidate<string>::ReadString();
		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "Account Number already exist, enter another one ? ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}
		clsBankClient NewClient = clsBankClient::GetAddNewClient(AccountNumber);
		_ReadClientRecordInfo(NewClient);
		
		clsBankClient::enSaveResults SaveResults;
		SaveResults = NewClient.Save();
		
		switch (SaveResults)
		{
		case clsBankClient::svFaildEmptyObject:
		{
			cout << "Error, Account Number was not save because it's empty\n";
			break;
		}
		case clsBankClient::svSecceded:
		{
			cout << "\nAccount added successfully\n";
			PrintClientRecord(NewClient);
			break;
		}
		case clsBankClient::svFaildAccountNumberExist:
		{
			cout << "Error, Account Number was not save because it's exist\n";
			break;
		}
		}

	}
};

