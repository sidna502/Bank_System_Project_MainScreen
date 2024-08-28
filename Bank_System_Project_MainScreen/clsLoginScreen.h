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
				cout << "\nInvalid UserName/Passeword\n";

			cout << "\nEnter User Name ? ";
			UserName = clsInputValidate::ReadString();

			cout << "\nEnter Passeword ? ";
			Passeword = clsInputValidate::ReadString();

			/*CurrentUser = clsUser::Find(UserName, Passeword);*/
			clsUser User = clsUser::Find(UserName, Passeword);
			FaildLogin = User.IsEmpty();
		} while (FaildLogin);
		clsMainScreen::MainMenueScreen();
	}
public:
	static void ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("Login Screen");
		_Login();
	}

};

