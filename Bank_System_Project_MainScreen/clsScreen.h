#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class clsScreen
{
protected:
	static void _DrawScreenHeader(string Title, string subtitle = "")
	{
		cout << left << setw(40) << "" << "________________________________________\n" << endl;
		cout << setw(48) << "" << Title << endl;
		if (subtitle != "")
		{
			cout << setw(40)<< "" << subtitle << endl;
		}

		cout << setw(40) << "" << "________________________________________\n" << endl;
	}
	
};

