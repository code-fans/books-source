//高精度幂
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000;

int a[MAXN+1],N,key,ans[MAXN+1];
string s;

void Out(int *ans,int i=1)
{
  for(; key!=1 && i<MAXN && ans[i]==0; i++);//key=0,未超过1000位,省略前导0
  for(; i<=MAXN; ++i)
    printf("%d",ans[i]);
  puts("");
}

int Mul(int u[],int v[],int ansn[])        //u*v=ansn
{
  int x[MAXN+1],y[MAXN+1];                 //用于复制a[]和b[],不对a[],b[]直接修改
  memcpy(x,u,sizeof(int)*(MAXN+1));        //u数组复制到x数组,因为有Mul(a,a,a)
  memcpy(y,v,sizeof(int)*(MAXN+1));        //v数组复制到y数组
  memset(ansn,0,sizeof(int)*(MAXN+1));
  for(int i=MAXN; i>=1; --i)               //u
    for(int j=MAXN; j>=1; --j)             //v
      if(i+j<=MAXN && x[i]!=0 && y[j]!=0 ) //超过1000位，则不计算
        key=1;                             //做标记
      else if(i+j>MAXN)                    //未超过1000位
        ansn[i+j-MAXN]+=x[i]*y[j];         //乘法运算
  for(int k=MAXN; k>=1; k--)               //整理
    if(ansn[k]>=10)
    {
      ansn[k-1]+=ansn[k]/10;
      ansn[k]%=10;
    }
  if(ansn[0])                                    //表示超过1000位
    key=1;
}

int main()
{
  //freopen("evolution.in","r",stdin);
  //freopen("evolution.out","w",stdout);
  ans[MAXN]=1;                                   //ans将为最终的结果,初始为1
  cin>>s>>N;
  for(int i=0,len=s.size(); i<len; i++)
    a[MAXN-len+i+1]=s[i]-'0';                    //例如12345存储为000...00012345
  for(; N>1; N>>=1)                              //降幂算法
  {
    if(N&1)                                      //如果为奇数
      Mul(ans,a,ans);                            //将多出来的一个a乘到ans
    Mul(a,a,a);                                  //算出a^2的值给a
  }
  Mul(ans,a,ans);
  Out(ans);
  return 0;
}

