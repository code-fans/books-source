//八数码问题-朴素算法
#include <bits/stdc++.h>
using namespace std;

int dx[]= {-1,0,0,1},dy[]= {0,-1,1,0}; //增量数组
int state,X0,Y0;

int main()
{
  //freopen("Puzzle8.in","r",stdin);
  //freopen("Puzzle8.out","w",stdout);

  for(int i=0,t; i<=8; i++)
  {
    cin>>t;
    state=(state<<3)+(state<<1)+t; //相当于state*10+t
  }
  queue<int> q;
  q.push(state);
  map<int,int> m;
  m[state]=0;
  while(!q.empty())
  {
    int top=q.front();
    q.pop();
    if(top==123804765)
      break;
    int c[3][3],temp=top;
    for(int i=2; i>=0; i--)
      for(int j=2; j>=0; j--)
      {
        c[i][j]=temp%10,temp/=10;
        if(c[i][j]==0)             //找到0所在的坐标
          X0=i,Y0=j;
      }
    for(int i=0; i<4; i++)
    {
      int nx=X0+dx[i],ny=Y0+dy[i];
      if(nx<0||ny<0||nx>2||ny>2)   //越界
        continue;
      swap(c[nx][ny],c[X0][Y0]);
      state=0;
      for(int i=0; i<3; i++)       //转换为新状态
        for(int j=0; j<3; j++)
          state=(state<<3)+(state<<1)+c[i][j];
      if(m.count(state)==0)        //当没有该状态时
      {
        m[state]=m[top]+1;         //将步数保存
        q.push(state);             //新状态入队列
      }
      swap(c[nx][ny],c[X0][Y0]);   //状态还原
    }
  }
  cout<<(m[123804765]==0?-1:m[123804765])<<endl;
  return 0;
}

