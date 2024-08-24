#include <bits/stdc++.h>
using namespace std;
int Que[500050],head,tail;
long long sum[500050],s[500050],Dp[500050];

double Y(int j)
{
  return Dp[j]+s[j]*s[j];
}

double Slop(int j1,int j2)
{
  return (Y(j2)-Y(j1))/(s[j2]-s[j1]);
}

int main()
{
  freopen("toy.in","r",stdin);
  freopen("toy.out","w",stdout);

  int n,L;
  scanf("%d%d",&n,&L);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&sum[i]);
    sum[i]+=sum[i-1];
    s[i]=sum[i]+i ;
  }
  L++;
  head=tail=1;
  for(int i=1; i<=n; i++)
  {
    while(head<tail && Slop(Que[head],Que[head+1])<=2.0*(s[i]-L))
      head++;
    Dp[i]=Dp[Que[head]]+(s[i]-s[Que[head]]-L)*(s[i]-s[Que[head]]-L);
    while(head<tail && Slop(Que[tail-1],Que[tail])>Slop(Que[tail],i))
      tail--;
    Que[++tail]=i;
  }
  printf("%lld\n",Dp[n]);
  return 0;
}

