#include <bits/stdc++.h>
using namespace std;
const int MAXINT=2147483647;

double k[2001],f[2001][2001][2];
int a[2001],b[2001],Map[301][301];
int n,m,v,e;

int main()
{
  int i,j;
  cin>>n>>m>>v>>e;
  for(i=1; i<=v; i++)
    for(j=1; j<=v; j++)
      i==j?Map[i][j]=0:Map[i][j]=MAXINT;
  for(i=1; i<=n; i++)
    for(j=0; j<n; j++)
    {
      f[i][j][0]=MAXINT;
      f[i][j][1]=MAXINT;
    }
  f[1][0][0]=0;
  f[1][1][1]=0;
  int x,y,z;
  for(i=1; i<=n; i++)
    cin>>a[i];
  for(i=1; i<=n; i++)
    cin>>b[i];
  for(i=1; i<=n; i++)
    cin>>k[i];
  for(i=1; i<=e; i++)
  {
    cin>>x>>y>>z;
    if(Map[x][y]>z)
    {
      Map[x][y]=z;
      Map[y][x]=z;
    }
  }
  for(int o=1; o<=v; o++)      //floyd
    for(i=1; i<=v; i++)
      for(j=1; j<=v; j++)
        if((Map[i][j]>Map[i][o]+Map[o][j])&&(Map[i][o]!=MAXINT)&&(Map[o][j]!=MAXINT))
          Map[i][j]=Map[i][o]+Map[o][j];
  for(i=2; i<=n; i++)
    f[i][0][0]=f[i-1][0][0]+Map[a[i-1]][a[i]];
  for(i=2; i<=n; i++)
    for(j=1; j<=min(m,i); j++)
    {
      f[i][j][0]=min(f[i-1][j][0] + Map[a[i-1]][a[i]],
                     f[i-1][j][1] + Map[a[i-1]][a[i]]*(1.0-k[i-1])+Map[b[i-1]][a[i]]*k[i-1]);
      f[i][j][1]=min(f[i-1][j-1][0] + Map[a[i-1]][a[i]]*(1.0-k[i])+Map[a[i-1]][b[i]]*k[i],
                     f[i-1][j-1][1]
                     + Map[a[i-1]][a[i]]*(1.0-k[i-1])*(1.0-k[i])//都没有成功
                     + Map[b[i-1]][a[i]]*k[i-1]*(1.0-k[i])      //上一个成功，现在没成功
                     + Map[a[i-1]][b[i]]*(1.0-k[i-1])*(k[i])    //上一个没成功，现在成绩
                     + Map[b[i-1]][b[i]]*k[i-1]*k[i]);          //都成功了
    }
  double ans=f[n][0][0];
  for(i=1; i<=m; i++)
  {
    if(f[n][i][0]<ans)
      ans=f[n][i][0];
    if(f[n][i][1]<ans)
      ans=f[n][i][1];
  }
  cout<<setprecision(2)<<fixed<<ans;
  return 0;
}

