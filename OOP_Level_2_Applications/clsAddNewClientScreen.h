#pragma once

#include<iostream>
#include<string>
#include<iomanip>
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsUtil.h"

class clsAddNewClientScreen : protected clsScreen
{
private:

	static void  _ReadClientInfo(clsBankClient & Client)
	{
		cout << "\n\t\t\t\tEnter First Name : ";
		Client.FirstName = clsInputValidate<string>::ReadString();

		cout << "\n\t\t\t\tEnter Last Name : ";
		Client.LastName = clsInputValidate<string>::ReadString();

		cout << "\n\t\t\t\tEnter Email : ";
		Client.Email = clsInputValidate<string>::ReadString();

		cout << "\n\t\t\t\tEnter Phone : ";
		Client.Phone = clsInputValidate<string>::ReadString();

		cout << "\n\t\t\t\tEnter Pin Code : ";
		Client.PinCode = clsInputValidate<string>::ReadString();

		cout << "\n\t\t\t\tEnter Account Balance : ";
		Client.AccountBalance = clsInputValidate<float>::ReadNumber();
	}

	static void _PrintClient(clsBankClient NewClient)
	{
		cout << "\n\tClient Card \n";
		cout << "_________________________________\n";
		cout << "\nFirst Name        : " << NewClient.FirstName;
		cout << "\nLast Name         : " << NewClient.LastName;
		cout << "\nFull Name         : " << NewClient.FullName();
		cout << "\nEmail             : " << NewClient.Email;
		cout << "\nPhone             : " << NewClient.Phone;
		cout << "\nAcc. Number       : " << NewClient.AccountNumber();
		cout << "\nPin Code          : " << NewClient.PinCode;
		cout << "\nBalance   : " << NewClient.AccountBalance;
		cout << "\n_________________________________\n";
	}

public:

	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
		{
			return; // this will exit the function and it will not continue 
		}
		
		string Title = "\t Add New Client Screen";

		clsScreen::_DrawScreenHeader(Title);

		cout << setw(8) << left << "" << "\t\t\t\tPlease Enter Account Number : ";
		string AccountNumber = clsInputValidate<string>::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{
			cout << setw(8) << left << "" << "\t\t\t\tEnter another account number, this one is used : ";
			AccountNumber = clsInputValidate<string>::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult;

		SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\n\t\t\t\tSave Faild, Because It's Empty.\n";
			break;

		case clsBankClient::enSaveResults::svFaildAccountNumberExist:
			cout << "\n\t\t\t\tSave Faild, Bcause The Account Number is used.\n";
			break;

		case clsBankClient::enSaveResults::svSuceeded:
			cout << "\n\t\t\t\tClient Successfully Saved. :-)\n";
			_PrintClient(NewClient);
			break;

		}


	}

};

