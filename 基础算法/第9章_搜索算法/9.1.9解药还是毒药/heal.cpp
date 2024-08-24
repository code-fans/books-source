//解药还是毒药
#include <bits/stdc++.h>
using namespace std;

int n,m,x,a[101],b[101],visit[1024],step[1024];
queue <int>q;

int main()
{
  //freopen("heal.in","r",stdin);
  //freopen("heal.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (int i=1; i<=m; ++i)
    for (int j=1; j<=n; ++j)
    {
      scanf("%d",&x);
      if (x==0)
        a[i]+=(1<<(j-1));//好的
      else if (x==-1)
        b[i]+=(1<<(j-1));//病的
    }
  q.push((1<<n)-1);
  visit[(1<<n)-1]=1;
  while (!q.empty())
  {
    int x=q.front();
    q.pop();
    if (!x)
    {
      printf("%d\n",step[x]);
      return 0;
    }
    for (int i=1; i<=m; ++i)
    {
      int y=x&a[i]|b[i];
      if (!visit[y])
      {
        q.push(y);
        visit[y]=1;
        step[y]=step[x]+1;
      }
    }
  }
  printf("The patient will be dead.\n");
  return 0;
}
