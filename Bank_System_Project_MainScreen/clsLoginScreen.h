#pragma once
#include "clsScreen.h";
#include "clsUser.h";
#include "Global.h";
#include "clsMainScreen.h"; 


class clsLoginScreen : protected clsScreen
{
	static void _Login()
	{
		bool FaildLogin = false;
		string UserName = "", Passeword = "";
		do
		{
			if (FaildLogin)
			{
				system("cls");
				_DrawScreenHeader("Login Screen");
				cout << "\nInvalid UserName/Passeword\n";
			}
			cout << "\nEnter User Name ? ";
			UserName = clsInputValidate::ReadString();

			cout << "\nEnter Passeword ? ";
			Passeword = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Passeword);

			FaildLogin = CurrentUser.IsEmpty();
		} while (FaildLogin);
		clsMainScreen::MainMenueScreen();
		//ShowLoginScreen();
	}
public:
	static void ShowLoginScreen()
	{
		_DrawScreenHeader("Login Screen");
		_Login();
	}

};

