//Prim�㷨����ʾ���� -����ͼ
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2001
#define INF 0x7f

int w[MAXN][MAXN];                  //����֮��ߵ�Ȩֵ
int mincount[MAXN];                 //�Ӽ��϶��㵽�ö������СȨֵ
int n,e,x,y,W;

void Prim(int star)
{
  int count=0,k;                    //countΪ���������бߵ�Ȩֵ��
  for(int i=1; i<=n; i++)           //����ÿ���㵽star�����СȨֵ
    mincount[i]=w[star][i];         //���û�����߾��������
  mincount[star]=0;                 //�˴�����뼯�ϵ�mincountΪ0

  for(int i=1; i<n; i++)
  {
    int Min=INF;
    for(int j=1; j<=n; j++)         //�ҵ���������СȨֵ�ı�
      if(mincount[j]!=0 && mincount[j]<Min)//�������mincount������0
      {
        Min=mincount[j];
        k=j;                        //��С�ıߵĶ������k
      }
    mincount[k]=0;                  //���������뵽��С��������
    count+=Min;                     //��������Ȩֵ���뵽��С��������

    for(int j=1; j<=n; j++)         //����������㵽k�����СȨֵ
      mincount[j]=min(mincount[j],w[k][j]);
  }
  cout<<count<<"\n";
}

int main()
{
  freopen("Line.in","r",stdin);
  freopen("Line.out","w",stdout);
  memset(w,127,sizeof(w));         //�����бߵı�ȨΪ�����
  cin>>n>>e;
  for(int i=1; i<=e; i++)
  {
    cin>>x>>y>>W;
    w[x][y]=W;
    w[y][x]=W;
  }
  Prim(1);                         //�ӱ��Ϊ1�Ķ��㿪ʼ����������
  return 0;
}

