//对拍程序
#include<bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("chat.in","r",stdin); //Dev-C++智能平台需加此行以保持运行
  //freopen("chat.in","w",stdout); //Dev-C++智能平台需加此行以保持运行
  int i=0;
  do
  {
    system("random.exe");
    system("chat1.exe");
    system("chat2.exe");
  }
  while(system("fc chat1.out chat2.out")==0);
  return 0;
}

