#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "clsPerson.h";
#include "D:\Prorgramming_device\programing\OOP_Applications\InputValidate\InputValidate\clsInputValidate.h";
#include "D:\Prorgramming_device\programing\OOP_Couse\String_Library_Project\String_Library_Project\clsString.h";
//#include "clsBankClient.h";
const string User = "Users.txt";
class clsUser : public clsPerson
{
	string _UserName = "";
	string _Passeword = "";
	int _Permissions = 0;
	enum enMode{EmptyMode = 1, UpdateMode = 2, AddNewUser = 3};
	enMode _Mode;
	bool _MarkedForDelete = false;

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}
	static clsUser _ConvertLineToUserObject(string Line, string delim = "#//#")
	{
		vector <string>vUserData = clsString::SplitString(Line, delim);
		return clsUser(enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2], vUserData[3], vUserData[4],
			vUserData[5], stoi(vUserData[6]));
	}
	static string _ConvertUserObjectToLine(clsUser User, string delim = "#//#")
	{
		string UserRecord = "";
		UserRecord += User.FirstName + delim;
		UserRecord += User.LastName+ delim;
		UserRecord += User.Email + delim;
		UserRecord += User.Phone + delim;
		UserRecord += User.UserName + delim;
		UserRecord += User.Passeword + delim;
		UserRecord += to_string(User.Permissions);
		return UserRecord;
	}
	static vector <clsUser>_LoadUserDataFromFile()
	{
		vector <clsUser>vUser;
		fstream MyFile;
		MyFile.open(User, ios::in);
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				vUser.push_back(User);
			}
			MyFile.close();
		}
		return vUser;
	}
	static void _SaveUserDataToFile(vector <clsUser>vUser)
	{
		fstream MyFile;
		MyFile.open(User, ios::out);
		if (MyFile.is_open())
		{
			string DataLine = "";
			for (clsUser& U : vUser)
			{
				if (U.MarkForDelete() == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}
	void _Update()
	{
		vector <clsUser>vUser = _LoadUserDataFromFile();
		for (clsUser& U : vUser)
		{
			if (U.UserName == UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUserDataToFile(vUser);
	}
	void _AddUserLineToFile(string UserLine)
	{
		fstream MyFile;
		MyFile.open(User, ios::out | ios::app);
		if (MyFile.is_open())
		{
			MyFile << UserLine << endl;
			MyFile.close();
		}
	}
	void _AddNewUser()
	{
		_AddUserLineToFile(_ConvertUserObjectToLine(*this));
	}
public:
	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Passeword, int Permission) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Passeword = Passeword;
		_Permissions = Permission;
	}
	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}
	bool MarkForDelete()
	{
		return _MarkedForDelete;
	}
	void SetPasseword(string Passeword)
	{
		_Passeword = Passeword;
	}
	string GetPasseword()
	{
		return _Passeword;
	}
	_declspec(property(get = GetPasseword, put = SetPasseword)) string Passeword;

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	string GetUserName()
	{
		return _UserName;
	}
	_declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	void SetPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int GetPermissions()
	{
		return _Permissions;
	}
	_declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

	static vector<clsUser>GetUserList()
	{
		return _LoadUserDataFromFile();
	}
	static clsUser Find(string UserName)
	{
		/*vector <clsUser>vUser = _LoadUserDataFromFile();
		for (clsUser& U : vUser)
		{
			if (U.UserName == UserName)
			{
				return U;
			}
		}
		return _GetEmptyUserObject();*/
		fstream MyFile;
		MyFile.open(User, ios::in);
		if (MyFile.is_open())
		{
			string Line = "";
			while (getline(MyFile, Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
			MyFile.close();
		}
		return _GetEmptyUserObject();
	}
	static clsUser Find(string UserName, string Passeword)
	{
		clsUser User = clsUser::Find(UserName);
		if (!User.IsEmpty() && User.Passeword == Passeword)
			return User;
		else
			return _GetEmptyUserObject();
	}
	static bool IsUserExist(string UserName)
	{
		clsUser User = clsUser::Find(UserName);
		return !User.IsEmpty();
	}
	bool Delete()
	{
		vector <clsUser>vUser = _LoadUserDataFromFile();
		for (clsUser& U : vUser)
		{
			if (U.UserName == UserName)
			{
				U._MarkedForDelete = true;
				_SaveUserDataToFile(vUser);
				*this = _GetEmptyUserObject();
				return true;
			}
		}
		return false;
	}
	static clsUser GetAddNewUser(string UserName)
	{
		return clsUser(enMode::AddNewUser, "", "", "", "", UserName, "", 0);
	}
	enum enPermissions{eAll = -1, pListClient = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8,
	                    pFindClient = 16, pTransactions = 32, pManageUser = 64};

	enum enSaveResults{svFaildEmptyObject = 1, svSecceded = 2, svFaildUserNameExist = 3};
	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsUser::EmptyMode:
			return enSaveResults::svFaildEmptyObject;

		case clsUser::UpdateMode:
		{
			_Update();
			return enSaveResults::svSecceded;
		}
		case clsUser::AddNewUser:
			if (clsUser::IsUserExist(UserName))
			{
				return enSaveResults::svFaildUserNameExist;
			}
			else
			{
				_AddNewUser();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSecceded;
			}
		}
	}
	bool CheckAccessPermission(enPermissions Permission)
	{
		return ((this->Permissions == enPermissions::eAll) || ((this->Permissions & Permission) == Permission));
		/*if (this->Permissions == enPermissions::eAll)
			return true;
		if ((this->Permissions & Permission) == Permission)
			return true;
		return false;*/
	}
};

