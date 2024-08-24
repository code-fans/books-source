#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
char s[1001000];
int mod=10009;
int len,k=131;
ll now;
ll Hash[1001000];
ll cal(int x,ll y)
{
  ll re=1;
  while(x)
  {
    if(x&1) re=(re*y)%mod;
    x>>=1;
    y=(y*y)%mod;
  }
  return re;
}
bool check(int x)
{
  ll cc=cal(x,(ll)k);
  for(int i=(x<<1); i<=len; i+=x)
  {
    if((Hash[i]-(Hash[i-x]*cc)%mod+mod)%mod!=Hash[x])
    {
      return false;
    }
  }
  return true;
}
int main()
{
  freopen("strings.in","r",stdin);
  freopen("strings.out","w",stdout);
  while(1)
  {
    scanf("%s",s+1);
    len=strlen(s+1);
    if(len==1 && s[1]=='.')
    {
      return 0;
    }
    for(int i=1; i<=len; i++)
    {
      Hash[i]=(Hash[i-1]*k+s[i])%mod;
    }
    for(int i=1; i<=len; i++)
    {
      if(len%i==0 && check(i))
      {
        printf("%d\n",len/i);
        break;
      }
    }
  }
}
