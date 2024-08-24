//平台上的小球
#include <bits/stdc++.h>
using namespace std;

int n,H[1001],L[1001],R[1001];

int main()
{
  freopen("ball.in","r",stdin);
  freopen("ball.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    scanf("%d%d%d",&H[i],&L[i],&R[i]);
  for(int i=1; i<=n; i++)
  {
    int AnsL=0,AnsR=0,h1=0,h2=0;
    for(int j=1; j<=n; j++)
      if(H[j]<H[i])                             //如果有更低的平台
      {
        if(H[j]>h1 && L[j]<L[i] && R[j]>=L[i]-1)//向左滚动
        {
          h1=H[j];
          AnsL=j;
        }
        if(H[j]>h2 && R[j]>R[i] && L[j]<=R[i]+1)//向右滚动
        {
          h2=H[j];
          AnsR=j;
        }
      }
    printf("%d %d\n",AnsL,AnsR);
  }
  return 0;
}

