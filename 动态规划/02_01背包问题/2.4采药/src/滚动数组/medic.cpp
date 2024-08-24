//采药
#include <bits/stdc++.h>
using namespace std;
#define F(i,j) f[i&1][j]

int t,m,a[10001],b[10001],f[2][10001];

inline int Read(int &x)                        //以字符串形式读入数字可提速
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //位运算优化即x*8+x*2=x*10
}

int main()
{
  freopen("medic.in","r",stdin);
  freopen("medic.out","w",stdout);
  Read(t),Read(m);
  for (int i=1; i<=m; i++)
    Read(a[i]),Read(b[i]);
  for (int i=1; i<=m; i++)
    for (int j=0; j<=t; j++)
    {
      F(i,j)=F(i-1,j);
      if (j>=a[i] && F(i,j)<F(i-1,j-a[i])+b[i])
        F(i,j)=F(i-1,j-a[i])+b[i];
    }
  cout<<F(m,t)<<endl;
  return 0;
}
