#pragma once
#include "clsBankClient.h";
#include "clsScreen.h";

class clsDeleteClientScreen : protected clsScreen
{
	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "___________________________________";
		cout << "\nFirst Name.......: " << Client.FirstName;
		cout << "\nLast Name........: " << Client.LastName;
		cout << "\nFull Name........: " << Client.FullName();
		cout << "\nEmail............: " << Client.Email;
		cout << "\nPhone............: " << Client.Phone;
		cout << "\nAccount Number...: " << Client.AccountNumber();
		cout << "\nPin Code.........: " << Client.PinCode;
		cout << "\nAccount Balance..: " << Client.AccountBalance;
		cout << "\n___________________________________\n";
	}
public:
	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient))
		{
			return;
		}

		_DrawScreenHeader("Delete Client Screen");
		cout << "Enter Account number ? ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number not exist, ente another one ? ";
			AccountNumber = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		char answer = 'y';
		_PrintClientRecord(Client);
		cout << "\nAre you sure do you want to delete this client ? y/n ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			
			if (Client.Delete())
			{
				cout << "\nAccount deleted successfully\n";
				_PrintClientRecord(Client);
			}
			else
				cout << "\nAccount not deleted \n";
		}
	}
};

