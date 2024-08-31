#include <iostream>
#include "clsLoginScreen.h";

int main()
{
    system("color 5f");
	while (clsLoginScreen::ShowLoginScreen());

	/*while (true)
	{
		if (!clsLoginScreen::ShowLoginScreen()) {
			break;
		}
	}*/
	return 0;
    system("pause > 0");
}