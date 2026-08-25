#pragma once

#include<iostream>
#include<iomanip>
#include"clsUser.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsDeleteUserScreen : protected clsScreen
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

	static void ShowDeleteUserScreen()
	{
		system("cls");

		_DrawScreenHeader("\t Delete User Screen");

		string UserName = "";
		cout << "\nEnter User Name : ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name IS Not Found, Try Again : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		if (UserName == "admin")
		{
			cout << "\nYou cannot delete this user.\n";
		}
		else
		{
			char answer = 'n';
			cout << "\nAre you sure you want to delete this user? [Y/N] : ";
			cin >> answer;

			if (answer == 'Y' || answer == 'y')
			{
				if (User1.Delete())
				{
					User1.Delete();
					cout << "\nUser Deleted Successfully :-)\n";
					_PrintUser(User1);
				}
				else
				{
					cout << "\nUser is not deleted (:-\n";
				}
			}
		}
	
	}

};

