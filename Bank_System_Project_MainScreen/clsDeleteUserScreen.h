#pragma once
#include "clsUser.h";
#include "clsScreen.h";

class clsDeleteUserScreen : protected clsScreen
{
	static void _PrintUserCard(clsUser User)
	{
		cout << "\nUser Card:\n";
		cout << "_________________________________________\n";
		cout << "User Name : " << User.UserName << endl;
		cout << "Full Name : " << User.FullName() << endl;
		cout << "Email     : " << User.Email << endl;
		cout << "Phone Num : " << User.Phone << endl;
		cout << "Passeword : " << User.Passeword << endl;
		cout << "Permission: " << User.Permissions << endl;

		cout << "_________________________________________\n";
	}

public:
	static void ShowDeleteUser()
	{
		_DrawScreenHeader("Delete User Screen");
		cout << "Enter User Name ? ";
		string UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser does not exist, enter another one ? ";
			UserName = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		_PrintUserCard(User);
		char Answer = 'y';
		cout << "\nAre you sure do you want to delete this user y/n ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			if (User.Delete())
			{
				cout << "\nUser deleted secceffully\n";
				_PrintUserCard(User);
			}
			else
				cout << "\nUser not deleted\n";
		}
		
	}
};

