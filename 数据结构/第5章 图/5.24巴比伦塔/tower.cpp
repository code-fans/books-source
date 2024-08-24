//�ͱ�����
#include <bits/stdc++.h>
using namespace std;
const int MAXN=35;
int n;
struct node
{
  int x,y,z;
} cube[MAXN*3];
int G[MAXN*3][MAXN*3];
int dp[MAXN*3];

int Judge(int i,int j)                        //�ж�i�ɲ����Է���j��
{
  return ((cube[i].x<cube[j].x && cube[i].y<cube[j].y) ||
          (cube[i].x<cube[j].y &&cube[i].y<cube[j].x) ) ? 1:0;
}

int Solve(int a)
{
  if(dp[a]) return dp[a];                     //���仯����
  dp[a]=cube[a].z;
  for(int j=0; j<n; j++)
    if(G[a][j]==1)
      dp[a]=max(dp[a], Solve(j)+ cube[a].z);
  return dp[a];
}

int main()
{
  freopen("tower.in","r",stdin);
  freopen("tower.out","w",stdout);
  int T=0,x,y,z;
  while(cin>>n,n)
  {
    memset(dp,0,sizeof(dp));
    for(int i=0; i<n; i++)
    {
      cin>>x>>y>>z;
      cube[i].x=x,    cube[i].y=y,    cube[i].z=z;
      cube[i+n].x=y,  cube[i+n].y=z,  cube[i+n].z=x;
      cube[i+2*n].x=z,cube[i+2*n].y=x,cube[i+2*n].z=y;
    }
    n*=3;
    for(int i=0; i<n; i++)
      for(int j=i+1; j<n; j++)
      {
        G[i][j]= Judge(i,j);                  //�ж�i�Ƿ������j֮��
        G[j][i]= Judge(j,i);
      }
    int ans=0;
    for(int i=0; i<n; i++)
      ans=max(ans,Solve(i));
    cout<<"Case "<<++T<<": maximum height = "<<ans<<endl;
  }
}

