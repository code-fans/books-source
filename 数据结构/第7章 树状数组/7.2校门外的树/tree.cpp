//У�������
#include <bits/stdc++.h>
using namespace std;

const int n=50000;
int a[n],b[n];                 //a[]�������ţ�b[]��������

int Lowbit(int x)
{
  return x&(-x);
}

int GetSum(int n,int c[])
{
  int sum=0;
  for(; n>0; n-=Lowbit(n))
    sum+=c[n];
  return sum;
}

void Add(int i,int c[])
{
  for(; i<=n; i+=Lowbit(i))
    c[i]++;
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  int m,k,option,x,y;
  cin>>m>>k;
  while(k--)
  {
    cin>>option>>x>>y;
    if(option==1)
    {
      Add(x,a);             //a�������������
      Add(y,b);             //b�������������
    }
    else
      cout<<GetSum(y,a)-GetSum(x-1,b)<<"\n";
  }
  return 0;
}

