//翻转棋盘2
#include<bits/stdc++.h>
using namespace std;

int Map[20][20];
int n,ans =(1<<31)-1;

void Flip(int x,int y)
{
  Map[x-1][y] ^= 1;
  Map[x][y-1] ^= 1;
  Map[x][y] ^= 1;
  Map[x][y+1] ^= 1;
  Map[x+1][y] ^= 1;
}

void Dfs(int row,int step,int value)
{
  if(row == n+1)
  {
    for(int i = 1; i <= n; i++)
      if(Map[n][i]==value)          //若不符合，退出
        return;
    ans=min(step,ans);          //符合则更新答案
    return;
  }
  int v = 0;
  for(int i = 1; i <= n; i++)
    if(Map[row-1][i]==value)        //上一层的某棋子不是目标状态，则翻转
    {
      step++;
      Flip(row,i);                  //翻转当前层以改变上一层的棋子
      v |= 1<<(i-1);                //记录翻转的位置
    }
  Dfs(row+1,step,value);
  for(int i = 1; i <= n; i++)       //还原
    if((v>>(i-1))&1)
      Flip(row,i);
}

int main()
{
  freopen("flip.in","r",stdin);
  freopen("flip.out","w",stdout);
  cin >> n;
  char ch;
  for(int i = 1; i <= n; i++)
    for(int j = 1; j <= n; j++)
    {
      cin >> ch;
      Map[i][j] =(ch=='b');
    }
  for(int k = 0; k <(1<<n); k++)
  {
    for(int i = 1; i <= n; i++)     //枚举出第0行(不存在的行)的所有状态
      Map[0][i]=(k>>(i-1))&1;
    Dfs(1,0,0);                     //从第1行开始，搜索能不能找到全为1的状态
    Dfs(1,0,1);                     //从第1行开始，搜索能不能找到全为0的状态
  }
  if(ans!=(1<<31)-1)
    cout<<ans<<endl;
  else
    cout<<"Impossible"<<endl;
  return 0;
}
