//��������
#include <bits/stdc++.h>
#define MAXN 1025
using namespace std;

int t[MAXN][MAXN];
int lowbit[MAXN];
int s;                               //�����ά��

void Update(int x,int y,int value)
{
  for(int i=x; i<=s; i+=lowbit[i])
    for(int j=y; j<=s; j+=lowbit[j])
      t[i][j]+=value;
}

int GetSum(int x,int y)              //��ѯ��1�е���x�У���1�е���y�еĺ�
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
  for(int i=1; i<=MAXN ; i++)        //Ԥ����lowbit
    lowbit[i]=i&(-i);
  int Option;
  while(true)
  {
    scanf("%d",&Option);
    if(Option==0)                    //��ʼ��
    {
      scanf("%d",&s);
      memset(t,0,sizeof(t));
    }
    else if(Option==1)              //���ھ����X��Y��������A
    {
      scanf("%d%d%d",&X,&Y,&A);
      Update(X+1,Y+1,A);
    }
    else if(Option==2)              //ѯ��(L��B)��(R��T)������ֵ���ܺ�
    {
      scanf("%d%d%d%d",&L,&B,&R,&T);
      L++,B++,R++,T++;
      printf("%d\n",GetSum(R,T)+GetSum(L-1,B-1)-GetSum(R,B-1)-GetSum(L-1,T));
    }
    else
      return 0;
  }
}

