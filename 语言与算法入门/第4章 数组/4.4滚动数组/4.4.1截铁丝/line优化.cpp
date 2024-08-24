//截铁丝-滚动数组法
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  long long d[3]= {1,1};
  int total,i,sum=2;    //sum为已截的铁丝长度和，现在是2
  scanf("%d",&total);
  for(i=2; ; i++)
  {
    d[i%3]=d[(i-1)%3]+d[(i-2)%3];
    if(total-sum>=d[i%3])
      sum+=d[i%3];      //已经截去的铁丝总长
    else
      break;
  }
  printf("%d\n",i);
  return 0;
}

