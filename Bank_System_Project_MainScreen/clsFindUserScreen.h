#pragma once
#include "clsUser.h";
#include "clsScreen.h";

class clsFindUserScreen : protected clsScreen
{
	static void _PrintUser(clsUser User)
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
	static void ShowFindUser()
	{
		_DrawScreenHeader("Find User Screen");
		cout << "Enter User Name ? ";
		string UserName = clsInputValidate<string>::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser not found, enter another one ? "; 
			UserName = clsInputValidate<string>::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		if (!User.IsEmpty())
			cout << "\nUser Found\n";
		else
			cout << "\nUser not found\n";
		
		_PrintUser(User);


	}
};

