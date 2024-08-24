//万进制高精度乘法
#include <bits/stdc++.h>
using namespace std;
const int BASE=10000;
const int MAXN=2500;
int x[MAXN+1],y[MAXN+1],ans[MAXN+1];   //默认x[0],y[0],ans[0]保存第一个数所在的位数

void Mul(int a[],int b[],int ans[])
{
  int k;
  for(int i=MAXN; i>=b[0]; i--)          //a*b
  {
    for(int j=MAXN; j>=a[0]; j--)
    {
      ans[j-(MAXN-i)]+=a[j]*b[i];
      for(k=j-(MAXN-i); ans[k]>0; k--)
        if(ans[k]>=BASE)
        {
          ans[k-1]+=ans[k]/BASE;
          ans[k]=ans[k]%BASE;
        }
    }
    ans[0]=k+1;
  }
}

void Output(int p[])
{
  int star=p[0];
  cout<<p[star];                    //最高位不用加零
  for (int i=star+1; i<=MAXN; i++)
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
    result[MAXN-m]+=(in[i]-'0')*k;
    k*=10;
  }
  result[0]=MAXN-m;                  //存当前位数
}

int main()
{
  freopen("mul.in","r",stdin);
  freopen("mul.out","w",stdout);
  std::ios::sync_with_stdio(false); //取消cin与stdin的同步以加快读取速度
  char a[4*MAXN],b[4*MAXN];
  cin>>a>>b;
  if((strlen(a)==1 && a[0]=='0') || (strlen(b)==1 && b[0]=='0'))
    cout<<"0"<<endl;
  else
  {
    Init(x,a);
    Init(y,b);
    Mul(x,y,ans);
    Output(ans);
  }
  return 0;
}

