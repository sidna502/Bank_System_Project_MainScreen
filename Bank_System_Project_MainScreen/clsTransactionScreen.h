#pragma once
#include "clsScreen.h";
#include "D:\Prorgramming_device\programing\OOP_Applications\InputValidate\InputValidate\clsInputValidate.h";
#include <iomanip>
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalanceScreen.h";

class clsTransactionScreen : protected clsScreen
{
	static void _ShowDepositScreen()
	{
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen()
	{
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	static void _ShowTotalBalanceScreen()
	{
		clsTotalBalanceScreen::ShowTotalBalanceScreen();
	}
	static void _GoBackToTransactionMenue()
	{
		cout << "\nPress any key to go back to transaction menue... ";
		system("pause > 0");
		TransactionMenueScreen();
	}
	static short _ReadTransactionOptions()
	{
		cout << setw(37) << "" << "Choose you what do you want from [1 to 4] ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 4, "Out of range, enter a number beween [1 to 4] ? ");
		return Choice;
	}
	enum enTransactionOptions{eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eMainMenueScreen};
	static void _PerformTransactionMenue(enTransactionOptions Option)
	{
		system("cls");
		switch (Option)
		{
		case enTransactionOptions::eDeposit:
			_ShowDepositScreen();
			_GoBackToTransactionMenue();
			break;
		case enTransactionOptions::eWithdraw:
			_ShowWithdrawScreen();
			_GoBackToTransactionMenue();
			break;
		case enTransactionOptions::eTotalBalance:
			_ShowTotalBalanceScreen();
			_GoBackToTransactionMenue();
			break;
		case enTransactionOptions::eMainMenueScreen:
		{

		}
		
		}
	}

public:
	static void TransactionMenueScreen()
	{
		system("cls");
		_DrawScreenHeader("Transaction Screen");
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << "" << setw(15) << "" << "Transaction Menue\n";
		cout << setw(37) << left << "" << "================================================\n";
		cout << setw(37) << "" << "\t[1] Deposit\n";
		cout << setw(37) << "" << "\t[2] Withdraw\n";
		cout << setw(37) << "" << "\t[3] Total Balance\n";
		cout << setw(37) << "" << "\t[4] Main Menue\n";
		cout << setw(37) << left << "" << "================================================\n";
		_PerformTransactionMenue((enTransactionOptions)_ReadTransactionOptions());

	}
};

