//求素数 - 普通方法
#include <bits/stdc++.h>
using namespace std;
const int MAX=100001;

bool a[MAX+10];                  //全局数组，初始值均为false即0
int prime[MAX/3],Count=0;        //prime存素数,Count统计素数个数

int main()
{
  //freopen("prime.out","w",stdout);
  for(int i=2,limit=sqrt(MAX); i<MAX; i++)
  {
    if(a[i]==0)                   //a[i]=0表示是素数
      prime[Count++]=i;           //素数依次存入prime[]
    if(limit>i)                   //限制，否则i*i可能会过大而溢出
      for(int j=i*i; j<MAX; j+=i)//从i*i开始，因为i*(2~i-1)已删除
        a[j]=1;                   //标记a[j]不是素数
  }
  for(int i=0; i<Count-1; i++)
    cout<<prime[i]<<' ';
  cout<<prime[Count-1]<<endl;
  return 0;
}

