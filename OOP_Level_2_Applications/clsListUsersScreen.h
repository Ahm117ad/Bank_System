#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"

class clsListUsersScreen : protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser Users)
	{
		cout << setw(8) << left << "" << "| " << left << setw(15) << Users.UserName;
		cout << "| " << left << setw(20) << Users.FullName();
		cout << "| " << left << setw(12) << Users.Phone;
		cout << "| " << left << setw(20) << Users.Email;
		cout << "| " << left << setw(10) << Users.Password;
		cout << "| " << left << setw(12) << Users.Permissions;
	}



public:

	static void ShowUsersList()
	{

		system("cls");

		vector<clsUser>vUsers = clsUser::GetUsersList();

		string Title = "\t List Users Screen";
		string SubTitle = "\t Users List (" + to_string(vUsers.size()) + ") User(s)";

		_DrawScreenHeader(Title,SubTitle);

		cout << setw(8) << left << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "User Name";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permissions";
		cout << setw(8) << left << "" << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;

		if (vUsers.size() == 0)
		{
			cout << "\n\t\t\t\tNo Users Available In The System.\n ";
		}
		else
		{
			for (clsUser U : vUsers)
			{
				_PrintUserRecordLine(U);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;
	}
};

