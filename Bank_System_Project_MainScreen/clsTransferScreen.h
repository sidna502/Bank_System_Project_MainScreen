#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsBankClient.h"


class clsTransferScreen : protected clsScreen
{
	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << "\nClient Card:\n";
		cout << "_______________________________________\n";
		cout << "Full Name  : " << Client.FullName() << endl;
		cout << "Acc. Number: " << Client.AccountNumber() << endl;
		cout << "Balance    : " << Client.AccountBalance<< endl;
		cout << "_______________________________________\n";
	}
	static string _ReadAccountNumber(string Message)
	{
		cout << "\nPlease enter account Number to transfer ";
		cout << Message + ": ";
		string AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nNo Account Number found, Enter another one ? ";
			string AccountNumber = clsInputValidate::ReadString();
		}
		return AccountNumber;
	}
	static float ReadAmount(clsBankClient SourceClient)
	{
		cout << "\nEnter Transfer Amount ? ";
		float Amount = clsInputValidate::ReadFloatNumber("Invalid Enter enter number again");
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAccount Exceeds the available balnce, enter another one ? ";
			Amount = clsInputValidate::ReadFloatNumber("Invalid Enter enter number again");
		}
		return Amount;
	}
public:
	static void TranferScreen()
	{
		_DrawScreenHeader("Transfer Screen");
		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber("From"));
		_PrintClientRecord(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		while (DestinationClient.AccountNumber() == SourceClient.AccountNumber())
		{
			cout << "\nYou cannot transfer to yourself\n";
			cout << "Please another account Number to transfer to: ";
			DestinationClient = clsBankClient::Find(_ReadAccountNumber("To"));
		}

		_PrintClientRecord(DestinationClient);

		float Amount = ReadAmount(SourceClient);
		
		char Answer = 'n';
		cout << "\nAre you sure to perform this transaction Y/N ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient, CurrentUser.UserName))
			{
				cout << "\nTransfer done successfully\n";
			}
			else
				cout << "\nTransfe Faild\n";
			
		}
		_PrintClientRecord(SourceClient);
		_PrintClientRecord(DestinationClient);
		
	}
};

