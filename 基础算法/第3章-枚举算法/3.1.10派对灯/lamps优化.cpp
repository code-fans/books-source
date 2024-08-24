//派对灯
//每个开关按偶数次的时候，相当于没按
#include<bits/stdc++.h>
using namespace std;

int flag[7],n,c,OK;
int state[9][7]=
{
  0,0,0,0,0,0,0,//已排好序
  1,0,0,0,0,0,0,
  2,0,0,1,1,1,0,
  1,0,1,0,1,0,1,
  1,0,1,1,0,1,1,
  2,1,0,0,1,0,0,
  1,1,0,1,0,1,0,
  2,1,1,0,0,0,1,
  0,1,1,1,1,1,1,
};//循环节是6，并且能达到的只有8种形式,第一列保存达到该状态需要的步数

int Loc(int x)//映射为6个一循环的位置
{
  return (x%6==0?6:x%6);
}

int Check(int s)
{
  if (state[s][0]>c) return 0;//步数超了
  if (c==2 && s==4) return 0;//2步，达不到011011状态
  if (c==3 && ((s==2)||(s==5)||(s==7))) return 0;//3步，达不到001110/100100/110001
  if (c==1 && s==8) return 0;//1步，达不到111111状态
  for (int i=1; i<=6; i++)
  {
    if (flag[i]==-1) continue;//状态没有变，忽略
    if (state[s][i]!=flag[i]) return 0;
  }
  return 1;
}

int main()
{
  freopen("lamps.in","r",stdin);
  freopen("lamps.out","w",stdout);
  memset(flag,-1,sizeof(flag));
  scanf("%d%d",&n,&c);
  for(int k; scanf("%d",&k) && k!=-1; flag[Loc(k)]=1);
  for(int k; scanf("%d",&k) && k!=-1; flag[Loc(k)]=0);
  for (int i=1; i<=8; i++)//穷举8种状态
    if (Check(i))
    {
      for (int j=1; j<=n; j++)
        printf("%d",state[i][Loc(j)]);
      printf("\n");
      OK=1;
    }
  if (!OK) printf("IMPOSSIBLE\n");
  return 0;
}
