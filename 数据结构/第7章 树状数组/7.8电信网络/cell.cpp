//电信网络
#include <bits/stdc++.h>
#define MAXN 1025
using namespace std;

int t[MAXN][MAXN];
int lowbit[MAXN];
int s;                               //矩阵的维数

void Update(int x,int y,int value)
{
  for(int i=x; i<=s; i+=lowbit[i])
    for(int j=y; j<=s; j+=lowbit[j])
      t[i][j]+=value;
}

int GetSum(int x,int y)              //查询第1行到第x行，第1列到第y列的和
{
  int sum=0;
  for(int i=x; i>0 ; i-=lowbit[i])
    for(int j=y ; j>0 ; j-=lowbit[j])
      sum+=t[i][j];
  return sum;
}

int main()
{
  freopen("cell.in","r",stdin);
  freopen("cell.out","w",stdout);
  int X,Y,A,L,B,R,T;
  for(int i=1; i<=MAXN ; i++)        //预处理lowbit
    lowbit[i]=i&(-i);
  int Option;
  while(true)
  {
    scanf("%d",&Option);
    if(Option==0)                    //初始化
    {
      scanf("%d",&s);
      memset(t,0,sizeof(t));
    }
    else if(Option==1)              //对于矩阵的X，Y坐标增加A
    {
      scanf("%d%d%d",&X,&Y,&A);
      Update(X+1,Y+1,A);
    }
    else if(Option==2)              //询问(L，B)到(R，T)区间内值的总和
    {
      scanf("%d%d%d%d",&L,&B,&R,&T);
      L++,B++,R++,T++;
      printf("%d\n",GetSum(R,T)+GetSum(L-1,B-1)-GetSum(R,B-1)-GetSum(L-1,T));
    }
    else
      return 0;
  }
}

