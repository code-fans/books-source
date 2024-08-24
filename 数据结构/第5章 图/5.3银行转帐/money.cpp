//����ת��
#include <bits/stdc++.h>
#define MAXN 1<<30
using namespace std;
int n,m,vis[2001];
double Del[2001][2001],cost[2001];

void Dijkstra(int b)
{
  cost[b]=100;
  for(int i=1; i<=n; i++)
  {
    int MAX=-MAXN,k;
    for(int j=1; j<=n; j++)
      if(!vis[j] && MAX<cost[j])       //��δʹ�ù��Ľ���������ֵ
        MAX=cost[j],k=j;
    vis[k]=1;
    for(int j=1; j<=n; j++)
      if(Del[k][j] && !vis[j] && cost[k]*Del[k][j]>cost[j])
        cost[j]=cost[k]*Del[k][j];
  }
}

int main()
{
  //freopen("money.in","r",stdin);
  //freopen("money.out","w",stdout);
  int a,b,money;
  cin>>n>>m;
  for(int i=1; i<=m; i++)
  {
    cin>>a>>b>>money;
    Del[a][b]=Del[b][a]=(100.0-money)/100;//����������תΪ���
  }
  cin>>a>>b;
  Dijkstra(b);                         //��b������������
  printf("%.8lf",100.0/cost[a]*100);
  return 0;
}
