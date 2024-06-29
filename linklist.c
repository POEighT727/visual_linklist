#include<stdio.h>
#include<stdlib.h>
#include "./include/linklist.h"

//链表的头结点存储的是链表的元素个数
ListNode* ListNode_Create(int val) 
{
	ListNode *node = (ListNode*)malloc(sizeof(ListNode));
	node->value = val;
	node->next = NULL;
	node->post=NULL;
	return node;
}

LinkList* LinkList_Create() 
{
	LinkList *list = (LinkList*)malloc(sizeof(LinkList));
	ListNode *node=ListNode_Create(0);
	list->head = node;
	list->tail = node;
	return list;
}


void LinkList_Append(LinkList *list, int val) 
{
	ListNode *node = ListNode_Create(val);
	list->tail->next = node;
	node->post=list->tail;
	list->tail = node;
	(list->head->value)++;
}

void LinkList_Unshift(LinkList *list,int val) {
	ListNode *node = ListNode_Create(val);
	node->next = list->head->next;
	node->post=list->head;
	if(list->head->next==NULL)list->tail=node;
	list->head->next=node;
	(list->head->value)++;
}

void LinkList_Delete(LinkList *list, int val) 
{
	ListNode *node = list->head;
	while (node->next != NULL) 
    {
		if(node->next->value==val)
		{
			ListNode *t=node->next;
			if(t->next==NULL)list->tail=node;
			node->next=t->next;
			t->next->post=node;
			free(t);
			(list->head->value)--;
			return;
		}
		node=node->next;
	}
}

void LinkList_Replace(LinkList *list,int val1,int val2)//用val2替换第一个val1
{
	ListNode *node=list->head;
	while(node->next!=NULL)
	{
		node=node->next;
		if(node->value==val1)
		{
			node->value=val2;
			return;
		}
	}
}

int LinkList_Find(LinkList *list,int val)
{
	ListNode *node=list->head->next;
	int i=1;
	while(node!=NULL)
	{
		if(node->value==val)return i;
		i++;
		node=node->next;
	}
	if(node==NULL)return 0;
}

bool LinkList_Empty(LinkList *list) 
{
	return (list->head==list->tail||list==NULL);
}

void LinkList_Print(LinkList *list)
{
	ListNode *node=list->head;
	while(node->next!=NULL)
	{
		node=node->next;	
		printf("%d ",node->value);
	}
	printf("\n");
}
void LinkList_Clear(LinkList *list)
{
	ListNode *node=list->tail;
	while(node!=NULL)
	{
		ListNode *t=node->next;
		free(t);
		node=node->post;
	}
	list->head->value=0;
	list->head->next=NULL;
	list->tail=list->head;
	list->tail->post=NULL;
}