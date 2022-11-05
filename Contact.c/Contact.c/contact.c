#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"






int CheckCapacity(pContact pc)
{
	if (pc->sz == pc->capacity)
	{
		PeoInfo* ptr =(PeoInfo*) realloc(pc->data, (pc->capacity + DEFSULT_INC)*sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("����ʧ��\n");
			return 0;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += DEFSULT_INC;
			printf("���ݳɹ�\n");
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
			printf("ͨѶ¼����ʧ��\n");
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
	//��̬
	/*pc->sz = 0;
	memset(pc->data, 0, sizeof(pc->data));*/

	//��̬
	pc->sz = 0;
	pc->capacity = DEFSULT_SZ;
	pc->data = (PeoInfo*)malloc(DEFSULT_SZ* sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("��ʼ��ͨѶ¼ʧ��\n");
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
		printf("ͨѶ¼�������޷����\n");
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", pc->data[pc->sz].name);
		printf("���������䣺>");
		scanf("%d", &(pc->data[pc->sz].age));
		printf("�������Ա�>");
		scanf("%s", pc->data[pc->sz].sex);
		printf("������绰��>");
		scanf("%s", pc->data[pc->sz].tele);
		printf("�������ַ��>");
		scanf("%s", pc->data[pc->sz].addr);

		pc->sz++;
		printf("��ӳɹ�\n");

	}


}



void ShowContact(const struct Contact* pc)
{
	int i = 0;
	if (pc->sz == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����","����","�Ա�","�绰","��ַ");
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
	printf("������Ҫ���ҵ��˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����");
	}
	else
	{
		printf("%-15s\t%-5s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");
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
		printf("��\n");
	}
	else
	{
		printf("������Ҫɾ�����˵�����:>");
		scanf("%s", name);
		int pos = FindByName(pc, name);
		if (pos == -1)
		{
			printf("Ҫɾ�����˲�����\n");
		}
		else
		{
			int j = 0;
			for (j = pos; j < pc->sz; j++)
			{
				pc->data[j] = pc->data[j + 1];

			}
			pc->sz--;
			printf("ɾ���ɹ�\n");
		}
	}
}



void ModifyContact(struct Contact* pc)
{
	char name[NAME_MAX];
	printf("������Ҫ�޸��˵����֣�>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("���������֣�>");
		scanf("%s", pc->data[pos].name);
		printf("���������䣺>");
		scanf("%d", &(pc->data[pos].age));
		printf("�������Ա�>");
		scanf("%s", pc->data[pos].sex);
		printf("������绰��>");
		scanf("%s", pc->data[pos].tele);
		printf("�������ַ��>");
		scanf("%s", pc->data[pos].addr);

		printf("�޸ĳɹ�\n");
	}
}


void EmptyContact(struct Contact* pc)
{
	pc->sz = 0;
	printf("��ճɹ�!\n");
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