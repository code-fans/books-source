#include <bits/stdc++.h>
using namespace std;

const int MAXN=10010;
int F[MAXN];
int val[MAXN];

int find(int x)
{
  if(F[x]==-1)return x;
  int tmp=find(F[x]);
  val[x]^=val[F[x]];
  return F[x]=tmp;
}

map<int,int>mp;
int tol=0;
int insert(int x)
{
  if(mp.find(x)==mp.end())mp[x]=tol++;
  return mp[x];
}

int main()
{
  freopen("parity.in","r",stdin);
  freopen("parity.out","w",stdout);
  int n,m;
  int u,v;
  char str[20];
  while(scanf("%d%d",&n,&m)==2)
  {
    tol=0;
    memset(F,-1,sizeof(F));
    memset(val,0,sizeof(val));
    mp.clear();
    int ans=m;
    for(int i=0; i<m; i++)
    {
      scanf("%d%d%s",&u,&v,&str);
      if(u>v)swap(u,v);
      if(ans<m)continue;
      u=insert(u-1);
      v=insert(v);
      int tmp;
      if(str[0]=='e')tmp=0;
      else tmp=1;
      int t1=find(u);
      int t2=find(v);
      if(t1==t2)
      {
        if(val[u]^val[v]!=tmp)ans=i;
      }
      else
      {
        F[t2]=t1;
        val[t2]=tmp^val[u]^val[v];
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
