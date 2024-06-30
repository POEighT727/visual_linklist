#include<stdlib.h>
#include<time.h>
#include "./include/randomseq.h"
void Get_Randomseq(long long seq[],int n,int m)
{
    srand((unsigned)time(NULL));
    int exp=1,mod=m;
    while(mod--)exp*=10;
    if(m)for(int i=0;i<n;i++)seq[i]=rand()%exp;
    else for(int i=0;i<n;i++)seq[i]=rand();
}