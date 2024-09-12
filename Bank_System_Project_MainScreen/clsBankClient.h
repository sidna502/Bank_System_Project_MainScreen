#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsPerson.h";
#include "D:\Prorgramming_device\programing\OOP_Applications\InputValidate\InputValidate\clsInputValidate.h";
#include "D:\Prorgramming_device\programing\OOP_Couse\String_Library_Project\String_Library_Project\clsString.h";
#include "Global.h"

const string FileName = "Clients.txt";

class clsBankClient : public clsPerson
{
	string _PinCode = "";
	string _AccountNubmer = "";
	float _AccountBalance = 0;
	enum enMode{EmptyMode = 0, UpdateMode = 1, AddNewMode = 2};
	enMode _Mode;
	bool _MarkForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string delim = "#//#")
	{
		vector <string> vDataClient = clsString::SplitString(Line, delim);
		return clsBankClient(enMode::UpdateMode, vDataClient[0], vDataClient[1], vDataClient[2], vDataClient[3],
			vDataClient[4], clsUtil::DecryptText(vDataClient[5]), stof(vDataClient[6]));
	}
	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertLoginTransferLineToClientObject(string Line, string delim = "#//#")
	{
		stTransferLogRecord LoginTransferRecord;
		vector <string>vLoginTransferRecord = clsString::SplitString(Line, delim);
		LoginTransferRecord.DateTime = vLoginTransferRecord[0];
		LoginTransferRecord.SourceAccount = vLoginTransferRecord[1];
		LoginTransferRecord.DestAccount = vLoginTransferRecord[2];
		LoginTransferRecord.Amount = stof(vLoginTransferRecord[3]);
		LoginTransferRecord.SoureceBalance = stof(vLoginTransferRecord[4]);
		LoginTransferRecord.DestBalance = stof(vLoginTransferRecord[5]);
		LoginTransferRecord.UserName = vLoginTransferRecord[6];
		return LoginTransferRecord;
	}
	static string _ConvertClientObjectToLine(clsBankClient Client, string delim = "#//#")
	{
		string ClientRecord = "";
		ClientRecord += Client.FirstName + delim;
		ClientRecord += Client.LastName + delim;
		ClientRecord += Client.Email + delim;
		ClientRecord += Client.Phone + delim;
		ClientRecord += Client.AccountNumber() + delim;
		ClientRecord += clsUtil::EncryptText(Client.PinCode) + delim;
		ClientRecord += to_string(Client.AccountBalance) ;
		return ClientRecord;
	}
	string _PrepareTransferLogIn(clsBankClient DestinationClient, float Amount,string UserName, string delim = "#//#")
	{
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + delim;
		LoginRecord += AccountNumber() + delim;
		LoginRecord += DestinationClient.AccountNumber() + delim;
		LoginRecord += to_string(Amount) + delim;
		LoginRecord += to_string(AccountBalance) + delim;
		LoginRecord += to_string(DestinationClient.AccountBalance) + delim;
		LoginRecord += UserName;
		
		return LoginRecord;
	}
	

	void _RegisterTransferLogIn(clsBankClient DestinationClient, float Amount, string UserName)
	{
		string DataLine = _PrepareTransferLogIn(DestinationClient, Amount, UserName);
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	static void _AddDataLine(string DataLine)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	void _AddNew()
	{
		_AddDataLine(_ConvertClientObjectToLine(*this));
	}
	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static vector <clsBankClient> _LoadClientDataFromFile()
	{
		fstream MyFile;
		string Line = "";
		vector <clsBankClient> vClientData;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClientData.push_back(Client);
			}
			MyFile.close();
		}
		return vClientData;
	}
	static void _SaveClientDataToFile(vector <clsBankClient>vClient)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::out);
		if (MyFile.is_open())
		{
			string DataLine = "";
			for (clsBankClient& C : vClient)
			{
				if (C.MakrForDeleted() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsBankClient>vClient = _LoadClientDataFromFile();
		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveClientDataToFile(vClient);
	}
public:
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance)
		: clsPerson(FirstName, LastName, Email, Phone)
	{
		_AccountNubmer = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
		_Mode = Mode;
	}
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	string AccountNumber()
	{
		return _AccountNubmer;
	}
	bool MakrForDeleted()
	{
		return _MarkForDelete;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static vector <clsBankClient> GetClientList()
	{
		
		return _LoadClientDataFromFile();
	}
	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		MyFile.open(FileName, ios::in);
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}
	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		if (IsClientExist(Client.AccountNumber()) && Client.PinCode == PinCode)
			return Client;
		else
			return _GetEmptyClientObject();
	}
	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		return !Client.IsEmpty();
	}
	enum enSaveResults{svFaildEmptyObject = 0, svSecceded = 1, svFaildAccountNumberExist = 3};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case clsBankClient::UpdateMode:
		{
			_Update();
			return enSaveResults::svSecceded;
		}
		case clsBankClient::AddNewMode:
			
			if(IsClientExist(AccountNumber()))
				return enSaveResults::svFaildAccountNumberExist;
			
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSecceded;
			}
		
		}
	}
	static clsBankClient GetAddNewClient(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}
	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}
	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
			return false;
			
		_AccountBalance -= Amount;	
		 Save();
		 return true;
	}
	bool Delete()
	{
		vector <clsBankClient>vClient = _LoadClientDataFromFile();
		
		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C._MarkForDelete = true;
					
				_SaveClientDataToFile(vClient);
				*this = _GetEmptyClientObject();
				return true;
			}
		}
		return false;
	}
	static double GetTotalBalance()
	{
		vector<clsBankClient>vClient = clsBankClient::GetClientList();
		double TotalBalance = 0;
		for (clsBankClient& Client : vClient)
		{
			TotalBalance += Client.AccountBalance;
		}
		return TotalBalance;
	}
	bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	{
		
		//return (Amount > AccountBalance) ? false : (Withdraw(Amount), DestinationClient.Deposit(Amount), true);
		
		if (Amount > AccountBalance)
			return false;
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLogIn(DestinationClient, Amount, UserName);
		return true;
	}
	struct stTransferLogRecord
	{
		string DateTime = "";
		string SourceAccount = "";
		string DestAccount = "";
		string UserName = "";
		float Amount = 0; 
		float SoureceBalance = 0;
		float DestBalance = 0;

	};
	static vector <stTransferLogRecord>GetLoginTransferList()
	{
		vector <stTransferLogRecord>vLoginTransferRecord;
		stTransferLogRecord LoginTransferRecord;
		string Line = "";
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open())
		{
			while (getline(MyFile, Line))
			{
				LoginTransferRecord = _ConvertLoginTransferLineToClientObject(Line);
				vLoginTransferRecord.push_back(LoginTransferRecord);
			}
			MyFile.close();
		}
		return vLoginTransferRecord;
	}
};

