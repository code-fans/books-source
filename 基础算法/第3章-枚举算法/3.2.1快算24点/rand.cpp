//rand.cpp
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

int main()
{
  freopen("24.in","r",stdin);                   //Dev-C++智能开发平台需加此句
  freopen("24.in","w",stdout);
  SYSTEMTIME sys;                               //定义sys为SYSTEMTIME类型
  GetLocalTime( &sys );
  srand(sys.wSecond*1000+sys.wMilliseconds);    //以毫秒级精度为随机数种子
  for(int i=0; i<=3; i++)
    cout<<rand()%9+1<<' ';
  return 0;
}
