//��������
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
        a[i][j]=k; //���д��д��û�£���ΪXYZ����������жϾͿ��԰ѹ�
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
  for(int i=0; i<=8; i++)                   //���ɷ�ֵ����
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
        O[i]++;     //ͳ�Ƹ���0�ĸ���
    }
  }
  sort(Line, Line+9, CMP);//���򣬴�δ֪���ٵ��п�ʼ��,����������
  DFS(0, 0);//�������ж����DFS��Ĵ�С������ans����֦����Ч��������
  printf("%d\n", ans);
  return 0;
}
