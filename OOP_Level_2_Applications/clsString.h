#pragma once

#include<iostream>
#include<string>
#include<vector>

using namespace std;


class clsString
{
private:
	string _Value;
	static char _InvertLetterCase(char Ch)
	{
		return isupper(Ch) ? tolower(Ch) : toupper(Ch);
	}


public:

	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}



	void setValue(string Value)
	{
		_Value = Value;
	}

	string getValue()
	{
		return _Value;
	}
	__declspec(property(get = getValue, put = setValue))string Value;

	static short Length(string S)
	{
		return S.length();
	}
	short Length()
	{
		return _Value.length();
	}

	static short CountWords(string S1)
	{
		short counter = 0;
		string delim = " "; // delimiter

		short pos = 0;
		string sWord; //define a string variable

		// use find() function to get the position of the delimiters 
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				counter++;
			}
			S1.erase(0, pos + delim.length());
		}
		if (S1 != "")
		{
			counter++;
		}
		return counter;
	}
	short CountWords()
	{
		return CountWords(_Value);
	}

	static void FirstLetterOFEachWord(string S)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < S.length(); i++)
		{
			if (S[i] != ' ' && isFirstLetter)
			{
				cout << S[i] << endl;
			}
			isFirstLetter = S[i] == ' ' ? true : false;
		}
	}
	void FirstLetterOFEachWord()
	{
		FirstLetterOFEachWord(_Value);
	}

	static string FirstLetterToUpper(string Word)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < Word.length(); i++)
		{
			if (Word.at(i) != ' ' && isFirstLetter)
			{
				Word.at(i) = toupper(Word.at(i));
			}
			isFirstLetter = Word.at(i) == ' ' ? true : false;
		}
		return Word;
	}
	void FirstLetterToUpper()
	{
		_Value = FirstLetterToUpper(_Value);
	}

	static string FirstLetterToLower(string Word)
	{
		bool isFirstLetter = true;
		for (int i = 0; i < Word.length(); i++)
		{
			if (Word.at(i) != ' '&& isFirstLetter)
			{
				Word.at(i) = tolower(Word.at(i));
			}
			isFirstLetter = Word.at(i) == ' ' ? true : false;
		}
		return Word;
	}
	void FirstLetterToLower()
	{
		_Value = FirstLetterToLower(_Value);
	}

	static string UpperAllString(string Word)
	{
		for (int i = 0; i < Word.length(); i++)
		{
			Word.at(i) = toupper(Word.at(i));
		}
		return Word;
	}
	void UpperAllString()
	{
		_Value = UpperAllString(_Value);
	}

	static string LowerAllString(string Word)
	{
		for (int i = 0; i < Word.length(); i++)
		{
			Word.at(i) = tolower(Word.at(i));
		}
		return Word;
	}
	void LowerAllString()
	{
		_Value = LowerAllString(_Value);
	}


	static string InvertAllLetters(string Word)
	{
		for (int i = 0; i < Word.length(); i++)
		{
			Word[i] = _InvertLetterCase(Word[i]);
		}
		return Word;
	}
	void InvertAllLetters()
	{
		_Value = InvertAllLetters(_Value);
	}

	// CountLetters!!!!
	enum enWhatToCount { SmallLetters = 0, CapitalLetters = 1, All = 3 };
	static short CountLetters(string S, enWhatToCount WhatToCount = enWhatToCount::All)
	{
		int Counter = 0;
		if (WhatToCount == enWhatToCount::All)
		{
			return S.length();
		}

		for (int i = 0; i < S.length(); i++)
		{

			if (WhatToCount == enWhatToCount::SmallLetters && islower(S[i]))
			{
				Counter++;
			}

			if (WhatToCount == enWhatToCount::CapitalLetters && isupper(S[i]))
			{
				Counter++;
			}

		}

		return Counter;
	}
	short CountLetters()
	{
		return CountLetters(_Value);
	}

	static short CountSpecicficLetter(string str, char Letter, bool MatchCase = true)
	{
		short counter = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (MatchCase)
			{
				if (Letter == str[i])
				{
					counter++;
				}
			}
			else
			{
				if (tolower(str[i]) == tolower(Letter))
					counter++;
			}
		}
		return counter;
	}

	short CountSpecicficLetter(char Letter, bool MachCase = true)
	{
		return CountSpecicficLetter(_Value, Letter, MachCase);
	}

	static bool IsVowle(char Letter)
	{
		Letter = tolower(Letter);

		return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));
	}
	static short CountVowle(string str)
	{
		short counter = 0;
		for (short i = 0; i < str.length(); i++)
		{
			if (IsVowle(str[i]))
			{
				counter++;
			}
		}
		return counter;
	}
	short CountVowle()
	{
		return CountVowle(_Value);
	}

	static void PrintEachWordInString(string S1)
	{
		string delim = " "; // delimiter
		cout << "\nYour string words are:\n\n";
		short pos = 0;
		string sWord; //define a string variable

		// use find() function to get the position of the delimiters 
		while ((pos = S1.find(delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				cout << sWord << endl;
			}
			S1.erase(0, pos + delim.length()); //erase() until positon and move to next word
		}
		if (S1 != "")
		{
			cout << S1 << endl; // print the last word of the string.
		}
	}
	void PrintEachWordInString()
	{
		PrintEachWordInString(_Value);
	}

	// !!!!!!!!!!
	static vector<string>Split(string str, string delimitir)
	{
		vector<string>vString; // to store the words
		short pos = 0; // position of the delimitir
		string sWord; // temp word

		while ((pos = str.find(delimitir)) != std::string::npos)
		{
			sWord = str.substr(0, pos); // sWord = from the beginig of sWord to delimitir
			//if (sWord != "")
			//{
			vString.push_back(sWord);
			//}

			str.erase(0, pos + delimitir.length()); // delete and move to the next
		}
		if (str != "") // if there is no delimitir
		{
			vString.push_back(str); // add the last word
		}
		return vString;
	}
	

	static string TrimLeft(string st)
	{
		for (short i = 0; i < st.length(); i++)
		{
			if (st[i] != ' ')
				return st.substr(i, st.length() - 1);
		}
		return "";
	}
	void TrimLeft()
	{
		_Value = TrimLeft(_Value);
	}

	static string TrimRight(string st)
	{
		for (short i = st.length() - 1; i >= 0; i--)
		{
			if (st[i] != ' ')
				return st.substr(0, i + 1);
		}
		return "";
	}
	void TrimRight()
	{
		_Value = TrimRight(_Value);
	}

	static string Trim(string st)
	{
		return (TrimLeft(TrimRight(st)));
	}
	void Trim()
	{
		_Value = Trim(_Value);
	}


	static string JoinString(vector<string>vString, string sep = " ")
	{
		string word = "";
		for (string &S : vString)
		{
			word = word + S + sep;
		}
		return word.substr(0, word.length() - sep.length());
	}

	static string JoinString(string arrString[], short Length, string sep)
	{
		string word = "";
		for (short i = 0; i < Length; i++)
		{
			word = word + arrString[i] + sep;
		}
		return word.substr(0, word.length() - sep.length());
	}


	static string ReverseEachWordInString(string str)
	{
		string st = "";
		vector<string>vString;
		vString = Split(str, " ");
		vector<string>::iterator iter = vString.end();
		while (iter != vString.begin())
		{
			--iter;
			st += *iter + " ";
		}
		st = st.substr(0, st.length() - 1);
		return st;
	}
	void ReverseEachWordInString()
	{
		_Value = ReverseEachWordInString(_Value);
	}

	static string ReplaceWord(string str, string OldWord, string NewWord)
	{
		short pos = str.find(OldWord);

		while (pos != std::string::npos)
		{
			str = str.replace(pos, OldWord.length(), NewWord);
			pos = str.find(OldWord);
		}
		return str;
	}
	string ReplaceWord(string OldWord, string NewWord)
	{
		return ReplaceWord(_Value, OldWord, NewWord);
	}

	static string ReplaceWordByCoustum(string str, string Old, string New, bool MatchCase = true)
	{
		vector<string>vString;
		vString = Split(str, " ");
		for (string &s : vString)
		{
			if (MatchCase)
			{
				if (s == Old)
				{
					s = New;
				}
			}
			else
			{
				if (LowerAllString(s) == LowerAllString(Old))
				{
					s = New;
				}
			}
		}

		return JoinString(vString, " ");
	}
	string ReplaceWordByCoustum(string OldWord, string NewWord, bool MatchCase = true)
	{
		return ReplaceWordByCoustum(_Value, OldWord, NewWord, MatchCase);
	}

	static string RemovePunctuation(string str)
	{
		string st = "";
		for (short i = 0; i < str.length(); i++)
		{
			if (!ispunct(str[i]))
			{
				st += str[i];
			}
		}
		return st;
	}
	void RemovePunctuation()
	{
		_Value = RemovePunctuation(_Value);
	}



};


