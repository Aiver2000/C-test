#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{
	char name[20] = { 0 };
	char password[20] = { 0 };
	while (~scanf("%s &s", name, password))
	{
		if ((strcmp(name, "admin") == 0) && (strcmp(password, "admin") == 0))

		{
			printf("Login Success!\n");
		}
		else
		{
			printf("Login Fail!\n");
		}
	}
	return 0;
}