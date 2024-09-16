#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
class clsCurrencyCalculatorScreen : protected clsScreen
{
	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Convert Currency from")
	{
		cout << Title << endl;
		cout << "________________________________________\n";
		cout << "Country : " << Currency.Country() << endl;
		cout << "Code    : " << Currency.CurrencyCode() << endl;
		cout << "Name    : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$): " << Currency.Rate() << endl;
		cout << "________________________________________\n";
	}
	static float _ReadAmountToExchange()
	{
		float AmountToExchange = 0;
		cout << "\nEnter Amount To Exchange: ";
		AmountToExchange = clsInputValidate::ReadFloatNumber();
		return AmountToExchange;
	}
	static clsCurrency _GetCurrency(string Message)
	{
		cout << Message;
		string CurrencyCode = clsInputValidate::ReadString();
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency not found, enter another one ? ";
			CurrencyCode = clsInputValidate::ReadString();
		}
		return Currency;
	}
	static void _PrintCalculationResults(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		_PrintCurrencyCard(Currency1, "\nCurrency from:");
		float AmountInUSD = Currency1.ConvertToUSD(Amount);
		cout << Amount << " " << Currency1.CurrencyCode() << " = ";
		cout << AmountInUSD << " USD\n";
		if (Currency1.CurrencyCode() == "USD")
		{
			return;
		}
		_PrintCurrencyCard(Currency2, "\nConverting to:");
		float AmountCurrency2 = Currency1.ConvertToOtherCurrency(Amount, Currency2);
		cout << Amount << " " << Currency1.Country() << " = ";
		cout << AmountCurrency2 << Currency2.CurrencyCode() << endl;

	}
	static float ExchangeCurrencies(float Amount, clsCurrency Currency1, clsCurrency Currency2)
	{
		Amount = Amount / Currency1.Rate();
		Amount *= Currency2.Rate();
		return Amount;
	}
public:
	static void ShowCurrencyCalculatorScreen()
	{
		
		char Answer = 'n';
		do
		{
			system("cls");
			_DrawScreenHeader("Currency Calculator Screen");
			clsCurrency Currency1 = _GetCurrency("\nPlease enter currency1 code: ");
			clsCurrency Currency2 = _GetCurrency("\nPlease enter currency2 code: ");
			float Amount = _ReadAmountToExchange();
			_PrintCalculationResults(Amount, Currency1, Currency2);
			cout << "\nDo you want to perform another Calculation y/n ? ";
			cin >> Answer;

		} while (toupper(Answer) == 'Y');
	}
};

