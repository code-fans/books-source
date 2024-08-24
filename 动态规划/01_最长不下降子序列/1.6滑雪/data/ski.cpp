//��ѩ
#include <bits/stdc++.h>
using namespace std;

const int dx[4]= {-1,0,1,0};         //x����������
const int dy[4]= {0,1,0,-1};         //y����������
int m[101][101],f[101][101];
int r,c;

int Search(int x,int y)              //��[x,y]����·��
{
  if(f[x][y]>0)                      //��˵�����ĳ��������
    return f[x][y];                  //������ݹ�
  f[x][y]=1;                         //�����ʼ���Ⱦ���1
  for(int i=0; i<=3; i++)            //���ĸ��������ܵ���[x,y]�ĵ�
  {
    int nx=x+dx[i];                  //���Ϻ���������
    int ny=y+dy[i];                  //��������������
    if(nx>=1 && nx<=r && ny>=1 && ny<=c && m[x][y]<m[nx][ny])
      f[x][y]=max(Search(nx,ny)+1,f[x][y]);      //�ݹ���м��仯����
  }
  return f[x][y];
}

int main()
{
  freopen("ski.in","r",stdin);
  freopen("ski.out","w",stdout);
  scanf("%d%d",&r,&c);
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++)
      scanf("%d",&m[i][j]);
  int ans=0;
  for(int i=1; i<=r; i++)
    for(int j=1; j<=c; j++)
    {
      f[i][j]=Search(i,j);
      ans=max(f[i][j],ans);
    }
  printf("%d\n",ans);
  return 0;
}

