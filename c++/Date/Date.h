#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <iostream>
#include <assert.h>

using std::cout;
using std::cin;
using std::endl;

//class Date
//{
//public:
//	//1.无参构造函数
//	Date()
//	{}
//
//	//2.带参构造函数
//	Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate()
//{
//	Date d1;//调用无参构造函数
//	Date d2(2015, 1, 1);//调用带参构造函数
//
//	// 注意： 如果通过无参构造函数创建对象时，对象后面不用跟
//	//        括号，否则就成了函数声明
//	//以下代码的函数：声明了d3 函数，该函数无参，返回一个日期
//	//				  类型的对象。
//	Date d3();
//}

class Date
{
public:
	//获取某年某月的天数
	//inline int GetMonthDay(int yeat, int month);  分离会产生链接错误
	void Print();
	//全缺省参数构造函数
	Date(int year = 1900, int month = 1, int day = 1);
	//拷贝构造函数
	Date(const Date& d);
	//赋值运算符重载
	Date& operator =(const Date& d);
	//析构函数
	~Date();
	//日期+=天数
	Date& operator += (int day);
	Date& operator -= (int day);
	//日期+天数
	Date operator+(int day);
	//日期-天数
	Date operator-(int day);
	//前置++
	Date& operator++();
	//后置++
	Date operator++(int);
	//前置--
	Date& operator--();
	//后置--
	Date operator--(int);
	// >运算符重载
	bool operator>(const Date& d);
	// == 运算符重载
	bool operator==(const Date& d);
	// >=运算符重载
	bool operator>=(const Date& d);
	// < 运算符重载
	bool operator<(const Date& d);
	// <=运算符重载
	bool operator<=(const Date& d);
	// ！=运算符重载
	bool operator!=(const Date& d);
	//日期-日期 返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
