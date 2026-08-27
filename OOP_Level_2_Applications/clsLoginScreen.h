#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
#include"Global.h"
#include<stdlib.h>

class clsLoginScreen : protected clsScreen
{

private:

	static bool _Login()
	{
		bool LoginFailde = false;
		short FaildLoginCount = 0;
		string UserName, Password;

		do
		{
			if (LoginFailde)
			{
				FaildLoginCount++;
				cout << "\nInvalid UserName/Password!\n\n";
				
				cout << "You have " << (3 - FaildLoginCount) << " trial(s) to login.\n";
			}
			if (FaildLoginCount == 3)
			{
				cout << "\nYou are locked after 3 failed trials.\n";
				return false;
			}

			cout << "\nEnter User Name : ";
			UserName = clsInputValidate<string>::ReadString();

			cout << "\nEnter Password : ";
			Password = clsInputValidate<string>::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);

			LoginFailde = CurrentUser.IsEmpty();

		} while (LoginFailde);
		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();

	}


public:

	static bool ShhowLoginScreen()
	{
		system("cls");

		_DrawScreenHeader("\t Login Screen");
		return _Login();
	}

	
};

