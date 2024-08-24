//产生指定长度的随机字符串
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i,n,m;//输出n行m个字符的随机字符串
  string str;
  cin>>n>>m;
  srand(time(0));
  for(i=1; i<=n; i++)
  {
    str="";//清空字符串
    for(int j=1; j<=m; j++)
    {
      int temp=rand()%2;//随机决定输出大写或小写字母
      if (temp)//相当于temp==1
        str+=(char)(rand()%(26)+1+64);//随机生成大写字符添加到str的末尾
      else
        str+=(char)(rand()%(26)+1+96);//随机生成小写字符添加到str的末尾
    }
    cout<<str<<endl;
  }
  return 0;
}

