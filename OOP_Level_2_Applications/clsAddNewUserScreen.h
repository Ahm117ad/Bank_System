#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"

class clsAddNewUserScreen : protected clsScreen
{

private:

	static void _ReadNewUserInfo(clsUser& User)
	{
		cout << "Enter First Name : ";
		User.FirstName = clsInputValidate<string>::ReadString();

		cout << "Enter Last Name  : ";
		User.LastName = clsInputValidate<string>::ReadString();

		cout << "Enter Email      : ";
		User.Email = clsInputValidate<string>::ReadString();

		cout << "Enter Phone      : ";
		User.Phone = clsInputValidate<string>::ReadString();

		cout << "Enter Password   : ";
		User.Password = clsInputValidate<string>::ReadString();

		cout << "Enter Permissions: ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static void _PrintUser(clsUser NewUser)
	{
		cout << "\n\tUser Card \n";
		cout << "_________________________________\n";
		cout << "\nFirst Name        : " << NewUser.FirstName;
		cout << "\nLast Name         : " << NewUser.LastName;
		cout << "\nFull Name         : " << NewUser.FullName();
		cout << "\nEmail             : " << NewUser.Email;
		cout << "\nPhone             : " << NewUser.Phone;
		cout << "\nUser Name         : " << NewUser.UserName;
		cout << "\nPassword          : " << NewUser.Password;
		cout << "\nPermissions       : " << NewUser.Permissions;
		cout << "\n_________________________________\n";
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

	static void ShowAddNewUserScreen()
	{
		system("cls");

		_DrawScreenHeader("\t Add New User Screen");

		string UserName = "";

		cout << setw(8) << left << "" << "\t\t\t\tPlease Enter User Name : ";
		UserName = clsInputValidate<string>::ReadString();

		while (clsUser::IsUserExist(UserName))
		{
			cout << setw(8) << left << "" << "\t\t\t\tUser Name Is Already Used, Choose Another One : ";
			UserName = clsInputValidate<string>::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObjcet(UserName);
		_ReadNewUserInfo(NewUser);

		clsUser::enSaveResult SaveResult;
		SaveResult = NewUser.Save();

		switch (SaveResult)
		{
		case clsUser::enSaveResult::svSucceded:
			cout << "\n\t\t\t\tUser Successfully Added. :-)\n";
			_PrintUser(NewUser);
			break;
		case clsUser::enSaveResult::svFildeUserNameExists:
			cout << "\n\t\t\t\tSave Faild, Bcause The User Name is used.\n";
			break;

		case clsUser::enSaveResult::svFaildeEmptyObject:
			cout << "\n\t\t\t\tSave Faild, Because Object Is Empty.\n";
			break;
		}
	}
};

