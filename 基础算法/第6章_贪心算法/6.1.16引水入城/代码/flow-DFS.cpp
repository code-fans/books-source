//��ˮ��ǡ�DFS+����ѡ��
//����һ�������������䣬��Ϊ����������г������ɱ��ˮ�������Ļ���
//��ô��ˮ��һ���н����,�Ǵ��⽻���Ϳ��Ե���
//��ΪDFS���̫��Windows����һ�����ݻ����
#include<bits/stdc++.h>
using namespace std;
int h[505][505],l[505][505],r[505][505];
int N,M,sum;
bool vis[505][505];
int dx[]= {0,0,1,-1};
int dy[]= {1,-1,0,0};

void DFS(int x,int y)
{
  vis[x][y]=true;
  for (int i=0; i<4; i++)
  {
    int X=x+dx[i];
    int Y=y+dy[i];
    if (X<1 || X>N || Y<1 || Y>M || h[x][y]<=h[X][Y])//�������continue
      continue;                                      //����ǰ��ӷ�������
    if (!vis[X][Y])
      DFS(X,Y);
    l[x][y] = min(l[x][y], l[X][Y]);//����ǰ����û��DFS�����ֵ��һ��Ҫ���µ�
    r[x][y] = max(r[x][y], r[X][Y]);//�������û��DFSֱ�����������޷�����
  }
}

int main()
{
  //freopen("flow.in","r",stdin);
  //freopen("flow.out","w",stdout);
  memset(l,127,sizeof(l));
  scanf("%d%d",&N,&M);
  for (int i=1; i<=N; i++)
    for (int j=1; j<=M; j++)
      scanf("%d",&h[i][j]);     //��ȡ���г��еĺ���
  for (int i=1; i<=M; i++)
    l[N][i]=r[N][i]=i;          //��N�г������ұ߽��ʼ��
  for (int i=1; i<=M; i++)
    if(h[1][i]>=h[1][i+1] && h[1][i]>=h[1][i-1] && !vis[1][i])//�Ż�
      DFS(1,i);                 //�����Ҷ��߲�ѡ��������е�������Ƿ�Χ����
  for (int i=1; i<=M; i++)      //ͳ���Ƿ��������޷�����
    if (!vis[N][i])
      sum++;
  if (sum)
    printf("0\n%d\n",sum);
  else
  {
    for(int L=1, R=r[1][1]; L<=M; L=R+1)            //����ѡ��
    {
      for (int i=1; i<=M; i++)
        if (l[1][i]<=L)
          R=r[1][i];
      sum++;
    }
    printf("1\n%d\n",sum);
  }
  return 0;
}
