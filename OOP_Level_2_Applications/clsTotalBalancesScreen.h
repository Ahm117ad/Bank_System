#pragma once

#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include<iomanip>
#include"clsUtil.h"

class clsTotalBalancesScreen : protected clsScreen
{

private:

	static void _PrintClientRecord(clsBankClient Client)
	{

		cout << setw(25) << left << "" << "|" << left << setw(15) << Client.AccountNumber();
		cout << "|" << setw(25) << left << Client.FullName();
		cout << "|" << setw(12) << left << Client.AccountBalance;
		
	}

public:

	static void ShowTotalBalancesScreen()
	{

		vector<clsBankClient>vClient = clsBankClient::GetClientsList();
		
		string Title = "\t   Balances List Screen";
		string SubTitle = "\t   (" + to_string(vClient.size()) + ") Client(s)";
		_DrawScreenHeader(Title, SubTitle);

		double TotalBalances = 0;
		TotalBalances = clsBankClient::GetTotalBalances();

		cout << setw(25) << left << "\n\t\t-------------------------------------------------";
		cout << "------------\n" << endl;

		cout << setw(25) << left << "" << "|" << left << setw(15) << "Account Number";
		cout << "|" << left << setw(25) << "Client Name";
		cout << "|" << left << setw(12) << "Balance";
		
		cout << setw(25) << left << "\n\t\t-------------------------------------------------";
		cout << "------------\n" << endl;

		if (vClient.size() == 0)
		{
			cout << "\t\tNo Clients Available.\n";
		}
		else
		{
			for (clsBankClient C : vClient)
			{
				_PrintClientRecord(C);
				cout << endl;
			}
		}

		cout << setw(25) << left << "\n\t\t-------------------------------------------------";
		cout << "------------\n" << endl;

		cout << setw(8) << left << "" << "\t\t Total Balances is : [" << TotalBalances << "].\n";
		cout << setw(8) << left << "" << "\t\t(" << clsUtil::NumberToText(TotalBalances) << ")\n";

	}

};

