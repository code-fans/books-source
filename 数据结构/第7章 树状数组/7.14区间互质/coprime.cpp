#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <vector>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define delf int m=(l+r)>>1
using namespace std;

const int MAX=200000+10;
int tree[MAX];
int v[MAX];
int vl[MAX];        //左端到哪
int vr[MAX];        //右端到哪
int mark[MAX];     //记录上一个素数出现的位置
int ans[MAX];
int n,m;
int cnt;
vector <int> vc[MAX];
vector <int> pri[MAX];

void init()
{
  for (int i=2; i<=200000; i++)
    for (int t=i; t<=200000; t+=i)
      pri[t].push_back(i);
  return ;
}

void pre()      //预处理出每个数的左边第一个非互质的位置和右边第一个非互质的位置
{
  for (int i=0; i<=n; i++)
    vc[i].clear();
  for (int i=1; i<=n; i++)
  {
    for (int t=0; t<pri[v[i]].size(); t++)
    {
      int p=pri[v[i]][t];
      if (mark[p]==0)
      {
        mark[p]=i;
        continue ;
      }
      int a=mark[p];
      if (vr[a]==0)
        vr[a]=i;
      if (vl[i]<a)
        vl[i]=a;
      mark[p]=i;
    }
    vc[vl[i]].push_back(i);
  }
  return ;
}

struct node
{
  int l,r,id;
} q[MAX];

bool cmp(node a,node b)
{
  return a.l<b.l;
}

int lowbit(int a)
{
  return (a)&(-a);
}

int sum(int a)
{
  int s=0;
  while (a>0)
  {
    s+=tree[a];
    a-=lowbit(a);
  }
  return s;
}

void update(int a,int b)
{
  while (a<=n)
  {
    tree[a]+=b;
    a+=lowbit(a);
  }
}

int main()
{
  //freopen("coprime1.in","r",stdin);
  //freopen("coprime1.ans","w",stdout);
  init();
  while (~scanf("%d%d",&n,&m)&&n+m)
  {
    for (int i=1; i<=n; i++)
      scanf("%d",&v[i]);
    for (int i=1; i<=m; i++)
    {
      scanf("%d%d",&q[i].l,&q[i].r);
      q[i].id=i;
    }
    sort(q+1,q+m+1,cmp);
    for (int i=1; i<=n; i++)
      tree[i]=0;
    for (int i=1; i<=n; i++)
      vl[i]=0;
    for (int i=1; i<=n; i++)
      vr[i]=0;
    memset(mark,0,sizeof(mark));
    pre();
    int cur=1;
    for (int i=0; i<=n; i++)
    {
      while (q[cur].l==i)
      {
        ans[q[cur].id]=sum(q[cur].r)-sum(q[cur].l-1);
        cur++;
      }
      for (int t=0; t<vc[i].size(); t++)
      {
        update(vc[i][t],1);
        if (vr[vc[i][t]]!=0)
          update(vr[vc[i][t]],-1);
      }
      if (vr[i]!=0)
        update(vr[i],1);
    }
    for (int i=1; i<=m; i++)
      printf("%d\n",ans[i]);
  }
}

