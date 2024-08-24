//数独游戏
#include <bits/stdc++.h>
using namespace std;

int G[9][9];                       //数独方阵
bool X[9][9],Y[9][9],Z[9][9];

void Out()
{
  for(int i=0; i<=8; i++)
    for(int j=0; j<=8; j++)
      printf("%d%c",G[i][j],(j==8?'\n':' '));
  exit(0);
}

void DFS(int step)
{
  if(step>80)
    Out();
  int x=step/9,y=step%9;
  if(G[x][y])
    DFS(step+1);
  else
    for(int i=1; i<=9; i++)
      if((!X[x][i]) && (!Y[y][i]) && (!Z[x/3*3+y/3][i]))
      {
        G[x][y]=i;
        X[x][i]=Y[y][i]=Z[x/3*3+y/3][i]=1;
        DFS(step+1);
        G[x][y]=0;
        X[x][i]=Y[y][i]=Z[x/3*3+y/3][i]=0;
      }
}

int main()
{
  //freopen("sudoku.in","r",stdin);
  //freopen("sudoku.out","w",stdout);
  for(int i=0; i<=8; i++)
    for(int j=0; j<=8; j++)
    {
      cin>>G[i][j];
      if(G[i][j])
        X[i][G[i][j]]=Y[j][G[i][j]]=Z[i/3*3+j/3][G[i][j]]=1;
    }
  DFS(0);
  return 0;
}
