#pragma once
#include "clsUser.h";
#include "clsScreen.h";

class clsAddNewUserScreen : protected clsScreen
{
	static void _ReadUserInfo(clsUser &User)
	{
		cout << "\nEnter First Name ? ";
		User.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Last Name ? ";
		User.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email ? ";
		User.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone ? ";
		User.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter Passeword ? ";
		User.Passeword = clsInputValidate<string>::ReadString();
		cout << "\nEnter Permission ? ";
		User.Permissions = _ReadPermissions();

	}
	static int _ReadPermissions()
	{
		int Permissions = 0;
		char Answer = 'n';
		cout << "\nDo you want to give full access y/n ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
			return -1;
		
	    cout << "\nDo you want to give access to: \n";
		if (clsInputValidate<bool>::ReadChoice("Show List Client y/n ? "))
		{
			Permissions += clsUser::enPermissions::pListClient;
		}
		
		if (clsInputValidate<bool>::ReadChoice("Add New Client y/n ? "))
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Delete Client y/n ? "))
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Update Client y/n ? "))
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Find Client y/n ? "))
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Transactions y/n ? "))
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}
		if (clsInputValidate<bool>::ReadChoice("Manage User y/n ? "))
		{
			Permissions += clsUser::enPermissions::pManageUser;
		}
		if (clsInputValidate<bool>::ReadChoice("Show Login Register Screen y/n ? "))
		{
			Permissions += clsUser::enPermissions::pLoginRegisterScreen;
		}
		return Permissions;
	}
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
	static void ShowAddNewUser()
	{
		_DrawScreenHeader("Add New user Screen");
		cout << "\nEnter User Name ? ";
		string UserName = clsInputValidate<string>::ReadString();
		while (clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name already exist, enter amother one ? ";
			UserName = clsInputValidate<string>::ReadString();
		}
		clsUser User = clsUser::GetAddNewUser(UserName);
		
		_ReadUserInfo(User);

		clsUser::enSaveResults SaveResult;
		SaveResult = User.Save();
		
		switch (SaveResult)
		{
		case clsUser::svFaildEmptyObject:
		{
			cout << "\nError User was not saved because object it's empty\n";
			break;
		}
		case clsUser::svSecceded:
		{
			cout << "\nUser Added succefully\n";
			_PrintUserCard(User);
			break;
		}
		case clsUser::svFaildUserNameExist:
		{
			cout << "\nError User was not saved because it's exist\n";
			break;
		}
		
		}

		
	}
};

