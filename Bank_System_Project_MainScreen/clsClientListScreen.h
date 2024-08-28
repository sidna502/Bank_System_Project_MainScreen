#pragma once
#include "clsScreen.h";
#include "clsBankClient.h";
class clsClientListScreen: protected clsScreen
{
	static void PrintClientRecord(clsBankClient Client)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << Client.FirstName;
		cout << "| " << setw(15) << Client.LastName;
		cout << "| " << setw(20) << Client.FullName();
		cout << "| " << setw(20) << Client.Email;
		cout << "| " << setw(12) << Client.Phone;
		cout << "| " << setw(15) << Client.AccountNumber();
		cout << "| " << setw(15) << Client.PinCode;
		cout << "| " << setw(15) << Client.AccountBalance;
	}

public:
	static void ShowClientListScreen()
	{
		vector <clsBankClient>vClient = clsBankClient::GetClientList();
		string Title = "Client List Screen";
		string Subtitle = "\t" + to_string(vClient.size()) + " Client List";
		_DrawScreenHeader(Title, Subtitle);

		cout << setw(8) << left << "" << "______________________________________________________________________________________________________________________________________________\n";

		cout << setw(8) << "" << "| " << setw(15)<< "First Name";
		cout << "| " << setw(15) << "Last Name";
		cout << "| " << setw(20) << "FullName";
		cout << "| " << setw(20) << "Email";
		cout << "| " << setw(12) << "Phone";
		cout << "| " << setw(15) << "AccountNumber";
		cout << "| " << setw(15) << "PinCode";
		cout << "| " << setw(15) << "AccountBalance";

		cout << endl << setw(8) << left << "" << "______________________________________________________________________________________________________________________________________________\n";
		if (vClient.size() == 0)
			cout << "No Client Found in the system\n";
		else
		{
			for (clsBankClient& Client : vClient)
			{
				PrintClientRecord(Client);
				cout << endl;
			}
		}
		cout << endl << setw(8) << left << "" << "______________________________________________________________________________________________________________________________________________\n";

	}
};

