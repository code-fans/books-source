#include <bits/stdc++.h>
using namespace std;

int c[35][35];
int X,Y,k,b;

void Init()
{
  c[0][0]=1;
  for (int i=1; i<=32; i++)
  {
    c[i][0]=c[i-1][0];
    for (int j=1; j<=i; j++)
      c[i][j]=c[i-1][j]+c[i-1][j-1];
  }
}

int Cal(int n)
{
  int a[100],len=0,cnt=0,ans=0;
  for(; n; n/=b)     //拆成B进制数
    a[len++]=n%b;
  cout<<len<<endl;
  for (int i=len-1; i>=0; i--)//从高位往低位扫描
  {
    if (a[i]==1)     //如果为1，依次计算
    {
      ans+=c[i][k-cnt];
      cout<<"=C"<<i<<","<<k-cnt<<' '<<c[i][k-cnt]<<endl;
      cnt++;
      if (cnt==k)    //已经有足够的1了
        break;
    }
    else if (a[i]>1) //第一个非0/1的数，后面全部设为1
    {
      ans+=c[i+1][k-cnt];//所以直接求解跳出
      break;
    }
  }
  cout<<ans<<" fir"<<endl;
  if (cnt==k)//由于是闭区间，不要忘了统计原数本身
    ans++;
  cout<<ans<<" d"<<endl;
  return ans;
}

int main()
{
//  freopen("amount.in","r",stdin);
//  freopen("amount.out","w",stdout);
  Init();
  scanf("%d%d%d%d",&X,&Y,&k,&b);
  printf("%d\n",Cal(Y)-Cal(X-1));
  return 0;
}
