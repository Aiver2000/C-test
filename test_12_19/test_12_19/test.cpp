#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	while (~scanf("%d", &n))
	{
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n; j++)
			{
				printf("* ");
			}
			printf("\n");
			printf("* ");
			for (j = 0; j<n - 2; j++)
			{
				printf("  ");
			}
			printf("\n");
			if (i == n - 1)
			{
				for (j = 0; j<n; j++)
				{
					printf("* ");
				}
			}

		}
	}

	return 0;
}