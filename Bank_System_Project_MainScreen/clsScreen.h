#pragma once
#include <iostream>
#include <iomanip>
#include "Global.h"
#include "clsUser.h";

using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string subtitle = "")
	{
		cout << left << setw(40) << "" << "__________________________________________________\n" << endl;
		cout << setw(48) << "" << Title << endl;
		if (subtitle != "")
		{
			cout << setw(40)<< "" << subtitle << endl;
		}

		cout << setw(40) << "" << "__________________________________________________\n" << endl;
	}
	static bool CheckAccessRight(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			_DrawScreenHeader("Access Denied Contact your Admin");
			return false;
		}
		return true;
	}
};

