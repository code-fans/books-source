#include <bits/stdc++.h>
using namespace std;
const int MAXN=100005;

long long d[MAXN],g[MAXN];
int tmp[MAXN],f[MAXN],a[MAXN],b[MAXN],c[MAXN];
struct node
{
  long long ci, di_gi;                //ci:c[i],di_gi:d[i]+g[i]
  bool operator>(const node b) const  //比较斜率
  {
    return di_gi*b.ci>ci*b.di_gi;
  }
};

node Slope(node a,node b)             //斜率
{
  return node {a.ci-b.ci,a.di_gi-b.di_gi};
}

bool Cmp(int x,int y)
{
  return c[x]^c[y]?c[x]<c[y]:x<y;
}

void Cdq(int l,int r)
{
  if(l==r)
    return;
  int mid=l+r>>1;
  Cdq(l,mid);                 //前半部分先递归
  int cnt=0,FMaxDP=-1;
  for(int i=l; i<=r; ++i)
    tmp[++cnt]=i;
  sort(tmp+1,tmp+cnt+1,Cmp);  //按c[]排序,因决策点斜率优化是建立在c[k]<c[j]
  vector<node>v;
  for(int i=1,j; i<=cnt; ++i)
  {
    j=tmp[i];
    if(j<=mid)                //左半段c[k]<c[j]，可以进行斜率优化
    {
      if(f[j]<FMaxDP || (j && f[j]==0))//房子无法保留的跳过
        continue;
      if(f[j]>FMaxDP)         //找到更优的f[i]
      {
        FMaxDP=f[j];          //f[i]找到更优的
        v.clear();            //可能某些房子的状态被更改,所以要维护全新的下凸包
      }
      node p= {c[j],d[j]+g[j]};
      while(v.size()>=2 && Slope(v[v.size()-1],v[v.size()-2])>Slope(p,v[v.size()-1]))
        v.pop_back();        //按照前面的斜率式删除点
      v.push_back(p);
    }
    else    //前半部分对后半部分保持j<i且c[j]<=c[i]，可以满足DP转移
    {
      if(f[j]<FMaxDP+1)  //如果f[i]有更优值，则前面的转移无效
      {
        f[j]=FMaxDP+1;   //f[i]直接链到前面的Maxfdp,强条件f[i]=f[j]+1
        g[j]=5e18;
      }
      else if(f[j]>FMaxDP+1)         //不是这个值，就不转移它
        continue;
      int L=0,R=v.size()-1,k1,k2;
      while(L+2<R)        //由于维护的是下凸包，可以三分确定最优决策点范围
      {
        k1=L+(R-L+1)/3;
        k2=R-(R-L+1)/3;
        v[k1].ci*j+v[k1].di_gi<=v[k2].ci*j+v[k2].di_gi ? R=k2 : L=k1;
      }
      for(; L<=R; ++L)               //在找到的区间中更新更优答案
        g[j]=min(g[j],v[L].ci*j+v[L].di_gi+j*1ll*(j-1)/2+a[j]+b[j]);
    }
  }
  Cdq(mid+1,r);                      //递归后半段
}

int main()
{
  long long n,F=0,G=0;
  scanf("%lld",&n);
  for(int i=1; i<=n; ++i)
    scanf("%d",&a[i]);               //读入房子的美观程度
  for(int i=1; i<=n; ++i)
  {
    scanf("%d",&b[i]);               //读入房子的赔偿金
    c[i]=a[i]-i;                     //计算c[i]
    d[i]=i*(i+1)/2-a[i]*i-a[i];      //计算d[i]
    g[i]=5e18;                       //最小代价设为最大值
  }
  Cdq(0,n);                          //CDQ分治
  for(int i=1; i<=n; ++i)            //计算答案
    if(f[i]>F)                       //比原来的大就要更新最优解
      F=f[i],G=g[i]+(n-i)*(n-i+1ll)/2+(n-i)*1ll*a[i];
    else if(f[i]==F)                 //相同的解下找更优
      G=min(G, g[i]+(n-i)*(n-i+1ll)/2+(n-i)*1ll*a[i]);
  printf("%lld %lld\n",F,G);
  return 0;
}

