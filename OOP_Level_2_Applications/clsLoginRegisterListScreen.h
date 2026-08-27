#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"

class clsLoginRegisterListScreen : protected clsScreen
{

private:

	static void _PrintUserRecordLine(clsUser::stLoginRegisterRecord LoginRegisterRecord)
	{
		
		cout << setw(8) << left << "" << "| " << left << setw(35) << LoginRegisterRecord._Date_Time;
		cout << "| " << left << setw(20) << LoginRegisterRecord._UserName;
		cout << "| " << left << setw(20) << LoginRegisterRecord._Password;
		cout << "| " << left << setw(10) << LoginRegisterRecord._Permission;
	}

public:

	static void ShowLoginRegisterScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return; // this will exit the function and it will not continue 
		}

		system("cls");

		
		vector<clsUser::stLoginRegisterRecord>vUsers = clsUser::GetLoginRegisterList();



		string Title = "\t Login Register List";
		string SubTitle = "\t (" + to_string(vUsers.size()) + ") Record(s)";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "User Name";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;

		if (vUsers.size() == 0)
		{
			cout << "\n\t\t\t\tNo Logins Available In The System.\n ";
		}
		else
		{
			for (clsUser::stLoginRegisterRecord U : vUsers)
			{
				_PrintUserRecordLine(U);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;
	}



};

