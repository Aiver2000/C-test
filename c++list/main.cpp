#include "List.h"

//printlist 打印不需要返回什么，参数是一个模板参数类型的列表
template<class Con>
void PrintContainer(const Con& c)
{
	Con::const_iterator it = c.begin();
	while (it != c.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

}

void test_list1()
{
	cout << "list1使用pushback插入数据的打印" << endl;
	LL::list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);
	lt1.push_back(6);
	PrintContainer(lt1);
	//for (auto e : lt)
	//{
	//	cout << e << " ";

	//}
	//cout << endl;

	//LL::list<int>::iterator it = lt.begin();
	//while (it != lt.end())
	//{
	//	(*it)++;
	//	cout << *it << " ";
	//	++it;
	//}
	//cout << endl;


	cout << "拷贝构造list2的打印" << endl;
	LL::list<int> lt2(lt1);
	PrintContainer(lt2);
	
	//cout << "在list2的2位置前insert一个0并打印" << endl;
	//LL::list<int>::iterator pos = find(lt2.begin(), lt2.end(),2);		
	//lt2.insert(pos,0);
	//PrintContainer(lt2);

	//cout << "在list2的2位置前insert一个0并打印" << endl;
	//lt2.erase(pos);
	//PrintContainer(lt2);

	cout << "用list2给list3赋值,并打印" << endl;
	LL::list<int> lt3;
	lt3 = lt2;
	PrintContainer(lt3);

	cout << "获得list3的第一个元素和最后一个元素" << endl;
	cout << lt3.front() <<"  ";
	cout << lt3.back() << endl;

	cout << "整一个全是0的list4，并打印" << endl;
	LL::list<int> lt4;
	lt4.push_back(0);
	lt4.push_back(0);
	lt4.push_back(0);
	lt4.push_back(0);
	lt4.push_back(0);
	lt4.push_back(0);
	PrintContainer(lt4);

	cout << "交换链表list1和list4、并打印" << endl;
	lt1.swap(lt4);
	PrintContainer(lt4);


	cout << "头删list4" << endl;
	lt4.pop_front_erase();
	PrintContainer(lt4);
	cout << "头插list4" << endl;
	lt4.push_front_insert(0);
	PrintContainer(lt4);
	cout << "尾删list4" << endl;
	lt4.pop_back_erase();
	PrintContainer(lt4);
	cout << "尾插list4" << endl;
	lt4.push_back_insert(0);
	PrintContainer(lt4);


	cout << "list4的节点个数" << endl;
	cout << lt4.size() << endl;

	cout << "判断是list1是否为空链表" << endl;
	cout << lt1.empty() << endl;




	cout << "    " << endl;
	cout << "    " << endl;
	cout << "    " << endl;
	cout << "    " << endl;

	cout << "    " << endl;
	cout << "    " << endl;
}


int main()
{

	test_list1();
	return 0;
}
