//后缀树
//首先，我们能确定，第一个字符一定能填 26个字符任意一个。因为分割不能从第一个前面分。
//当 |S|=2时，分割只能从中间分，也就是当两个字符不同时，就是合法方案。
//当 |S|=3时，分割只能从第一位后面分。因为从第二位分，前面的长度已经大于后面，
//不可能是其子串。那么，只要第一个字母（前面子串）不与后面的字母（后面子串）相同即可。
//推广到一般情况，直接考虑最极端的情况，也就是最容易非法的情况。显然能想到，在第一位后面分，使第一个字母单独成子串。
//那么后面的每一个字母都有机会与它重复，成为非法方案。
//所以最终的答案就是，第一个字母任取，后面的字母不与第一个重复就可以，也就是从剩下的 25个字母里去。
//根据乘法原理，答案为：
//26×25^(n-1)
#include <bits/stdc++.h>
using namespace std;

long long n;
long long Pow(long long a,long long b,long long c)
{
  long long ans=1,base=a;
  while(b)
  {
    if(b&1)
      ans=ans*base%c;
    b=b>>1;
    base=base*base%c;
  }
  return ans;
}

int main()
{
  //freopen("tree.in","r",stdin);
  //freopen("tree.out","w",stdout);
  scanf("%lld",&n);
  printf("%lld\n",(26ll*Pow(25ll,n-1,998244353ll))%998244353ll);
  return 0;
}
