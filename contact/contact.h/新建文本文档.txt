#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include<assert.h>
#define MAX 1000
#define NAME_MAX 20
#define SEX_MAX 5
#define TELE_MAX 12
#define ADDR_MAX 30

#define DEFSULT_SZ 5
#define DEFSULT_INC 2




typedef struct PeoInfo
{
	char name[NAME_MAX];
	int age;
	char sex[SEX_MAX];
	char tele[TELE_MAX];
	char addr[ADDR_MAX];
}PeoInfo;


//struct Contact
//{
//	struct PeoInfo data[MAX];
//	int sz;
//
//};
//动态
typedef struct Contact
{
	PeoInfo* data;//数据存储的区域
	int sz; //有效元素个数
	int capacity; // 容量

}Contact,*pContact;


void InitContact(struct Contact* pc);

void AddContact(struct Contact* pc);

void ShowContact(const struct Contact* pc);

void SearchContact(const struct Contact* pc);

void DelContact(struct Contact* pc);

void ModifyContact(struct Contact* pc);

void EmptyContact(struct Contact* pc);

void SortNameContact(struct Contact* pc);

void DestoryContact(pContact pc);

void SaveContact(Contact* pc);