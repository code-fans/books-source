//火柴棒等式
#include <bits/stdc++.h>
using namespace std;

int Need[]= {6,2,5,5,4,5,6,3,7,6}; //保存十个数字使用的火柴数
int M[2000];

int Match(int cur)                 //返回cur使用的火柴数
{
  if(cur==0)
    return 6;
  int ans=0;
  for(; cur>0; cur/=10)
    ans+= Need[cur%10];
  return ans;
}

void GetMatch()                   //事先将从0~1999使用的火柴数存到Match[]
{
  for(int i=0; i<=1999; ++i)
    M[i]=Match(i);
}

int main()
{
  freopen("matches.in","r",stdin);
  freopen("matches.out","w",stdout);
  int ans=0,n;
  scanf("%d",&n);
  GetMatch();
  for(int i=0; i<=1000; ++i)
    for(int j=i; j<=1000; ++j)   //此处有个小优化
      if(M[i]+M[j]+M[i+j]+4==n)
        i==j?ans++:ans+=2;
  printf("%d\n",ans);
  return 0;
}

