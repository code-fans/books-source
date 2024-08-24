//如：
//n=728，x=7
//可以按照这样的思路：
//个位7:73个 7,17,...,727
//十位7:70个 70~79,170~179,...,670~679
//百位7:29个 700~728
//答案是172

#include<bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("NumX.in","r",stdin);
  //freopen("NumX.out","w",stdout);
  long long n,x,m=1,ans=0;
  scanf("%lld%lld",&n,&x);
  while(m<=n)
  {
    int L=n/(m*10),P=n/m%10,R=n%m;
    if(x)                          //x不为0时
      if(P>x)//如果P>x，说明有(L+1)*m个x（如求1~728中个位7的个数，则为（72+1）*1=73）
        ans+=(L+1)*m;
      else if(P==x)
        ans+=L*m+R+1; //如果P=x，说明有L*m+R+1个x（如求1~728中百位7的个数，则为0*100+28+1=29）
      else
        ans+=L*m; //如果P<x，说明有L*m个x（如求1~728中十位7的个数，则为7*10个）
    else  //x=0的情况和x！=0的情况有所不同
      ans+=P?L*m:(L-1)*m+R+1;
    m*=10;
  }
  printf("%lld\n",ans);
  return 0;
}
