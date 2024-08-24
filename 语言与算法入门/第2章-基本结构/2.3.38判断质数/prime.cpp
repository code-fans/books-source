//判断质数
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int number,i;
  cin>>number;
  int k=sqrt(number); //k为输入数的平方根,想一下为什么？
  for(i=2; i<=k; i++) //枚举数从2到k
    if(number%i==0)
      break;          //只要能被整除，即跳出for循环
  cout<<(i>k?"Yes\n":"No\n");
  return 0;
}

