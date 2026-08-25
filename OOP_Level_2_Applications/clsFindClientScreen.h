#pragma once

#include<iostream>
#include<string>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsFindClientScreen : protected clsScreen
{
private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\tClient Card \n";
		cout << "_________________________________\n";
		cout << "\nFirst Name        : " << Client.FirstName;
		cout << "\nLast Name         : " << Client.LastName;
		cout << "\nFull Name         : " << Client.FullName();
		cout << "\nEmail             : " << Client.Email;
		cout << "\nPhone             : " << Client.Phone;
		cout << "\nAcc. Number       : " << Client.AccountNumber();
		cout << "\nPin Code          : " << Client.PinCode;
		cout << "\nBalance           : " << Client.AccountBalance;
		cout << "\n_________________________________\n";
	}


public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient))
		{
			return; // this will exit the function and it will not continue 
		}

		_DrawScreenHeader("\t Find Client Screen ");

		string AccountNumber = "";
		cout << "\nEnter Account Number : ";
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number not found, enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		
		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient was not found (:-\n";
		}
		_PrintClient(Client);

	}


};

