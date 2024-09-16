#pragma once
#include "clsScreen.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRate.h"
#include "clsCurrencyCalculatorScreen.h";

class clsCurrencyExchangeMainScreen : protected clsScreen
{
	enum enCurrencyExchangeMenueOptions{eCurrencyList = 1, eFindCurrency = 2, eUpdateRate = 3, eCaculateCurrency = 4,
	                                           eMainMenue = 5};

	static void _ShowCurrenciesListScreen()
	{
		clsCurrenciesListScreen::_ShowCurrenciesListScreen();

	}
	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::_ShowFindCurrencyScreen();

	}
	static void _ShowUpdateCurrencyScreen()
	{
		clsUpdateCurrencyRate::ShowUpdateCurrencyRataScreen();

	}
	static void _ShowCalculateCurrencyScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();

	}

	static short _ReadOptions()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do from [1 to 5] ? ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Out of range, please enter a number between 1 and 5");
		return Choice;
    }
	static void _GoBackToMainMenue()
	{
		cout << "\nPress any Key to go back to main menue...";
		system("pause > 0");
		MainMenueScreen();
	}
	static void _PerformMainMenueOption(enCurrencyExchangeMenueOptions Options)
	{
		system("cls");
		switch (Options)
		{
		case enCurrencyExchangeMenueOptions::eCurrencyList:
			_ShowCurrenciesListScreen();
			_GoBackToMainMenue();
			break;
		case enCurrencyExchangeMenueOptions::eFindCurrency:
			_ShowFindCurrencyScreen();
			_GoBackToMainMenue();
			break;
		case enCurrencyExchangeMenueOptions::eUpdateRate:
			_ShowUpdateCurrencyScreen();
			_GoBackToMainMenue();
			break;
		case enCurrencyExchangeMenueOptions::eCaculateCurrency:
			_ShowCalculateCurrencyScreen();
			_GoBackToMainMenue();
			break;
		case enCurrencyExchangeMenueOptions::eMainMenue:
		{

		}

		}
	}
public:
	static void MainMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("Currency Exchange Main Screen");
		cout << left << setw(37) << "" << "==============================================\n";
		cout << setw(37) << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << "" << "==============================================\n";
		cout << setw(37) << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << "" << "\t[5] Main Menue. \n";
		cout << setw(37) << "" << "==============================================\n";
		_PerformMainMenueOption((enCurrencyExchangeMenueOptions)_ReadOptions());
	}
};

