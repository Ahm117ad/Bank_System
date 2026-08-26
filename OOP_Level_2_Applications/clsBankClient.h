#pragma once

#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include"clsString.h"
#include"clsPerson.h"


class clsBankClient : public clsPerson
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DelelteMode = 3 };
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;


	static clsBankClient _ConvertLinetoClientObject(string Line, string Seperator = "#//#")
	{
		vector<string> vClientData;
		vClientData = clsString::Split(Line, Seperator); // split the line and add it to vector

		/*return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1], vClientData[2],
			vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));*/

		return clsBankClient(enMode::UpdateMode, vClientData.at(0), vClientData.at(1), vClientData.at(2),
			vClientData.at(3), vClientData.at(4), vClientData.at(5), stod(vClientData.at(6)));

	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string sep = "#//#")
	{
		string DataLine = "";
		DataLine += Client.FirstName + sep;
		DataLine += Client.LastName + sep;
		DataLine += Client.Email + sep;
		DataLine += Client.Phone + sep;
		DataLine += Client.AccountNumber() + sep;
		DataLine += Client.PinCode + sep;
		DataLine +=to_string (Client.AccountBalance);

		return DataLine;
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsBankClient>_LoadClientDataFromFile()
	{
		// to load from file you need a container like (vector)
		vector<clsBankClient>_vClient;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // open file in read mode

		if (MyFile.is_open())
		{
			string DataLine; // the line inside the file
			while (getline(MyFile,DataLine))
			{
				// function to convert line to object (to save it in object)
				clsBankClient Client = _ConvertLinetoClientObject(DataLine);
				_vClient.push_back(Client); // push the object inside vector
			}
			MyFile.close();
		}
		return _vClient; // vector full of data 
	}

	static void _SaveClientsDataToFile(vector<clsBankClient> vClient)
	{
		string DataLine; // to the store the line came from object
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out); // overrwite mode

		if (MyFile.is_open())
		{
			for (clsBankClient C : vClient) // ranged loop
			{
				if (C.MarkedForDelete() == false)
				{
					//we only write records that are not marked for delete
					DataLine = _ConvertClientObjectToLine(C); // convert every object to line
					MyFile << DataLine << endl; // add the line to the file
				}
			
			}
			MyFile.close();
		}
		
	}

	void _Update()
	{
		// update client in file
		vector<clsBankClient>vClient; // to store data from file
		vClient = _LoadClientDataFromFile(); // vector is full

		for (clsBankClient &C : vClient)
		{
			if (C.AccountNumber() == AccountNumber()) // search for account number
			{
				C = *this; // if found the correct data
				break;
			}
		}
		_SaveClientsDataToFile(vClient); // overrwite new data
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	string _PrepareTransferLogRecord(clsBankClient& DestinationClient, double Amount, string UserName, string Separator = "#//#")
	{

		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Separator;
		TransferLogRecord += AccountNumber() + Separator;
		TransferLogRecord += DestinationClient.AccountNumber() + Separator;
		TransferLogRecord += to_string(Amount) + Separator;
		TransferLogRecord += to_string(AccountBalance) + Separator;
		TransferLogRecord += to_string(DestinationClient.AccountBalance) + Separator;
		TransferLogRecord += UserName;
		
		return TransferLogRecord;
	}

	void _RegisterTransferLog(clsBankClient DestinationClient, double Amount, string UserName)
	{
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		string DataLine = _PrepareTransferLogRecord(DestinationClient, Amount, UserName);

		if (MyFile.is_open())
		{
			MyFile << DataLine << endl;
			MyFile.close();
		}
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogToRecord(string RecordLine, string Separator = "#//#")
	{
		
		stTransferLogRecord TransferLogRecord;

		
		vector<string>vClients;
		vClients = clsString::Split(RecordLine, Separator);
		TransferLogRecord.Date_Time = vClients[0];
		TransferLogRecord.SourceAccountNumber = vClients[1];
		TransferLogRecord.DestinationAccountNumber = vClients[2];
		TransferLogRecord.Amount = stod(vClients[3]);
		TransferLogRecord.SourceAccountBalance = stod(vClients[4]);
		TransferLogRecord.DestinationAccountBalance = stod(vClients[5]);
		TransferLogRecord.UserName = vClients[6];
		
		return TransferLogRecord;
	}


public:

	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode,
		float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	struct stTransferLogRecord
	{
		string Date_Time;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		double Amount;
		double SourceAccountBalance;
		double DestinationAccountBalance;
		string UserName;
	};

	// property
	string AccountNumber()
	{
		return _AccountNumber;
	}

	void setPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	string getPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = getPinCode, put = setPinCode))string PinCode;

	void setAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}
	float getAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = getAccountBalance, put = setAccountBalance))float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{
		vector<clsBankClient>vClient;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // read mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		clsBankClient Client = Find(AccountNumber);
		if (Client.PinCode == PinCode)
		{
			return Client;
		}
		else
		{
			return _GetEmptyClientObject();
		}
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client = Find(AccountNumber);
		return (!Client.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSuceeded = 1, svFaildAccountNumberExist = 2 };
	enSaveResults Save()
	{
		switch (_Mode)
		{
			{
		case enMode::EmptyMode:
			return enSaveResults::svFaildEmptyObject;
			}

			{
		case enMode::UpdateMode:

			_Update();

			return enSaveResults::svSuceeded;
			}

			{
		case enMode::AddNewMode:

			if (clsBankClient::IsClientExist(AccountNumber()))
			{
				return enSaveResults::svFaildAccountNumberExist;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSuceeded;
				
			}

			}
		}
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	bool Delete()
	{
		vector<clsBankClient>vClient;
		vClient = _LoadClientDataFromFile();

		for (clsBankClient &C : vClient)
		{
			if (C.AccountNumber()==_AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveClientsDataToFile(vClient);
		*this = _GetEmptyClientObject();
		return true;
	}
	
	static vector<clsBankClient> GetClientsList()
	{
		return _LoadClientDataFromFile();
	
	}
	
	static double GetTotalBalances()
	{
		vector<clsBankClient>vClients;
		vClients = _LoadClientDataFromFile();
		double TotalBalances = 0;
		for (clsBankClient C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
	}

	bool Transfer(double Amount, clsBankClient& DestinationClient, string UserName)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}
		
		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(DestinationClient, Amount, UserName);

		return true;
	}

	static vector<stTransferLogRecord> GetTransferLogList()
	{
		vector<stTransferLogRecord>vTransferLogRecord;

		stTransferLogRecord TransferLogRecord;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		string RecordLine;

		if (MyFile.is_open())
		{
			while (getline(MyFile,RecordLine))
			{
				TransferLogRecord = _ConvertTransferLogToRecord(RecordLine);
				vTransferLogRecord.push_back(TransferLogRecord);
			}
			MyFile.close();
		}
		return vTransferLogRecord;
	}



};

