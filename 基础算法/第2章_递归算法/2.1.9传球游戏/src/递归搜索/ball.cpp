//传球游戏 - 递归搜索
#include <bits/stdc++.h>
using namespace std;

int n,m,Sum;

void Pass(int man,int step)
{
  if(step==m)                             //如果传了m步
  {
    if(man==1)                            //恰好传到本人手里，总数加1
      ++Sum;
    return;
  }
  if(man==n)                              //如果球在第n个人手里
  {
    Pass(1,step+1);                       //或者传给第一个人
    Pass(man-1,step+1);                   //或者传给n－1人
  }
  else if(man==1)                         //如果球在第一人手里
  {
    Pass(n,step+1);                       //或者传给第n人
    Pass(man+1,step+1);                   //或者传给第2人
  }
  else                                    //如果在1和n之间的任何一人
  {
    Pass(man+1,step+1);                   //或者传给右边
    Pass(man-1,step+1);                   //或者传给左边
  }
}

int main()
{
  scanf("%d%d",&n,&m);
  Pass(1,0);                              //从1号开始传球，当前步数为0
  printf("%d\n",Sum);
  return 0;
}

