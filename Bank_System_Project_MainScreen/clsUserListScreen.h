#pragma once
#include "clsScreen.h";
#include "clsUser.h";

class clsUserListScreen : protected clsScreen
{
	static void _PrintUserRecord(clsUser User)
	{
		cout << setw(37) << left << "" << "| " << setw(10) << User.UserName;
		cout << "| " << setw(25) << User.FullName();
		cout << "| " << setw(15) << User.Passeword;
		cout << "| " << setw(20) << User.Email; 
		cout << "| " << setw(15) << User.Phone;
		cout << "| " << setw(15) << User.Permissions;
	}

public:
	static void ShowUsersList()
	{
		vector <clsUser>vUser = clsUser::GetUserList();
		string Title = "User List Screen";
		string SubTitle = "\tNumber of User= " + to_string(vUser.size());
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(37) << left << "" << "==============================================================================================================\n";
		cout << setw(37) << "" << "| " << setw(10) << "User Name";
		cout << "| " << setw(25) << "Full Name";
		cout << "| " << setw(15) << "Passeword";
		cout << "| " << setw(20) << "Email";
		cout << "| " << setw(15) << "Phone";
		cout << "| " << setw(15) << "permissions";
		cout << endl << setw(37) << left << "" << "==============================================================================================================\n";
		if (vUser.size() == 0)
			cout << "No user avalaible in the system\n";
		else
		{
			for (clsUser& User : vUser)
			{
				_PrintUserRecord(User);
				cout << endl;
			}
		}

		cout << endl << setw(37) << left << "" << "=============================================================================================================\n";

	}
};

