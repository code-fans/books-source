//蜜蜂线路 —滚动数组实现
#include <bits/stdc++.h>
using namespace std;
#define F(i) F[(i)%3]

int n,m,len=1;
int F[3][1005];

void Add(int a[],int b[],int ans[])
{
  for(int i=1; i<=len; i++)
    ans[i]=a[i]+b[i];
  for(int i=1; i<=len; i++)
    if(ans[i]>=10)
    {
      ans[i+1]++;
      ans[i]-=10;
    }
  if(ans[len+1])
    len++;
}

int main ()
{
  freopen("bee.in","r",stdin);
  freopen("bee.out","w",stdout);
  scanf("%d%d",&m,&n);
  F[1][1]=1,F[2][1]=1;
  for(int i=3; i<=n-m+1; i++)
    Add(F(i-2),F(i-1),F(i));
  for(int i=len; i; i--)
    printf("%d",F(n-m+1)[i]);
  printf("\n");
  return 0;
}
