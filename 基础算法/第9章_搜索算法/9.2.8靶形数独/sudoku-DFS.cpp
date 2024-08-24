//靶形数独
#include<bits/stdc++.h>
using namespace std;
#define z(i, j) i/3*3+j/3

int score[9][9];
int a[9][9],X[9][9],Y[9][9],Z[9][9],O[9],Line[9],ans=-1;

bool CMP(int a, int b)
{
  return O[a]<O[b];
}

void DFS(int step, int sum)
{
  if(step == 81)
  {
    ans = max(ans, sum);
    return;
  }
  int i = Line[step/9], j = step % 9;
  if(a[i][j])
    DFS(step+1, sum+a[i][j]*score[i][j]);
  else
    for(int k = 1; k <= 9; k++)
      if(!X[i][k] && !Y[j][k] && !Z[z(i, j)][k])
      {
        a[i][j]=k; //这句写不写都没事，因为XYZ三个数组的判断就可以把关
        X[i][k] = Y[j][k] = Z[z(i, j)][k] = 1;
        DFS(step+1, sum+k*score[i][j]);
        a[i][j]=0;
        X[i][k] = Y[j][k] = Z[z(i, j)][k] = 0;
      }
}

int main()
{
  //freopen("sudoku.in","r",stdin);
  //freopen("sudoku.out","w",stdout);
  for(int i=0; i<=8; i++)                   //生成分值矩阵
    for(int j=0; j<=8; j++)
      score[i][j]=min(min(i,j),min(8-i,8-j))+6;
  for(int i = 0; i < 9; i++)
  {
    Line[i] = i;
    for(int j = 0; j < 9; j++)
    {
      scanf("%d", &a[i][j]);
      if(a[i][j])
        X[i][a[i][j]]=Y[j][a[i][j]]=Z[z(i, j)][a[i][j]]=1;
      else
        O[i]++;     //统计该行0的个数
    }
  }
  sort(Line, Line+9, CMP);//排序，从未知量少的行开始搜,减少搜索量
  DFS(0, 0);//还可以判断如果DFS后的大小不超过ans，剪枝，但效果不明显
  printf("%d\n", ans);
  return 0;
}
