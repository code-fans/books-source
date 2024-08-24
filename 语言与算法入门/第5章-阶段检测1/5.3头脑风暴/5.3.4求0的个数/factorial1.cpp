//求N！后面零的个数 - 方法1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans=0,n,sum=1;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    sum*=i;
    while(sum%10==0)      //若后面有0，则去掉0并计数
    {
      sum/=10;
      ans++;
    }
    sum%=1000;            //保持三位数即可
  }
  printf("%d\n",ans);
  return 0;
}

