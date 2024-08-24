//计算机病毒
//模拟即可
#include <bits/stdc++.h>
using namespace std;

int a[101][101];
char b[101][101];

int main()
{
  //freopen("virus.in","r",stdin);
  //freopen("virus.out","w",stdout);
  int n,m,ans=0;
  cin>>n;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
    {
      cin>>b[i][j];
      if(b[i][j]=='@')
      {
        a[i][j]=1;
        ans++;
      }
    }
  cin>>m;
  for(int t=1; t<m; t++)
    for(int i=1; i<=n; i++)
      for(int j=1; j<=n; j++)
        if(a[i][j]==t)
          for(int y=0; y<=2; y+=2)
          {
            if(b[i-1+y][j]=='*')
            {
              ans++;
              b[i-1+y][j]='@';
              a[i-1+y][j]=t+1;
            }
            if(b[i][j-1+y]=='*')
            {
              ans++;
              b[i][j-1+y]='@';
              a[i][j-1+y]=t+1;
            }
          }
  cout<<ans<<endl;
  return 0;
}

