//��Ȼ����� - �ǵݹ��㷨
#include <bits/stdc++.h>
using namespace std;

int Num[100];
int n,sum,Count;

void Print(int k)
{
  printf("%d=%d",n,Num[1]);
  for(int i=2; i<=k; i++)
    printf("+%d",Num[i]);
  printf("\n");
  ++Count;
}

int main()
{
  freopen("Distribution.in","r",stdin);
  freopen("Distribution.out","w",stdout);
  scanf("%d",&n);
  Num[1]=1;
  for(int p=1; p>=1;)          //pΪ��ջ��ָ��
    if(sum+Num[p]<n)
    {
      sum+=Num[p];
      p++;                     //ָ����һ������λ��
      Num[p]=Num[p-1];         //����������ٲ�С��ǰ�����
    }
    else                       //�������ĺʹ��ڵ���n�����
    {
      if(sum+Num[p]==n && p!=1)//p!=1��ֹ����n=n�����
        Print(p);              //�ҵ�һ��⣬���
      p--;                     //������һ������λ��
      sum-=Num[p];
      Num[p]++;                //��һ������1������Ѱ����һ���
    }
  printf("%d\n",Count);
  return 0;
}
