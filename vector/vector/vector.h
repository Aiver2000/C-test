#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <assert.h>

using namespace std;

namespace xxx
{
	template <class T>
	class Vector
	{
	public:  //c++��Ĭ����private������Ҫ����pblic
		//һ�������������   ��������ô����		1����дָ�� 
										//	2�� дbegin ��end  ��ȻҪ��const�ͷ�const�汾��
		
		typedef T* iterator;
		typedef const T* const_iterator;

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		// �� �����ǿ�ʼʵ��Ĭ�ϳ�Ա����
		// ���캯�������캯��Ҫ��ôʵ���أ�������������һ����Vector����Ҫ��ɳ�ʼ���б������Զ������Զ���ʼ����
		// ������Ҫ��ʼ��ʲô�أ��Ǿ����Ǽ�����Ա������������������private��д��ֻ������������Ż������Ķ��塣�������ȱʡ���ܡ�
		//����ע��һ�£������ʼ���ɲ����õȺų�ʼ���ģ�Ҫ��С���š����Ҳ���Ҫ����������������ǲ��ô�iterator
		//����ֻ�е�һ������ǰ�� �� �������� ��
		
		//Vector() = default; //��������ϵͳ����Ĭ�ϵĹ��캯��
		
		Vector()
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			printf("���캯���ܺã�over\n");
		
		}
		

		//������������������ͬ����ǰ�����~,��������Ҫʵ�� 1��if �п�  2��delete ע��delete����=  3��ָ�븳��
		~Vector()
		{
			
			if (_start)
			{
				delete[]  _start;
				_start = _finish = _end_of_storage = nullptr;

				
			}
			printf("  ~���������ܺã�over\n");
		}
		//���Ǹ���������������const,ʹ��������СȨ�ޡ�
		size_t Capacity()   const
		{
			return _end_of_storage - _start;
		}
		size_t Size()  const           
		{
			return _finish - _start;
		}

		//reserve����capacity�ռ�
		//����void �����뿪�ٵ�size_t һ��ʵ�ξ�Ϊcapacity 
		//1,�ж��Ƿ���Ҫ���ݣ������Ҫ���ݣ����ǿ���һ����ʱ�������¿��ٵ����顣2����Ҫ�п� 3������Ϊ�վ�ѭ����ֵ����ʱ����4����������������ֵ��
		//�������ǽ���һ����������Ĺ��ܣ�v2��v1�� �����rerserve��v2�ģ���Ȼ���֮ǰ�����ݵĻ���size�����Ͳ���0�����￪���µĹ���ռ䣬��ԭ�������ݿ������������
		void reserve(size_t n)
		{
		
			
			if (n > Capacity())
			{
				size_t size = Size();
				T* tmp = new T[n]; //����������Ϊ��T���͵����鿪n���ռ䡣
				if (_start)     
				{

					//memcpy(tmp, _start, sizeof(T)*size);       //�������ǻ�һ��д����
					for (size_t i = 0; i < size; i++)
					{
						tmp[i] = _start[i];
					 }
					//delete[] _start;          //��ԭ����_startɾ�ˣ���Ȼ�����õ�ԭ���ġ�
					
				}
				_start = tmp;
				_finish = _start + size;
				_end_of_storage = _start + n;
			}
			
		}


		//resize ����Ϊ��С��һ��ȱʡ���졣1���жϲ����� 2���������n��������ݣ�ѭ����Ĭ��ֵ�����±���

		void resize(size_t n, const T& val = T()) //����T����Ϊ���캯������val ��ȱʡֵ��Ĭ����0��
		{
			if (n <= Size())
			{
				_finish =_start + n;
			}
			else
			{
				if (n>Capacity())
				{
					reserve(n);
				}

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
				
				

			}
			//����Ϊʲô������_endof
		}





		//*****��������****** �ѵ�
		//���������ǹ��캯�������أ����Ժ���д��һ����ֻ�ǲ�����һ������������ʹ����ģ�岢��ȡ����
		//�������ʵ���أ�1����Ҫnewһ���¿ռ�,T���͵����飬capacity��ô��,ָ����start��2��Ȼ��Ѵ���������һ��һ����ֵ���¿ռ�3���޸���������������ֵ
		/*Vector(Vector <T> & v)
		{
			printf("���ǹ��캯���ĵܵܣ��Һܺã�over\n");
			_start = new T[v.Capacity()];
			for (int i = 0; i < v.Size(); i++)
			{
				_start[i] = v._start[i];
			}
			_finish = _start + v.Size();
			_end_of_storage = _start + v.Capacity();
			
		}*/

		//�������컹�еڶ���ʵ�ַ��� v2(v1)
		//���Ǵ���const ��������Ϊ���ǲ���ȥ�޸�Сv�����ݣ�һ�㴫����Ȩ����С����Ϊֻ����ͬʱ���ǽ��г�ʼ���б��ʼ���������и����⣬���ﲻ�Ǻ͹��캯���ĳ�ʼ���б�һ�����������ǿɵã����ÿ�����������ĺ�����������ȥ�������Ĺ��캯���ˡ�
		// 1 ,��reserve���ռ�  2, �����������������һ����this�ĵ�������һ����const�ĵ�������ѭ����ֵ 3������������������

		Vector(const Vector<T> & v)
			: _start(nullptr)
			, _finish(nullptr)
			, _end_of_storage(nullptr)
		{
			reserve(v.Capacity());  

			iterator vi = begin();
			const_iterator cvi = v.cbegin();

			while (cvi != v.cend())
			{
				*vi++ = *cvi++;
			}
			_finish = _start + v.Size();
			_end_of_storage = _start + v.Capacity();
		
		}


		//****��ֵ���������*****
		//�����ķ���ֵ��������ã� ������const���ã�1���ж��Ƿ���Լ���ֵ2��ɾ��֮ǰ�Ŀռ䣬�������µĿռ�3��Ȼ������ݿ�������4�����±���5������ֵ
		//Vector<T>& operator=(const Vector<T>& v)
		//{
		//	if (this != &v)        //ע��������ȡ��ַV
		//	{
		//		delete[] _start;
		//		_start = new T[sizeof(T)*v.Size()];  //����ΪʲôҪsizeof��T��������Ӧ��T�����м������Ǽ�����ΪʲôҪ���ֽ��أ�
		//		//reserve(sizeof(T)*v.Size());       //����Ϊʲô��ȥ���ÿ��ٺ����أ�
		//		memcpy(_start, v._start, v.Size()*sizeof(T));
		//		_finish = _start + v.Size();
		//		_end_of_storage = _start + _capacity;
		//	}
		//	return *this;
		//}
		//��Ȼ���еڶ���ʵ�ַ���
		// ���Ƿ���ֵ��Ȼ�����÷��أ���������ɷ�const �����á�1�����ǽ���swap��2������
		// �������һ����������������ǿ�������һ��v��������������������н��������õ��Ѿ���this�������ˣ�û�õĳ�����ջ֡�Զ������ˡ�
		Vector<T>& operator=(Vector<T> v)   
		{
			Swap(v);
			return *this;
		}

		void Swap(Vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_end_of_storage, v._end_of_storage);
		}
		//pushback 1���ж����� 2�����±���
		void pushback(const T& val)
		{
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				reserve(newcapacity);

			}
			*_finish = val;
			_finish++;
			//insert(_finish, val);  ��insert��ʱ��һ��Ҫ���find���µĵ���������Ȼ���¿ռ��ֱ���Ҳ���
		}

		//popback 1������ 2����������
		void popback()
		{
			assert(Size() > 0);
			--_finish;

			//erase(--end());

		}





		//insert ���� �����벻��Ҫ����ֵ��������posλ�õĵ�����������T�������ã���Ȼ��Ҫconst��
		//1�������ȶ���һ��posλ�õ���ȷ�ԡ�2����һ��posλ��(���������ʧЧ) 3���жϿռ��С��������Ҫ���ݲ����� 4��������ѭ���ƶ���λ��5���������ݡ�6�����±���
		void insert(iterator pos, const T& val)
		{
			assert(pos <= _finish);
			size_t posindex = pos - _start;
			if (_finish == _end_of_storage)
			{
				size_t newcapacity = Capacity() == 0 ? 2 : Capacity() * 2;
				reserve(newcapacity); 
				pos = _start + posindex;
			}

			iterator end = _finish;
			while (pos < end)    //�Ӻ���ǰŲ
			{
				*end = *(end - 1);
				end--;
			}
			*pos = val;
			_finish++;


		}


		//Erase ������һ��λ�ã�����Ĭ����pos����������ֵ�Զ����£� ������pos��������
		//1��pos��һ����������2��ѭ������3�����±���
		iterator erase(iterator pos)
		{
			iterator begin = pos;
			while (pos != _finish)
			{
				*pos = *(pos + 1);	
				++pos;
			}
			--_finish;
			return begin;
		}




		//operator[] ����Ӧ���������汾 �������ã�ʹ֮���޸ģ�������һ��λ�þ���
		//1������ 2������
		T& operator [] (size_t pos)    //�ɶ���д
		{
			assert(pos < Size());
			return _start[pos];
		}
		//��������const���������ĺ���ʱ�����޷����õģ�����������ĺ���ʱ������Ӧ����const����Ȼ������������Ȩ�ޡ�����const���õ��㣬���㺯������תһȦ�ұ��޸��ˡ�
		//const T& operator[] (size_t pos)  const    //ֻ�ɶ�
		//{
		//	assert(pos < Size());
		//	return _start[pos];
		//}

		void print()
		{
			for (size_t i = 0; i < Size(); i++)
			{
				cout << _start[i] << " ";

			}
			cout << endl;
		}










	private:
		iterator _start = nullptr;
		iterator _finish = nullptr;
		iterator _end_of_storage = nullptr;



		
	};


	void test1()            //���Թ��졢������pushback popback ������ ���������� .����
	{
		Vector<int> v1;
		v1.pushback(1);
		v1.pushback(2);
		v1.pushback(3);
		v1.pushback(4);
		v1.pushback(5);
		v1.pushback(6);
		v1.print();
		v1.popback();
		v1.print();
		cout << endl;
		Vector<int>v2(v1);
		v2.print();
		Vector<int>::iterator  it = v1.begin();
		while (it != v1.end())
		{
			cout << *it << "  " ;
			it++;
		}
		cout << "����ѭ��������";
		cout << endl;
		

		for (auto e : v1)
		{
			cout << e << "   ";
			
		}
		cout << "����for������";
		cout << endl;

		Vector<int> v3;
		v3 = v2;
		v3.print();
		


	}

	void test2()     //����insert��erase
	{
		Vector<int> v1;
		v1.pushback(1);
		v1.pushback(2);
		v1.pushback(3);
		v1.pushback(4);
		v1.pushback(5);

		v1.print();

		Vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
		v1.insert(pos, 250);
		v1.print();
		v1.insert(pos, 0);

		Vector<int>::iterator pos1 = find(v1.begin(), v1.end(), 250);
		Vector<int> ::iterator e_ret = v1.erase(pos1);
		e_ret = v1.erase(e_ret);
		e_ret = v1.erase(e_ret);
		v1.print();

	}


}


