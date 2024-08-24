//时钟问题 — DFS
#include <bits/stdc++.h>
using namespace std;

int Clock[9],P[9];                      //P[i]=j表示第i种方法用了j次
int M[9][9]=                            //表示每种方法控制了哪几个钟
{
  {1,1,0,1,1,0,0,0,0},
  {1,1,1,0,0,0,0,0,0},
  {0,1,1,0,1,1,0,0,0},
  {1,0,0,1,0,0,1,0,0},
  {0,1,0,1,1,1,0,1,0},
  {0,0,1,0,0,1,0,0,1},
  {0,0,0,1,1,0,1,1,0},
  {0,0,0,0,0,0,1,1,1},
  {0,0,0,0,1,1,0,1,1}
};

bool OK(int P[])                        //必须要将当前P数组的值传过来
{
  int test[9];
  for(int i=0; i<9; i++)
    test[i]=Clock[i];                   //复制
  for(int i=0; i<9; i++)
    for(int j=0; j<9; j++)
      test[i]=(test[i]+M[j][i]*P[j])%4; //算出当前组合下钟的状态
  for(int i=0; i<9; i++)
    if(test[i])
      return false;                     //只有全为0，即全是12点才可以
  return true;
}

void DFS(int dep)                         //DFS产生所有方法的组合
{
  if(dep>9)
    return;                             //边界条件
  if(OK(P))                             //如果符合
  {
    for(int i=0; i<9; i++)              //输出
      for(int j=0; j<P[i]; j++)
        cout<<i+1;
    cout<<endl;
    exit(0);
  }
  for(int i=0; i<4; i++)                //当前的旋转方法在0-3次之间
  {
    P[dep]=i;
    DFS(dep+1);
  }
}

int main()
{
  //freopen("clock.in","r",stdin);
  //freopen("clock.out","w",stdout);
  for(int i=0; i<9; i++)
    cin>>Clock[i];
  DFS(0);
  return 0;
}
