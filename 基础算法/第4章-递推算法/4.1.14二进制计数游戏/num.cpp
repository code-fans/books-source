//二进制计数游戏
//长度为i的二进制数可分为第i位为0和第i位为1的两类。设F[i][j]表示
//所有长度为i的，1的个数不超过j的二进制数的总数，则显然有递推公式：
//F[i][j]=f[i－1][j]+f[i－1][j－1]
//初始条件（边界条件）为：
//F[0][j]=1，F[j][0]=1，其中j≥0
//显然可以递推出结果。

#include <bits/stdc++.h>
using namespace std;
const int M=65;
long long n,s,t;
long long f[M][M];

long long cal(long long x)                //计算0~x之间有多少符合要求的数
{
  int len,b[M];
  for(len=0; x>0; x/=2)              //转为二进制数
    b[len++]=x%2;
  long long ans=0;
  /*
  例如x=1001000，n=3时，需要累加f[6][3]和f[[3][2]的值
  f[6][3]是假设最高位为0，后面6位有3个1的情况
  f[3][2]是假设最高位为1，则后三位只剩2个1可用的情况
  */
  for(int i=0,c=0; i<len &&  c<n; ++i)   //c统计n的个数
    if(b[len-i-1]==1)
    {
      ans+=f[len-i-1][n-c];
      c++;
    }
  return ans;
}

int main()
{
//  freopen("num.in","r",stdin);
//  freopen("num.out","w",stdout);
  cin>>n>>s>>t;
  for(int i=0; i<M; ++i)
    f[i][0]=1,f[0][i]=1;
  for(int i=1; i<M; ++i)
    for(int j=1; j<M; ++j)
      f[i][j]=f[i-1][j]+f[i-1][j-1];
  cout<<cal(t)-cal(s-1)<<endl;
  return 0;
}

