//开关灯1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("light1.in","r",stdin);
  //freopen("light1.out","w",stdout);
  int f[101]; //在没赋初值的情况下，数组f里的各元素值未知
  memset(f,0,sizeof(f));//全部数组元素赋值为0
  for(int  i=1; i<=100; i++)
    if(i%2==0)
      f[i]=!f[i];
  for(int  i=1; i<=100; i++)
    if(i%3==0)
      f[i]=!f[i];
  for(int  i=1; i<=100; i++)
    printf("%d",f[i]);
  printf("\n");
  return 0;
}

