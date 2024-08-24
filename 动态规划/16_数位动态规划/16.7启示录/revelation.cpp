#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("revelation.in","r",stdin);
  //freopen("revelation.out","w",stdout);
  long long f[210][5]= {1};
  for (int i=1; i<=20; i++)
  {
    f[i][0]=9LL* (f[i-1][0]+f[i-1][1]+f[i-1][2]);
    f[i][1]=f[i-1][0];
    f[i][2]=f[i-1][1];
    f[i][3]=f[i-1][2]+10LL*f[i-1][3];
  }
  int x,m, T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &x);
    for(m=3; f[m][3]<x; m++);           //位数逼近答案
    for (int i = m, k = 0; i > 0; i--)  //由高往低填到第i位,k表示末尾已有k个6
      for (int j = 0; j <= 9; j++)      //尝试第i位填数为0~9
      {
        long long cnt=f[i-1][3];        //求出后面i-1位有多少填法能让整个数是魔鬼数 
        if (j == 6 || k == 3)           //求由前o(0~2)个6开头的非魔鬼数与已经出现的3-o个6构成的魔鬼数个数
          for (int o=max(3-(j==6)-k, 0); o<3; o++)//o为加上的最小限制
            cnt+=f[i-1][o];
        if (cnt<x)                      //小了，第i位应填更大的数
          x-=cnt;                       //离x的目标更近了
        else                            //填j产生的魔鬼数不少于要求的个数,则可以填
        {
          if (k<3)                      //当有3个以上连续6，没必要继续统计连续6了 
            k=(j==6?k+1:0);             //如果j为6,数量加1,否则重置为0 
          printf("%d", j);
          break;
        }
      }
    puts("");
  }
  return 0;
}
