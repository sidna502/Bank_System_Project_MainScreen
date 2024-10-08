#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsClientListScreen.h"
#include "clsAddNewClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUserScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeMainScreen.h"

class clsMainScreen : protected clsScreen
{
	enum enMainMenueOptions {
		eListClients = 1, eAddNewClient = 2, eDeleteClient = 3, eUpdateClient = 4, eFindClient = 5,
		eTransactions = 6, eManageUsers = 7, eLoginRegister = 8, eCurrency = 9, eLogout = 10};

	static void _ShowAllClientsScreen()
	{
		clsClientListScreen::ShowClientListScreen();
	}
	static void _ShowAddNewClientScreen()
	{
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	static void _ShowDeleteClientScreen()
	{
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}
	static void _ShowTransactionsScreen()
	{
		clsTransactionScreen::TransactionMenueScreen();
	}
	static void _ShowManageUsersScreen()
	{
		clsManageUserScreen::ManageUserMenueScreen();
	}
	static void _ShowLoginRegisterListScreen()
	{
		clsLoginRegisterScreen::ShowLoginRegisterScreen();
		
	}
	static void _ShowCurrencyExchangeScreen()
	{
		clsCurrencyExchangeMainScreen::MainMenueScreen();

	}
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		
	}
	static void _PerforMainMenueOption(enMainMenueOptions Options)
	{
		system("cls");
		switch (Options)
		{
		case enMainMenueOptions::eListClients:
		{
			/*if (!CheckAccessRight(clsUser::enPermissions::pListClient))
			{
				_GoBackToMainMenue();
				return;
			}*/
			_ShowAllClientsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eAddNewClient:

		{
			/*if (!CheckAccessRight(clsUser::enPermissions::pAddNewClient))
			{
				_GoBackToMainMenue();
				return;
			}*/
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eDeleteClient:
			
			/*if (!CheckAccessRight(clsUser::enPermissions::pDeleteClient))
			{
				_GoBackToMainMenue();
				return;
			}*/
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eUpdateClient:
			/*if (!CheckAccessRight(clsUser::enPermissions::pUpdateClient))
			{
				_GoBackToMainMenue();
				return;
			}*/
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eFindClient:
			/*if (!CheckAccessRight(clsUser::enPermissions::pFindClient))
			{
				_GoBackToMainMenue();
				return;
			}*/
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eTransactions:
		{
			/*if (!CheckAccessRight(clsUser::enPermissions::pTransactions))
			{
				_GoBackToMainMenue();
				return;
			}*/
			_ShowTransactionsScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eManageUsers:
		{
			/*if (!CheckAccessRight(clsUser::enPermissions::pManageUser))
			{
				_GoBackToMainMenue();
				return;
			}*/
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		}
		case enMainMenueOptions::eLoginRegister:
			_ShowLoginRegisterListScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eCurrency:
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOptions::eLogout:

			_Logout();
			break;
		}
	}
	static void _GoBackToMainMenue()
	{
		cout << "\nPress any key to go back to main menue...";
		system("pause > 0");
		MainMenueScreen();

	}
	
	static short _ReadOption()
	{
		cout << left << setw(37) << "" << "Choose what do you want to do from [1 to 10] ? ";
		short Number = clsInputValidate<short>::ReadNumberBetween(1, 10, "Out of range, please enter a number between 1 and 10");
		return Number;
	}

public:
	static void MainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("Main Screen");
		cout << left << setw(37) << "" << "==============================================\n";
		cout << setw(37) << "" << "\t\tMain Menue\n";
		cout << setw(37) << "" << "==============================================\n";
		cout << setw(37) << "" << "\t[1] Show client list.\n";
		cout << setw(37) << "" << "\t[2] Add New client.\n";
		cout << setw(37) << "" << "\t[3] Delete client.\n";
		cout << setw(37) << "" << "\t[4] Update client Info.\n";
		cout << setw(37) << "" << "\t[5] Find client. \n";
		cout << setw(37) << "" << "\t[6] Transactions.\n";
		cout << setw(37) << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << "" << "\t[8] Login Register.\n";
		cout << setw(37) << "" << "\t[9] Currency Exchange.\n";
		cout << setw(37) << "" << "\t[10] Logout.\n";
		cout << setw(37) << "" << "==============================================\n";
		_PerforMainMenueOption((enMainMenueOptions)_ReadOption());
	}
};

