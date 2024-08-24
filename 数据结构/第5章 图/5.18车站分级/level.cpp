//��վ�ּ�
#include <bits/stdc++.h>
using namespace std;
#define MAX 1001

int n,m,Ans=1,station[MAX],Line[MAX][MAX],ind[MAX],dist[MAX];
bool Stop[MAX];

void TopoSort()                        //��������
{
  queue <int> q;
  for(int i=1; i<=n; i++)
    if(ind[i]==0)
    {
      q.push(i);
      dist[i]=1;
    }
  while(!q.empty())
  {
    int i=q.front();
    q.pop();                           //ȥ������Ԫ�� i
    for(int j=1; j<=n; j++)
      if(Line[i][j])                   //��� i->j �б�
      {
        ind[j]--;                      // j ����ȼ�1,�Ӳ����ж�Ϊ��������ν
        if(ind[j]==0)                  //��j������Ϊ 0�ĵ㣬�������
        {
          q.push(j);
          dist[j]=dist[i]+1;           //�伶��i�Ļ����ϼ� 1��i�ĵȼ�С��j��
          Ans=max(Ans,dist[j]);
        }
      }
  }
}

int main()
{
  //freopen("level.in","r",stdin);
  //freopen("level.out","w",stdout);
  scanf("%d %d",&n,&m);
  for(int i=1,s; i<=m; i++)
  {
    memset(Stop,0,sizeof(Stop));       //��ʾ�Ƿ���ͣ��վ
    scanf("%d",&s);
    for(int j=1; j<=s; j++)
    {
      scanf("%d",&station[j]);
      Stop[station[j]]=true;
    }
    for(int j=station[1]; j<=station[s]; j++)//ö��վ��
      if(!Stop[j])			                 //��������ͣ���ľ�С������ͣ��վ�ĵȼ�
        for(int k=1; k<=s; k++)	             //ö����ͣ��վ��
          if(!Line[j][station[k]])
          {
            Line[j][station[k]]=1;           //Line[i][j]��ʾj>i�ļ���
            ind[station[k]]++;
          }
  }
  TopoSort();
  cout<<Ans<<endl;
  return 0;
}
