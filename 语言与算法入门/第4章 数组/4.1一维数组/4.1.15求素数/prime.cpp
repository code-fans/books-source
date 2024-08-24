//求素数 - 普通方法
#include <bits/stdc++.h>
using namespace std;
const int MAX=100000;

bool a[MAX+10];                    //全局数组，初始值均为false即0
int prime[MAX],Count=0;            //prime存素数,Count统计素数个数

int main()
{
  for (int i=2; i<=MAX; i++)
  {
    if (a[i]==0)                   //a[i]=0表示是素数
      prime[Count++]=i;            //素数依次存入prime[]
    if(i<=sqrt(MAX))               //不要写成i*i<=MAX,防止i*i过大溢出
      for (int j=i*i; j<=MAX; j+=i)//从i*i开始，因为i*(2~i-1)已删除
        a[j]=1;                    //标记a[j]不是素数
  }
  for (int i=0; i<Count; i++)
    cout<<prime[i]<<' ';
  return 0;
}

