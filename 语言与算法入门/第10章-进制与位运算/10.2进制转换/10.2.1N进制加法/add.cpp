//N进制数加法运算
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("add.in","r",stdin);
  //freopen("add.out","w",stdout);
  string w="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",a,b;
  int N,x[100],y[100];
  cin>>N>>a>>b;
  while(a.length()<b.length())
    a='0'+a;
  while(b.length()<a.length())
    b='0'+b;
  a='0'+a;//前面多加一位，用于进位
  b='0'+b;
  for(int i=a.length()-1; i>=0; i--)
  {
    x[i]=w.find(a[i],0);//查找a[i]在W中的位置获得真实的数字
    y[i]=w.find(b[i],0);//转换到x,y数组中准备相加
  }
  for(int i=a.length()-1; i>=0; i--) //进位加法
  {
    x[i]=x[i]+y[i];
    if(x[i]>=N)
      for(int k=i; x[k]>=N; k--)
      {
        x[k]=x[k]-N;
        x[k-1]++;
      }
    a[i]=w[x[i]];
  }
  while(a[0]=='0')
    a.erase(0,1);  //删除前导0
  cout<<(a.length()==0?"0":a)<<endl;
  return 0;
}

