//基因武器
//状态压缩dp
//dp[i][s]:在所有字符串选取情况为s时，最前面为i字符串的最小长度,i放在前面是便于DFS找字典序
//依次枚举下一个字符串可得状态转移方程
//dp[i][s | 1 << i] = min(dp[i][s | 1<< i], dp[j][s] + cost[i][j]);
//dp完毕后即可通过搜索来逐渐往后加字符串，最终得到答案。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 17;
const int INF = 0x3f3f3f3f;

int n, dp[MAX][1<<MAX];//dp[i][s]:在所有字符串选取情况为s时，最前面为i字符串的最小长度
string S[MAX], ans;
int LEN[MAX][MAX]; //LEN[i][j]表示将j字符串前面接上i字符串所加上的最小长度

void Init()
{
  for(int i = 0; i < n; i++)
    for(int j = i+1; j < n; j++)
      if(S[i].find(S[j]) != string::npos)//如果S[i]包含了S[j]
        S[j] = S[i]; //只包含母串，以备删除
  stable_sort(S, S + n);
  n = unique(S, S + n) - S;
  memset(LEN, 0, sizeof(LEN));
  for(int i = 0; i < n; i++)//预处理出两个字符串相接最短需要增加的长度LEN[][]
    for(int j = 0; j < n; j++)
      if(i != j)
      {
        int len = min(S[i].length(), S[j].length());
        for(int k = 0; k <= len; k++)
          if(S[i].substr(S[i].length() - k) == S[j].substr(0, k))
            LEN[i][j] = S[i].length() - k;//j字符串前面接上i字符串所加上的最小长度
      }
}

void DFS(int id, int s)
{
  if(s!=0)
  {
    string tmp;
    int next_id = -1;
    for(int i = 0; i < n; i++)
      if(i != id && (s >> i & 1))
        if(dp[id][s] == dp[i][s & ~(1 << id)] + LEN[id][i])
        {
          string t = S[i].substr(S[id].length()-LEN[id][i],S[i].length());
          if(next_id == -1 || t < tmp)
          {
            tmp = t;
            next_id = i;
          }
        }
    ans += tmp;
    DFS(next_id, s & ~(1 << id));
  }
}

int main()
{
  //freopen("DNA1.in", "r", stdin);
  //freopen("DNA1.ans", "w", stdout);
  int T, Case = 0;
  cin >> T;
  while(T--)
  {
    cin >> n;
    for(int i = 0; i < n; i++)
      cin >> S[i];
    if(n==1)
      ans = S[0];
    else
    {
      Init();
      for(int i = 0; i <= n; i++)
        fill(dp[i], dp[i] + (1 << n), INF);
      for(int i = 0; i < n; i++)
        dp[i][1 << i] = S[i].length();
      for(int s = 0; s < 1 << n; s++)
        for(int j = 0; j < n; j++)                   //依次枚举下一个字符串
          if(dp[j][s] != INF && (s >> j & 1))
            for(int i = 0; i < n; i++)
              if(!(s>>i & 1))
                dp[i][s|1<<i]=min(dp[i][s|1<<i], dp[j][s]+LEN[i][j]);
      int id = 0;
      for(int i = 1; i < n; i++)
        if(dp[i][(1 << n) - 1] < dp[id][(1 << n) - 1])
          id = i;
      ans = S[id];
      DFS(id, (1 << n) - 1);//找最优解
    }
    cout<<"Scenario #"<<++Case<<":"<<endl<<ans<<endl<<endl;
  }
  return 0;
}

