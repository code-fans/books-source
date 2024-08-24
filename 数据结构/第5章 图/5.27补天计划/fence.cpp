//²¹Ìì¼Æ»®
#include<bits/stdc++.h>
using namespace std;
const int N=510;

int du[N],ans[N*3],Map[N][N];
int m,ans_tot,st;

void Init()
{
  scanf("%d",&m);
  for (int i=1,x,y; i<=m; i++)
  {
    scanf("%d%d",&x,&y);
    Map[x][y]++;
    Map[y][x]++;
    du[x]++;
    du[y]++;
  }
  for(int i=1; i<=500; i++)
    if(du[i]%2==1)
    {
      st=i;
      break;
    }
  if(st==0)
  {
    for(int i=1; i<=500; i++)
      if(du[i])
      {
        st=i;
        break;
      }
  }
}

void Dfs(int x)
{
  for(int i=1; i<=500; i++)
    if (Map[x][i])
    {
      Map[x][i]--;
      Map[i][x]--;
      du[i]--;
      du[x]--;
      Dfs(i);
    }
  ans[++ans_tot]=x;
}

int main()
{
  //freopen("fence.in","r",stdin);
  //freopen("fence.out","w",stdout);
  Init();
  Dfs(st);
  for (int i=ans_tot; i>=1; i--)
    printf("%d\n",ans[i]);
  return 0;
}

