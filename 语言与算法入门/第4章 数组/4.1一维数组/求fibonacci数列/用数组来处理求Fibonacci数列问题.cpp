//用数组来处理求Fibonacci数列问题
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int f[20]= {1,1}; //f[0]=1,a[1]=1,其余18个元素自动赋值为0
  for(int i=2; i<20; i++)//从下标2开始到下标19
    f[i]=f[i-2]+f[i-1];//依次递推
  for(int i=0; i<20; )
  {
    printf("%5d",f[i]);
    if(++i%5==0)
      printf("\n");//5个数为一行
  }
  return 0;
}

