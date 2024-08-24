//�Թ� - STLʵ��BFS
#include <bits/stdc++.h>
using namespace std;
#define N 105

struct M
{
  int  x,y;
  bool vis;                                     //�߹�����Ϊ1�Է��߻�ȥ
} pre[N][N];
bool Map[N][N];                                 //�����ͼ
int m,n;
int dir[8][2]= {{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1}};

bool In(int x,int y)                            //�ж������Ƿ�Խ��
{
  return (x>0 && x<=m && y>0 && y<=n);
}

void PrintWay(int x,int y)                      //�ݹ����·��
{
  if (x==1 && y==1)
    printf("%d %d\n",x,y);
  else
  {
    PrintWay(pre[x][y].x,pre[x][y].y);
    printf("%d %d\n",x,y);
  }
}

void BFS()
{
  queue<M>q;                                    //����һ������
  q.push(M {1,1});                              //�����,ע������C++11д��
  pre[1][1].vis=true;                           //��ʼ��������Ϊ���߹�
  while (!q.empty())
  {
    M cur=q.front();
    q.pop();                                    //������
    if(cur.x==m && cur.y==n)                    //�ҵ�����
    {
      PrintWay(m,n);
      exit(0);
    }
    for (int i=0; i<=7; i++)                    //���԰˸�����
    {
      int x=cur.x+dir[i][0];
      int y=cur.y+dir[i][1];
      if (In(x,y) && !pre[x][y].vis && !Map[x][y])//������������
      {
        q.push(M {x,y});                        //������ӣ�C++11д��
        pre[x][y].x=cur.x;                      //������һ��������
        pre[x][y].y=cur.y;
        pre[x][y].vis=true;
      }
    }
  }
}

int main()
{
  cin>>m>>n;
  for (int i=1; i<=m; i++)
    for (int j=1; j<=n; j++)
      scanf("%d",&Map[i][j]);
  BFS();
  puts("-1");
  return 0;
}

