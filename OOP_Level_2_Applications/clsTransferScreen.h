#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsUser.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

class clsTransferScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\tClient Card \n";
		cout << "_________________________________\n";
		
		cout << "\nFull Name         : " << Client.FullName();
		cout << "\nAcc. Number       : " << Client.AccountNumber();
		cout << "\nBalance           : " << Client.AccountBalance;
		cout << "\n_________________________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNumber;
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number not found, enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		return AccountNumber;
	}

	static double _ReadAmount(clsBankClient SourceClient)
	{
		double Amount;
		cout << "\nPlease Enter Transfer Amount : ";
		Amount = clsInputValidate<double>::ReadNumber();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available Balance, Enter another amount : ";
			Amount = clsInputValidate<double>::ReadNumber();
		}
		return Amount;
	}


public:

	static void ShowTransferSacreen()
	{

		system("cls");

		_DrawScreenHeader("\t Transfer Screen");


		cout << "\nPlease Enter Account Number To Transfer From : ";
		string TransferFrom = _ReadAccountNumber();
		clsBankClient SourceClient = clsBankClient::Find(TransferFrom);
		_PrintClient(SourceClient);

		cout << "\nPlease Enter Account Number To Transfer To : ";
		string TransferTo = _ReadAccountNumber();
		clsBankClient DestinationClient = clsBankClient::Find(TransferTo);
		_PrintClient(DestinationClient);		

		if (TransferFrom == TransferTo)
		{
			cout << "\nTransfer faild, because Source Client and Destination Client are the same.\n";
			return;
		}
	
		double Amount = _ReadAmount(SourceClient);

		char answer = 'n';
		cout << "\nAre you sure you want to do this transfer? [Y/N] ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient,CurrentUser.UserName))
			{
				cout << "\nTransfer Done Successfully :-)\n";
			}
			else
			{
				cout << "\nTransfer Faild (-:\n";
			}
		}
		else
		{
			return;
		}
		
		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

	}

};

