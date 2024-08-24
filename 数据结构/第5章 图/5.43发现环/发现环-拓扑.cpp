//���ֻ�-�������� 
#include <bits/stdc++.h>
using namespace std;

vector<int>vec[100005];
queue<int>que;
int deg[100005];
bool vis[100005];
int n;

void TopSort()
{
  memset(vis,true,sizeof(vis));
  while(!que.empty())//��ն���
    que.pop();
  for(int i=1; i<=n; i++)//�������Ϊ1�Ľڵ�
    if(deg[i]==1)
      que.push(i);
  while(!que.empty())
  {
    int now=que.front();
    que.pop();
    vis[now]=false;
    for(int i=0; i<vec[now].size(); i++)
      if(--deg[ vec[now][i] ] == 1)
        que.push(vec[now][i]);
  }
}

int main()
{
  int a,b;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
  {
    scanf("%d%d",&a,&b);
    vec[a].push_back(b);
    vec[b].push_back(a);
    deg[a]++;//���++
    deg[b]++;
  }
  TopSort();
  for(int i=1; i<=n; i++)
    if(vis[i])
      printf("%d ",i);
  return 0;
}
