#pragma once
#include "clsUser.h";
#include "clsScreen.h"

class clsLoginRegisterScreen : protected clsScreen
{
	static void _PrintLoginRegister(clsUser::stLoginRegisterRecord Record)
	{
		cout << setw(8) << left << "" << "| " << setw(40) << Record.DateTime;
		cout << "| " << setw(15) << Record.UserName;
		cout << "| " << setw(15) << Record.Passeword;
		cout << "| " << setw(20) << Record.Permissions;
	}
public:
	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRight(clsUser::enPermissions::pLoginRegisterScreen))
		{
			return;
		}
		vector<clsUser::stLoginRegisterRecord>vLoginRegisterRecord = clsUser::GetLoginRegisterList();
		string Title = "Login Register List Screen";
		string SubTile = "\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s)";
		_DrawScreenHeader(Title, SubTile);
		cout << setw(8) << left << "" << "____________________________________________________________________________________________________\n";
		cout << setw(8) << "" << "| " << setw(40) << "Date/Time";
		cout << "| " << setw(15) << "User Name";
		cout << "| " << setw(15) << "Passeword";
		cout << "| " << setw(20) << "Permissions";
		cout << endl<< setw(8) << left << "" << "| " << "____________________________________________________________________________________________________\n";
		if (vLoginRegisterRecord.size() == 0)
			cout << "\nNo User Login available in the system\n";
		else
		{
			for (clsUser::stLoginRegisterRecord& Record : vLoginRegisterRecord)
			{
				_PrintLoginRegister(Record);
				cout << endl;
			}
			
		}
		cout << setw(8) << left << "" << "| " << "____________________________________________________________________________________________________\n";


	}
};

