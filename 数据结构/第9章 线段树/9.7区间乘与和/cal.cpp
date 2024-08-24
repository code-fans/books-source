//区间乘与加
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=100005;
#define lson rt<<1
#define rson rt<<1|1
#define mid  (L+R>>1)

ll Len[MAXN<<2],Sum[MAXN<<2],Mul[MAXN<<2],Add[MAXN<<2];
ll n,m,p;

void Build(ll rt,ll L,ll R)
{
  Mul[rt]=1;                                        //乘法懒标记初始为1
  Len[rt]=R-L+1;
  if(L==R)
  {
    scanf("%lld",&Sum[rt]);                         //输入叶结点值
    return;
  }
  Build(lson,L,mid);
  Build(rson,mid+1,R);
  Sum[rt]=(Sum[lson]+Sum[rson])%p;
}

void PushDown(ll rt,ll L,ll R)
{
  if(Mul[rt]==1 && Add[rt]==0)
    return;
  Sum[lson]=(Sum[lson]*Mul[rt]+Add[rt]*Len[lson])%p;//左儿子计算Sum值
  Sum[rson]=(Sum[rson]*Mul[rt]+Add[rt]*Len[rson])%p;//右儿子计算Sum值
  Mul[lson]=(Mul[lson]*Mul[rt])%p;                  //向左儿子下放乘标记
  Mul[rson]=(Mul[rson]*Mul[rt])%p;                  //向右儿子下放乘标记
  Add[lson]=(Add[lson]*Mul[rt]+Add[rt])%p;          //向左儿子下放加标记
  Add[rson]=(Add[rson]*Mul[rt]+Add[rt])%p;          //向右儿子下放加标记
  Mul[rt]=1;                                        //下放完毕,懒标记归1
  Add[rt]=0;                                        //下放完毕,懒标记归0
}

void UpMul(ll rt,ll L,ll R,ll x,ll y,ll k)
{
  if(x>R || y<L)                       //不在区间则退出
    return;
  if(x<=L && y>=R)                     //包含在区间内，更新后退出
  {
    Sum[rt]=(Sum[rt]*k)%p;
    Mul[rt]=(Mul[rt]*k)%p;
    Add[rt]=(Add[rt]*k)%p;
    return;
  }
  PushDown(rt,L,R);                    //没退出就向下传值更新
  UpMul(lson,L,mid,x,y,k);
  UpMul(rson,mid+1,R,x,y,k);
  Sum[rt]=(Sum[lson]+Sum[rson])%p;
}

void UpAdd(ll rt,ll L,ll R,ll x,ll y,ll k)
{
  if(x>R || y<L)                       //不在区间则退出
    return;
  if(x<=L && y>=R)                     //包含在区间内，更新后退出
  {
    Sum[rt]=(Sum[rt]+Len[rt]*k)%p;
    Add[rt]=(Add[rt]+k)%p;
    return;
  }
  PushDown(rt,L,R);                    //没退出就向下传值更新
  UpAdd(lson,L,mid,x,y,k);
  UpAdd(rson,mid+1,R,x,y,k);
  Sum[rt]=(Sum[lson]+Sum[rson])%p;
}

ll Query(ll rt,ll L,ll R,ll x,ll y)
{
  if(x>R || y<L)                      //不在区间则返回0
    return 0;
  if(x<=L && y>=R)                    //包含在区内则返回值
    return Sum[rt];
  PushDown(rt,L,R);                   //没退出则向下传值更新
  return (Query(lson,L,mid,x,y)+Query(rson,mid+1,R,x,y))%p;
}

int main()
{
  scanf("%lld%lld%lld",&n,&m,&p);
  Build(1,1,n);
  for(ll i=1,Q,x,y,k; i<=m; i++)
  {
    scanf("%lld%lld%lld",&Q,&x,&y);
    if(Q^3)
    {
      scanf("%lld",&k);
      Q==1?UpMul(1,1,n,x,y,k):UpAdd(1,1,n,x,y,k);
    }
    else
      printf("%lld\n",Query(1,1,n,x,y));
  }
  return 0;
}
