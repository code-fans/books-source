//冲突
#include<bits/stdc++.h>
using namespace std;
char board[5][5];
int visited[5][5];      //visited数组表示此位置是否被访问过
int cnt,n,maxn;

bool Try(int x,int y)   //上下左右尝试看是否有冲突
{
  for(int i=x+1; i<n && board[i][y]!='X'; i++)
    if(visited[i][y])
      return false;
  for(int i=x-1; i>=0 && board[i][y]!='X'; i--)
    if(visited[i][y])
      return false;
  for(int i=y+1; i<n && board[x][i]!='X'; i++)
    if(visited[x][i])
      return false;
  for(int i=y-1; i>=0 && board[x][i]!='X'; i--)
    if(visited[x][i])
      return false;
  return true;
}

void Placed(int cnt)
{
  if(cnt>=maxn)
    maxn=cnt;
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(!visited[i][j] && board[i][j]=='.' && Try(i,j))
      {
        visited[i][j]=1;
        Placed(cnt+1);
        visited[i][j]=0;
      }
}

int main()
{
  freopen("Conflict.in","r",stdin);
  freopen("Conflict.out","w",stdout);
  while(cin>>n && n)
  {
    maxn=0;
    memset(visited, 0, sizeof(visited));
    for(int i=0; i<n; i++)
      for(int j=0; j<n; j++)
        cin>>board[i][j];
    Placed(0);
    cout<<maxn<<endl;
  }
  return 0;
}

