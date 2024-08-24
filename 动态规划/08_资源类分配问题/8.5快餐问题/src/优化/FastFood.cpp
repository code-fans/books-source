#include<bits/stdc++.h>
using namespace std;
const int maxn = 111;

int A,B,C,p1,p2,p3,n,t[maxn],ans;
int f[11][maxn][maxn][maxn];

int main()
{
  //freopen("FastFood.in","r",stdin);
  //freopen("FastFood.out","w",stdout);
  scanf("%d%d%d%d%d%d%d",&A,&B,&C,&p1,&p2,&p3,&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&t[i]);
    t[i]+=t[i-1];
  }
  for(int i=1; i<=n; i++)
    for(int a=A; a*p1<=t[i]&&a<=100; a++)
      for(int b=B; a*p1+b*p2<=t[i]&&b<=100; b++)
        for(int c=C; a*p1+b*p2+c*p3<=t[i]&&c<=100; c++)
        {
          f[i][a][b][c]=max(f[i][a-A][b-B][c-C]+1,max(f[i-1][a-A][b-B][c-C]+1,f[i][a][b][c]));
          ans=max(ans,f[i][a][b][c]);
        }
  cout<<ans<<endl;
  return 0;
}

