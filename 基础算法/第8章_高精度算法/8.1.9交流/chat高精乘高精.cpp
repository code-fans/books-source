//交流 高精乘高精
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1010;
string s[MAXN];

int x[MAXN],K[MAXN],z[MAXN],sum[MAXN],len;

void Add(int x[],int ans[],int len)
{
  for(int j=0; j<len; ++j)
  {
    ans[j]+=x[j];
    if(ans[j]>=10)//后面的乘法还会继续整理
    {
      ans[j+1]++;
      ans[j]-=10;
    }
  }
}

void Init(int x[],string str, int len) //字符串倒序转换为整型数组
{
  for(int i=0; i<len; i++)
    x[len-i-1]=str[i]-'0';
}

void Output(int ans[])                 //输出相加的结果
{
  int i=MAXN-1;
  for(; ans[i]==0 && i>0; i--);        //忽略前导0
  for(; i>=0; i--)
    printf("%d",ans[i]);
  printf("\n");
}

void Mul(int a[],int b[],int c[])
{
  for(int i=0; i<MAXN; ++i)
  {
    for(int j=0; j<len; ++j)
      c[i+j]+=a[i]*b[j];               //注意乘积保存的位置
    for(int j=0; j<MAXN; ++j)
      if(c[j]>=10)
      {
        c[j+1]+=c[j]/10;
        c[j]%=10;
      }
  }
}

int main()
{
  //freopen("chat.in","r",stdin);
  //freopen("chat.out","w",stdout);
  int n;
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>s[i];
    int x[MAXN]= {0};
    Init(x,s[i],s[i].size());
    Add(x,sum,s[i].size());
  }
  int k=(n-1)*(n-2)>>1;//答案是k*（所有价值和），k可以用等差数列求
  for(len=0; k!=0; len++)//将K转为字符数组
  {
    K[len]=k%10;
    k/=10;
  }
  Mul(sum,K,z);
  Output(z);
  return 0;
}

