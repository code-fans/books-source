#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=2048;

int b[MAXN*MAXN][2];
ll dp[1<<13][13];
int n,m,tot;

void DFS(int pos,int s,int state)//�ҳ���i-1��״̬s���i����Щ״̬state��ƥ��
{
  if(pos>m)
    return;
  if(pos==m)
  {
    b[tot][0]=s;
    b[tot++][1]=state;
    return;
  }
  DFS(pos+1,s<<1,state<<1|1); //0->1
  DFS(pos+1,s<<1|1,state<<1); //1->0
  DFS(pos+2,s<<2|3,state<<2|3); //11->11
}

int main()
{
  //freopen("Imprisonment.in","r",stdin);
  //freopen("Imprisonment.out","w",stdout);
  while(cin>>n>>m,n)
  {
    if(m>n)
      swap(n,m);
    tot=0;
    DFS(0,0,0);
    memset(dp,0,sizeof(dp));
    dp[(1<<m)-1][0]=1;           //��0��ȫ��Ϊ1����ʾ����
    for(int i=1; i<=n; i++)
      for(int j=0; j<tot; j++)   //ö������״̬
        dp[b[j][1]][i]+=dp[b[j][0]][i-1];
    cout<<dp[(1<<m)-1][n]<<endl;
  }
  return 0;
}

