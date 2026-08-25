#pragma once

#include<iostream>
#include<string>
#include"clsPerson.h"
#include"E:\Programming_Advices\Course#1_to_#13\Course_#10\Project_String_Library\Project_String_Library\clsString.h"
#include<vector>
#include<fstream>
#include"clsUtil.h"





class clsUser : public clsPerson
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	enMode _Mode;

	string _UserName;
	string _Password;
	int _Permissions;

	bool _MarkedForDelete = false;


	static clsUser _ConvertLineToUserObject(string Line, string Separator = "#//#")
	{
		vector<string>vUser;
		vUser = clsString::Split(Line, Separator);

		// here decrypt the password to print in the system
		return clsUser(enMode::UpdateMode, vUser[0], vUser[1], vUser[2], vUser[3], vUser[4],
			clsUtil::DecryptText(vUser[5]),stoi( vUser[6]));
	}

	static string _ConvertUserObjectToLine(clsUser User, string Separator = "#//#")
	{
		string DataLine = "";

		DataLine += User.FirstName + Separator;
		DataLine += User.LastName + Separator;
		DataLine += User.Email + Separator;
		DataLine += User.Phone + Separator;
		DataLine += User.UserName + Separator;
		//here we encrypt store to the encrypted Password not the real one.
		DataLine += clsUtil::EncryptText(User.Password) + Separator;
		DataLine += to_string (User.Permissions);

		return DataLine;
	}

	static clsUser _GetEmptyUserObject()
	{
		return clsUser(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector<clsUser>_LoadUserDataFromFile()
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in); // read mode
		  
		vector<clsUser>vUser;
		if (MyFile.is_open())
		{
			string line;
			while (getline(MyFile,line))
			{
				clsUser User = _ConvertLineToUserObject(line);
					vUser.push_back(User);
			}
				MyFile.close();
		}
		return vUser;
	}

	static void _SaveUserDataToFile(vector<clsUser>vUser)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out);

		string DataLine;
		if (MyFile.is_open())
		{
			for (clsUser U : vUser)
			{
				if (U.MarkedForDelete() == false)
				{
					DataLine = _ConvertUserObjectToLine(U);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
		

	}

	void _Update()
	{
		vector<clsUser>vUser;
		vUser = _LoadUserDataFromFile();

		for (clsUser &U : vUser)
		{
			if (U.UserName == _UserName)
			{
				U = *this;
				break;
			}
		}
		_SaveUserDataToFile(vUser);
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::out | ios::app);
		
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
		}
		MyFile.close();
	}

	void _AddNewUser()
	{
		_AddDataLineToFile(_ConvertUserObjectToLine(*this));
	}

	string _GetLoginDataLine()
	{
		string sep = "#//#";
		string DataLine = "";
		DataLine += clsDate::GetSystemDateTimeString() + sep;
		DataLine += UserName + sep;
		//here we encrypt to store the encrypted Password not the real one.
		DataLine += clsUtil::EncryptText(Password) + sep;
		DataLine += to_string(Permissions);

		return DataLine;
	}
	
	void _AddLoginDataToFile()
	{
		
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::out | ios::app);
		string LoginData = _GetLoginDataLine();
		
		if (MyFile.is_open())
		{
			MyFile << LoginData << endl;
			MyFile.close();
		}
	}

	struct stLoginRegisterRecord;
	static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string sep = "#//#")
	{

		stLoginRegisterRecord LoginData;
		vector<string>vUser;

		vUser = clsString::Split(Line, sep);

		LoginData._Date_Time = vUser[0];
		LoginData._UserName = vUser[1];
		// here decrypt the password to print in the system
		LoginData._Password = clsUtil::DecryptText(vUser[2]);
		LoginData._Permission =stoi( vUser[3]);
		return LoginData;
	}
	
	
	

public:

	enum enPermissions
	{
		eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
		pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64,
		pLoginRegister = 128
	};

	clsUser(enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName,
		string Password, int Permissions) :
		clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Password;
		_Permissions = Permissions;
	}

	struct stLoginRegisterRecord
	{
		string _Date_Time;
		string _UserName;
		string _Password;
		short _Permission;
	};

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	// property
	void setUserName(string UserName)
	{
		_UserName = UserName;
	}
	string getUserName()
	{
		return _UserName;
	}
	__declspec(property(get = getUserName, put = setUserName))string UserName;

	void setPassword(string Password)
	{
		_Password = Password;
	}
	string getPassword()
	{
		return _Password;
	}
	__declspec(property(get = getPassword, put = setPassword))string Password;

	void setPermissions(int Permissions)
	{
		_Permissions = Permissions;
	}
	int getPermissions()
	{
		return _Permissions;
	}
	__declspec(property(get = getPermissions, put = setPermissions))int Permissions;

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	static clsUser Find(string UserName)
	{
		fstream MyFile;
		MyFile.open("Users.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsUser User = _ConvertLineToUserObject(Line);
				if (User.UserName == UserName)
				{
					MyFile.close();
					return User;
				}
			}
		}
		return _GetEmptyUserObject();
	}

	static clsUser Find(string UserName, string Password)
	{
		clsUser User = Find(UserName);
		if (User.Password == Password)
		{
			return User;
		}
		else
		{
			return _GetEmptyUserObject();
		}
	}

	static bool IsUserExist(string UserName)
	{
		clsUser User = Find(UserName);

		return (!User.IsEmpty());
	}

	static clsUser GetAddNewUserObjcet(string UserName)
	{
		return clsUser(enMode::AddNewMode, "", "", "", "", UserName, "", 0);
	}

	enum enSaveResult { svFaildeEmptyObject = 0, svSucceded = 1, svFildeUserNameExists = 2 };
	enSaveResult Save()
	{
		switch (_Mode)
		{
		case enMode::EmptyMode:

			if (IsEmpty())
			{
				return enSaveResult::svFaildeEmptyObject;
			}
			
		case enMode::UpdateMode:
			_Update();
			return enSaveResult::svSucceded;
			
		case enMode::AddNewMode:
			
			if (clsUser::IsUserExist(_UserName))
			{
				return enSaveResult::svFildeUserNameExists;
			}
			else
			{
				_AddNewUser();

				_Mode = enMode::UpdateMode;
				return enSaveResult::svSucceded;
			}
			break;
		}
	}
	
	bool Delete()
	{
		vector<clsUser> vUser;
		vUser = _LoadUserDataFromFile();

   		for (clsUser &U : vUser)
		{
			if (U.UserName == UserName)
			{
				U._MarkedForDelete = true;
				break;
			}
		}
		_SaveUserDataToFile(vUser);
		*this = _GetEmptyUserObject();
		return true;
	}

	static vector<clsUser> GetUsersList()
	{
		return _LoadUserDataFromFile();
	}

	bool CheckAccessPermission(enPermissions Permission)
	{
		if (this->Permissions == enPermissions::eAll)
		{
			return true;
		}

		if ((Permission & this->Permissions) == Permission)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void RegisterLogin()
	{
		_AddLoginDataToFile();
	}
	
	static vector<stLoginRegisterRecord> GetLoginRegisterList()
	{
		vector<stLoginRegisterRecord>vLoginRegisterRecord;
		fstream MyFile;
		MyFile.open("LoginRegister.txt", ios::in);

		stLoginRegisterRecord LoginRegisterRecord;

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				LoginRegisterRecord = _ConvertLoginRegisterLineToRecord(Line);
				vLoginRegisterRecord.push_back(LoginRegisterRecord);
			}
			MyFile.close();
		}
		return vLoginRegisterRecord;
	}

	
};

