#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsUpdateCurrencyScreen : protected clsScreen
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

	static float _ReadRate()
	{
		cout << "\nEnter New Rate : ";

		float NewRate = 0;
		NewRate = clsInputValidate<float>::ReadNumber();
		return NewRate;
	}


public:

	static void ShowUpdateCurrencyScreen()
	{

		_DrawScreenHeader("\t Update Currerncy Screen");

		string Code = "";
		cout << "\nPlease Enter Currency Code : ";
		Code = clsInputValidate<string>::ReadString();
		Code = clsString::UpperAllString(Code);
		while (!clsCurrency::IsCurrencyExist(Code))
		{
			cout << "\nCurrency Code is not exist, enter another one : ";
			Code = clsInputValidate<string>::ReadString();
		}
		float Rate;
		clsCurrency Currency = clsCurrency::FindByCode(Code);
		_PrintCurrencyCard(Currency);

		char answer = 'n';
		cout << "\nAre you sure you want to update this rate? ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{

			Currency.UpdateRate(_ReadRate());// finisfed
			cout << "\nRate Updated Successfully :-)\n";
			_PrintCurrencyCard(Currency);
		}

	}

};

