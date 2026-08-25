#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsListCurrenciesScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{

private:
	enum enCurrencyOption
	{
		eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4,
		eMainMenue = 5
	};

	static void _ShowListCurrenciesScreen()
	{
		//cout << "\nList Currencies will be here...";
		clsListCurrenciesScreen::ShowListCurrencies();
	}

	static void _ShowFindCurrencyScreen()
	{
		//cout << "\nFind Currency will be here...";
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateRateScreen()
	{
		//cout << "\nUpdate Rate will be here...";
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		//cout << "\nCurrency calculator will be here...";
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _BackToCurrencyExchangeMenue()
	{
		cout << "\nPress any key to go back to Currency Exchange Menue...";
		system("pause>0");
		ShowCurrencyExchangeMenue();
	}

	static short _ReadCurrencyExchangeOption()
	{
		cout << clsUtil::Taps(2) << "Choose What To Do Between [1 and 5] : ";
		short Choice = clsInputValidate<short>::ReadNumberBetween(1, 5, "Invalide Number, Choose between [1 and 5].");
		return Choice;
	}

	static void _PerformCurrencyExchangeOption(enCurrencyOption CurrencyExchangeOption)
	{
		switch (CurrencyExchangeOption)
		{
		case enCurrencyOption::eListCurrencies:
			system("cls");
			_ShowListCurrenciesScreen();
			_BackToCurrencyExchangeMenue();
			break;
		case enCurrencyOption::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_BackToCurrencyExchangeMenue();
			break;
		case enCurrencyOption::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_BackToCurrencyExchangeMenue();
			break;
		case enCurrencyOption::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_BackToCurrencyExchangeMenue();
			break;
		case enCurrencyOption::eMainMenue:
		{
			// do nothing here main menue will handle it :-)
		}
		}
	}


public:

	static void ShowCurrencyExchangeMenue()
	{
		system("cls");

		_DrawScreenHeader("\t Currency Exchange Screen");

		cout << endl;
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\t Currency Exchange Menue\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "[1] List Currencies.\n";
		cout << setw(37) << left << "" << "[2] Find Currency.\n";
		cout << setw(37) << left << "" << "[3] Update Rate.\n";
		cout << setw(37) << left << "" << "[4] Currency Calculater.\n";
		cout << setw(37) << left << "" << "[5] Main Menue.\n";
		cout << setw(37) << left << "" << "=========================================\n";

		_PerformCurrencyExchangeOption(enCurrencyOption(_ReadCurrencyExchangeOption()));
	}




};

