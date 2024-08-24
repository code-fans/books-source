//改写的CreatRand.cpp
#include <bits/stdc++.h>
#include <windows.h>  //添加windows.h头文件,注意正式比赛不能有该头文件 
using namespace std;

int main()
{
  SYSTEMTIME sys;//定义sys为SYSTEMTIME类型
//获得当前系统时间,其成员wSecond为秒,wMilliseconds为毫秒
  GetLocalTime( &sys );
  srand(sys.wSecond*1000+sys.wMilliseconds);//以毫秒级精度为随机数种子
  //freopen("in.txt","w",stdout);//产生的随机数据写入in.txt
  cout<<rand()%1000<<" "<<rand()%1000<<" "<<rand()%1000<<endl;
  return 0;
}

