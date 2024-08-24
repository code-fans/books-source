//油桶问题 - 递归算法(一组数据不过）
#include <bits/stdc++.h>
using namespace std;

int a[100+1];
int m,n;

int p(int n,int m)
{
  if(n==0)
    return 0;
  if(a[n]==m || p(n-1,m-a[n]) || (p(n-1,m)))
    return 1;
  return 0;
}

int main()
{
  freopen("oil.in","r",stdin);
  freopen("oil.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  printf("%s\n",p(n,m)?"yes":"no");
  return 0;
}

