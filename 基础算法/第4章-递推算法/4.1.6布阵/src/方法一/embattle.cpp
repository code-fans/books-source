//布阵 - 方法1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("embattle.in","r",stdin);
  //freopen("embattle.out","w",stdout);
  long long n,fn=0;
  scanf("%d",&n);
  if(n==1)
    fn=3;                          //初始化当n=1和n=2时的临界条件
  else if(n==2)
    fn=7;
  else
  {
    long long fn_1=7;
    long long fn_2=3;
    for(int i=3; i<=n; i++)
    {
      fn=2*fn_1+fn_2;              //当n>=3时fn的通式
      fn_2=fn_1;                   //更新fn_1和fn_2的值
      fn_1=fn;
    }
  }
  printf("%lld\n",fn);
  return 0;
}

