//太空堡垒
#include <bits/stdc++.h>
using namespace std;

struct
{
  int a,b,sum;
} t[200040];
int people[50010];                        //people[50010]存放每个点上的船数

void BuildTree(int x,int y,int num)       //构造线段树
{
  t[num].a=x;                             //确定左端点为x
  t[num].b=y;                             //确定右端点为y
  if(x==y)                                //如果x==y，说明已经是叶子结点了
    t[num].sum=people[y];                 //则人数为单个的堡垒飞船数
  else
  {
    int Lson=num<<1,Rson=Lson|1;          //左子结点为num*2,右子结点为num*2+1
    BuildTree(x,((x+y)>>1),Lson);         //递归构造左儿子树
    BuildTree(((x+y)>>1)+1,y,Rson);       //递归构造右儿子树
    t[num].sum=t[Lson].sum+t[Rson].sum;   //父结点等于左右子结点的和
  }
}

int Query(int L,int R,int num)            //初始num为1，即从根结点开始查找
{
  if(L <= t[num].a && R >= t[num].b)      //如果在包含区间内，则返回值
    return t[num].sum;
  int min = (t[num].a+t[num].b)>>1;       //取左右端点的中间
  int ans = 0;
  if(L <= min)
    ans += Query(L, R, num<<1);           //递归左子树
  if(R > min)
    ans += Query(L, R, num<<1|1);         //递归右子树
  return ans;
}

void Update(int i,int j,int num)          //第i个堡垒增加或减少j个飞船
{
  t[num].sum+=j;
  if(t[num].a==i && t[num].b==i)          //如果找到i的叶子结点，则停止
    return;
  if(i>(t[num].a+(t[num].b)>>1))          //如果点i在该线段的右边
    Update(i,j,num<<1|1);                 //则递归进入右子结点
  else
    Update(i,j,num<<1);                   //否则递归进入左子结点
}

int main()
{
  freopen("fort.in","r",stdin);
  freopen("fort.out","w",stdout);
  int a,b,n,t,Case=0;
  cin>>t;
  while(t--)
  {
    scanf("%d",&n);                       //注意读写要加速，否则会超时
    people[0]=0;
    for(int i=1; i<=n; i++)
      scanf("%d",&people[i]);
    BuildTree(1,n,1);                     //从根结点t[1]开始建线段树
    printf("Case %d:\n",++Case);
    getchar();                            //用于忽略换行符
    for(string command; cin>>command;)
    {
      if(command=="End")
        break;
      cin>>a>>b;
      if(command=="Query")
        printf("%d\n",Query(a,b,1));      //从根结点t[1]开始
      if(command=="Add")
        Update(a,b,1);                    //从根结点t[1]开始
      if(command=="Sub")
        Update(a,-b,1);                   //从根结点t[1]开始
    }
  }
  return 0;
}

