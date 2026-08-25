#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsFindUserScreen : protected clsScreen
{

private:

	static void _PrintUser(clsUser User)
	{
		cout << "\n\tUser Card \n";
		cout << "_________________________________\n";
		cout << "\nFirst Name        : " << User.FirstName;
		cout << "\nLast Name         : " << User.LastName;
		cout << "\nFull Name         : " << User.FullName();
		cout << "\nEmail             : " << User.Email;
		cout << "\nPhone             : " << User.Phone;
		cout << "\nUser Name         : " << User.UserName;
		cout << "\nPassword          : " << User.Password;
		cout << "\nPermissions       : " << User.Permissions;
		cout << "\n_________________________________\n";
	}


public:

	static void ShowFindUserScreen()
	{
		system("cls");

		_DrawScreenHeader("\t Find User Screen");

		string UserName = "";
		cout << "\nPlease Enter User Name : ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name Is Not Found, Try Another One : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User = clsUser::Find(UserName);
		
		if (!User.IsEmpty())
		{
			cout << "\nUser Found. :-)\n";
		}
		else
		{
			cout << "\nUser Not Found. (-:\n";
		}
		_PrintUser(User);
	}


};

