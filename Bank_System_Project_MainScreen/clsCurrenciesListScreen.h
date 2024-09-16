#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsCurrenciesListScreen : protected clsScreen
{
	static void _PrintCurrenciesList(clsCurrency Currency)
	{
		cout << setw(37) << left << "" << "| " << setw(30) << Currency.Country();
		cout << "| " << setw(10) << Currency.CurrencyCode();
		cout << "| " << setw(40) << Currency.CurrencyName();
		cout << "| " << setw(10) << Currency.Rate();
	}
public:
	static void _ShowCurrenciesListScreen()
	{
		vector <clsCurrency>vCurrency = clsCurrency::GetCurrencyList();
		string Title = "Currencies List Screen";
		string SubTitle = "\t(" + to_string(vCurrency.size()) + ") Currency\n";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(37) << left << "" << "_____________________________________________________________________________________________________\n";
		cout << setw(37) << "" << "| " << setw(30) << "Country";
		cout << "| " << setw(10) << "Code";
		cout << "| " << setw(40) << "Name";
		cout << "| " << setw(10) << "Rate(1$)";

		cout << endl << setw(37) << left << "" << "_____________________________________________________________________________________________________\n";
		if (vCurrency.size() == 0)
			cout << "No Currency found\n";
		else
		{
			for (clsCurrency& C : vCurrency)
			{
				_PrintCurrenciesList(C);
				cout << endl;
			}
		}
		cout << setw(37) << left << "" << "___________________________________________________________________________________________________\n";
	}
};

