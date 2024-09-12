#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"


class clsTransferLogScreen : protected clsScreen
{
	static void _PrintRegiaterTransferLog(clsBankClient::stTransferLogRecord Record)
	{
		cout << setw(8) << left << "" << "| " << setw(40) << Record.DateTime;
		cout << "| " << setw(15) << Record.SourceAccount;
		cout << "| " << setw(15) << Record.DestAccount;
		cout << "| " << setw(15) << Record.Amount;
		cout << "| " << setw(15) << Record.SoureceBalance;
		cout << "| " << setw(15) << Record.DestBalance;
		cout << "| " << setw(15) << Record.UserName;
	}
public:
	static void ShowRegisterTransferLog()
	{
		vector <clsBankClient::stTransferLogRecord>vLoginTranferRecord = clsBankClient::GetLoginTransferList();
		string Title = "Transfer Log List Scree";
		string SubTitle = "\t(" + to_string(vLoginTranferRecord.size()) + ") Record(s)";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "________________________________________________________________________________";
		cout << "________________________________________________________________________________\n";
		cout << setw(8) << "" << "| " << setw(40) << "Date/Time";
		cout << "| " << setw(15) << "S.Account";
		cout << "| " << setw(15) << "D.Account";
		cout << "| " << setw(15) << "Amount";
		cout << "| " << setw(15) << "S.Balance";
		cout << "| " << setw(15) << "D.Balance";
		cout << "| " << setw(15) << "UserName";

		cout << endl<< setw(8) << left << "" << "________________________________________________________________________________";
		cout << "________________________________________________________________________________\n";
		if (vLoginTranferRecord.size() == 0)
			cout << "No Login Register Transfer available in the system\n";
		else
		{
			for (clsBankClient::stTransferLogRecord& Record : vLoginTranferRecord)
			{
				_PrintRegiaterTransferLog(Record);
				cout << endl;

			}
		}

		cout << setw(8) << left << "" << "________________________________________________________________________________";
		cout << "________________________________________________________________________________\n";
	}
};

