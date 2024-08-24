//��ת���� - DFS
#include <bits/stdc++.h>
using namespace std;

int Map[6][6];                                   //����,ע����д��map
int dir[5][2]= {{-1,0},{1,0},{0,-1},{0,1},{0,0}};//��Χ��������ƫ����
int step;
bool flag;

void Flip(int x,int y)                           //��ת��x,y���������ڵ�
{
  for(int i=0; i<=4; i++)
    Map[x+dir[i][0]][y+dir[i][1]]=!Map[x+dir[i][0]][y+dir[i][1]];//���ӷ�ת
}

bool OK()                                        //�ж������Ƿ�ɫ
{
  for(int i=1; i<=4; i++)
    for(int j=1; j<=4; j++)
      if(Map[i][j]!=Map[1][1])
        return false;
  return true;
}

void DFS(int x,int y,int dep)
{
  if(dep==step)
  {
    flag=OK();
  }
  if(flag||x==5)                                 //�����ҵ�������ö�ٵ����һ��ĩ
    return ;
  Flip(x,y);                                     //��ת��(x,y)
  if(y<4)                                        //����������һ��
    DFS(x,y+1,dep+1);                            //��������һ��
  else
    DFS(x+1,1,dep+1);                            //����������һ�е�һ��
  Flip(x,y);                                     //��ԭ��(x,y)
  if(y<4)
    DFS(x,y+1,dep);
  else
    DFS(x+1,1,dep);
}

int main()
{
  //freopen("FlipGame.in","r",stdin);
  //freopen("FlipGame.out","w",stdout);
  char c;
  for(int i=1; i<=4; i++)
    for(int j=1; j<=4; j++)
    {
      cin>>c;
      if(c=='w')
        Map[i][j]=1;                             //��ɫ��Ϊ1����ɫ��Ϊ0
    }
  for(step=0; step<=16; ++step)                  //ö��16�η�ת
  {
    DFS(1,1,0);                                  //��(1,1)��ʼ����ǰ����Ϊ0
    if(flag)                                     //����ҵ�����������ö��
      break;
  }
  flag?printf("%d\n",step):puts("Impossible");
  return 0;
}

