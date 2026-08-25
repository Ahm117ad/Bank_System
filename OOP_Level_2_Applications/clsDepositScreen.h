#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"

class clsDepositScreen : protected clsScreen
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

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\t   Deposit Screen");

		string AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] does Not Exist. ln";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);

		double amount = 0;

		cout << "\nEnter Deposit Amount : ";
		amount = clsInputValidate<double>::ReadNumber();

		cout << "\nAre you sure you want to perform this transaction? Y/N : ";
		char answer = 'n';
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{

			Client1.Deposit(amount);
			cout << "\nAmount Deposited Successfully. :-)\n";
			cout << "\nNew Balance Is : " << Client1.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled. (-:\n";
		}

	}
	

};

