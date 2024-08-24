//魔方阵
#include<bits/stdc++.h>
using namespace std;
int a[10]= {0,0,0,0,0,5,0,0,0,0},num=0;

int Fun(int m)
{
  if(m==5)
  {
    for(int j=1; j<=3; ++j)           //检测魔方阵是否成立
      if(a[j]+a[j+3]+a[j+6]!=15 || a[3*j]+a[3*j-1]+a[3*j-2]!=15)
        return 0;
    printf("%d%d%d\n",a[1],a[2],a[3]);//如成立则输出结果
    printf("%d%d%d\n",a[4],a[5],a[6]);
    printf("%d%d%d\n\n",a[7],a[8],a[9]);
    num++;
  }
  else
    for(int i=1; i<=9; ++i)           //枚举9个格子
      if(a[i]==0)                     //如果该格子未填数
      {
        a[i]=m;                       //该格子填数
        a[10-i]=10-m;                 //对应格子填数
        Fun(m+1);                     //递归填下一个数
        a[i]=0;                       //要恢复原样,否则无法继续填其它数
        a[10-i]=0;                    //要恢复原样,否则无法继续填其它数
      }
}

int main()
{
  freopen("matrix.in","r",stdin);
  freopen("matrix.out","w",stdout);
  Fun(1);                             //从数字1开始填
  printf("%d\n",num);
  return 0;
}

