#pragma once

#include<iostream>
#include"clsString.h"
#include<fstream>
#include<vector>
#include<string>


class clsCurrency
{

private:

	enum enMode {EmptyMode = 0, UpdateMode = 1};
	enMode _Mode;

	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;

	bool _MarkedForDelete = false;

	static clsCurrency _ConvertLineToCurrencyObject(string Line, string Separator = "#//#")
	{
		vector<string>vCurrency;
		vCurrency = clsString::Split(Line, Separator);

		return clsCurrency(enMode::UpdateMode, vCurrency[0], vCurrency[1], vCurrency[2],
			stod(vCurrency[3]));
	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{
		string CurrencyLine = "";
		CurrencyLine += Currency.Country() + Separator;
		CurrencyLine += Currency.CurrencyCode() + Separator;
		CurrencyLine += Currency.CurrencyName() + Separator;
		CurrencyLine += to_string(Currency.Rate());
		
		return CurrencyLine;
	}

	static vector<clsCurrency> _LoadCurrencysFromFile()
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		vector<clsCurrency>vCurrency;

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				vCurrency.push_back(Currency);
			}
			MyFile.close();
		}
		return vCurrency;
	}
	
	static void _SaveCurrencyDataToFile(vector<clsCurrency>vCurrencys)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);
		string Line;

		if (MyFile.is_open())
		{
			for (clsCurrency C : vCurrencys)
			{
				Line = _ConvertCurrencyObjectToLine(C);
				MyFile << Line << endl;
			}
			MyFile.close();
		}

	}

	void _Update()
	{
		vector<clsCurrency>vCurrencys;
		vCurrencys = _LoadCurrencysFromFile();

		for (clsCurrency &C : vCurrencys)
		{
			if (C.CurrencyCode() == CurrencyCode())
			{
				C = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrencys);
	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}


public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode,
		string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	static vector <clsCurrency> GetAllUSDRates()
	{

		return _LoadCurrencysFromFile();

	}

	string Country()
	{
		return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float Rate)
	{
		_Rate = Rate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}

	static clsCurrency FindByCode(string TargetCode)
	{
		TargetCode = clsString::UpperAllString(TargetCode);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile,Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.CurrencyCode()) == TargetCode)
				{
					MyFile.close();
					return Currency;
				}

			}
		}
		
		
		return _GetEmptyCurrencyObject();
	}

	static clsCurrency FindByCountry(string CountryName)
	{
		CountryName = clsString::UpperAllString(CountryName);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLineToCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == CountryName)
				{
					MyFile.close();
					return Currency;
				}

			}
		}
		return _GetEmptyCurrencyObject();
	}

	static bool IsCurrencyExist(string Code)
	{
		clsCurrency C1 = FindByCode(Code);
		
		return (!C1.IsEmpty());
	}

	static vector<clsCurrency> GetCurrencysList()
	{
		return _LoadCurrencysFromFile();
	}

	bool MarkForDelete()
	{
		return _MarkedForDelete;
	}

	

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}

	float ConvertToAnotherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);
		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());
	}

};

