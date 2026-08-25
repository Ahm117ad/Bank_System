#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"


class clsListCurrenciesScreen : protected clsScreen
{

private:

	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{
		cout << setw(8) << left << "" << "| " << left << setw(26) << Currency.Country();
		cout <<  "| " << left << setw(5) << Currency.CurrencyCode();
		cout <<  "| " << left << setw(39) << Currency.CurrencyName();
		cout <<  "| " << left << setw(8) << Currency.Rate();
	
	}

public:

	static void ShowListCurrencies()
	{
		vector<clsCurrency>vCurrencies;
		vCurrencies = clsCurrency::GetCurrencysList();
		string Title = "\t List Currencies Screen";
		string SubTitle = "(" + to_string(vCurrencies.size()) + ") Currency.";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;

		cout << setw(8) << left << "" << "| " << setw(26) << left << "Country";
		cout << "| " << left << setw(5) << "Code";
		cout << "| " << left << setw(39) << "Name";
		cout << "| " << left << setw(8) << "Rate/(1$)";
		cout << setw(8) << left << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;
		
		if (vCurrencies.size() == 0)
		{
			cout << "\n\t\t\t\t\tNo Currencies Available In The System...\n";
		}
		else
		{
			for (clsCurrency &C : vCurrencies)
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}
		}

		cout << setw(8) << left << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;
	}


};

