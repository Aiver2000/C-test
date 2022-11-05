#include "stack_queue.h"

void test_stack()
{
	lqx::stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	while (!st.empty())
	{		
		cout << st.top();
		cout << endl;
		cout <<"Ê£Óà¸öÊý"<< st.size() << endl;
		st.pop();
	}
	cout << st.size() << endl;

	
}


void test_queue()
{
	lqx::queue<int> que;
	que.push(1);
	que.push(2);
	que.push(3);
	que.push(4);
	while (!que.empty())
	{
		cout << que.front();
		
		que.pop();
		
	}
}
int main()
{
	//test_stack();
	test_queue();
	return 0;
}


