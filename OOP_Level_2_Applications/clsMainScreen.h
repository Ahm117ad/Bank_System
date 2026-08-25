#pragma once

#include<iostream>
#include<string>
#include<iomanip>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionScreen.h"
#include"clsManageUsersScreen.h"
#include"clsLoginRegisterListScreen.h"
#include"Global.h"
#include"clsCurrencyExchangeScreen.h"
// if you include LoginClass (circular referece) will happin 

class clsMainScreen : protected clsScreen
{
protected:

	enum enMainMenueOption
	{
		enShowAllClientList = 1, enShowAddNewClient = 2, enShowDeleteClient = 3,
		enShowUpdateClient = 4, enShowFindClient = 5, enShowTransactions = 6,
		enShowManageUsers = 7, enShowLoginRegister = 8, enShowCurrencyExchange = 9
		, enExit = 10
	};

	static short _ReadMainMenueOption()
	{
		short Choice;
		cout << clsUtil::Taps(2) <<"Choose What You Want To Do Between [1 To 10] : ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1, 10, "Invalide Number, Choose From 1 To 8 : ");
		return Choice;
	}
	// done
	static void _GoBackToMainMenue()
	{
		cout << clsUtil::Taps(2) << "Press any key to go back to main menue...";
		system("pause>0");
		ShowMainMenue();
	}
	// done
	static void _ShowAllClientsList()
	{
		clsClientListScreen::ShowClientsList();
	}
	// done
	static void _ShowAddNewClientScreen()
	{
		//cout << "Show Add New Client Will Be Here...\n";
		clsAddNewClientScreen::ShowAddNewClientScreen();
	}
	// sone
	static void _ShowDeleteClientScreen()
	{
		//cout << "Show Delete Client Will Be Here...\n";
		clsDeleteClientScreen::ShowDeleteClientScreen();
	}
	// done
	static void _ShowUpdateClientScreen()
	{
		clsUpdateClientScreen::ShowUpdateClientScreen();
	}
	// done
	static void _ShowFindClientScreen()
	{
		clsFindClientScreen::ShowFindClientScreen();
	}
	// done
	static void _ShowTransactionsScreen()
	{
		clsTransactionsScreen::ShowTransactionsMenue();
	}
	// done
	static void _ShowManageUsersScreen()
	{
		//cout << "\nShow manage users screen will be here...\n";
		clsManageUsersScreen::ShowManageUsersMenue();
	}

	static void _ShowLoginRegisterScreen()
	{
		//cout << "\nLogin Register Screen will be here...";
		clsLoginRegisterListScreen::ShowLoginRegisterScreen();
	}
	
	static void  _ShowCurrencyExchangeScreen()
	{
		//cout << "\nCurrency Exchange will be here...";
		clsCurrencyExchangeScreen::ShowCurrencyExchangeMenue();
	}

	// done
	static void _Logout()
	{
		CurrentUser = clsUser::Find("", "");
		// then it will go back to main function
	}

	static void _PerformMainMenueOptions(enMainMenueOption MainMenueOption)
	{
		switch (MainMenueOption)
		{
		case enMainMenueOption::enShowAllClientList:
			system("cls");
			_ShowAllClientsList();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enShowAddNewClient:
			system("cls");
			_ShowAddNewClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enShowDeleteClient:
			system("cls");
			_ShowDeleteClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enShowUpdateClient:
			system("cls");
			_ShowUpdateClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enShowFindClient:
			system("cls");
			_ShowFindClientScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enShowTransactions:
			system("cls");
			_ShowTransactionsScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enShowManageUsers:
			system("cls");
			_ShowManageUsersScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enShowLoginRegister:
			system("cls");
			_ShowLoginRegisterScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enShowCurrencyExchange:
			system("cls");
			_ShowCurrencyExchangeScreen();
			_GoBackToMainMenue();
			break;
		case enMainMenueOption::enExit:
			system("cls");
			_Logout();
			break;
		}
	}


public:

	static void ShowMainMenue()
	{
		system("cls");
		clsScreen::_DrawScreenHeader("\t\tMain Screen");

		cout << setw(37) << left << "" <<"=========================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "[1] Show Client List.\n";
		cout << setw(37) << left << "" << "[2] Add New.\n";
		cout << setw(37) << left << "" << "[3] Delete Client.\n";
		cout << setw(37) << left << "" << "[4] Update Client.\n";
		cout << setw(37) << left << "" << "[5] Find Client.\n";
		cout << setw(37) << left << "" << "[6] Transactions.\n";
		cout << setw(37) << left << "" << "[7] Manage Users.\n";
		cout << setw(37) << left << "" << "[8] Login Register.\n";
		cout << setw(37) << left << "" << "[9] Currency Exchange.\n";
		cout << setw(37) << left << "" << "[10] Logout.\n";
		cout << setw(37) << left << "" << "=========================================\n";


		_PerformMainMenueOptions((enMainMenueOption)_ReadMainMenueOption());
	}
		



};

