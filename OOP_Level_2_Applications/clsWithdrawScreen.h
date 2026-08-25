#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsWithdrawScreen : protected clsScreen
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

	static string _ReadAccountNumber()
	{
		string AccountNumber = "";
		cout << "\nPlease Enter Account Number : ";
		AccountNumber = clsInputValidate<string>::ReadString();
		return AccountNumber;
	}

public:

	static void ShowWithdrawScreen()
	{
		_DrawScreenHeader("\t   Withdraw Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] Does not Exist.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double amount = 0;
		cout << "\nPlease Enter Withdraw Amount : ";
		//amount = clsInputValidate::ReadDoubleNumber();
		amount = clsInputValidate<double>::ReadNumberBetween(0,Client1.AccountBalance);


		cout << "\nAre you sure you want perform this transaction? Y/N : ";
		char answer = 'n';
		cin >> answer;

		if (answer == 'y'||answer == 'Y')
		{
			if (Client1.Withdraw(amount))
			{
				cout << "\nAmount Withdraw Successfully. -:)\n";
				cout << "\nNew Balance Is : " << Client1.AccountBalance;
			}
			else
			{
				cout << "\nCannot withdraw, Insuffecient Balance!\n";
				cout << "\nAmount to withdraw is: " << amount;
				cout << "\nYour Balance is: " << Client1.AccountBalance;
			}
		}
		else
		{
			cout << "\nOperation was Cancelled. (-:\n";
		}

	}

};

