#pragma once

#include<iostream>
#include<string>
#include<iomanip>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsDeleteClientScreen : protected clsScreen
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

	static void ShowDeleteClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
		{
			return; // this will exit the function and it will not continue 
		}

		string Title = "\t  Delete Client Screen";

		_DrawScreenHeader(Title);

		string AccountNumber = "";
		cout << "\t\t\t\tPlease Enter Account Number To Delete : ";
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\n\t\t\t\tAccount Number is not found, Enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char answer = 'n';
		cout << "\n\t\t\t\tAre you sure you want to delete this client? Y/N. ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (Client.Delete())
			{
				Client.Delete();
				cout << "\nClient Deleted Successfully :-)\n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\nClient is not deleted.\n";
			}
		}
	}

};

