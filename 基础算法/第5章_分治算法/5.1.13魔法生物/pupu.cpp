//魔法生物
//用total[n]、ans[n}分别表示【前n层皮肤同时为透明的天数】和【第n层皮肤变为透明的天数】
//（ans[n]即为题中所求）
//（举一个有4层皮肤的pupu为例，+表示不透明，  -表示透明）
//第一天       第二天    第三天    第四天    第五天   第六天   第七天   第八天    第九天
//    +          -         +          -         +       -        +        -          +
//    +          +         -          -         +       +        -        -          +
//    +          +         +          +         -       -        -        -          +
//    +          +         +          +         +       +        +        +          -
//有ans[1]=total[1]=2
//ans[2]=3, total[2]=4
//ans[3]=5, total[3]=8
//ans[4]=9
//可以看到要使第n层皮肤变透明，必须要前n-1层同时为透明，然后第二天第n层皮肤就会变为透明，同时前n-1层皮肤变成不透明
//即有ans[n]=total[n-1]+1----------------------------------------1
//而要使前n层皮肤同时为透明，则必须第n层皮肤变成透明，然后前n-1层同时为透明，由于第n层皮肤变成透明的那一天，也就是前n-1层皮肤同时为透明的过程的第一天
//即有total[n]=ans[n]+total[n-1]-1---------------------------------------2
//由1式代入2式可得total[n]=total[n-1]*2,又total[1]=2
//所以total[n]=2^n
//所以ans[n]=total[n-1]+1=2^(n-1)+1
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Pow(ll a,ll b,ll Mod)
{
  ll ret=1;
  while(b)
  {
    if(b&1)
      ret=ret*a%Mod;
    a=a*a%Mod;
    b>>=1;
  }
  return ret;
}

int main ()
{
  freopen("pupu.in","r",stdin);
  freopen("pupu.out","w",stdout);
  ll n;
  while(scanf("%lld",&n) && n)
    printf("%lld\n",(Pow(2,n-1,n)+1)%n);
  return 0;
}
