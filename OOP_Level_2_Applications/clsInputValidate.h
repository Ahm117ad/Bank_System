#pragma once

#include<iostream>
#include"clsDate.h"
#include<string>

template<class T>
class clsInputValidate
{
public:

	static T ReadNumber(string ErrorMessege = "Invalide Number, Enter Again")
	{
		float Number = 0;
		while (!(cin >> Number))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessege << endl;
		}
		return Number;
	}

	static bool IsNumberBetween(T Number, T From, T To)
	{
		return (Number >= From && Number <= To ? true : false);
	}

	
	
	static T ReadNumberBetween(T From, T To, string ErrorMessege = "Invalide Number, enter again")
	{
		int Number = ReadNumber();
		while (!IsNumberBetween(Number,From,To))
		{
			cout << ErrorMessege << endl;
			Number = ReadNumber();
		}
		return Number;
	}

	

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		
		// Date>=From && Date<=To
		if ((clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From) &&
			clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To)))
		{
			return true;
		}

		// Date>=To && Date<=From
		if ((clsDate::IsDate1AfterDate2(Date, To) || clsDate::IsDate1EqualDate2(Date, To) &&
			clsDate::IsDate1BeforeDate2(Date, From) || clsDate::IsDate1EqualDate2(Date, From)))
		{
			return true;
		}
		return false;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::ValidateDate(Date);
	}

	static T ReadString()
	{
		string S = "";
		getline(cin >> ws, S);
		return S;
	}

	

};

