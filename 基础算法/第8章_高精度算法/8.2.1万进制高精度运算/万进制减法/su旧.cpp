//万进制高精度减法
#include <bits/stdc++.h>
using namespace std;
const int base=10000;
const int Max=2500;
int x[Max+1],y[Max+1],ans[Max+1];   //默认x[0],y[0],ans[0]保存第一个数所在的位数

void Sub(int x[],int y[],int ans[])
{
  int i;
  for(i=Max; (i>=x[0])||(i>=y[0]); i--) //减法计算的关键
  {
    ans[i]+=x[i]-y[i];
    if(ans[i]<0)
    {
      x[i-1]--;
      ans[i]=ans[i]+base;
    }
  }
  while(ans[i]==0)                  //获得所在位数
    i++;
  ans[0]=i;
}

void Out(int p[])
{
  int star=p[0];
  cout<<p[star];                    //最高位不用加零
  for (int i=star+1; i<=Max; i++)
    cout<<setw(4)<<setfill('0')<<p[i];
  cout<<endl;
}

void Init(int result[],char in[])   //将字符数组in转成数字数组ans,四位数一格
{
  int k=1,m=0;
  for(int i=strlen(in)-1; i>=0; i--)//从最后一位开始向前赋值
  {
    if(k>=10000)
      k=1, m++;
    result[Max-m]+=(in[i]-'0')*k;
    k*=10;
  }
  result[0]=Max-m;                  //存当前位数
}

int Compare(int x[],int y[])        //x比y大，返回1，x比y小，返回-1，相等返回0
{
  if(x[0]<y[0])       //直接比较位数
    return 1;
  else if(x[0]>y[0])
    return -1;
  else
    for(int i=x[0]; i<=Max; i++)
      if(x[i]>y[i])
        return 1;
      else if(x[i]<y[i])
        return -1;
  return 0;
}

int main()
{
  freopen("sub.in","r",stdin);
  freopen("sub.out","w",stdout);
  std::ios::sync_with_stdio(false); //取消cin与stdin的同步以加快读取速度
  char a[4*Max],b[4*Max];
  cin>>a>>b;
  Init(x,a);
  Init(y,b);
  if(Compare(x,y)==1)
    Sub(x,y,ans),Out(ans);
  else if(Compare(x,y)==-1)
    Sub(y,x,ans),cout<<"-",Out(ans);
  else
    cout<<"0"<<endl;
  return 0;
}

