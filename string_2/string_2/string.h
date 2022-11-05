#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace lqx
{
	class string
	{
	public:

		//���캯��
		string(const char* str = "")              								            		
		{									      // ע��һ��:����str��10byte������_size�����9����Ϊ��һ����\0	
			_size = strlen(str);			      //           _capacity��ʱ������9Ҳ������10 �� �����Ƽ������9	
			_capacity = _size;			
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//��ͳд��
		//��������		
		//s2��s1��
		//string(const string &s)
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}

		//��ֵ���������
		//s1 = s3
		//s1 = s1
		//string& operator= (const string &s)
		//{
		//	if (this != &s)				              // �ж��Ƿ�Ϊ�Լ����Լ���ֵ
		//	{
		//		delete[] _str;                         //����Ӧ���������أ�
		//		_str = new char[strlen(s._str) + 1];   //�����ַ�����ֵ��1��������Ҫ��ɾ��ԭ���ı���ֵ���ַ���
		//											   //					 ��Ϊ���ǵ��ı���ֵ���ַ����ռ䲻��
		//												//				2������Ҫȥ���¿��ٺ�Ҫ��ֵ�ַ���һ���Ŀռ䣬
		//												//				    +1Ϊ�˴�'\0'
		//		strcpy(_str, s._str);				    //                3�����п���
		//	}
		//	return *this;							   //���÷���ָ�룬���ٿ�����
		//}

		//s1.swap(s2)       ������õ��������Լ������
		//swap(s1,s3)       ���õ��ǿ�ģ��
		                                       //��Ȼ�����Լ�����ĸ��ã���Ϊ��ģ����Ҫ��һ�ο������죬������������ء�һ������������������Ǻܴ�ġ�
		void swap(string& s)				
		{									
			::swap(_str, s._str);              //������swap����ѭ�ͽ�ԭ���ҵ������Լ�д��swap�����ǲ�����������һ����
			::swap(_size, s._size);			   //��������Ҫʹ�����������޶���,���û��ָ��Ϊȫ�ֵġ�
			::swap(_capacity, s._capacity);

		}


		//�ִ�д��
		string(const string &s)
			:_str(nullptr) 
			,_size(0)
			,_capacity(0)				//�����ʼ��Ϊ��ָ�룬��Ϊ�������ʼ����_strΪ���ֵ�������ǰ�����tmp������									   //tmp��Ϊ���ֵ����������ʱ����������ʱ������
		{
			string tmp(s._str);        //�ȹ���һ����ʱ���� tmp���ٽ��н�����
			swap(tmp);				           //�����swap�ǿ��ṩ�ĺ���ģ��
			
			
		}

		string& operator=(string s)     //������д�ֵ���Σ�s��ʵ�� ��� �����ģ�����s���Զ�������
										//s�����꣬����������Ҫ���������,��ʱ��ͻ��ˬ��
		{							    //��������������Լ����Լ���ֵ��ʱ���Լ��ĵ�ַ�ᷢ���ı�
			//���ǿ��������д��
			swap(s);
			return *this;
		}

		/*string& operator=(const string& s)
		{
			if (this != &s)
			{
				string tmp(s);
				swap(_str, tmp._str);
				return *this;

			}
		}*/
		/*---------------------------------------------------------------------------------------------------
		��ͳ���ִ�Ч��һ��  ��ͳ����һ����ͬ�Ŀռ�棬�������

		----------------------------------------------------------------------------------------------------*/

		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = 0;
			_capacity = 0;
		}

		//const char* c_str()
		//{
		//	return _str;
		//}
		//================����ΪĬ�ϳ�Ա�����Լ���ǳ�����Ľӿڣ���������ʵ��string��ɾ��ĵȹ���============

		typedef char* iterator;       //�����������ڿ��԰ѵ������������ָ��һ���Ķ���
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		const_iterator begin()  const
		{
			return _str;
		}

		const_iterator end() const
		{
			return _str + _size;
		}

		const char* c_str() const
		{
			return _str;
		}

		//string(const char* str = "")
		//����
		//��
		//at ���ú�operator[]���ƣ�ʧ�����쳣
		const char& operator [](size_t i) const  //ǰ�󶼼�const���ſ��Գ�������const����
		{
			assert(i < _size);
			return _str[i];
		}

		char& operator [](size_t i)  //����const����
		{
			assert(i < _size);
			return _str[i];
		}

		size_t size()  const //�������const��ʹconst���Ե���
		{
			return _size;
		}
		//���ռ䣬��չcapacity
		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strncpy(tmp, _str,_size+1);           //���ﲻ����strcpy����Ϊ�������ԭ�ַ�������\0��\0Ϊ���ǵ���Ч�ַ������ǽ�����ʶ����ô�ͻ���ǰ������
				delete[] _str;
				_str = tmp;
			}
			_capacity = n;
		}
		//���ռ�+��ʼ������չcapacity ���ҳ�ʼ���ռ䣬sizeҲ�ᶯ��
		void resize(size_t n,char val = '\0')
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n>_capacity)         //������ﲻ�жϣ������ǲ�֪��reserve��������û��if����ô���ǿ��ܾͻ����ݣ���Ҫ���ݣ���
				{					     //��϶�Ҫ��
					reserve(n);
				}
				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = val;
				}
				_str[n] = '\0';
				_size = n;
			}

		}

		// ���漸����Ҫ�����ӿ�

		void push_back(char ch)         
		{
			if (_size = _capacity)
			{				
				reserve(_capacity == 0  ?  4:_capacity*2);
			}
			_str[_size] = ch;
			_str[_size + 1] = '\0';
			++_size;

			//inset(_size,ch)
		}

		void append(const char* str)                //û�ж���Ĺ���
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str + _size, str);
			_size = len;

			//insert(_size,str);
		}

		string& operator += (char ch)           
		{
			push_back(ch);
			return *this;
		}
		string& operator += (const char* str)
		{
			append(str);
			return *this;
		}

		string& insert(size_t pos,const char* str)					//�ܲ��þͲ��ã���ΪЧ�ʲ���  
		{														// ��1234��+��345��  -> ͷ��  (N^2)   n���ַ�����ͷ��
																//                   ->β��+����  ��2*N��
																//
																
			assert(pos <=_size);
			size_t len = strlen(str);
			if (_size + strlen(str) > _capacity)
			{
				reserve(_size + len);
			}

			//Ų������
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + len) = *end;
				--end;
			}
			strncpy(_str + pos, str, len);     //���ﲻ��ʹ��strcpy ��Ϊ���\0������ȥ��
			_size += len;
			return *this;
			



		}
		//posλ��֮ǰ����
		string& insert(size_t pos, char ch)
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);  //���ַ���Ϊһ���մ�ʱ����Ҫ��һ��4����Ȼreserve�Ὺ2*0���ռ䡣
			}
			//����һ								//���Ǵ�size��\0��λ�ÿ�ʼŲ��
			int end = _size;                        //����ΪʲôҪ��int ������size_t ����Ϊ����0λ�ò���һ���ַ���ʱ��0��-- ����42��9ǧ���һ�����ݣ�Ҳ���ǣ�2^32 -1 ;����һ�����������Ǵ���pos�Ļ������ѭ��
			while (end >=(int) pos)                 //����ҲҪǿתΪint����Ϊ��ΧС�Ļ���Χ���޷��ŷ�Χ�������Σ����������ֱ�Ϊ�޷����ˡ�
			{										
				_str[end + 1] = _str[end];				
				--end;

			}
		//	//������
		//	size_t end = _size + 1;
		//	while (pos > end)
		//	{
		//		_str[end] = _str[end-1];
		//		--end;
		//	}

		//	//��������ָ��

		//	char* end = _str + _size;
		//	while (end >= _str + pos)
		//	{
		//		*(end + 1) = *end;
		//	}



			_str[pos] = ch;
			_size++;
			return *this;
		}


		//ɾ
		//pop_back();//βɾ
		string& erase(size_t pos,size_t len = npos)   //Խ��ͷȥɾ����Ҫ��֮����ַ�ȫ��ǰ��һ�¡�
		{			
			assert(pos < _size);
			size_t leftLen = _size - pos;
			if (len >= leftLen) 
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				strcpy(_str + pos, _str + pos + len);
				_size += len;


			}
			return *this;			
		
		}
		//��
		size_t find(char ch,size_t pos = 0)		//���ַ������ַ���
		{
			assert(pos < _size);
			for (size_t i = pos; i <_size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
				else
				{
					return npos;
				}
			}

		}

		size_t find(const char* str, size_t pos = 0)
		{
			assert(pos < _size);
			const char* ret = strstr(_str+pos,str);  //strstrƥ��ıȽϱ�������һ���ַ�ƥ�䵽�ˣ���ʼƥ��ڶ��������û��ƥ�䵽���˳����ӵڶ����ַ���ʼƥ�䡣
			if (ret)							     //��������KMP���ִ��ظ��ܶ࣬�Ż�Ч���ȽϺá�ʵ���������Ĵ�����
			{									     //��������BMƥ���㷨����ʵ���У���KMP���ӿ��ס�
				return ret - _str;
			}
			else
			{
				return npos;
			}


		
		}
		//rfind(); //�����ң�����findȥ�����


		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
		static const size_t npos; //���ǲ����������ֵ����Ȼ�ͱ��ȱʡ�ˡ�

	};

	const size_t string:: npos = -1;


	//һ���ַ�һ���ַ���ascll���볤���޹�
	inline bool operator<(const string& s1,const string& s2)         //һ��ʵ�ֳɷǳ�Ա������
	{
		return strcmp(s1.c_str(), s2.c_str()) <0; 

	}
	inline bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}
	inline bool operator == (const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	inline bool operator <= (const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	inline bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	inline bool operator != (const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}

	ostream& operator<<(ostream& out, string& s)     //cout��һ��ostream���͵�ȫ�ֶ���
	{											     //���ﲢ������Ҫ�������Ԫ�� 
		for (auto ch : s)
		{
			out << ch;
		}
		return out;						  //outΪcout�ı���������out����ʹ�����������out<<c1��<<c2
	}


	istream& operator>>(istream& in, string&s)
	{
		s.clear();
		char ch;
		ch = in.get();         //�����ո�ͻس���Ҳ����ա�
		while (ch != ' '&& ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}

}

