#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsListUsersScreen.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{

private:

	enum enManageUsersOption
	{
		eListUsers=1,eAddNewUser=2,eDeleteUser=3,
		eUpdateUser=4,eFindUser=5,eMainMenue=6
	};
	// done
	static void _ShowListUsersScreen()
	{
		clsListUsersScreen::ShowUsersList();
	}
	// done
	static void _ShowAddNewUserScreen()
	{
		clsAddNewUserScreen::ShowAddNewUserScreen();
	}
	// 
	static void _ShowDeleteUserScreen()
	{
		clsDeleteUserScreen::ShowDeleteUserScreen();
	}
	// done
	static void _ShowUpdateUserScreen()
	{
		clsUpdateUserScreen::ShowUpdateUserScreen();
	}
	// done
	static void _ShowFindUserScreen()
	{
		clsFindUserScreen::ShowFindUserScreen();
	}

	static short _ReadManageUsersOption()
	{
		cout << clsUtil::Taps(2) << "Choose What To Do Between [1 and 6] : ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 6, "Invalide Number, Choose between [1 and 6].");
		return Choice;
	}

	static void _GoBackToManageUsersMenue()
	{
		cout << "\nPress any key to go back to manage users menue...";
		system("pause>0");
		ShowManageUsersMenue();
	}

	static void _PerformManageUsersMenueOption(enManageUsersOption ManageUsersOption)
	{
		switch (ManageUsersOption)
		{
		case enManageUsersOption::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOption::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOption::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOption::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOption::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersMenue();
			break;
		case enManageUsersOption::eMainMenue:
		{
			// do nothing here main menue will handle it :-)
		}

		}
	}

public:

	static void ShowManageUsersMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return; // this will exit the function and it will not continue 
		}

		system("cls");
		_DrawScreenHeader("\t Manage Users Screen");

		cout << endl;
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\t Manage Users Menue\n";
		cout << setw(37) << left << "" << "=========================================\n";

		cout << setw(37) << left << "" << "[1] Show Users List.\n";
		cout << setw(37) << left << "" << "[2] Add New User.\n";
		cout << setw(37) << left << "" << "[3] Delete User.\n";
		cout << setw(37) << left << "" << "[4] Update User.\n";
		cout << setw(37) << left << "" << "[5] Find User.\n";
		cout << setw(37) << left << "" << "[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=========================================\n";

		_PerformManageUsersMenueOption((enManageUsersOption)_ReadManageUsersOption());

	}

	

};

