//��Ȼ����� - �����㷨
#include <bits/stdc++.h>
using namespace std;

int n, Num[50]= {1}, Count=0;

void Print(int k)
{
  printf("%d=%d",n,Num[1]);
  for(int i=2; i<k; i++)
    printf("+%d",Num[i]);
  printf("\n");
  ++Count;
}

void DFS(int k,int remain) //kΪ��ǰλ��,remainΪʣ�µ���
{
  if(remain==0 && k>2)     //k>2��ֹ���n=n���������
    Print(k);
  else
    for(int i=Num[k-1]; i<=remain; i++)
    {
      Num[k]=i;
      remain-=i;
      DFS(k+1,remain);
      remain+=i;           //�ָ�ԭ״̬�����
    }
}

int main()
{
  freopen("Distribution.in","r",stdin);
  freopen("Distribution.out","w",stdout);
  scanf("%d",&n);
  DFS(1,n);
  printf("%d\n",Count);
  return 0;
}
