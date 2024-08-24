//简单高精度乘法
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001

char str1[MAXN],str2[MAXN];
int a[MAXN],b[MAXN],c[MAXN];

void Multiply(int a[],int b[],int la,int lb)
{
  for(int i=0; i<lb; ++i)                       //第一个乘　
  {
    for(int j=la-1; j>=0; --j)                  //第二个乘数
      c[j+i]+=b[i]*a[j];                    //注意乘积保存的位置
    for(int k=0; c[k]>=0; ++k)                 //如某位数>=10，则需进行整理，还可优化
    {
      c[k+1]+=c[k]/10;
      c[k]%=10;
    }
  }
}

void Init(int x[],char str[],int len)       //字符串转为整型数组
{
  for(int i=0; i<len; i++)
    x[len-i-1]=str[i]-'0';
}

void Output(int ans[])
{
  int i=MAXN-1;
  for(; ans[i]==0 && i>0; --i);       //查找最高位数，注意句末有个分号
  for(; i>=0; --i)                   //输出结果
    cout<<ans[i];
  cout<<'\n';
}

int main()
{
  freopen("mul.in","r",stdin);
  freopen("mul.out","w",stdout);
  cin>>str1>>str2;
  int la=strlen(str1);
  int lb=strlen(str2);
  Init(a,str1,la);                        //初始化为整型数组
  Init(b,str2,lb);
  Multiply(a,b,la,lb);
  Output(c);
  return 0;
}

