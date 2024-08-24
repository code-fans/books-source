//求N！后面零的个数 - 方法2需N/5次循环
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans=0,n;
  scanf("%d",&n);
  for(int j=5; j<=n; j+=5)          //从5开始，步长为5
    for(int i=j; i%5==0; ans++)     //i能被5整除，就说明有因子5
      i/=5;
  printf("%d\n",ans);
  return 0;
}

