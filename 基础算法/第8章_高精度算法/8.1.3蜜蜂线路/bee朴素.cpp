//蜜蜂线路
//模拟可知是一个fibonacci数列
#include <bits/stdc++.h>
using namespace std;
int n,m,len=1;
int f[1005][1005];//第一个下标表示第几个数，第二个下标表示该数位数

void Add(int x)
{
  for(int i=1; i<=len; i++)
    f[x][i]=f[x-1][i]+f[x-2][i];
  for(int i=1; i<=len; i++)
    if(f[x][i]>9)
    {
      f[x][i+1]++;
      f[x][i]-=10;
    }
  if(f[x][len+1])
    len++;
}

int main ()
{
  //freopen("bee.in","r",stdin);
  //freopen("bee.out","w",stdout);
  scanf("%d%d",&m,&n);
  f[1][1]=1,f[2][1]=1;
  for(int i=3; i<=n-m+1; i++)
    Add(i);
  for(int i=len; i; i--)
    printf("%d",f[n-m+1][i]);
  printf("\n");
  return 0;
}
