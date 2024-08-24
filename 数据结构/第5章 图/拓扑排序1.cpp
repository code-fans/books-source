//��������
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1001

int n,m;                                 //nΪ�����,mΪ����
int mark[MAXN],ind[MAXN],Stack[MAXN];
//markΪ����������,indΪ���������,stackΪһ��ջ
bool w[MAXN][MAXN];                     //�ڽӱ�

void TopoSort()
{
  int u,t;
  int top = -1;                         //ջ��ָ��
  //�����Ϊ0�Ľ����ջ�����������
  for(int i = 1 ; i <= n ; i ++)
    if(ind[i] == 0 )
    {
      mark[i] = 1;
      Stack[++top] = i;
      ind[i] = -1;
    }

  do                                    //��DFS�ķ�ʽ��ǽ���������
  {
    u = Stack[top--];//ȡ��ջ�е�һ����㲢������ý�����ڵĽ�����ȼ�1
    for(int i=1; i<=n; i++)
      if(w[u][i] && ind[i] != -1)
        ind[i]--;

    for(int i=1; i<=n; i++)//���ҵ�ǰ�Ƿ������Ϊ0��û����ջ�Ľ�㲢������ջ
      if(ind[i] == 0)
      {
        mark[i] = mark[u] + 1;
        Stack[++top] = i;
        ind[i] = -1;
      }
  }
  while(top >= 0);
}

int main()
{
  cin>>n>>m;                           //������ͱ���n,m
  int u,v;
  for(int i=1; i<=m; i++)
  {
    cin>>u>>v;
    w[u][v] = true;
    ind[v]++;
  }
  TopoSort();
  for(int i=1; i<=n; i++)
    cout<<mark[i]<<" ";
  cout<<"\n";
  return 0;
}

