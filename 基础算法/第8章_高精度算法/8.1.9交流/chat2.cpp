//交流—高精乘单精
#include<bits/stdc++.h>
using namespace std;
const int Max=1010;
string ss[1010];
int x[Max],y[Max],z[Max],ans[Max],len;

void Add(int x[],int ans[],int len)
{
  for(int j=0; j<len; ++j)
  {
    ans[j]+=x[j];
    if(ans[i]>=10)
    {
      ans[i+1]++;
      ans[i]-=10;
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
  int i=Max-1;
  for(; ans[i]==0 && i>0; i--);        //忽略前导0
  for(; i>=0; i--)
    printf("%d",ans[i]);
  printf("\n");
}

void Mul(int a[],int k,int b[])
{
  for(int i=0; i<Max; ++i)
    b[i]=a[i]*k;
  for(int i=0; i<Max; ++i)
    if(b[i]>=10)
    {
      b[i+1]+=b[i]/10;
      b[i]%=10;
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
    cin>>ss[i];
    int x[Max]= {0};
    Init(x,ss[i],ss[i].size());
    Add(x,ans,ss[i].size());
  }
  int k=(n-1)*(n-2)>>1;
  Mul(ans,k,z);
  Output(z);
  return 0;
}

