//对拍程序
#include<bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("in.txt","r",stdin); //Dev-C++智能平台需加此行以保持自动运行
  do
  {
    system("CreatRand.exe");
    system("program1.exe");
    system("program2.exe");
  }
  while(system("fc out1.txt out2.txt")==0);
  return 0;
}

