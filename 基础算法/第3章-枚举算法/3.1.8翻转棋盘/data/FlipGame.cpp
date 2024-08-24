//翻转棋盘 - BFS
#include <bits/stdc++.h>
using namespace std;

queue <int> que;                           //宽度优先搜索中用到的队列
bool flag[65536];                          //flag[i]=1即i状态已出现过
int step[65536];                           //step[i]即到i状态的步数

int Flip(int state,int pos)                //翻转pos及其周围位置
{
  state^=(1<<pos);
  state^=((pos-4)>=0)<<(pos-4);            //翻转上方
  state^=((pos+4)<=15)<<(pos+4);           //翻转下方
  state^=(pos%4!=0)<<(pos-1);              //翻转左方
  state^=(pos%4!=3)<<(pos+1);              //翻转右方
  return state;
}

int BFS()                                  //广搜
{
  while(que.empty()!=1)                    //当队列不为空
  {
    int state=que.front();                 //取出队首状态
    que.pop();                             //弹出队首元素
    for(int i=0; i<16; i++)
    {
      int temp=Flip(state,i);              //枚举当前状态下，翻转16个棋子后的状态
      if(temp==0 || temp==65535)           //若全0或全1
      {
        flag[temp]=1;
        step[temp]=step[state]+1;
        return true;
      }
      else if(!flag[temp])                 //若该状态没有出现过
      {
        que.push(temp);
        flag[temp]=1;                      //保存该状态
        step[temp]=step[state]+1;
      }
    }
  }
  return false;
}

int main()
{
  //freopen("FlipGame.in","r",stdin);
  //freopen("FlipGame.out","w",stdout);
  int state=0;
  char s[5];
  for(int i=0; i<4; i++)
  {
    scanf("%s",s);
    for(int j=0; j<4; j++)
      state|=((s[j]=='b')<<(i*4+j));       //该位为1时，state+=1^位置
  }
  if(state==0 || state==65535)             //或全白或全黑
    printf("0\n");
  else
  {
    que.push(state);                       //初始状态入队列
    flag[state]=1;                         //表示该状态已出现过
    if(BFS())                              //广度优先搜索
      printf("%d\n",flag[0]?step[0]:step[65535]);
    else
      printf("Impossible\n");
  }
  return 0;
}

