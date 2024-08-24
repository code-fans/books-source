//万进制高精度加法
#include <bits/stdc++.h>
using namespace std;
const int BASE=10000;
const int Max=1260;
int x[Max],y[Max],ans[Max],len;

void Sub(int x[],int y[],int ans[])
{
  for(int i=Max-1; i>Max-len; i--)
  {
    ans[i]+=x[i]-y[i];
    if(ans[i]<0)
    {
      x[i-1]--;
      ans[i]=ans[i]+BASE;
    }
  }
}

void Output(int ans[])
{
  int st=0;
  for(; ans[st]==0 && st<Max-1; st++);
  printf("%d",ans[st]);                 //输出最高位无前导0的数
  for (int i=st+1; i<Max; i++)
    printf("%04d",ans[i]);
  printf("\n");
}

void Init(int result[],string in)       //string转整型数组,4位数一格
{
  int k=1,m=0;                          //m记录已用的数组元素个数
  for(int st=in.size()-1; st>=0; --st)  //从字符串最后一位开始逆向赋值
  {
    if(k>=10000)                        //当一个数组元素已有4位数字时
      k=1, m++;                         //k还原为1，位数+1
    result[Max-m-1]+=(in[st]-'0')*k;    //个位在Max-1,如0000000000123
    k*=10;
  }
}

int main()
{
  freopen("sub.in","r",stdin);
  freopen("sub.out","w",stdout);
  string a,b;
  cin>>a>>b;
  if((a<b && a.size()==b.size()) || a.size()<b.size())
  {
    cout<<'-';
    swap(a, b);
  }
  Init(x,a);
  Init(y,b);
  len=a.size()/4+1;
  Sub(x,y,ans);
  Output(ans);
  return 0;
}

