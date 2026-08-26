#pragma once


#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include"clsString.h"


using namespace std;

class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;

public:

	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;

	}
	clsDate(string sDate)
	{

		vector<string>vDate;

		vDate = clsString::Split(sDate, "/");
		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}
	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}
	clsDate(short NumberOfDays, short Year)
	{
		clsDate Date1 = GetDateFromDayOrderInYear(NumberOfDays, Year);
		_Day = Date1.Day;
		_Month = Date1.Month;
		_Year = Date1.Year;

	}

	void setDay(short Day)
	{
		_Day = Day;
	}
	short getDay()
	{
		return _Day;
	}
	__declspec(property(get = getDay, put = setDay)) short Day;

	void setMonth(short Month)
	{
		_Month = Month;
	}
	short getMonth()
	{
		return _Month;
	}
	__declspec(property(get = getMonth, put = setMonth)) short Month;

	void setYear(short Year)
	{
		_Year = Year;
	}
	short getYear()
	{
		return _Year;
	}
	__declspec(property(get = getYear, put = setYear)) short Year;

	static bool ValidateDate(clsDate Date)
	{
		if (Date.Day < 1)
			return false;
		return (Date.Day <= NumberOfDaysInMonth(Date.Month, Date.Year));
	}

	bool ValidateDate()
	{
		return ValidateDate(*this);
	}


	static bool IsLeapYear(short Year)
	{
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
	}
	bool IsLeapYear()
	{
		return IsLeapYear(_Year);
	}

	static int DaysInYear(short Year)
	{
		return IsLeapYear(Year) ? 366 : 365;
	}
	int DaysInYear()
	{
		return DaysInYear(_Year);
	}

	static int HoursInYear(short Year)
	{

		return DaysInYear(Year) * 24;
	}
	int HoursInYear()
	{
		return HoursInYear(_Year);
	}

	static int MinutesInYear(short Year)
	{
		return HoursInYear(Year) * 60;
	}
	int MinutesInYear()
	{
		return MinutesInYear(_Year);
	}

	static int SecondsInYear(short Year)
	{
		return  MinutesInYear(Year) * 60;
	}
	int SecondsInYear()
	{
		return SecondsInYear(_Year);
	}

	static void PrintYearDetails(int Year)
	{
		cout << "\nNumber Of Days in year    [" << Year << "] is : " << DaysInYear(Year) << endl;

		cout << "\nNumber Of Hours in year   [" << Year << "] is : " << HoursInYear(Year) << endl;

		cout << "\nNumber Of Minutes in year [" << Year << "] is : " << MinutesInYear(Year) << endl;

		cout << "\nNumber Of Seconds in year [" << Year << "] is : " << SecondsInYear(Year) << endl;
	}
	void PrintYearDetails()
	{
		PrintYearDetails(_Year);
	}

	static short NumberOfDaysInMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
		{
			return 0;
		}
		if (Month == 2)
		{
			return IsLeapYear(Year) ? 29 : 28;
		}
		short arr31Days[7] = { 1,3,5,7,8,10,12 };
		for (short i = 1; i <= 7; i++)
		{
			if (arr31Days[i - 1 == Month])
				return 31;
		}
		return 30;
	}
	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static int HoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}
	int HoursInMonth()
	{
		return HoursInMonth(_Month, _Year);
	}

	static int MinutesInMonth(short Month, short Year)
	{
		return HoursInMonth(Month, Year) * 60;
	}
	int MinutesInMonth()
	{
		return MinutesInMonth(_Month, _Year);
	}

	static int SecondsInMonth(short Month, short Year)
	{
		return MinutesInMonth(Month, Year) * 60;
	}
	int SecondsInMonth()
	{
		return SecondsInMonth(_Month, _Year);
	}

	static void PrintMonthDetails(short Month, short Year)
	{
		cout << "\nNumber Of Days in Month    [" << Month << "] is :" << NumberOfDaysInMonth(Month, Year) << endl;

		cout << "\nNumber Of Hours in Month   [" << Month << "] is :" << HoursInMonth(Month, Year) << endl;

		cout << "\nNumber Of Minutes in Month [" << Month << "] is :" << MinutesInMonth(Month, Year) << endl;

		cout << "\nNumber Of Seconds in Month [" << Month << "] is :" << SecondsInMonth(Month, Year) << endl;
	}
	void PrintMonthDetails()
	{
		PrintMonthDetails(_Month, _Year);
	}

	static int DayOfWeakOrder(short Day, short Month, short Year)
	{
		int a = (14 - Month) / 12;
		int y = Year - a;
		int m = Month + (12 * a) - 2;
		int d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
		return d;
	}
	int DayOfWeakOrder()
	{
		return DayOfWeakOrder(_Day, _Month, _Year);
	}
	//!!!!!!!!!!!
	static string DayOfWeakName(int NameOfDay)
	{
		string arrDayOfWeak[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayOfWeak[NameOfDay];
	}
	string DayOfWeakName()
	{
		return DayOfWeakName(DayOfWeakOrder(_Day, _Month, _Year));
	}

	static void PrintDayOfWeakOrder(short Day, short Month, short Year)
	{
		short Result = DayOfWeakOrder(Day, Month, Year);
		cout << "\nDate \t\t: " << Day << "/" << Month << "/" << Year << endl;
		cout << "Day Order \t: " << Result << endl;
		cout << "Day Name \t: " << DayOfWeakName(Result);
	}
	void PrintDayOfWeakOrder()
	{
		PrintDayOfWeakOrder(_Day, _Month, _Year);
	}

	static string MonthShortName(short Month)
	{
		string MonthName[] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep",
			"Oct","Nov","Dec" };
		return MonthName[Month];
	}
	string MonthShortName()
	{
		return MonthShortName(_Month);
	}

	static void PrintMonthCalender(short Month, short Year)
	{
		short NumberOfDays;

		// Index of day from 0 to 6
		short Current = DayOfWeakOrder(1, Month, Year);
		NumberOfDays = NumberOfDaysInMonth(Month, Year);

		// Print current month name
		printf("\n __________________%s__________________ \n\n",
			MonthShortName(Month).c_str());

		// print the columns
		printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		// print spaces
		short i;
		for (i = 0; i < Current; i++)
			printf("     ");

		for (short j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}

		printf("\n _______________________________________ \n");
	}
	void PrintMonthCalender()
	{
		PrintMonthCalender(_Month, _Year);
	}

	static void PrintYearCalender(short Year)
	{
		printf(" _______________________________________\n");
		printf("\n          Calender - %d\n", Year);
		printf(" _______________________________________\n");

		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalender(i, Year);
		}
	}
	void PrintYearCalender()
	{
		PrintYearCalender(_Year);
	}

	static short NumberOfDaysFrom1stDayOfYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;
		for (short i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}
	short NumberOfDaysFrom1stDayOfYear()
	{
		return NumberOfDaysFrom1stDayOfYear(_Day, _Month, _Year);
	}
	// !!!
	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;

		Date.Year = Year;
		Date.Month = 1;

		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date.Month, Year);

			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	static clsDate DateAfterAddDays(short Days, clsDate &Date)
	{
		short RemainingDays = Days + NumberOfDaysFrom1stDayOfYear(Date.Day, Date.Month, Date.Year);

		short MonthDays = 0;

		Date.Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInMonth(Date.Month, Date.Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date.Month++;
				if (Date.Month > 12)
				{
					Date.Month = 1;
					Date.Year++;
				}
			}
			else
			{
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day) ? true : false;
	}
	bool IsDate1EqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date.Day == NumberOfDaysInMonth(Date.Month, Date.Year));
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(_Month);
	}

	static clsDate AddOneDay(clsDate & Date)
	{

		if (IsLastDayInMonth(Date) && IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else if (IsLastDayInMonth(Date) && !IsLastMonthInYear(Date.Month))
		{
			Date.Day = 1;
			Date.Month++;
		}
		else
		{
			Date.Day++;
		}

		return Date;
	}
	void AddOneDay()
	{
		*this = AddOneDay(*this);
	}

	static void SwapDates(clsDate & Date1, clsDate & Date2)
	{
		clsDate TempDate;
		/*TempDate.Year = Date1.Year;
		TempDate.Month = Date1.Month;
		TempDate.Day = Date1.Day;

		Date1.Year = Date2.Year;
		Date1.Month = Date2.Month;
		Date1.Day = Date2.Day;

		Date2.Year = TempDate.Year;
		Date2.Month = TempDate.Month;
		Date2.Day = TempDate.Day;*/
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}
	void SwapDates(clsDate Date2)
	{
		SwapDates(*this, Date2);
	}

	static int GetDiffrenceInDays(clsDate Date1, clsDate Date2, bool EndDay = false)
	{
		int Days = 0;
		short SwapFlagValue = 1;

		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			// Swap Date
			SwapDates(Date1, Date2);
			SwapFlagValue = -1;
		}


		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Date1 = AddOneDay(Date1);
			Days++;
		}

		return EndDay ? ++Days * SwapFlagValue : Days * SwapFlagValue;
	}
	int GetDiffrenceInDays(clsDate Date2, bool EndDay = false)
	{
		return GetDiffrenceInDays(*this, Date2, EndDay);
	}

	static clsDate GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		return clsDate(Day, Month, Year);
	}


	static clsDate IncteaseDateByXDay(clsDate &Date, short Days)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	void IncteaseDateByXDay(short Days)
	{
		IncteaseDateByXDay(*this, Days);
	}

	static clsDate IncreaseDateByOneWeak(clsDate & Date)
	{
		short Counter = 1;
		do
		{
			Date = AddOneDay(Date);
			Counter++;
		} while (Counter <= 7);
		return Date;
	}
	void IncreaseDateByOneWeak()
	{
		IncreaseDateByOneWeak(*this);
	}

	static clsDate IncreaseDateByXWeaks(clsDate & Date, short Weaks)
	{
		short Counter = 1;
		do
		{
			Date = IncreaseDateByOneWeak(Date);
			Counter++;
		} while (Counter <= Weaks);
		return Date;
	}
	void IncreaseDateByXWeaks(short Weaks)
	{
		IncreaseDateByXWeaks(*this, Weaks);
	}

	static clsDate IncreaseDateByOneMonth(clsDate & Date)
	{
		if (Date.Month == 12)
		{
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
		}

		short NumberOfDays = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDays)
		{
			Date.Day = NumberOfDays;
		}

		return Date;
	}
	void IncreaseDateByOneMonth()
	{
		IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXMonths(clsDate & Date, short Months)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}

		return Date;
	}
	void IncreaseDateByXMonths(short Months)
	{
		IncreaseDateByXMonths(*this, Months);
	}

	static clsDate IncreaseDateByOneYear(clsDate & Date)
	{
		Date.Year++;
		return Date;
	}
	void IncreaseDateByOneYear()
	{
		IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(clsDate & Date, short Years)
	{
		Date.Year += Years;
		return Date;
	}
	void IncreaseDateByXYears(short Years)
	{
		IncreaseDateByXYears(*this, Years);
	}

	static clsDate IncreaseDateByOneDecade(clsDate & Date)
	{
		// Increase One Decade
		Date.Year += 10;
		return Date;
	}
	void IncreaseDateByOneDecade()
	{
		IncreaseDateByOneDecade(*this);
	}

	static clsDate IncreaseDateByXDecades(clsDate & Date, short Decade)
	{

		Date.Year += Decade * 10;
		return Date;
	}
	void IncreaseDateByXDecades(short Decade)
	{
		IncreaseDateByXDecades(*this, Decade);
	}

	static clsDate IncreaseDateByOneCentury(clsDate & Date)
	{
		Date.Year += 100;
		return Date;
	}
	void IncreaseDateByOneCentury()
	{
		IncreaseDateByOneCentury(*this);
	}

	static clsDate IncraeseDateByOneMillennium(clsDate & Date)
	{
		Date.Year += 1000;
		return Date;
	}
	void IncraeseDateByOneMillennium()
	{
		IncraeseDateByOneMillennium(*this);
	}

	// Decrement ====================================

	static clsDate DecreaseDateByOneDay(clsDate & Date)
	{
		if (Date.Day != 1)
		{
			Date.Day--;
		}
		else if (Date.Day == 1 && Date.Month != 1)
		{
			Date.Month--;
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		}
		else if (Date.Day == 1 && Date.Month == 1)
		{
			Date.Month = 12;
			Date.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
			Date.Year--;
		}

		return Date;
	}
	void DecreaseDateByOneDay()
	{
		DecreaseDateByOneDay(*this);
	}

	static clsDate DecreaseDateByXDays(clsDate & Date, short Day)
	{
		for (short i = Day; i >= 1; i--)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByXDays(short Day)
	{
		DecreaseDateByXDays(*this, Day);
	}

	static clsDate DecreaseDateByOneWeak(clsDate & Date)
	{
		for (short i = 7; i >= 1; i--)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	void DecreaseDateByOneWeak()
	{
		DecreaseDateByOneWeak(*this);
	}

	static clsDate DecreaseDateByXWeaks(clsDate & Date, short Weak)
	{
		for (short i = Weak; i >= 1; i--)
		{
			Date = DecreaseDateByOneWeak(Date);
		}
		return Date;
	}
	void DecreaseDateByXWeaks(short Weak)
	{
		DecreaseDateByXWeaks(*this, Weak);
	}

	static clsDate DecreaseDateByOneMonth(clsDate & Date)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}
		short NumberOfDays = NumberOfDaysInMonth(Date.Month, Date.Year);
		if (Date.Day > NumberOfDays)
		{
			Date.Day = NumberOfDays;
		}
		return Date;
	}
	void DecreaseDateByOneMonth()
	{
		DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXMonths(clsDate & Date, short Month)
	{
		for (short i = Month; i >= 1; i--)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	void DecreaseDateByXMonths(short Month)
	{
		DecreaseDateByXMonths(*this, Month);
	}

	static clsDate DecreaseDateByOneYear(clsDate & Date)
	{
		Date.Year--;
		return Date;
	}
	void DecreaseDateByOneYear()
	{
		DecreaseDateByOneYear(*this);
	}

	static clsDate DecreaseDateByXYears(clsDate & Date, short Year)
	{
		Date.Year -= Year;
		return Date;
	}
	void DecreaseDateByXYears(short Year)
	{
		DecreaseDateByXYears(*this, Year);
	}

	static clsDate DecreaseDateByOneDecade(clsDate & Date)
	{
		Date.Year -= 10;
		return Date;
	}
	void DecreaseDateByOneDecade()
	{
		DecreaseDateByOneDecade(*this);
	}

	static clsDate DecreaseDateByXDecades(clsDate & Date, short Decade)
	{
		Date.Year -= Decade * 10;
		return Date;
	}
	void DecreaseDateByXDecades(short Decade)
	{
		DecreaseDateByXDecades(*this, Decade);
	}

	static clsDate DecreaseDateByOneCentury(clsDate & Date)
	{
		Date.Year -= 100;
		return Date;
	}
	void DecreaseDateByOneCentury()
	{
		DecreaseDateByOneCentury(*this);
	}

	static clsDate DecreaseDateByOneMillennium(clsDate & Date)
	{
		Date.Year -= 1000;
		return Date;
	}
	void DecreaseDateByOneMillennium()
	{
		DecreaseDateByOneMillennium(*this);
	}

	//!!!!!!!!
	static int DayOfWeakOrder(clsDate Date)
	{
		return DayOfWeakOrder(Date.Day, Date.Month, Date.Year);
	}

	//!!!!!!!!!!!!
	static bool IsEndOfWeak(clsDate Date)
	{
		return DayOfWeakOrder(Date) == 6;
	}
	bool IsEndOfWeak()
	{
		return DayOfWeakOrder(*this) == 6;
	}

	static bool IsWeakend(clsDate Date)
	{
		return (DayOfWeakOrder(Date) == 5 || DayOfWeakOrder(Date) == 6);
	}
	bool IsWeakend()
	{
		return (DayOfWeakOrder(*this) == 5 || DayOfWeakOrder(*this) == 6);
	}

	static bool IsBusinessDay(clsDate Date)
	{
		// First Mithod
		/*if (DayOfWeakOrder(Date) == 5 || DayOfWeakOrder(Date) == 6)
		{
			return false
		}
		return true;*/
		// Best Mithod
		return !IsWeakend(Date);
	}
	bool IsBusinessDay()
	{

		return IsBusinessDay(*this);
	}

	static short DaysUntilTheEndOfWeak(clsDate Date)
	{

		// Best Mithod
		return 6 - DayOfWeakOrder(Date);
	}
	short DaysUntilTheEndOfWeak()
	{
		return DaysUntilTheEndOfWeak(*this);
	}

	static short DaysUntilEndOfMonth(clsDate Date)
	{
		/*short Res = 0;
		short TheDay = NumberOfDaysInMonth(Date.Month, Date.Year);

		for (short i = Date.Day; i <= TheDay; i++)
		{
			Res++;
		}
		return Res;*/
		clsDate EndOfMonthDate;
		EndOfMonthDate.Day = NumberOfDaysInMonth(Date.Month, Date.Year);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;

		return GetDiffrenceInDays(Date, EndOfMonthDate, true);
	}
	short DaysUntilEndOfMonth()
	{
		return DaysUntilEndOfMonth(*this);
	}

	static short DaysUntilEndOfYear(clsDate Date)
	{
		clsDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;

		return GetDiffrenceInDays(Date, EndOfYearDate, true);
	}
	short DaysUntilEndOfYear()
	{
		return DaysUntilEndOfYear(*this);
	}

	static short VacationDays(clsDate Date1, clsDate Date2)
	{
		short DaysCount = 0;

		while (IsDate1BeforeDate2(Date1, Date2))
		{
			if (IsBusinessDay(Date1))
				DaysCount++;

			Date1 = AddOneDay(Date1);
		}
		return DaysCount;
	}
	short VacationDays(clsDate Date2)
	{
		return VacationDays(*this, Date2);
	}

	static clsDate VacationEndDate(clsDate Date, short VacationDays)
	{
		short WeakEndCounter = 0;

		//in case the data  is weekend keep adding one day util you reach business day
		//we get rid of all weekends before the first business day
		while (IsWeakend(Date))
		{
			Date = AddOneDay(Date);
		}

		//here we increase the vacation dates to add all weekends to it.
		for (short i = 1; i <= VacationDays + WeakEndCounter; i++)
		{
			if (IsWeakend(Date))
				WeakEndCounter++;

			Date = AddOneDay(Date);
		}

		//in case the return date is week end keep adding one day util you reach business day
		while (IsWeakend(Date))
		{
			Date = AddOneDay(Date);
		}
		return Date;
	}
	clsDate VacationEndDate(short VacationDays)
	{
		return VacationEndDate(*this, VacationDays);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDateAfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare
	{
		Before = -1, Equal = 0, After = 1
	};
	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		/*if(IsDate1AfterDate2(Date1,Date2))
			return enDateCompare::After;*/

			// this is faster 
		return enDateCompare::After;
	}
	enDateCompare CompareDates(clsDate Date2)
	{
		if (IsDate1BeforeDate2(*this, Date2))
			return enDateCompare::Before;

		if (IsDate1EqualDate2(*this, Date2))
			return enDateCompare::Equal;
		return enDateCompare::After;
	}


	//!!!!!!!!!!!!!!!!!!!
	static clsDate StringToDate(string strDate, string sep = "/")
	{
		clsDate Date;
		vector<string>vDate;

		vDate = clsString::Split(strDate, sep);
		Date.Day = stoi(vDate[0]);
		Date.Month = stoi(vDate[1]);
		Date.Year = stoi(vDate[2]);

		return Date;
	}
	/*clsDate StringToDate(string sep = "/")
	{
		return StringToDate(StringDate, sep);
	}*/

	static string DateToString(clsDate Date)
	{
		return to_string(Date.Day) + "/" + to_string(Date.Month) + "/" + to_string(Date.Year);
	}
	string DateToString()
	{
		return DateToString(*this);
	}

	static string FormatDate(clsDate Date, string Format = "dd/mm/yyyy")
	{
		string FormatDateToStringString = "";
		FormatDateToStringString = clsString::ReplaceWord(Format, "dd", to_string(Date.Day));
		FormatDateToStringString = clsString::ReplaceWord(FormatDateToStringString, "mm", to_string(Date.Month));
		FormatDateToStringString = clsString::ReplaceWord(FormatDateToStringString, "yyyy", to_string(Date.Year));

		return FormatDateToStringString;
	}
	string FormatDate(string Format = "dd/mm/yyyy")
	{
		return FormatDate(*this, Format);
	}

	/*void Print()
	{
		cout << DateToString() << endl;
	}*/

	static string GetSystemDateTimeString()
	{
		time_t t = time(0);
		tm* now = localtime(&t);
		short year, month, day, hour, minute, second;
		
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;
		hour = now->tm_hour;
		minute = now->tm_min;
		second = now->tm_sec;

		return (to_string(year) + "/" + to_string(month) + "/" + to_string(day) + " - " +
			to_string(hour) + ":" + to_string(minute) + ":" + to_string(second));

	}

};
