//求数的总和
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int sum=0,n;
  while(true)//表示永远为真，即永远循环，也可以用while(1)
  {
    //cout<<"输入一个整数（0表示结束）";
    cin>>n;
    if(n==0)
      break;//跳出该层循环
    sum+=n;
  }
  cout<<sum<<endl;
  return 0;
}

