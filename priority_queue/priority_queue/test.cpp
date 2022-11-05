#define _CRT_SECURE_NO_WARNINGS 1
#include "priority_queue.h"


int main()
{

	www::priority_queue<int,vector<int>,www::greater<int>> pq;

	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5); 
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
	return 0;
}




