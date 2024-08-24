//趣味摇奖机
#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));//srand()取当前时间作为随机数种子
  int t=rand()%10;   //rand()产生0~32767之间的随机数
  cout<<"     *** 趣味摇奖机 ***  \n\n";
  cout<<"请任选一个数字(0~9):  ";
  int j;
  cin>>j;
  if(j<0 || j>9)        //输入的数字不合规
    return 0;

  if(j==t)
    cout<<"\n哇,特等奖!你真厉害!";
  else if(abs(j-t)<=1)
    cout<<"\n一等奖!很不错呀!";
  else if(abs(j-t)<=2)
    cout<<"\n二等奖!也可以啦...";
  else if(abs(j-t)<=3)
    cout<<"\n三等奖!还要努力哦...";
  else
    cout<<"\n真可惜!什么都没有...";
  return 0;
}

