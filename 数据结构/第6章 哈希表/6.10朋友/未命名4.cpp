#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 2000050
#define LL unsigned long long
char s[N];
LL p=13131,mi[N],h[N],ans;
int n,pos;
int main()
{
  //freopen("friends5.in","r",stdin);
  //freopen("friends5.ans","w",stdout);
  ans=-1;
  scanf("%d%s",&n,s+1);
  int l=(n-1)/2;
  if(n%2==0)
  {
    puts("NOT POSSIBLE");
    return 0;
  }
  int i;
  mi[0]=1;
  for(i=1; i<=n; i++)
  {
    h[i]=h[i-1]*p+s[i];
    mi[i]=mi[i-1]*p;
  }
  for(i=1; i<=n+1; i++)
  {
    if(i-1<l)
    {
      LL h1=h[i-1]*mi[l-i+1]+(h[l+1]-h[i]*mi[l-i+1]);
      LL h2=h[n]-h[l+1]*mi[l];
      if(h1==h2)
      {
        pos=i;
        if(ans==-1)ans=h1;
        else if(ans!=h1)
        {
          puts("NOT UNIQUE");
          return 0;
        }
      }
    }
    else
    {
      LL h1=h[l];
      LL h2=(h[i-1]-h[l]*mi[i-l-1])*mi[n-i]+h[n]-h[i]*mi[n-i];
      if(h1==h2)
      {
        pos=i;
        if(ans==-1)ans=h1;
        else if(ans!=h1)
        {
          puts("NOT UNIQUE");
          return 0;
        }
      }
    }
  }
  if(ans==-1)
  {
    puts("NOT POSSIBLE");
    return 0;
  }
  if(pos-1<l)
  {
    for(i=l+2; i<=n; i++)printf("%c",s[i]);
  }
  else
  {
    for(i=1; i<=l; i++)printf("%c",s[i]);
  }
}
