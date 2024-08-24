//截铁丝-滚动数组法
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  long long d[3]= {1,1};
  long long x,sum=2;
  scanf("%lld",&x);
  int i;
  for(i=2; i<100; i++)
  {
    d[i%3]=d[(i-1)%3]+d[(i-2)%3];
    if(x-sum>=d[i%3])
      sum+=d[i%3];//已经截去的铁丝总长
    else
      break;
  }
  printf("%d\n",i);
  return 0;
}

