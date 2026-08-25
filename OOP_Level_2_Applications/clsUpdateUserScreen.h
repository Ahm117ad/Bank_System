#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsUpdateUserScreen : protected clsScreen
{

private:

	enum enUpdateOption
	{
		eFirstName = 1, eLastName = 2, eEmail = 3, ePhone = 4,
		ePassord = 5, ePermissions = 6, eAll = 7
	};

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

	static void _ReadUserInfo(clsUser & User)
	{
		cout << "\nEnter First Name : ";
		User.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Last Name  : ";
		User.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email      : ";
		User.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone      : ";
		User.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter Password   : ";
		User.Password = clsInputValidate<string>::ReadString();

		cout << "\nEnter Pemissions : ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static short _WhatToUpdate()
	{
		short Choice;
		cout << "What Do You Want To Update?\n";
		cout << "|[1] First Name.\n";
		cout << "|[2] Last Name.\n";
		cout << "|[3] Email.\n";
		cout << "|[4] Phone.\n";
		cout << "|[5] Password.\n";
		cout << "|[6] Permissinos.\n";
		cout << "|[7] All.\n";
		cout << "|Choose between 1 and 7 : ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1, 7);

		return Choice;
	}

	static void _PerformUpdateOption(enUpdateOption Choice, clsUser &User)
	{
		switch (Choice)
		{
		case enUpdateOption::eFirstName:
			cout << "\nEnter New First Name : ";
			User.FirstName = clsInputValidate<string>::ReadString();
			break;
		case enUpdateOption::eLastName:
			cout << "\nEnter New Last Name : ";
			User.LastName = clsInputValidate<string>::ReadString();
			break;
		case enUpdateOption::eEmail:
			cout << "\nEnter New Email : ";
			User.Email = clsInputValidate<string>::ReadString();
			break;
		case enUpdateOption::ePhone:
			cout << "\nEnter New Phone : ";
			User.Phone = clsInputValidate<string>::ReadString();
			break;
		case enUpdateOption::ePassord:
			cout << "\nEnter New Password : ";
			User.Password = clsInputValidate<string>::ReadString();
			break;
		case enUpdateOption::ePermissions:
			if (User.UserName == "admin")
			{
				cout << "\nYou Cant Change This User's Permissions...";
				return;
			}
			else
			{
				_ReadPermissionsToSet();
			}
			
			break;
		case enUpdateOption::eAll:
			_ReadUserInfo(User);
			break;
		}
	}

	static int _ReadPermissionsToSet()
	{
		int Permission = 0;
		char answer = 'n';
		cout << "\nDo You Want To Give Full Acces? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			return clsUser::enPermissions::eAll;
		}

		cout << "\nDo You Want To Give Acces To:\n";
		cout << "Show Client List? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Permission += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Permission += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Permission += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Permission += clsUser::enPermissions::pUpdateClient;
		}

		cout << "\nFind Client? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Permission += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Permission += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Permission += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nLogin Register? Y/N. ";
		cin >> answer;
		if (answer == 'Y' || answer == 'y')
		{
			Permission += clsUser::enPermissions::pLoginRegister;
		}

		if (Permission == 255)
		{
			return -1;
		}

		return Permission;
	}

public:

	static void ShowUpdateUserScreen()
	{
		system("cls");

		_DrawScreenHeader("\t Update User Screen");

		string UserName = "";
		cout << "\nPlease Enter User Name : ";
		UserName = clsInputValidate<string>::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name Is Not Found, Enter Another One : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);
		_PrintUser(User1);

		char answer = 'n';
		cout << "\nAre you sure you want to update this user? [y/n] : ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			cout << "\nUpdate User Info : ";
			cout << "\n______________________________\n";

			//_ReadUserInfo(User1);
			_PerformUpdateOption(enUpdateOption(_WhatToUpdate()), User1);


			clsUser::enSaveResult SaveResult;
			SaveResult = User1.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResult::svSucceded:
				cout << "\nUser Info Updated Successfully :-)\n";
				_PrintUser(User1);
				break;
			case clsUser::enSaveResult::svFaildeEmptyObject:
				cout << "\nError, Update Failde (-:\n";
				break;
			}
		}
		


	}


};

