#pragma once

#include<iostream>
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsUtil.h"
#include"clsDepositScreen.h"
#include"clsWithdrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLogScreen.h"



class clsTransactionsScreen : protected clsScreen
{
private:

	enum enTransactionsOption
	{
		eDeposit = 1, eWithdraw = 2, eTotalBalances = 3, eTransfer = 4, eTransferLog = 5,
		eMainMenue = 6
	};
	
	static void _ShowDepositScreen()
	{
		//cout << "Deposit Screen will be here...";
		clsDepositScreen::ShowDepositScreen();
	}
	
	static void _ShowWithdrawScreen()
	{
		//cout << "Withdraw Screen will be here...";
		clsWithdrawScreen::ShowWithdrawScreen();
	}
	
	static void _ShowTotalBalancesScreen()
	{
		//cout << "Total Balances Screen will be here...";
		clsTotalBalancesScreen::ShowTotalBalancesScreen();
	}
	
	static void _ShowTransferScreen()
	{
		//cout << "\nTransfer Screen will be here...";
		clsTransferScreen::ShowTransferSacreen();
	}

	static void _ShowTransferLogScreen()
	{
		//cout << "\nTransfer Log Screen will be here...";
		clsTransferLogScreen::ShowTransferLogScreen();
	}

	static void _BackToTransactionsScreen()
	{
		cout << "\nPress any key to go back to Transactions menue...";
		system("pause>0");
		ShowTransactionsMenue();
	}
	
	static short _ReadTransactionsOption()
	{
		short Choice;
		cout << clsUtil::Taps(2) << "Choose What to do between [1 and 6]: ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1, 6,"Invalid Number, Choose between 1 and 4 : ");
		return Choice;
	}

	static void _PerformTransactionsMenue(enTransactionsOption TransactionsOption)
	{

		switch (TransactionsOption)
		{
		case enTransactionsOption::eDeposit:
		{
			system("cls");
			_ShowDepositScreen();
			_BackToTransactionsScreen();
			break;
		}
		case enTransactionsOption::eWithdraw:
		{
			system("cls");
			_ShowWithdrawScreen();
			_BackToTransactionsScreen();
			break; 
		}
		case enTransactionsOption::eTotalBalances:
		{
			system("cls");
			_ShowTotalBalancesScreen();
			_BackToTransactionsScreen();
			break;
		}

		case enTransactionsOption::eTransfer:
		{
			system("cls");
			_ShowTransferScreen();
			_BackToTransactionsScreen();
			break;
		}

		case enTransactionsOption::eTransferLog:
		{
			system("cls");
			_ShowTransferLogScreen();
			_BackToTransactionsScreen();
			break;
		}
		case enTransactionsOption::eMainMenue:
		{
			// break; (without these -> {} you need to write break;)
			// Do nothing here the main screen will handle it :-) ;
		}
			
		}

	}


public:

	static void ShowTransactionsMenue()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pTransactions))
		{
			return; // this will exit the function and it will not continue 
		}

		system("cls");
		_DrawScreenHeader("\t Transactions Screen");
		cout << endl;
		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\t Transactions Menue\n";
		cout << setw(37) << left << "" << "=========================================\n";

		cout << setw(37) << left << "" << "[1] Deposit.\n";
		cout << setw(37) << left << "" << "[2] Withdraw.\n";
		cout << setw(37) << left << "" << "[3] Total Balances.\n";
		cout << setw(37) << left << "" << "[4] Transfer.\n";
		cout << setw(37) << left << "" << "[5] Transfer Log.\n";
		cout << setw(37) << left << "" << "[6] Main Menue.\n";
		cout << setw(37) << left << "" << "=========================================\n";
		
		_PerformTransactionsMenue((enTransactionsOption)_ReadTransactionsOption());
	}

};

