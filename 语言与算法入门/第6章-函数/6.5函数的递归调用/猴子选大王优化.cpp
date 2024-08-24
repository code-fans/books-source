//×îÓÅËã·¨
#include<bits/stdc++.h>
using namespace std;

int main()
{
  int M,K,ans=0,x;
  scanf("%d %d",&M,&K);
  for(int i=1; i<=M; i++)
  {
    if(ans+K<i)
    {
      x=(i-ans)/K;
      if(i+x<M)
      {
        ans=ans+K*x;
        i=i+x;
      }
      else
      {
        ans=ans+K*(M-i);
        i=M;
      }
    }
    ans=(ans+K-1)%i+1;
  }
  printf("%d\n",ans);
  return 0;
}

