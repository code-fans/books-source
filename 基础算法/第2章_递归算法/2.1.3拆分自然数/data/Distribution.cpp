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
  //freopen("Distribution.in","r",stdin);
  //freopen("Distribution.out","w",stdout);
  cin>>n;
  Num[1]=1;
  for(int p=1; p>=1;) //pΪ��ջ��ָ��
  {
    if(sum+Num[p]<n)
    {
      sum+=Num[p];
      p++;
      Num[p]=Num[p-1];
    }
    else
    {
      if(sum+Num[p]==n && p!=1)//p!=1��ֹ����n=n�����
        Print(p);
      p--;
      sum-=Num[p];
      Num[p]++;
    }
  }
  cout<<Count<<endl;
  return 0;
}
