#pragma once
#include "clsUser.h";
#include "clsScreen.h";

class clsUpdateUserScreen : protected clsScreen
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
		cout << "\nEnter Permissins ? ";
		User.Permissions = _ReadPermissionsToSet();
	}
	static int _ReadPermissionsToSet()
	{
		int Permissions = 0;
		if (clsInputValidate<bool>::ReadChoice("Do you want to give full access ? "))
			return -1;
		
		cout << "\nDo you want to give access to:\n";
		if (clsInputValidate<bool>::ReadChoice("Show Client List ? "))
		{
			Permissions += clsUser::enPermissions::pListClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Add New Client ? "))
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Delete Client ? "))
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Update Client ? "))
		{
			Permissions += clsUser::enPermissions::pUpdateClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Find Client ? "))
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}
		if (clsInputValidate<bool>::ReadChoice("Transactions ? "))
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}
		if (clsInputValidate<bool>::ReadChoice("Manage User ? "))
		{
			Permissions += clsUser::enPermissions::pManageUser;
		}
		if (clsInputValidate<bool>::ReadChoice("Login Register Screen ? "))
		{
			Permissions += clsUser::enPermissions::pLoginRegisterScreen;
		}
		return Permissions;
	}
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
	static void ShowUserUpdate()
	{
		_DrawScreenHeader("User Update Screen");
		cout << "Enter User Name ? ";
		string UserName = clsInputValidate<string>::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nNo User Found, Please enter another one ? ";
			UserName = clsInputValidate<string>::ReadString();
		}
		clsUser User = clsUser::Find(UserName);
		
		_PrintUser(User);
		char Answer = 'n';
		cout << "Are you sure do want to update this user y/n ? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y');
		{
			_ReadUserInfo(User);

			clsUser::enSaveResults SaveResults;
			SaveResults = User.Save();

			switch (SaveResults)
			{
			case clsUser::enSaveResults::svSecceded:
				cout << "\nUser updated successfully\n";
				_PrintUser(User);
				break;
			case clsUser::svFaildEmptyObject:
				cout << "\nError, User not updated because it's empty\n";
				break;

			}

		}
		
		


	}
};

