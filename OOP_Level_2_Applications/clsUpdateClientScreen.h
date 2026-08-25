#pragma once

#include<iostream>
#include<string>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{

private:

	enum enUpdateOption {
		eFirstName = 1, eLastName = 2, eEmail = 3, ePhone = 4,
		ePinCode = 5, eBalance = 6, eAll = 7
	};

	static void _ReadClientInfo(clsBankClient & Client)
	{
		cout << "\nEnter First Name : ";
		Client.FirstName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Last Name : ";
		Client.LastName = clsInputValidate<string>::ReadString();

		cout << "\nEnter Email : ";
		Client.Email = clsInputValidate<string>::ReadString();

		cout << "\nEnter Phone : ";
		Client.Phone = clsInputValidate<string>::ReadString();

		cout << "\nEnter Pin Code : ";
		Client.PinCode = clsInputValidate<string>::ReadString();

		cout << "\nEnter Account Balance : ";
		Client.AccountBalance = clsInputValidate<float>::ReadNumber();
	}

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\n\tClient Card \n";
		cout << "_________________________________\n";
		cout << "\nFirst Name        : " << Client.FirstName;
		cout << "\nLast Name         : " << Client.LastName;
		cout << "\nFull Name         : " << Client.FullName();
		cout << "\nEmail             : " << Client.Email;
		cout << "\nPhone             : " << Client.Phone;
		cout << "\nAcc. Number       : " << Client.AccountNumber();
		cout << "\nPin Code          : " << Client.PinCode;
		cout << "\nBalance           : " << Client.AccountBalance;
		cout << "\n_________________________________\n";
	}

	static void _PerformOptions(enUpdateOption Choice, clsBankClient &Client)
	{
		switch (Choice)
		{
		case clsUpdateClientScreen::eFirstName:
			cout << "\nEnter First Name : ";
			Client.FirstName = clsInputValidate<string>::ReadString();
			break;
		case clsUpdateClientScreen::eLastName:
			cout << "\nEnter Last Name : ";
			Client.LastName = clsInputValidate<string>::ReadString();
			break;
		case clsUpdateClientScreen::eEmail:
			cout << "\nEnter Email : ";
			Client.Email = clsInputValidate<string>::ReadString();
			break;
		case clsUpdateClientScreen::ePhone:
			cout << "\nEnter Phone : ";
			Client.Phone = clsInputValidate<string>::ReadString();
			break;
		case clsUpdateClientScreen::ePinCode:
			cout << "\nEnter Pin Code : ";
			Client.PinCode = clsInputValidate<string>::ReadString();
			break;
		case clsUpdateClientScreen::eBalance:
			cout << "\nEnter Account Balance : ";
			Client.AccountBalance = clsInputValidate<float>::ReadNumber();
			break;
		case clsUpdateClientScreen::eAll:
			_ReadClientInfo(Client);
			break;
		}

		
	}

	static short _WhatToUpdate()
	{
		short Choice;
		cout << "What Do You Want To Update?\n";
		cout << "|[1] First Name.\n";
		cout << "|[2] Last Name.\n";
		cout << "|[3] Email.\n";
		cout << "|[4] Phone.\n";
		cout << "|[5] Pin Code.\n";
		cout << "|[6] Balance.\n";
		cout << "|[7] All.\n";
		cout << "|Choose between 1 and 7 : ";
		Choice = clsInputValidate<short>::ReadNumberBetween(1, 7);

		return Choice;
	}

public:

	static void ShowUpdateClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClient))
		{
			return; // this will exit the function and it will not continue 
		}

		_DrawScreenHeader("\t Update Client Screen");

		string AccountNumber = "";
		cout << "\nEnter Account Number To Update : ";
		AccountNumber = clsInputValidate<string>::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found, Enter another one : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		char answer = 'n';

		cout << "\nAre You Sure You Want To Update This Client? Y/N :  ";
		cin >> answer;
		if (answer == 'y' || answer == 'Y')
		{
			cout << "\tUpdate Client Info : \n";
			cout << "_________________________________\n";

			_PerformOptions(enUpdateOption(_WhatToUpdate()), Client);
			//_ReadClientInfo(Client);

			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case clsBankClient::svFaildEmptyObject:
				cout << "\nUpdate Faild, It's Empty Object.\n";
				break;
			case clsBankClient::svSuceeded:
				cout << "\nClient Updated Successfully. :-)\n";
				_PrintClient(Client);
				break;

			}
		}
	}

};

