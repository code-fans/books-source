//Dijkstra�㷨
#include <bits/stdc++.h>
using namespace std;
const int Max=1<<30;
const int MAXN=1510;

int n;
int Map[MAXN][MAXN];                     //�洢ͼ
int visit[MAXN];                         //���÷��ʱ��
int d[MAXN];                             //��㵽��������С����

void Dijkstra(int x)                     //�����x�㵽�������ĵ�Դ���·��
{
  int Min,p;
  for(int i=1; i<=n; i++)                //Ԥ���������ʼ��x����������̾���
    d[i]=Map[x][i];
  visit[x]=1;                            //�����Ϊ�ѷ��ʹ�
  d[x]=0;                                //��������Ϊ��
  for(int i=1; i<n; i++)
  {
    Min=Max;                             //���·����ʼ��Ϊ�����
    for(int j=1; j<=n; j++)
      if(!visit[j] && Min>d[j])          //��û���ҹ���·����̵Ľ��
      {
        p=j;                             //��λ·����̵Ľ��
        Min=d[j];
      }
    visit[p]=1;                          //·����̽����Ϊ�ѷ���
    for(int j=1; j<=n; j++)              //����δ���ҽ�����С�����ܺ�
      if(!visit[j] && Min+Map[p][j]<d[j])//MinΪMap[x][p]+Map[p][j]
        d[j]=Min+Map[p][j];
  }
  for(int i=1; i<=n; i++)                //��ӡ�������x����������̾���
    cout<<d[i]<<'\n';
}

int main()
{
  //freopen("map.in","r",stdin);
  //freopen("map.out","w",stdout);
  cin>>n;                                //n�����
  for(int i=1; i<=n; i++)                //����ͼ
    for(int j=1; j<=n; j++)
    {
      cin>>Map[i][j];
      if(Map[i][j]==-1)                  //��������·��,��Ϊ+��,����ʱС�����
        Map[i][j]=Max;
    }
  Dijkstra(1);
  return 0;
}

