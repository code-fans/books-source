//使用scanf函数输入数据
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int a;
  float b;
  long long n;
  char c;
  scanf("%d",&a);
  scanf("%f",&b);
  scanf("%lld",&n);
  getchar();//接收上一行输入后的回车键
  scanf("%c",&c);//否则此处的c就会接收回车键
  printf("%d,%f\n",a,b);
  printf("%lld\n",n);
  printf("%c\n",c);
  return 0;
}

