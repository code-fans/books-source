//哥德巴赫猜想—筛选法预处理
#include<bits/stdc++.h>
using namespace std;
bool p[10005];                           //保存素数

void GetPrime()                          //预处理出所有素数
{
  for(int i=2; i<=2000; i++)
    p[i]=true;
  int m=sqrt(2000);
  for(int i=2; i<=m; i++)
    if(p[i])
      for(int j=i*i; j<=2000; j+=i)
        p[j]=false;
}

int main()
{
  GetPrime();
  for(int i=4; i<=2000; i+=2)
    for(int n=2; n<i; n++)            //将偶数i分解为两个整数
      if(p[n] && p[i-n])
      {
        printf("%d=%d+%d\n",i,n,i-n); //若均是素数则输出
        break;
      }
  return 0;
}


