//쳲��������иĽ��㷨
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;//����unsigned long long�ı���ΪULL

ULL a[500];
ULL f(int n)
{
  if(n<3)
    a[n]=1;
  if(a[n]>0)//���������n���ֵ
    return a[n];//ֱ�ӷ��ظ�ֵ
  a[n]=f(n-1)+f(n-2);//����ݹ������ֵ
  return a[n];
}

int main()
{
  freopen("f.in","r",stdin);
  freopen("f.out","w",stdout);
  int n;
  scanf("%d",&n);
  printf("%llu\n",f(n));
  return 0;
}

