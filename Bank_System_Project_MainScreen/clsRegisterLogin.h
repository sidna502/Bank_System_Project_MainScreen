#pragma once
#include "Global.h"
#include "clsScreen.h"

class clsRegisterLogin : protected clsScreen
{
	static string _ConvertRegisterUserLoginToLine(string delim = "#//#")
	{
		string UserRecord = "";
		UserRecord += clsDate::DateToString(clsDate()) + delim;
		UserRecord += CurrentUser.UserName + delim;
		UserRecord += CurrentUser.Passeword + delim;
		UserRecord += to_string(CurrentUser.Permissions);
		return UserRecord;
	}
	static void _SaveDataToFile()
	{
		string DataLine = _ConvertRegisterUserLoginToLine();
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}
	
public:

	static void RegisterLoginInLogFile()
	{
		_SaveDataToFile();
	}
};

