//八数码问题 - IDA*
#include <bits/stdc++.h>
using namespace std;

const int goal[9]= {1,2,3,8,0,4,7,6,5};        //目标状态
const int seat[9]= {4,0,1,2,5,8,7,6,3};        //每个数字的目标位置
int step[100];                                 //保存每一步的方向
int limit=-1;                                  //深度限制

inline int Dis(int loc1,int loc2)
{
  return abs(loc1/3-loc2/3) + abs(loc1%3-loc2%3);
}

inline int Manhattan(int state[9])
{
  int ans=0;
  for(int i=0; i<9; i++)
    if(state[i])
      ans+=Dis(i,seat[state[i]]);
  return ans;
}

inline bool Check(int state[9])                //判断是否成功
{
  for(int i=0; i<9; i++)
    if(state[i]!=goal[i])
      return 0;
  return 1;
}

inline bool Move(int zero, int dir, int &nxt)  //判断空格能否向dir方向移动
{
  switch(dir)
  {
    case 0:
      nxt=zero-3;                         //nxt为0移动后的位置
      return zero>2;                      //0的位置大于2才可向上移
    case 1:
      nxt=zero+1;
      return zero%3!=2;                   //0的位置不在第三列才可右移
    case 2:
      nxt=zero+3;
      return zero<6;                      //0的位置不在第三行才可下移
    case 3:
      nxt=zero-1;
      return zero%3;                      //0的位置不在第一列才可左移
  }
}

bool DFS(int state[], int zero, int dep=0)     //dep为搜索深度
{
  if(dep==limit)
    return Check(state);
  if(dep+Manhattan(state)>limit)
    return 0;
  int nxt;                                     //空格移动后的位置
  for(int d=0; d<4; d++)            //尝试4个方向移动，0:上,1:右,2:下,3:左
    if((!dep || abs(step[dep-1]-d)!=2) && Move(zero,d,nxt))//正反方向差值为2
    {
      swap(state[zero],state[nxt]);
      step[dep]=d;
      if(DFS(state, nxt, dep+1))
        return 1;
      swap(state[zero],state[nxt]);
    }
  return 0;
}

int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  int start[9], zero;
  for(int i=0; i<9; i++)
  {
    cin>>start[i];
    if(start[i]==0)
      zero=i;
  }
  int sum=0;
  for(int i=0; i<8; i++)                //计算逆序对
    for(int j=i+1; j<9; j++)
      if(start[i] && start[j] && start[i]>start[j])
        sum++;
  if(sum & 1)                           //逆序对数为奇数则有解
  {
    limit=Manhattan(start);             //初始限制步数为初始状态的曼哈顿距离
    while(limit<100 && !DFS(start, zero))
      limit++;
  }
  cout<<limit<<endl;
  return 0;
}

