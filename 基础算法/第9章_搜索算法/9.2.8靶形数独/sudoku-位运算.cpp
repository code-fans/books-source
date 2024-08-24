//靶形数独-位运算
#include<bits/stdc++.h>
using namespace std;

int Ans=-1,score[9][9],a[15][15];
int X[9],Y[9],Z[9],cnt[512],num[512];

int z(int x,int y)
{
  return x/3*3+y/3;
}

void Sign(int x,int y,int k)//标记此行、列，小矩形该数字已填
{
  X[x]^=1<<k;
  Y[y]^=1<<k;
  Z[z(x,y)]^=1<<k;
}

void DFS(int now)
{
  if(now==0)                //已填满
  {
    int ans=0;
    for(int i=0; i<9; i++)
      for(int j=0; j<9; j++)
        ans+=score[i][j]*a[i][j];//统计分数
    Ans=max(Ans,ans);
    return;
  }
  int temp=10,x,y;
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
    {
      if(a[i][j]) continue;
      int val=X[i] & Y[j] & Z[z(i,j)];//看是否有数没有填
      if(val==0)
        return;
      if(cnt[val]<temp)
      {
        temp=cnt[val];
        x=i;      //确定最小的要填充的位置x,y
        y=j;
      }
    }
  for(int val=X[x]&Y[y]&Z[z(x,y)]; val; val-=val&-val)//枚举没有填的数
  {
    int t=num[val&-val];//找出这个没有填的数
    a[x][y]=t+1;
    Sign(x,y,t);
    DFS(now-1);
    a[x][y]=0;          //恢复
    Sign(x,y,t);
  }
}

void Init()
{
  for(int i=0; i<=8; i++)                   //生成分值矩阵
    for(int j=0; j<=8; j++)
      score[i][j]=min(min(i,j),min(8-i,8-j))+6;
  for(int i=0; i<1<<9; i++)
    for(int j=i; j; j-=j&-j)
      cnt[i]++;//标准每种状态的二进制有多少1，例如11101110为6
  for(int i=0; i<9; i++)
    num[1<<i]=i;//例如10000000为8
  for(int i=0; i<9; i++)
    X[i]=Y[i]=Z[i]=(1<<9)-1;//均初始为11111111
}

int main()
{
  //freopen("sudoku.in","r",stdin);
  //freopen("sudoku.out","w",stdout);
  Init();
  int tot=0;
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
    {
      scanf("%d",&a[i][j]);
      if(a[i][j])
        Sign(i,j,a[i][j]-1);//标记该行该列该小矩阵有此数
      else
        tot++;
    }
  DFS(tot);
  printf("%d",Ans);
  return 0;
}
