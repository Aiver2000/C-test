#pragma once
#include <iostream>
using namespace std;

namespace lqx
{
	class string
	{
	public:

		//���캯��
		string(const char* str = "")
			:_str(new char[strlen(str)+1])
		{
			strcpy(_str, str);
		}

	//��ͳд��
		//��������		
		//s2��s1��
		string(const string &s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		//��ֵ���������
		//s1 = s3
		//s1 = s1
		string& operator= (const string &s)
		{
			if (this != &s)            // �ж��Ƿ�Ϊ�Լ����Լ���ֵ
			{
				delete[] _str;                         //����Ӧ���������أ�
				_str = new char[strlen(s._str) + 1];   //�����ַ�����ֵ��1��������Ҫ��ɾ��ԭ���ı���ֵ���ַ���
													   //                   ��Ϊ���ǵ��ı���ֵ���ַ����ռ䲻��
													   //				 2������Ҫȥ���¿��ٺ�Ҫ��ֵ�ַ���һ���Ŀռ䣬
													   //				    +1Ϊ�˴�'\0'
				strcpy(_str,s._str);				   //                3�����п���
			}
			return *this;              //���÷���ָ�룬���ٿ�����
		}

    //�ִ�д��
		string(const string &s)		   
			:_str(nullptr)             //�����ʼ��Ϊ��ָ�룬��Ϊ�������ʼ����_strΪ���ֵ�������ǰ�����tmp������
									   //tmp��Ϊ���ֵ����������ʱ����������ʱ������
		{
			string tmp(s._str);        //�ȹ���һ����ʱ���� tmp���ٽ��н�����
			swap(_str, tmp._str);      //�����swap�ǿ��ṩ�ĺ���ģ��
		}

		string& operator=(string s)    //������д�ֵ���Σ�s��ʵ�� ��� �����ģ�����s���Զ�������
									   //s�����꣬����������Ҫ���������,��ʱ��ͻ��ˬ��
		{							   //��������������Լ����Լ���ֵ��ʱ���Լ��ĵ�ַ�ᷢ���ı�
									   //���ǿ��������д��
			swap(_str, s._str);
			return *this;
		}

		//string& operator=(const string& s)
		//{
		//	if (this != &s)
		//	{
		//		string tmp(s);
		//		swap(_str, tmp._str);
		//		return *this;

		//	}
		//}
/*---------------------------------------------------------------------------------------------------
 ��ͳ���ִ�Ч��һ��  ��ͳ����һ����ͬ�Ŀռ�棬�������
                     
----------------------------------------------------------------------------------------------------*/

		~string()
		{
			delete[] _str;
			_str = nullptr;
		}

		const char* c_str()
		{
			return _str;
		}
//================����ΪĬ�ϳ�Ա�����Լ���ǳ�����Ľӿڣ���������ʵ��string��ɾ��ĵȹ���============

		//typedef char* iterator;

		//iterator begin()
		//{
		//	return _str;
		//}

		//iterator end()
		//{
		//	return _str + _size;
		//}

		//string(const char* str = "")


	private:
		char* _str;
		size_t _size;
		size_t _capacity;

	};

	void string_test()
	{
		string s1("hello world");

	}
}

