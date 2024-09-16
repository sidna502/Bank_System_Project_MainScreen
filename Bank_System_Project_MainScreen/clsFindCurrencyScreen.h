#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"

class clsFindCurrencyScreen : protected clsScreen
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
	enum enFindCurrency { eByCode = 1, eByCountry = 2 };
	static enFindCurrency _ReadChoice()
	{
		cout << "\nFind By: [1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 2, "Out of range, please enter another one ? ");
		return (enFindCurrency)Choice;
	}
	static clsCurrency _FindByCode()
	{
		string CurrencyCode = "";
		cout << "\nPlease enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		/*if (!Currency1.IsEmpty())
		{
			cout << "Currency found :-)\n";
			_PrintCurrency(Currency1);
		}
		else
		{
			cout << "Currency not found -:)\n";
		}*/
		return Currency;
	}
	static clsCurrency _FindByCountry()
	{
		string CountryName = "";
		cout << "\nPlease enter Country Name: ";
		CountryName = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
		/*if (!Currency2.IsEmpty())
		{
			cout << "Currency found :-)\n";
			_PrintCurrency(Currency2);
		}
		else
		{
			cout << "Currency not found -:)\n";
		}*/
		return Currency;
	}
	static clsCurrency _ReadCurrecyChoice(enFindCurrency Choice)
	{
		switch (Choice)
		{
		case clsFindCurrencyScreen::eByCode:
			return _FindByCode();
		case clsFindCurrencyScreen::eByCountry:
			return _FindByCountry();
		}
	}
	static void _ShowResutls(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "Currency found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "Currency not found -:)\n";
		}
	}

public:

	static void _ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("Find Currency Screen");
		
		clsCurrency Currency = _ReadCurrecyChoice(_ReadChoice());
		_ShowResutls(Currency);
		//Second Method
		/*short Answer = 1;
		cout << "\nFind By: [1] Code or [2] Country ? ";
		cin >> Answer;
		if (Answer == 1)
		{
			string CurrencyCode = "";
			cout << "\nPlease enter Currency Code: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResutls(Currency);
		}
		else
		{
			string CountryName = "";
			cout << "\nPlease enter Country Name: ";
			CountryName = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);
			_ShowResutls(Currency);
		}*/

		
	}
};

