#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int n,i,j,x,y;
int board[MAX][MAX];
int dx[8]= {1,-1,-2,-2,-1,1,2,2};
int dy[8]= {2,2,1,-1,-2,-2,-1,1};

void Display()
{
  for(i=0 ; i<n ; i++)
  {
    for(j=0 ; j<n ; j++)
      printf("%3d",board[i][j]);
    printf("\n");
  }
  printf("\n");
}

void Dfs(int step,int x,int y)
{
  if(n*n==step)
  {
    Display();
    return;
  }
  for(int i=0 ; i<8 ; i++)
    if(x+dx[i]>=0 && x+dx[i]<n && y+dy[i]>=0 && y+dy[i]<n && board[x+dx[i]][y+dy[i]]==0)
    {
      board[x+dx[i]][y+dy[i]]=step+1;
      Dfs(step+1,x+dx[i],y+dy[i]);
      board[x+dx[i]][y+dy[i]]=0;
    }
}

int main()
{
  scanf("%d%d%d",&n,&x,&y);
  board[x][y]=1;
  Dfs(1,x,y);
  return 0;
}
