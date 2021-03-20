#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"






int CheckCapacity(pContact pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr =(PeoInfo*) realloc(pc->data, (pc->capacity + DEFSULT_INC)*sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("扩容失败\n");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += DEFSULT_INC;
			printf("增容成功\n");
			return 1;

		}
		
	}
	return 1;
}


void LoadContact(Contact* pc)
{
	FILE* pfIn = fopen("contact.dat", "rb");
	if (pfIn == NULL)
	{
		printf("LoadContact::%s\n", strerror(errno));
		return;
	}
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfIn))
	{
		if (CheckCapacity(pc) == 0)
		{
			printf("通讯录扩容失败\n");
			return;
		}
		pc->data[pc->sz] = tmp;
		pc->sz++;
	}
	fclose(pfIn);
	pfIn = NULL;
}


void InitContact(struct Contact* pc)
{
	//静态
	/*pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));*/

	//动态
	pc->sz = 0;
	pc->capacity = DEFSULT_SZ;
	pc->data = (PeoInfo*)malloc(DEFSULT_SZ* sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("初始化通讯录失败\n");
		exit(1);

	}
	/*memset(pc->data, 0, sizeof(PeoInfo));
	pc->capacity = DEFSULT_SZ;*/
	LoadContact(pc);
}


void AddContact(struct Contact* pc)
{
	assert(pc);
	CheckCapacity(pc);
	if (pc->sz == MAX)
	{
		printf("通讯录已满，无法添加\n");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", pc->data[pc->sz].name);
		printf("请输入年龄：>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("请输入性别：>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("请输入电话：>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("请输入地址：>");
		scanf("%s", pc->data[pc->sz].addr);

		pc->sz++;
		printf("添加成功\n");

	}


}



void ShowContact(const struct Contact* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字","年龄","性别","电话","地址");
		for (i = 0; i < pc->sz; i++)
		{
			printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
				pc->data[i].name,
				pc->data[i].age,
				pc->data[i].sex,
				pc->data[i].tele,
				pc->data[i].addr);
		}

	}
}

static int FindByName(const struct Contact* pc, char name[])
{
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		if (strcmp(pc->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}


void SearchContact(const struct Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要查找的人的名字；>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要查找的人不存在");
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-15s\t%-5d\t%-5s\t%-12s\t%-20s\n",
			pc->data[pos].name,
			pc->data[pos].age,
			pc->data[pos].sex,
			pc->data[pos].tele,
			pc->data[pos].addr);
	}

}



void DelContact(struct Contact* pc)
{
	char name[NAME_MAX] = { 0 };
	if (pc->sz == 0)
	{
		printf("空\n");
	}
	else
	{
		printf("请输入要删除的人的名字:>");
		scanf("%s", name);
		int pos = FindByName(pc, name);
		if (pos == -1)
		{
			printf("要删除的人不存在\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < pc->sz; j++)
			{
				pc->data[j] = pc->data[j + 1];

			}
			pc->sz--;
			printf("删除成功\n");
		}
	}
}



void ModifyContact(struct Contact* pc)
{
	char name[NAME_MAX];
	printf("请输入要修改人的名字：>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字：>");
		scanf("%s", pc->data[pos].name);
		printf("请输入年龄：>");
		scanf("%d", &(pc->data[pos].age));
		printf("请输入性别：>");
		scanf("%s", pc->data[pos].sex);
		printf("请输入电话：>");
		scanf("%s", pc->data[pos].tele);
		printf("请输入地址：>");
		scanf("%s", pc->data[pos].addr);

		printf("修改成功\n");
	}
}


void EmptyContact(struct Contact* pc)
{
	pc->sz = 0;
	printf("清空成功!\n");
}


void SortNameContact(struct Contact* pc)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pc->sz - 1;i++)
	for (j = 0; j < pc->sz - i - 1; j++)
	{
		if (strcmp(pc->data[j].name, pc->data[j + 1].name)>0)
		{
			struct PeoInfo tmp;
			tmp = pc->data[j];
			pc->data[j] = pc->data[j + 1];
			pc->data[j + 1] = tmp;
		}

	}
}

void DestoryContact(pContact pc)
{
	free(pc->data);
	pc->data = NULL;
	pc->capacity = 0;
	pc->sz = 0;
}


void SaveContact(Contact* pc)
{
	FILE* pfOut = fopen("contact.dat", "wb");
	if (pfOut == NULL)
	{
		printf("SaveContact::%s\n", strerror(errno));
		return;
	}
	int i = 0;
	for (i = 0; i < pc->sz; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfOut);
	}
	fclose(pfOut);
	pfOut = NULL;
}