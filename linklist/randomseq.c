#include<stdlib.h>
#include<time.h>
#include "./include/randomseq.h"
void Get_Randomseq(long long seq[],int n,int m)
{
    srand((unsigned)time(NULL));
    int exp=1;
    while(m--)exp*=10;
    for(int i=0;i<n;i++)seq[i]=rand()%exp;
}