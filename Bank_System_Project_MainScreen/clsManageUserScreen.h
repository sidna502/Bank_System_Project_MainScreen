#pragma once
#include <iostream>
#include "clsScreen.h"
#include "D:\Prorgramming_device\programing\OOP_Applications\InputValidate\InputValidate\clsInputValidate.h"
#include "clsUserListScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"


class clsManageUserScreen : protected clsScreen
{
	
	static void _ShowListUserScreen()
	{
		clsUserListScreen::ShowUsersList();
	}
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUser();
	}
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUser();
	}
	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUserUpdate();
	}
	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUser();
	}
	enum enManageUserOptions{eListUser = 1, eAddNewUser = 2, eDeleteUser = 3, eUpdateUser = 4, eFindUser = 5, eMainMenue =6};
	
	static short _ReadManageUserOption()
	{
		cout << setw(37) << "" << "Choose what do you want to do from [1 to 6] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Out of range, enter a number beween [1 to 6] ? ");
		return Choice;
	}
	static void _GoBackToMainUserMenue()
	{
		cout << "\nEnter any key to go back to main user scree...";
		system("pause > 0");
		ManageUserMenueScreen();
	}
	static void _PerformManageUserOptions(enManageUserOptions Option)
	{
		system("cls");
		switch (Option)
		{
		case clsManageUserScreen::eListUser:
			_ShowListUserScreen();
			_GoBackToMainUserMenue();
			break;
		case clsManageUserScreen::eAddNewUser:
			_ShowAddNewUserScreen();
			_GoBackToMainUserMenue();
			break;
		case clsManageUserScreen::eDeleteUser:
			_ShowDeleteUserScreen();
			_GoBackToMainUserMenue();
			break;
		case clsManageUserScreen::eUpdateUser:
			_ShowUpdateUserScreen();
			_GoBackToMainUserMenue();
			break;
		case clsManageUserScreen::eFindUser:
			_ShowFindUserScreen();
			_GoBackToMainUserMenue();
			break;
		case clsManageUserScreen::eMainMenue:
		{
			
		}
		
		}
	}
public:
	static void ManageUserMenueScreen()
	{
		
		if (!CheckAccessRight(clsUser::enPermissions::pManageUser))
		{
			return;// this will exit the function and it will not continue
		}
		system("cls");
		_DrawScreenHeader("Manage User Screen");
		cout << setw(37) << left<< "" << "=======================================================\n";
		cout << setw(45) << "" << "Manage User Menue\n";

		cout << setw(37) << left << "" << "=======================================================\n";
		cout << setw(37) << "" << "\t[1] User List\n";
		cout << setw(37) << "" << "\t[2] Add New User\n";
		cout << setw(37) << "" << "\t[3] Delete User \n";
		cout << setw(37) << "" << "\t[4] Update User\n";
		cout << setw(37) << "" << "\t[5] Find User \n";
		cout << setw(37) << "" << "\t[6] Main Menue \n";

		cout << setw(37) << left << "" << "=======================================================\n";

		_PerformManageUserOptions((enManageUserOptions)_ReadManageUserOption());
	}
};

