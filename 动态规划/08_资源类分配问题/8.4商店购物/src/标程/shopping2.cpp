//…ÃµÍπ∫ŒÔ
#include <bits/stdc++.h>
using namespace std;
#define MAXN 10

typedef struct
{
  int c;
  int m;
} NODE;

NODE s[MAXN];
long f[MAXN][MAXN][MAXN][MAXN][MAXN];
int cost[105][1005];
int Num,t;

int main()
{
  freopen("shopping2.in","r",stdin);
  freopen("shopping2.out","w",stdout);
  int i,j,n,l,a1,a2,a3,a4,a5;
  cin>>Num;
  memset(cost,0,sizeof(cost));
  for(i=1; i<=Num; i++)
  {
    cin>>n;
    for(j=1; j<=n; j++)
    {
      cin>>l;
      cin>>cost[i][l];
    }
    cin>>cost[i][1001];
  }
  for(cin>>t,i=1; i<=t; i++)
  {
    cin>>s[i].c>>s[i].m>>cost[++Num][1001];
    cost[Num][s[i].c]=1;
  }
  memset(f,1,sizeof(f));
  f[0][0][0][0][0]=0;
  for(i=1; i<=Num; i++)
  {
    a1=cost[i][s[1].c];
    a2=cost[i][s[2].c];
    a3=cost[i][s[3].c];
    a4=cost[i][s[4].c];
    a5=cost[i][s[5].c];
    for(int a=a1; a<=s[1].m; a++)
      for(int b=a2; b<=s[2].m; b++)
        for(int c=a3; c<=s[3].m; c++)
          for(int d=a4; d<=s[4].m; d++)
            for(int e=a5; e<=s[5].m; e++)
              f[a][b][c][d][e]=
                min(f[a][b][c][d][e],f[a-a1][b-a2][c-a3][d-a4][e-a5]+cost[i][1001]);
  }
  cout<<f[s[1].m][s[2].m][s[3].m][s[4].m][s[5].m]<<endl;
  return 0;
}

