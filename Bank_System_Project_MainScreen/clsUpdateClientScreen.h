#pragma once
#include "clsBankClient.h";
#include "clsScreen.h";

class clsUpdateClientScreen : protected clsScreen
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
	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pUpdateClient))
		{
			return;
		}
		
		_DrawScreenHeader("Update Client Screen");
		cout << "Enter Account Number ? ";
		string AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount does not exist, enter another one ? ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClientDataRecord(Client);
		cout << "\nAre you sure do you want to update this client y/n ? ";
		char Answer = 'y';
		cin >> Answer;
		clsBankClient::enSaveResults SaveResults;
		SaveResults = Client.Save();

		if (toupper(Answer) == 'Y')
		{
			_ReadClientRecordInfo(Client);
			switch (SaveResults)
			{
			case clsBankClient::svFaildEmptyObject:
			{
				cout << "Error, Account was not updated because it's empty\n";
				break;
			}
			case clsBankClient::svSecceded:
			{
				cout << "\nAccount apdated successfully\n";
				_PrintClientDataRecord(Client);
				break;
			}
			/*case clsBankClient::svFaildAccountNumberExist:
			{
				cout << "Error, Account was not updated \n";
				break;
			}*/
			}
		}

	}
};

