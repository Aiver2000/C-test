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
//	//1.�޲ι��캯��
//	Date()
//	{}
//
//	//2.���ι��캯��
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
//	Date d1;//�����޲ι��캯��
//	Date d2(2015, 1, 1);//���ô��ι��캯��
//
//	// ע�⣺ ���ͨ���޲ι��캯����������ʱ��������治�ø�
//	//        ���ţ�����ͳ��˺�������
//	//���´���ĺ�����������d3 �������ú����޲Σ�����һ������
//	//				  ���͵Ķ���
//	Date d3();
//}

class Date
{
public:
	//��ȡĳ��ĳ�µ�����
	//inline int GetMonthDay(int yeat, int month);  �����������Ӵ���
	void Print();
	//ȫȱʡ�������캯��
	Date(int year = 1900, int month = 1, int day = 1);
	//�������캯��
	Date(const Date& d);
	//��ֵ���������
	Date& operator =(const Date& d);
	//��������
	~Date();
	//����+=����
	Date& operator += (int day);
	Date& operator -= (int day);
	//����+����
	Date operator+(int day);
	//����-����
	Date operator-(int day);
	//ǰ��++
	Date& operator++();
	//����++
	Date operator++(int);
	//ǰ��--
	Date& operator--();
	//����--
	Date operator--(int);
	// >���������
	bool operator>(const Date& d);
	// == ���������
	bool operator==(const Date& d);
	// >=���������
	bool operator>=(const Date& d);
	// < ���������
	bool operator<(const Date& d);
	// <=���������
	bool operator<=(const Date& d);
	// ��=���������
	bool operator!=(const Date& d);
	//����-���� ��������
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};
