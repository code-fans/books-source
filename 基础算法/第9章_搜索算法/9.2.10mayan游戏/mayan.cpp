//Mayan游戏
#include <bits/stdc++.h>
using namespace std;

struct T
{
  short x,y,ops;             //ops标记操作
} ans[10];
short st[6][8];
int n;

void Down()                //模拟下落的过程
{
  for (short i=0; i<5; i++)  //逐列
    for (short h=1; h<7; h++)//按行从下到上
      if(st[i][h])         //这个方块有颜色
        for(short H=h; H-1>=0 && !st[i][H-1]; H--)//下面是空的就往下落
          swap(st[i][H],st[i][H-1]);
}

bool Clear(short flag=0)//清除块
{
  int del[6][8]= {0};
  for(short i=0; i<5; i++)
    for(short j=0; j<7; j++)
    {
      if(st[i][j] && i-1>=0 && i+1<5 &&st[i][j]==st[i-1][j] && st[i][j]==st[i+1][j])
        del[i-1][j]=del[i+1][j]=del[i][j]=flag=1;
      if(st[i][j] && j-1>=0 && j+1<7 &&st[i][j]==st[i][j+1] && st[i][j]==st[i][j-1])
        del[i][j]=del[i][j+1]=del[i][j-1]=flag=1;
    }
  if(!flag) return flag;
  for(short i=0; i<5; i++)
    for(short h=0; h<7; h++)
      if(del[i][h])
        st[i][h]=0;
  return flag;
}

void DFS(int step)
{
  if(step > n)
  {
    if(st[0][0]+st[1][0]+st[2][0]+st[3][0]+st[4][0]==0)
    {
      for(short i = 1; i <= n; i++)
        printf("%d %d %d\n",ans[i].x+ans[i].ops,ans[i].y,ans[i].ops?-1:1);
      exit(0);
    }
    return;
  }
  for(short x = 0; x < 4; x++)
    for(short y = 0; y < 7; y++)
      if(st[x][y] != st[x+1][y])    //颜色相同的就不用交换了
      {
        ans[step].x = x;
        ans[step].y = y;
        ans[step].ops = (!st[x][y]);//如果当前这一块是空的话，那么就把它右边那一块左移，避免了分情况讨论
        int temp[6][8];
        memcpy(temp,st,sizeof temp);//保存当前状态
        swap(st[x][y],st[x+1][y]);
        for(Down(); Clear(); Down());//下移之后可能产生连锁反应，所以循环
        DFS(step+1);//迭代加深
        memcpy(st,temp,sizeof st);//此处恢复，不这么写，无法恢复
      }
}

int main()
{
  //freopen("mayan.in","r",stdin);
  //freopen("mayan.out","w",stdout);
  scanf("%d",&n);
  for(short i = 0; i < 5; i++)//枚举列
    for(short h=0; scanf("%d",&st[i][h]) && st[i][h]; h++);//枚举行
  DFS(1);
  printf("-1\n");
  return 0;
}

