////#define _CRT_SECURE_NO_WARNINGS 1
////
////#include <stdio.h>
////#include <string.h>
////
////
////
//////int main()
//////{
//////	//命名冲突
//////	//C语言无法解决这种问题
//////
//////	int scanf = 10;
//////	int strlen = 20;
//////
//////	scanf("%d",&scanf);  //这里的scanf是指变量，无法接收参数 （就近原则）
//////	printf("%d\n", scanf);
//////	printf("%d\n", strlen);
//////	return 0;
//////}
////
////
////#include <iostream>
////using namespace std;
////namespace bit
////{
////	int scanf = 10;
////	int strlen = 20;
////	int Add(int left, int right)
////	{
////		return left + right;
////	}
////}
////int main()
////{
////	//默认访问的局部或者全局
////	printf("%x \n", scanf);
////	printf("%x \n", strlen);
////
////	//指定访问bit命名空间中
////	printf("%x \n",bit :: scanf);
////	printf("%x \n",bit :: strlen);
////	bit::Add(1, 2);
////
////	return 0;
////}
////#include <iostream>
////using namespace std;
////int main()
////{
////	cout << "hello world" << endl;
////
////
////	return 0;
////}
////void TestFunc(int a = 0)
////{
////	cout << a << endl;
////}
////int main()
////{
////	TestFunc();   //没有传参，使用默认值
////	TestFunc(10); //传参，使用实参
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//
//
//int Add(int left, int right)
//{
//	return left + right;
//}
//double Add(double left, double right)
//{
//	return left + right;
//}
//long Add(long left, long right)
//{
//	return left + right;
//}
//
//int main()
//{
//
//	Add(10, 20);
//	Add(10.0, 20.0);
//	Add(10L, 20L);
//
//
//	return 0;
//}
//
//
////int main()
////{
////	int a;
////	double b;
////	char c;
////	cin >> a;
////	cin >> b >> c;
////	
////	cout << a << endl;
////	cout << b << "  " << c << endl;
////	return 0;
////}

//
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//int days[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
//{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
//
//int isLeapYear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	{
//		return 1;
//
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//
//int main()
//{
//	int m; //定义m行日期
//
//	while (cin >> m)
//	{
//		for (int i = 0; i < m; i++)
//		{
//			int month, day, n, newday;
//			int year = 0;
//
//			cin >> year >> month >> day >> n;
//			int k = isLeapYear(year);
//
//			newday = n + day;
//
//			while (newday > days[k][month])
//			{
//				newday -= days[k][month];
//
//				month++;
//				if (month == 13)
//				{
//					year++;
//					k = isLeapYear(year);
//					month = 1;
//				}
//			}
//			printf("%4d-%02d-%02d\n", year, month, day);
//		}
//
//	}
//
//
//
//
//	return 0;
//}


//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//
//int days[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
//{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
//
//int isLeapYear(int year)
//{
//	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int i = 0;
//	while (cin >> i)
//	{
//		int y, d;
//		int m = 1;
//
//		while (cin >> y >> d)
//		{
//			int k = isLeapYear(y);
//			while (d > days[k][m])
//			{
//				d = d - days[k][m];
//				m++;
//				if (m == 13)
//				{
//					y++;
//					m = 1;
//					k = isLeapYear(y);
//				}
//
//			}
//			printf("%4d-%02d-%02d\n", y, m, d);
//			cin >> " " >> m >> " " >> y;
//		}
//		
//
//	}
//	return 0;
//}

//#include <iostream>
//using namespace std;
//#include <string>
//
//bool isLeapYear(int year)
//{
//	return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
//}
//int days[2][13] = { { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
//{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } };
//int main()
//{
//	int y, m, d;
//	int n = 0;
//
//	while (cin >> y >> m >> d)
//	{
//
//		while (m--)
//		{
//			n += days[isLeapYear(y)][m];
//		}
//		n += d;
//		cout << n << endl;
//	}
//
//}




//class Solution {
//public:
//	int StrToInt(string str) {
//		if (str.size() == 0)//判断是否为不合法字符串
//			return 0;
//		int i = 0, res = 0;
//		int flag = 1;//记录正负,默认为正
//		if (str[i] == '+' || str[i] == '-')
//		{
//			if (str[i] == '-')
//				flag = -1;
//			++i;
//		}
//
//		if (i == str.size())//只有正负号的情况
//			return 0;
//		while (i < str.size())
//		{
//			if (str[i] >= '0' && str[i] <= '9')
//			{
//				int temp = res * 10 + str[i] - '0';
//				if (temp / 10 != res) // 判断溢出
//					return 0;
//				else
//					res = temp;
//			}
//			else
//				return 0;
//			++i;
//		}
//
//		return flag* res;
//
//	}
//};
//
//int main()
//{
//	string a("123");
//	Solution().StrToInt(a);
//}


//#include <iostream>
//#include <string>
//using namespace std;
//
//int main()
//{
//
//	string str;
//	while (getline(cin, str))
//	{
//		int count[26] = { 0 };
//		char s;
//		for (int i = 0; i< str.size(); i++)
//		{
//			count[str[i] - 'a']++;
//		}
//		for (int i = 0; i<str.size(); i++)
//		{
//			if (count[str[i] - 'a'] == 1)
//			{
//				s = str[i];
//				break;
//			}
//		}
//		if (s == NULL)
//			cout << -1 << endl;
//		else
//			cout << s << endl;
//	}
//	return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//#include <windows.h>
//class Solution {
//public:
//	string multiply(string num1, string num2) {
//		if (num1 == "0" || num2 == "0") {
//			return "0";
//		}
//		string ans = "0";
//		int m = num1.size(), n = num2.size();
//		for (int i = n - 1; i >= 0; i--) {
//			string curr;
//			int add = 0;
//			for (int j = n - 1; j > i; j--) {
//				curr.push_back(0);
//			}
//			int y = num2.at(i) - '0';
//			for (int j = m - 1; j >= 0; j--) {
//				int x = num1.at(j) - '0';
//				int product = x * y + add;
//				curr.push_back(product % 10);
//				add = product / 10;
//			}
//			while (add != 0) {
//				curr.push_back(add % 10);
//				add /= 10;
//			}
//			reverse(curr.begin(), curr.end());
//			for (auto &c : curr) {
//				c += '0';
//			}
//			ans = addStrings(ans, curr);
//		}
//		return ans;
//	}
//
//	string addStrings(string &num1, string &num2) {
//		int i = num1.size() - 1, j = num2.size() - 1, add = 0;
//		string ans;
//		while (i >= 0 || j >= 0 || add != 0) {
//			int x = i >= 0 ? num1.at(i) - '0' : 0;
//			int y = j >= 0 ? num2.at(j) - '0' : 0;
//			int result = x + y + add;
//			ans.push_back(result % 10);
//			add = result / 10;
//			i--;
//			j--;
//		}
//		reverse(ans.begin(), ans.end());
//		for (auto &c : ans) {
//			c += '0';
//		}
//		return ans;
//	}
//};
//
//int main()
//{
//	cout<<Solution().multiply("123", "456");
//		return 0;
//}

//#include <vector>
//class Solution {
//public:
//	int removeElement(vector<int>& nums, int val) {
//
//		int len = nums.size();
//		int i = 0;
//		for (int j = 0; j<len ; j++){
//			if (nums[j] != val){
//				nums[i++] = nums[j];
//			}
//		}
//		return i;
//	}
//};
//
//int main()
//{
//	std::vector<int>nums{3,2,2,3};
//	int i = Solution().removeElement(nums, 2);
//	printf("%d",i);
//	return 0;
//}

//#include <stdio.h>
//int main()
//{
//	for (int i = 0; i < 20; i++)
//	{
//		printf("%d\n", i);
//		if (1)
//		{
//			auto int j = 0;//自动变量
//			printf("%d\n", j);
//			j += 1;
//			printf("%d\n", j);
//		}
//
//	}
//	system("pause");
//	return 0;
//}