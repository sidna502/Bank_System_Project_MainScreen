#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "D:\Prorgramming_device\programing\OOP_Couse\String_Library_Project\String_Library_Project\clsString.h"
const string CurrencyFileName = "Currencies.txt";

class clsCurrency
{
	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country = "";
	string _CurrencyCode = "";
	string _CurrencyName = "";
	float _Rate = 0;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string delim = "#//#")
	{
		vector<string>vCurrencyData = clsString::SplitString(Line, delim);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}
	static string _ConvertObjectCurrencyToLine(clsCurrency Currency, string delim = "#//#")
	{
		string CurrencyRecord = "";
		CurrencyRecord += Currency.Country() + delim;
		CurrencyRecord += Currency.CurrencyCode() + delim;
		CurrencyRecord += Currency.CurrencyName() + delim;
		CurrencyRecord += to_string(Currency.Rate()) + delim;

		return CurrencyRecord;
	}
	static vector<clsCurrency>_LoadCurrencyDataFromFile()
	{
		vector<clsCurrency>vCurrencyData;
		string Line = "";
		fstream MyFile;
		MyFile.open(CurrencyFileName, ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrencyData.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrencyData;
	}
	static void _SaveCurrencyDataToFile(vector<clsCurrency>& vCurrencyData)
	{
		string DataLine = "";
		fstream MyFile;
		MyFile.open(CurrencyFileName, ios::out);
		if (MyFile.is_open())
		{
			for (clsCurrency& C : vCurrencyData)
			{
				DataLine = _ConvertObjectCurrencyToLine(C);
				MyFile << DataLine << endl;
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsCurrency>vCurrencyData = _LoadCurrencyDataFromFile();
		for (clsCurrency& C : vCurrencyData)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				_SaveCurrencyDataToFile(vCurrencyData);
				break;
			}
		}

	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public:
	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}
	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}
	float Rate()
	{
		return _Rate;
	}
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		string Line = "";
		fstream MyFile;
		MyFile.open(CurrencyFileName, ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.CurrencyCode()) == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		string Line = "";
		fstream MyFile;
		MyFile.open(CurrencyFileName, ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}
			}
			MyFile.close();
		}
		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		return !Currency.IsEmpty();
	}
	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}
	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}
	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD")
			return AmountInUSD;
		return (float)(AmountInUSD * Currency2.Rate());
	}
};

