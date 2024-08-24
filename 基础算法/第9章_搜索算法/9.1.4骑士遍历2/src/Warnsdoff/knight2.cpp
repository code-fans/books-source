//��ʿ����2��Warnsdoff�㷨,���������Ҳ����⣬�����Ż�
#include <bits/stdc++.h>
using namespace std;

int N;
int dx[]= {2,1,-1,-2,-2,-1, 1, 2};
int dy[]= {1,2, 2, 1,-1,-2,-2,-1};
int board[100][100];

int ExitN(int x,int y,int start,int a[])//ͳ�ƣ�x,y���ĳ�����
{
  int xx,yy,count=0;
  for(int k=0; k<8; k++)
  {
    xx=x+dx[(start+k)%8];//�����һ����
    yy=y+dy[(start+k)%8];
    if(xx>=1 && xx<=N && yy>=1 && yy<=N && board[xx][yy]==0)
      a[count++]=(start+k)%8;//�����ڵ�ƫ���±�ֵ���δ浽a����
  }
  return count;//���س��ڸ���
}

int Next(int x,int y,int start)//���س������ٵĵ�
{
  int pos,a[8],b[8];
  int num=ExitN(x,y,start,a);//��ȡ�ж��ٸ��������
  if(num==0)
    return -1;               //���û�п����ߵĵ㣬����-1
  for(int min=N+1,k=0; k<num; k++) //�ҳ������ٵĵ�
  {
    int temp=ExitN(x+dx[a[k]],y+dy[a[k]],start,b);
    if(temp<min)
    {
      min=temp;
      pos=a[k];
    }
  }
  return pos;
}

int main()
{
  //freopen("knight2.in","r",stdin);
  //freopen("knight2.out","w",stdout);
  int x,y,step,start;
  cin>>N>>x>>y;
  board[x][y]=1;
  start=0;             //��ʼ˳���Ǵ�ƫ�������±�0��ʼ
  do
  {
    for(step=2; step<=N*N; step++)
    {
      int pos=Next(x,y,start);
      if(pos==-1)      //�Ҳ�������
        break;         //����ѭ������������˳��
      x+=dx[pos];      //���µ�ǰ��
      y+=dy[pos];
      board[x][y]=step;//�������ϼ�¼����
    }
    start++;           //����˳������һ�飬��Ҫ�Ľ�
  }
  while(step<N*N && start<8);
  if(step>N*N)
    for(int i=1; i<=N; i++)
      for(int j=1; j<=N; j++)
        printf("%d%c",board[i][j],(j==N?'\n':' '));
  else
    puts("-1");
  return 0;
}

