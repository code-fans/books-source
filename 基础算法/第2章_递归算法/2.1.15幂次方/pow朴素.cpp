//幂次方-朴素方法
#include<bits/stdc++.h>
using namespace std;

int Dg(int n)
{
  int j=1,i=0;
  for(; j*2<=n; i++)    //找到最大的指数
    j<<=1;              //j=j*2
  if(i==1)
    cout<<"2";
  if(i==0)
    cout<<"2(0)";
  if(i>1)
  {
    cout<<"2(";
    Dg(i);              //当前找到的最大指数继续递归
    cout<<")";
  }
  if(n-j>0)
  {
    cout<<"+";
    Dg(n-j);
  }
}

int main()
{
  freopen("pow.in","r",stdin);
  freopen("pow.out","w",stdout);
  int n;
  cin>>n;
  Dg(n);//直接调用
  cout<<endl;
  return 0;
}
