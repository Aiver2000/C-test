#define _CRT_SECURE_NO_WARNINGS 1
#include "Data.h"
inline int GetMonthDay(int year, int month)
{
	static int dayArray[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day = dayArray[month];
	if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
	{
		day = 29;
	}
	return day;

}

Date::Date(int year, int month, int day)
{
	//������ڵĺϷ���
	if (year >= 0
		&& month > 0 && month <13
		&& day>0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		cout << "�Ƿ�����" << endl;
		cout << year << "��" << month << "��" << day << "��" << endl;
	}
}

void Date::Print()
{
	cout << _year << "��" << _month << "��" << _day << "��" << endl;

}
Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}


Date& Date:: operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	return *this;
}

Date::~Date()
{
	_year = 0;
	_month = 0;
	_day = 0;
}

Date& Date ::operator += (int day)
{
	if (day < 0)
	{
		*this -= -day;
	}
	else
	{
		_day += day;
		//�������Ϸ������Ͻ�λ�������ںϷ�
		while (_day>GetMonthDay(_year, _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}


		}
	}
	return *this;
}
Date& Date:: operator -= (int day)
{
	if (day < 0)
	{
		*this += -day;
	}
	else
	{
		_day -= day;
		while (_day <= 0)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			_day += GetMonthDay(_year, _month);
		}
	}
	return *this;
}

Date Date:: operator+(int day)
{
	Date tmp(*this);
	//����operator+=
	tmp += day;
	return tmp;
}
Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}


Date& Date:: operator++()
{
	*this += 1;
	return *this;
}

Date Date:: operator++(int)
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

bool Date:: operator>(const Date& d) 
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
				return true;
		}
		
	}
	return false;
}


bool Date::operator==(const Date& d) const
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}


bool Date:: operator<(const Date& d) const
{
	return !(*this >= d);
}

bool Date::operator>=(const Date& d) const
{
	return *this>d || *this == d;
}

bool Date:: operator<=(const Date& d) const
{
	return !(*this > d);
}

bool Date:: operator!=(const Date& d) const
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}

	return n* flag;
}