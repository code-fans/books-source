//小球钟
#include <bits/stdc++.h>
using namespace std;
const int LIMIT[4] = {5,3,4,24}; //定义每行轨道容纳的小球数

int Line[4][25];                 //四行轨道，即1分钟，5分钟，15分钟，小时轨道
int solved[300];                 //保存计算好的结果
deque<int> Q;                    //队列

int GCD(int m, int n)            //求最大公约数
{
  return n==0?m:GCD(n,m%n);
}

unsigned long long GetDay(int n)
{
  int j,k;
  unsigned long long ans = 1;
  for (int i = 0; i < n; ++i)    //枚举每个小球
  {
    for (j = Q[i], k = 1; j != i; j = Q[j], ++k);//计算每个小球的周期k
    ans=ans*k/GCD(ans, k);//求此小球与之前所有小球的周期的最小公倍数
  }
  return ans;
}

int Solve(int n)
{
  Q.clear();                            //清空队列
  for (int i = 0; i < n; ++i)           //初始化队列
    Q.push_back(i);
  while(1)
  {
    Line[0][++Line[0][0]]=Q.front();    //Line[i][0]记录第i行轨道已有的球数
    Q.pop_front();
    for (int i = 0; i < 3; ++i)         //枚举1分钟，5分钟，15分钟的轨道
      if (Line[i][0] == LIMIT[i])       //若本行达到了容纳极限
      {
        Line[i+1][++Line[i+1][0]]=Line[i][Line[i][0]--];//最后一颗球滚入下行
        while (Line[i][0] != 0)
          Q.push_back(Line[i][Line[i][0]--]);//剩余的球依次逆序入队列
      }
    if (Line[3][0] == LIMIT[3])         //若24小时到了
    {
      int o = Line[3][0]--;             //先记录本球的编号
      while (Line[3][0] != 0)           //其他球依次入队列
        Q.push_back(Line[3][Line[3][0]--]);
      Q.push_back(Line[3][o]);          //最后这颗球滚入队列
      break;
    }
  }
  return GetDay(n);
}

int main()
{
  //freopen("ballclock4.in","r",stdin);
  //freopen("ballclock4.ans","w",stdout);
  int n;
  while (cin >> n, n != 0)
    if (solved[n] != 0)                 //如果之前已计算过，直接输出结果
      cout<<solved[n]<<"\n";
    else
      cout<<(solved[n]=Solve(n))<<'\n'; //记录计算结果并输出
  return 0;
}

