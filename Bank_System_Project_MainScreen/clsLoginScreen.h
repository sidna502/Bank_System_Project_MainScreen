#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"
#include "clsMainScreen.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
	
	static bool _Login()
	{
		bool FaildLogin = false;
		short FaildLoginCount = 0;
		string UserName = "", Passeword = "";
		do
		{
			if (FaildLogin)
			{
				system("cls");
				_DrawScreenHeader("Login Screen");
				cout << "\nInvalid UserName/Passeword\n";
				FaildLoginCount++;
				cout << "\nYou have " << (3 - FaildLoginCount) << " trial (s) to Login\n";
				if (FaildLoginCount == 3)
				{
					cout << "\nYou are Looked after " << FaildLoginCount << " trials\n";
					return false;
				}
			}
			cout << "\nEnter User Name ? ";
			UserName = clsInputValidate::ReadString();

			cout << "\nEnter Passeword ? ";
			Passeword = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Passeword);
			
			FaildLogin = CurrentUser.IsEmpty();
			
		} while (FaildLogin);
		CurrentUser.RegisterLogIn();
		clsMainScreen::MainMenueScreen();
		return true;
	}
public:
	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("Login Screen");
		 return _Login();
	}

};

