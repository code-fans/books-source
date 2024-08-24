//矿石检测
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL  n,m,s;
LL  Sum[200005],Sumv[200005];
int Value[200005],Weight[200005];
int ST[200005],END[200005];               //保存区间

void PreSum(LL S)                         //计算前缀和
{
  Sum[0]=Sumv[0]=0ll;                     //long long型赋值后面要加ll
  for(int i=1; i<=n; i++)
    if(Weight[i]>=S)
    {
      Sum[i]=Sum[i-1]+1;                  //前缀和计算
      Sumv[i]=Sumv[i-1]+Value[i];
    }
    else
      Sumv[i]=Sumv[i-1],Sum[i]=Sum[i-1];
}

LL Calc(LL MID)                           //计算Ｙ值
{
  LL ans=0ll;
  for(int i=1; i<=m; i++)
    ans+=(Sum[END[i]]-Sum[ST[i]-1])*(Sumv[END[i]]-Sumv[ST[i]-1]);
  return ans;
}

int main()
{
  //freopen("qc.in","r",stdin);
  //freopen("qc.out","w",stdout);
  scanf("%lld %lld %lld",&n,&m,&s);
  LL Start=0ll,End=0ll;                   //上界和下界, long long型赋值后面要加ll
  for(int i=1; i<=n; ++i)
  {
    scanf("%d %d",&Weight[i],&Value[i]);
    End=max(LL(Weight[i]),End);           //找出最重的,比较的两数均设为LL类型
  }
  for(int i=1; i<=m; ++i)
    scanf("%d %d",&ST[i],&END[i]);
  LL Ans=pow(2,63)-1;                     //即最大值9223372036854775807
  while(Start<=End)                       //二分查找
  {
    LL Mid=(Start+End)>>1;
    PreSum(Mid);                          //计算前缀和
    Ans=min(Ans,abs(Calc(Mid)-s));        //更新Ans,以尽可能逼近最小值
    if(Ans==0)
      break;
    s<Y ? Start=Mid+1:End=Mid-1;
  }
  printf("%lld\n",Ans);
  return 0;
}

