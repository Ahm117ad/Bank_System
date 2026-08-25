#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsFindCurrencyScreen : protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";
	}

	static short _ReadOption()
	{
		short Option;
		Option = clsInputValidate<short>::ReadNumberBetween(1, 2, "Invalide Number, Enter 1 or 2");
		return Option;
	}

	static void _ShowResult(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\nCurrency Was Not Found (-:\n";
		}
	}

public:

	static void ShowFindCurrencyScreen()
	{

		_DrawScreenHeader("\t Find Currency Screen");


		short Choice;
		cout << "\nFind By : Code [1] , Country [2] : ";
		Choice = _ReadOption();

		/*if (Choice == 1)
		{
			_CurrencyByCode();
			_PrintCurrencyCard(_CurrencyByCode());
		}
		else if (Choice == 2)
		{
			_CurrencyByCountry();
			_PrintCurrencyCard(_CurrencyByCountry());
		}*/

		if (Choice == 1)
		{
			string Code = "";
			cout << "\nEnter Currency Code : ";
			Code = clsInputValidate<string>::ReadString();
			Code = clsString::UpperAllString(Code);

			clsCurrency Currency1 = clsCurrency::FindByCode(Code);
			_ShowResult(Currency1);
		}
		else if (Choice == 2)
		{
			string Country = "";
			cout << "\nEnter Country Name : ";
			Country = clsInputValidate<string>::ReadString();
			Country = clsString::UpperAllString(Country);
			
			clsCurrency Currency2 = clsCurrency::FindByCountry(Country);

			_ShowResult(Currency2);
			
		}



	}

};

