#include<curses.h>
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include "./include/visual.h"
#include "./include/linklist.h"
#include "./include/randomseq.h"
#include "./include/select_sort.h"

void Initial()
{
    initscr();
    cbreak();
    noecho();
    clear();
    int maxline=LINES-1,maxcol=COLS-1;
    mvaddstr(maxline-1,0,"press a key.(l to get a random linklist,a/u to add a node,d to delete,c to clear,r to replace,f to find,s to sort,q to quit)");
}
void Clr()
{
    clear();
    int maxline=LINES-1,maxcol=COLS-1;
    mvaddstr(maxline-1,0,"press a key.(l to get a random linklist,a/u to add a node,d to delete,c to clear,r to replace,f to find,s to sort,q to quit)");
    move(0,0);
    refresh();
}
void Finish()
{
    clear();
    refresh();
    endwin();
}
void Next_Oper()
{
    int maxline=LINES-1,maxcol=COLS-1;
    for(int i=0;i<=maxcol;i++)mvaddch(maxline,i,' ');
    move(maxline,0);
    refresh();
}
void Print_Num(int y,int x, int num)
{
    int i;
    switch(num)
    {
        case 0:
            i=3;
            while(i--)mvaddch(y,x+i,'*');
            i=4;
            while(i--)mvaddch(y+i,x,'*');
            i=4;
            while(i--)mvaddch(y+i,x+3,'*');
            i=4;
            while(i--)mvaddch(y+4,x+i,'*');
            move(y,x+5);
            break;
        case 1:
            i=5;
            while(i--)mvaddch(y+i,x,'*');
            move(y,x+5);
            break;
        case 2:
            i=3;
            while(i--)mvaddch(y,x+i,'*');
            i=3;
            while(i--)mvaddch(y+i,x+3,'*');
            i=3;
            while(i--)mvaddch(y+2,x+i,'*');
            i=2;
            while(i--)mvaddch(y+2+i,x,'*');
            i=4;
            while(i--)mvaddch(y+4,x+i,'*');
            move(y,x+5);
            break;
        case 3:
            i=3;
            while(i--)mvaddch(y,x+i,'*');
            i=3;
            while(i--)mvaddch(y+i,x+3,'*');
            i=3;
            while(i--)mvaddch(y+2,x+i,'*');
            i=3;
            while(i--)mvaddch(y+2+i,x+3,'*');
            i=4;
            while(i--)mvaddch(y+4,x+i,'*');
            move(y,x+5);
            break;
        case 4:
            i=2;
            while(i--)mvaddch(y+i,x,'*');
            i=3;
            while(i--)mvaddch(y+i,x+3,'*');
            i=3;
            while(i--)mvaddch(y+2,x+i,'*');
            i=3;
            while(i--)mvaddch(y+2+i,x+3,'*');
            move(y,x+5);
            break;
        case 5:
            i=4;
            while(i--)mvaddch(y,x+i,'*');
            i=3;
            while(i--)mvaddch(y+i,x,'*');
            i=3;
            while(i--)mvaddch(y+2,x+i,'*');
            i=3;
            while(i--)mvaddch(y+2+i,x+3,'*');
            i=4;
            while(i--)mvaddch(y+4,x+i,'*');
            move(y,x+5);
            break;
        case 6:
            i=4;
            while(i--)mvaddch(y,x+i,'*');
            i=3;
            while(i--)mvaddch(y+i,x,'*');
            i=3;
            while(i--)mvaddch(y+2,x+i,'*');
            i=3;
            while(i--)mvaddch(y+2+i,x,'*');
            i=3;
            while(i--)mvaddch(y+2+i,x+3,'*');
            i=4;
            while(i--)mvaddch(y+4,x+i,'*');
            move(y,x+5);
            break;
        case 7:
            i=4;
            while(i--)mvaddch(y,x+i,'*');
            i=5;
            while(i--)mvaddch(y+i,x+3,'*');
            move(y,x+5);
            break;
        case 8:
            i=3;
            while(i--)mvaddch(y,x+i,'*');
            i=3;
            while(i--)mvaddch(y+i,x,'*');
            i=3;
            while(i--)mvaddch(y+i,x+3,'*');
            i=3;
            while(i--)mvaddch(y+2,x+i,'*');
            i=3;
            while(i--)mvaddch(y+2+i,x,'*');
            i=3;
            while(i--)mvaddch(y+2+i,x+3,'*');
            i=4;
            while(i--)mvaddch(y+4,x+i,'*');
            move(y,x+5);
            break;
        case 9:
            i=3;
            while(i--)mvaddch(y,x+i,'*');
            i=3;
            while(i--)mvaddch(y+i,x,'*');
            i=3;
            while(i--)mvaddch(y+i,x+3,'*');
            i=3;
            while(i--)mvaddch(y+2,x+i,'*');
            i=3;
            while(i--)mvaddch(y+2+i,x+3,'*');
            i=4;
            while(i--)mvaddch(y+4,x+i,'*');
            move(y,x+5);
            break;
    }
}
void Print_Node(ListNode *node)
{
    extern int minval;
    int val=node->value;
    int num[10];
    int i=0;
    while(val)
    {
        num[i++]=val%10;
        val/=10;
    }
    while(i)
    {
        i--;
        int y,x;
        getyx(stdscr,y,x);
        Print_Num(y,x,num[i]);
    }
    int y,x;
    getyx(stdscr,y,x);
    if(node->value==minval)
    {
        mvaddstr(y+5,x-5,"min");
        minval=1e9;
    }
    refresh();
    move(y,x);
}
void Print_Next()
{
    int y,x;
    getyx(stdscr,y,x);
    move(y+2,x);
    printw(" --> ");
    int maxcol=COLS-1;
    if(maxcol-(x+5)+1<17)move(y+7,0);
    else move(y,x+6);
}
void Display_LinkList(LinkList *list,int t)
{
    ListNode *node=list->head;
    int maxline=LINES-1;
    int y,x;
    getyx(stdscr,y,x);
    
    if(LinkList_Empty(list))
    {
        Print_Num(y,x,0);
        mvaddstr(maxline,0,"the linklist is empty,press any key to continue.");
        refresh();
        getch();
        move(y,x);
        return;
    }
    while(node->next!=NULL)
    {
        sleep(t);
        if(node==list->head)
        {
            mvaddstr(5,0,"head");
            move(y,x);
            refresh();
        }
        Print_Node(node);
        refresh();
        sleep(t);
        Print_Next();
        refresh();
        node=node->next;
    }
    sleep(t);
    Print_Node(node);
    refresh();
}
void Oper(LinkList *l,char op)
{
    int maxline=LINES-1,maxcol=COLS-1;
    int val;
    switch(op)
    {
        case 'l':
            LinkList_Clear(l);
            mvaddstr(maxline,0,"please enter the length of linklist");
            int len,bits;
            refresh();
            scanf("%d",&len);
            Clr();
            mvaddstr(maxline,0,"please enter the bits of number");
            refresh();
            scanf("%d",&bits);
            long long* num=(long long*)calloc(len,sizeof(long long));
            Get_Randomseq(num,len,bits);
            for(int i=0;i<len;i++)LinkList_Append(l,num[i]);
            free(num);
            move(0,0);
            Clr();
            Display_LinkList(l,1);
            int y,x;
            getyx(stdscr,y,x);
            mvaddstr(maxline,0,"Initialize a random linklist,press any key to continue.");
            refresh();
            getch();
            move(y,x);
            break;
        case 'q':
            Finish();
            break;
        case 'a':
            mvaddstr(maxline,0,"please enter the value");
            refresh();
            scanf("%d",&val);
            LinkList_Append(l,val);
            move(0,0);
            Clr();
            Display_LinkList(l,0);
            break;
        case 'u':
            mvaddstr(maxline,0,"please enter the value");
            refresh();
            scanf("%d",&val);
            LinkList_Unshift(l,val);
            move(0,0);
            Clr();
            Display_LinkList(l,0);
            break;
        case 'd':
            mvaddstr(maxline,0,"please enter the value");
            refresh();
            scanf("%d",&val);
            if(!LinkList_Find(l,val))
            {
                mvaddstr(maxline,0,"can not find the value!press any key to continue.");
                refresh();
                getch();
                Next_Oper();
                return;
            }
            LinkList_Delete(l,val);
            Clr();
            Display_LinkList(l,0);
            break;
        case 'c':
            LinkList_Clear(l);
            Clr();
            move(0,0);
            Display_LinkList(l,0);
            refresh();
            break;
        case 'r':
            int val1,val2;
            mvaddstr(maxline,0,"please enter the value to be replaced");
            refresh();
            scanf("%d",&val1);
            for(int i=0;i<=maxcol;i++)mvaddch(maxline,i,' ');
            if(!LinkList_Find(l,val1))
            {
                mvaddstr(maxline,0,"can not find the value!press any key to continue.");
                refresh();
                getch();
                Next_Oper();
                return;
            }
            move(0,0);
            refresh();
            mvaddstr(maxline,0,"please enter the new value");
            refresh();
            scanf("%d",&val2);
            LinkList_Replace(l,val1,val2);
            Clr();
            Display_LinkList(l,0);
            break;
        case 'f':
            mvaddstr(maxline,0,"please enter the value");
            refresh();
            scanf("%d",&val1);
            refresh();
            val2=LinkList_Find(l,val1);
            if(!val2)mvaddstr(maxline,0,"can not find the value!press any key to continue.");
            else 
            {
                mvaddstr(maxline,0,"find the value,the node`s index is ");
                printw("%d",val2);
                printw(".press any key to continue.");
            }
            refresh();
            getch();
            Next_Oper();
            return;
        case 's':
            Select_Sort(l);
            mvaddstr(maxline,0,"the select sort is over,press any key to continue.");
            refresh();
            getch();
            move(maxline,0);
            refresh();
            break;
    }
    Next_Oper();
}