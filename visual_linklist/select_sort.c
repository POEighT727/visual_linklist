#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include "./include/linklist.h"
#include "./include/select_sort.h"
#include "./include/visual.h"
int minval=1e9;
void Select_Sort(LinkList *list)
{
    ListNode *node=list->head;
    int n=node->value;
    int maxline=LINES-1;
    while(node->next!=NULL)
    {
        sleep(1);
        Clr();
        node=node->next;
        minval=node->value;
        ListNode *p=node,*pmin=node;
        while(p->next!=NULL)
        {
            p=p->next;
            if(p->value<minval)
            {
                minval=p->value;
                pmin=p;
            }
        }
        LinkList_Replace(list,pmin->value,node->value);
        LinkList_Replace(list,node->value,minval);
        move(0,0);
        Display_LinkList(list,0);
    }
    
}