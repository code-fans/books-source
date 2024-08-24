//简单高精度加法
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001

void Add(int x[],int y[],int ans[],int len)
{
  for(int j=0; j<len; ++j)             //从下标0开始逐位相加到len-1
  {
    ans[j]+=x[j]+y[j];                 //相加结果存到ans[]
    for(int i=j; ans[i]>=10; ++i)
    {
      ans[i+1]++;                      //如写成ans[i+1]+=ans[i]/10，速度慢
      ans[i]-=10;                      //如写成ans[i]%=10，速度慢
    }
  }
}

void Init(int x[],string str, int len) //字符串转为整型数组
{
  for(int i=0; i<len; i++)
    x[len-i-1]=str[i]-'0';             //倒序转换
}

void Output(int ans[])                 //输出相加的结果
{
  int i=MAXN-1;
  for(; ans[i]==0 && i>0; i--);        //忽略前导0
  for(; i>=0; i--)
    printf("%d",ans[i]);
  printf("\n");
}

int main()
{
  ////freopen("add.in","r",stdin);
  ////freopen("add.out","w",stdout);
  int a[MAXN]= {0},b[MAXN]= {0},ans[MAXN]= {0};
  string str1,str2;
  cin>>str1>>str2;
  int la=str1.size();
  int lb=str2.size();
  Init(a,str1,la);                     //初始化为整型数组
  Init(b,str2,lb);
  for(int i=0; i<=100; i++)
    cout<<a[i];
  return 0;
  Add(a,b,ans,la>=lb?la:lb);           //第四个参数为la和lb的最大值
  Output(ans);
  return 0;
}

