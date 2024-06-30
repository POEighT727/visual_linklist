#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include<stdbool.h>

typedef struct ListNode 
{
	int value;
	struct ListNode *next;
	struct ListNode *post;
} ListNode;


typedef struct LinkList 
{
	ListNode *head;
	ListNode *tail;
} LinkList;

ListNode* ListNode_Create(int val);
LinkList* LinkList_Create();
void LinkList_Append(LinkList *list, int val);
void LinkList_Unshift(LinkList *list, int val);
void LinkList_Delete(LinkList *list, int val);
void LinkList_Replace(LinkList *list,int val1,int val2);
int LinkList_Find(LinkList *list,int val);
bool LinkList_Empty(LinkList *list);
void LinkList_Print(LinkList *list);
void LinkList_Clear(LinkList *list);

#endif