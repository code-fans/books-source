//����������-�����㷨
#include <bits/stdc++.h>
using namespace std;

int dx[]= {-1,0,0,1},dy[]= {0,-1,1,0}; //��������
int state,X0,Y0;

int main()
{
  //freopen("Puzzle8.in","r",stdin);
  //freopen("Puzzle8.out","w",stdout);

  for(int i=0,t; i<=8; i++)
  {
    cin>>t;
    state=(state<<3)+(state<<1)+t; //�൱��state*10+t
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
        if(c[i][j]==0)             //�ҵ�0���ڵ�����
          X0=i,Y0=j;
      }
    for(int i=0; i<4; i++)
    {
      int nx=X0+dx[i],ny=Y0+dy[i];
      if(nx<0||ny<0||nx>2||ny>2)   //Խ��
        continue;
      swap(c[nx][ny],c[X0][Y0]);
      state=0;
      for(int i=0; i<3; i++)       //ת��Ϊ��״̬
        for(int j=0; j<3; j++)
          state=(state<<3)+(state<<1)+c[i][j];
      if(m.count(state)==0)        //��û�и�״̬ʱ
      {
        m[state]=m[top]+1;         //����������
        q.push(state);             //��״̬�����
      }
      swap(c[nx][ny],c[X0][Y0]);   //״̬��ԭ
    }
  }
  cout<<(m[123804765]==0?-1:m[123804765])<<endl;
  return 0;
}

