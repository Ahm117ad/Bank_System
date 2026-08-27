#pragma once

#include <iostream>
#include<ctime>
#include<cstdlib>
#include<string>
#include<array>
#include"clsDate.h"

class clsUtil
{

public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}

	static int RandomNumber(int From, int To)
	{
		int RandomNum = rand() % (To - From + 1) + From;
		return RandomNum;
	}

	static string EncryptText(string Text, short EncrptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char(int(Text[i] + EncrptionKey));
		}
		return Text;
	}

	static string DecryptText(string Text, short EncrptionKey = 2)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char(int(Text[i] - EncrptionKey));
		}
		return Text;
	}

	enum enCharType { SmallLetter = 1, CapitalLetter = 2, Digit = 3, Mix = 4, SpicialChar = 5};

	static char GetRandomChar(enCharType CharType)
	{

		if (CharType == Mix)
		{
			CharType = (enCharType)RandomNumber(1, 3);
		}

		switch (CharType)
		{
		case enCharType::SmallLetter:
			return char(RandomNumber(97, 122));
		case enCharType::CapitalLetter:
			return char(RandomNumber(65, 90));
		case enCharType::SpicialChar:
			return char(RandomNumber(33, 47));
		case enCharType::Digit:
			return char(RandomNumber(48, 57));
		default:
			break;
		}
	}

	static string GenerateWord (enCharType CharType, short Length)
	{
		string word = "";
		for (int j = 1; j <= Length; j++)
		{
			word = word + GetRandomChar(CharType);
		}
		return word;
	}
	static string GenerateKey()
	{
		string Key = "";
		Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key +  GenerateWord(enCharType::CapitalLetter, 4) + "-";
		Key = Key +  GenerateWord(enCharType::CapitalLetter, 4);
		return Key;
	}
	static void GenerateKeys(int NumberOfKeys)
	{
		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "Key [" << i << "] : ";
			cout << GenerateKey() << endl;
		}
	}

	static void FillArrayWithRandomNumber(int arr[], int arrLength)
	{
		
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = RandomNumber(1, 100);
		}
	}

	static void PrintArray(int ArrayElements[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			cout << ArrayElements[i] << " ";
		}
		cout << endl;
	}

	static int MaxElementOfArray(int arr[], int arrLength)
	{
		int MaxElement = 0;
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] > MaxElement)
				MaxElement = arr[i];
		}
		return MaxElement;
	}

	static int MinmumNumberInArray(int arr[], int arrLength)
	{
		int MinNumber = 0;
		MinNumber = arr[0];
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] < MinNumber)
				MinNumber = arr[i];
		}
		return MinNumber;
	}

	static int SumArray(int arr[], int arrLength)
	{
		int Sum = 0;
		for (int i = 0; i < arrLength; i++)
		{
			Sum += arr[i];
		}
		return Sum;
	}

	static float ArrayAverage(int arr[], int arrLength)
	{
		return (float)SumArray(arr, arrLength) / arrLength;
	}

	template<typename T> static T Swap(T &A, T &B)
	{
		T Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	
	static void SwapDate(clsDate& A, clsDate& B)
	{
		clsDate::SwapDates(A, B);
	}

	static void Swap(bool& A, bool& B)
	{
		bool Temp;
		Temp = A;
		A = B;
		B = Temp;
	}

	static void ShuffleArray(int arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
		
	}

	static void ShuffleArray(string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
		}
	}

	static void FillArrayWithKeys(string arr[], int arrLength)
	{
		for (int i = 0; i < arrLength; i++)
		{
			arr[i] = GenerateKey();
		}
	}

	static void PrintStringArray(string arr[], int arrLength)
	{
		cout << "Array Elements:\n";
		for (int i = 0; i < arrLength; i++)
		{
			cout << "\nArray [" << i << "] : " << arr[i] << endl;
		}
	}

	static short FindNumberPositionInArray(int number, int arr[], int arrLength)
	{
		/*This function will search for a number in array and return
		 its index, or return -1 if it does not exists*/
		for (int i = 0; i < arrLength; i++)
		{
			if (arr[i] == number)
				return i;
		}
		//if you reached here, this means the number is not found
		return -1;
	}

	static bool IsNumberInArray(int number, int arr[], int arrLength)
	{
		return FindNumberPositionInArray(number, arr, arrLength) != -1;
	}

	static string Taps(short NumberOfTaps)
	{
		string t = "";
		for (int i = 1; i <= NumberOfTaps; i++)
		{
			t = t + "\t";
			cout << t;
		}
		return t;
	}

	static string NumberToText(int Number)
	{
		if (Number == 0)
		{
			return "";
		}
		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "","One","Two","Three","Four","Five","six","Seven","Eight","Nine",
			"Ten","Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen",
			"Seventeen","Eighteen","Nineteen" };
			return arr[Number] + " ";
		}
		if (Number >= 20 && Number <= 99)
		{
			string arr[] = { "","","Twenty","Thirty","Fourty","Fifty","Sixty","Seventy",
			"Eighty","Ninety" };
			return arr[Number / 10] + " " + NumberToText(Number % 10);
		}
		if (Number >= 100 && Number <= 199)
		{
			return "One Hundred " + NumberToText(Number % 100);
		}
		if (Number >= 200 && Number <= 999)
		{
			return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
		}
		if (Number >= 1000 && Number <= 1999)
		{
			return "One Thousand " + NumberToText(Number % 1000);
		}
		if (Number >= 2000 && Number <= 999999)
		{
			return NumberToText(Number / 1000) + "Thousands " +
				NumberToText(Number % 1000);
		}
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Milione " + NumberToText(Number % 1000000);
		}
		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumberToText(Number / 1000000) + "Milions " +
				NumberToText(Number % 1000000);
		}
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Bilione " + NumberToText(Number % 1000000000);
		}
		else
		{
			return NumberToText(Number / 1000000000) + "Bilions " +
				NumberToText(Number % 1000000000);
		}
	}






};

