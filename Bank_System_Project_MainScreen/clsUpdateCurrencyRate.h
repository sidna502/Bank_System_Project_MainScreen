#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsUpdateCurrencyRate : protected clsScreen
{
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "Currency Card:\n";
		cout << "________________________________________\n";
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$): " << Currency.Rate() << endl;
		cout << "________________________________________\n";

	}
	static float _ReadNewCurrencyRate()
	{
		float Rate = 0;
		cout << "\nUpdate Currecny Rate:\n";
		cout << "__________________________\n";
		cout << "\nEnter New Rate: ";
		Rate =  clsInputValidate<float>::ReadNumber();

		return Rate;

	}
	static void _CheckUpdateCurrecy(clsCurrency Currency)
	{
		char Answer = 'n';
		cout << "\nAre you sure you want to update the rate of this currency y/n ? ";
		cin >> Answer;
		if (toupper(Answer) == 'Y')
		{
			//float NewRate = _ReadNewCurrencyRate();
			Currency.UpdateRate(_ReadNewCurrencyRate());
			cout << "\nCurrency Rate Updated seccessfully :-)\n";
			_PrintCurrency(Currency);
		}

	}
public:
	static void ShowUpdateCurrencyRataScreen()
	{
		_DrawScreenHeader("Update Currency Screen");
		cout << "\nPlease enter currency By [1] Code or [2] Country: ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 2, "Invalid number, enter number between 1 and 2");
		
		if (Choice == 1)
		{
			cout << "\nPlease enter Currency Code: ";
			string CurrencyCode = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			while (Currency.IsEmpty())
			{
				cout << "\nCurrency code not found, enter another one ? ";
				CurrencyCode = clsInputValidate<string>::ReadString();
			}
			_PrintCurrency(Currency);
			_CheckUpdateCurrecy(Currency);
		}
		else
		{
			cout << "\nPlease enter Country Name: ";
			string CountryName = clsInputValidate<string>::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
			while (Currency.IsEmpty())
			{
				cout << "\nCountry Name not found, enter another one ? ";
				CountryName = clsInputValidate<string>::ReadString();
			}
			_PrintCurrency(Currency);
			_CheckUpdateCurrecy(Currency);
		}
		
	}
};

