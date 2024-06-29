#ifndef _VISUAL_H_
#define _VISUAL_H_
#include<curses.h>
#include<stdlib.h>
#include<unistd.h>
#include "./linklist.h"
void Initial();
void Clr();
void Finish();
void Next_Oper();
void Print_Num(int y,int x,int num);
void Print_Node(ListNode *node);
void Print_Next();
void Display_LinkList(LinkList *list,int t);
void Oper(LinkList *l,char op);
#endif