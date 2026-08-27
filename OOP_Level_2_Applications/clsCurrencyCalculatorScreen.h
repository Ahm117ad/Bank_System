#pragma once

#include<iostream>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card: ")
	{
		cout << Title << endl;
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();
		cout << "\n_____________________________\n";
	}

	static float _ReadAmount()
	{
		double Amount = 0;
		cout << "\nEnter Amount To Exchange : ";
		Amount = clsInputValidate<double>::ReadNumber();
		return Amount;
	}

	static clsCurrency _GetCurrency(string Messege)
	{
		string CurrencyCode;
		cout << Messege;
		CurrencyCode = clsInputValidate<string>::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency was not found, enter again : ";
			CurrencyCode = clsInputValidate<string>::ReadString();
		}
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCurrencyCalculatorResult(float Amount, clsCurrency C1, clsCurrency C2)
	{
		
		_PrintCurrencyCard(C1, "Convert From : ");
		float AmountInUSD = C1.ConvertToUSD(Amount);
		cout << Amount << " " << C1.CurrencyCode() << " = " << AmountInUSD << " USD" << endl;

		if (C2.CurrencyCode() == "USD")
		{
			return;
		}

		_PrintCurrencyCard(C2, "Convert To : ");
		float AmountInCurrency2 = C1.ConvertToAnotherCurrency(Amount, C2);
		cout << Amount << " " << C1.CurrencyCode() << " = " << AmountInCurrency2 << C2.CurrencyCode() << endl;
		
	}

	static float _ExchangeAmount(clsCurrency FromCurrency1, clsCurrency ToCurrency2, float Amount)
	{
		float Rate1 = FromCurrency1.Rate();
		float Rate2 = ToCurrency2.Rate();

		if (Rate2 == 1)
		{
			return Amount / Rate1;
		}

		else
		{
			return Amount / Rate1 * Rate2;
		}

	}

public:

	static void ShowCurrencyCalculatorScreen()
	{

		char Contiue = 'y';
		while (Contiue == 'y'|| Contiue == 'Y')
		{
			system("cls");
			_DrawScreenHeader("\t Currency Calculator Screen");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 : ");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 : ");

			float Amount = _ReadAmount();

			_PrintCurrencyCalculatorResult(Amount, CurrencyFrom, CurrencyTo);
			cout << "\nDo You Want To Perform Another Calculation? [Y] or [N] : ";
			cin >> Contiue;
		}

	}


};

