#include<stdio.h>
#include<stdlib.h>
#include "./include/linklist.h"
#include "./include/select_sort.h"
#include "./include/randomseq.h"
#include "./include/visual.h"
int main()
{
    Initial();
    char ch;
    LinkList *list=LinkList_Create();
    while(ch=getch())
    {
        Oper(list,ch);
        if(ch=='q')break;
    }
    Finish();
    return 0;
}