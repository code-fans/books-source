//��������
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
  Mul[rt]=1;                                        //�˷�����ǳ�ʼΪ1
  Len[rt]=R-L+1;
  if(L==R)
  {
    scanf("%lld",&Sum[rt]);                         //����Ҷ���ֵ
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
  Sum[lson]=(Sum[lson]*Mul[rt]+Add[rt]*Len[lson])%p;//����Ӽ���Sumֵ
  Sum[rson]=(Sum[rson]*Mul[rt]+Add[rt]*Len[rson])%p;//�Ҷ��Ӽ���Sumֵ
  Mul[lson]=(Mul[lson]*Mul[rt])%p;                  //��������·ų˱��
  Mul[rson]=(Mul[rson]*Mul[rt])%p;                  //���Ҷ����·ų˱��
  Add[lson]=(Add[lson]*Mul[rt]+Add[rt])%p;          //��������·żӱ��
  Add[rson]=(Add[rson]*Mul[rt]+Add[rt])%p;          //���Ҷ����·żӱ��
  Mul[rt]=1;                                        //�·����,����ǹ�1
  Add[rt]=0;                                        //�·����,����ǹ�0
}

void UpMul(ll rt,ll L,ll R,ll x,ll y,ll k)
{
  if(x>R || y<L)                       //�����������˳�
    return;
  if(x<=L && y>=R)                     //�����������ڣ����º��˳�
  {
    Sum[rt]=(Sum[rt]*k)%p;
    Mul[rt]=(Mul[rt]*k)%p;
    Add[rt]=(Add[rt]*k)%p;
    return;
  }
  PushDown(rt,L,R);                    //û�˳������´�ֵ����
  UpMul(lson,L,mid,x,y,k);
  UpMul(rson,mid+1,R,x,y,k);
  Sum[rt]=(Sum[lson]+Sum[rson])%p;
}

void UpAdd(ll rt,ll L,ll R,ll x,ll y,ll k)
{
  if(x>R || y<L)                       //�����������˳�
    return;
  if(x<=L && y>=R)                     //�����������ڣ����º��˳�
  {
    Sum[rt]=(Sum[rt]+Len[rt]*k)%p;
    Add[rt]=(Add[rt]+k)%p;
    return;
  }
  PushDown(rt,L,R);                    //û�˳������´�ֵ����
  UpAdd(lson,L,mid,x,y,k);
  UpAdd(rson,mid+1,R,x,y,k);
  Sum[rt]=(Sum[lson]+Sum[rson])%p;
}

ll Query(ll rt,ll L,ll R,ll x,ll y)
{
  if(x>R || y<L)                      //���������򷵻�0
    return 0;
  if(x<=L && y>=R)                    //�����������򷵻�ֵ
    return Sum[rt];
  PushDown(rt,L,R);                   //û�˳������´�ֵ����
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
