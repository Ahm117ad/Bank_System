#pragma once

#include<iostream>
#include<iomanip>
#include"clsDate.h"
#include"clsUtil.h"
#include"clsUser.h"
#include<ctime>
#include"Global.h"

using namespace std;

class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title, string SubTitle = "")
	{
		cout << clsUtil::Taps(2) << "____________________________________\n";
		cout << clsUtil::Taps(2)<< "   " << Title << endl;
		
		if (SubTitle != "")
		{
			cout << clsUtil::Taps(2)<< "   " << SubTitle << endl;
		}
		cout << clsUtil::Taps(2) << "____________________________________\n";
		cout << endl;

		cout << clsUtil::Taps(2) << "User : " << CurrentUser.UserName << endl;
		cout << clsUtil::Taps(2) << "Date : " << clsDate::DateToString(clsDate()) << endl;
		
		cout << clsUtil::Taps(2) << "------------------------------------\n";
	}

	static bool CheckAccessRights(clsUser::enPermissions Permission)
	{
		if (!CurrentUser.CheckAccessPermission(Permission))
		{
			cout << clsUtil::Taps(2) << "-----------------------------------------\n\n";
			cout << clsUtil::Taps(2) << "Access Denied! Please Contact Your Admin.\n";
			cout << clsUtil::Taps(2) << "-----------------------------------------\n\n";
			return false;
		}
		else
		{
			return true;
		}
	}

};

