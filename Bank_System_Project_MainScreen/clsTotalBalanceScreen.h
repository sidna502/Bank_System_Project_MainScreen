#pragma once
#include "clsBankClient.h";
#include "clsScreen.h";


class clsTotalBalanceScreen : protected clsScreen
{
	static void _PrintClientRecord(clsBankClient Client)
	{
		cout << setw(37) << left << "" << "| " << setw(15) << Client.FullName();
		cout << "| " << setw(15) << Client.AccountNumber();
		cout << "| " << setw(20) << Client.AccountBalance;
	}

public:
	static void ShowTotalBalanceScreen()
	{
		double TotalBalance = 0;
		vector <clsBankClient> vClient = clsBankClient::GetClientList();
		string Title = "Total Balance Screen";
		string SubTitle = "\tNumber of client is: " + to_string(vClient.size()) + " Client(s)";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(37) << left << "" << "_______________________________________________________________\n";
		cout << setw(37) << "" << "| " << setw(15) << "Full Name";
		cout << "| " << setw(15) << "Account Number";
		cout << "| " << setw(20) << "Account Balance";
		cout << endl << setw(37) << left << "" << "_______________________________________________________________\n";
		if (vClient.size() == 0)
			cout << "\nThere is no client in the system\n";
		else
		{
			for (clsBankClient& Client : vClient)
			{
				_PrintClientRecord(Client);
				cout << endl;
			}
		}
		cout << setw(37) << left << "" << "_______________________________________________________________\n\n";
		TotalBalance = clsBankClient::GetTotalBalance();
		cout << setw(37) << "" << "Total Balance = " << TotalBalance << endl;
		cout << setw(37) << "" << "Total Balance in text = " << clsUtil::NumberToText(TotalBalance) << endl;
	}
};

