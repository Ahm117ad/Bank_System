#pragma once

#include<iostream>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"

class clsTransferLogScreen : protected clsScreen
{

private:

	static void _PrintTransferLog(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) <<  left << "" << "| " << left << setw(23) << TransferLogRecord.Date_Time;
		cout << "| " << left << setw(8) << TransferLogRecord.SourceAccountNumber;
		cout << "| " << left << setw(8) << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << left << setw(8) << TransferLogRecord.Amount;
		cout << "| " << left << setw(10) << TransferLogRecord.SourceAccountBalance;
		cout << "| " << left << setw(10) << TransferLogRecord.DestinationAccountBalance;
		cout << "| " << left << setw(8) << TransferLogRecord.UserName;
		
	}


public:

	static void ShowTransferLogScreen()
	{

		vector<clsBankClient::stTransferLogRecord>vTransferLog = clsBankClient::GetTransferLogList();

		string Title = "\t Transfer Log List Screen";
		string SubTitle = "\t (" + to_string (vTransferLog.size()) + ") Records";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acc";
		cout << "| " << left << setw(8) << "d.Acc";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(10) << "s.Blalance";
		cout << "| " << left << setw(10) << "d.Blalance";
		cout << "| " << left << setw(8) << "User";

		cout << endl;

		if (vTransferLog.size() == 0)
		{
			cout << "\n\t\t\tNo Records Available In The System...\n";
		}
		else
		{
			for (clsBankClient::stTransferLogRecord T : vTransferLog)
			{
				_PrintTransferLog(T);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t--------------------------------------------------------------------------------------";
		cout << "------------\n" << endl;

		
	}

};

