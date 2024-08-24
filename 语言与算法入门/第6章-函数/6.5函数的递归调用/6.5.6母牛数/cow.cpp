//母牛数
#include<bits/stdc++.h>
using namespace std;
typedef long long ULL;//typedef定义long long的别名为ULL

ULL num[65];          //此处的long long就可表示为ULL

ULL Cow(int n)
{
  if(n<=4)
    return n;
  if(num[n])                 //如果该值之前已经求出
    return num[n];           //无需递归，直接取值
  else
    num[n]=Cow(n-1)+Cow(n-3);//递归算出的值先存入num[n]
  return num[n];             //再返回结果num[n]
}

int main()
{
  freopen("cow.in","r",stdin);
  freopen("cow.out","w",stdout);
  int n;
  while(scanf("%d",&n)==1)
    printf("%lld\n",Cow(n));
  return 0;
}
