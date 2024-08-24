//��Ϣ����
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;

stack<int>st;
vector<int>vec[MAXN];
int n,cnt,idx,ans=MAXN;
int dfn[MAXN],low[MAXN],vis[MAXN];

void Tarjan(int x)
{
  low[x]=dfn[x]=++idx;
  st.push(x);
  vis[x]=1;
  for(int i=0; i<vec[x].size(); i++)
  {
    int v=vec[x][i];
    if(!dfn[v])
    {
      Tarjan(v);
      low[x]=min(low[x],low[v]);
    }
    else if(vis[v])
      low[x]=min(low[x],dfn[v]);
  }
  if(low[x]==dfn[x])                 //�ҵ���
  {
    vis[x]=0;
    for(cnt=1; st.top()!=x; cnt++)   //cntͳ�ƻ��н�����,��ʼΪ1
      st.pop();                      //��Ϊst.top=xʱѭ������,cnt����һ��
    if(cnt>2)                        //һ����㲻�ǻ�
      ans=min(ans,cnt);
  }
}

int main()
{
  freopen("message.in","r",stdin);
  freopen("message.out","w",stdout);
  scanf("%d",&n);
  for(int i=1,x; i<=n; i++)
  {
    scanf("%d",&x);
    vec[i].push_back(x);
  }
  for(int i=1; i<=n; i++)
    if(!dfn[i])
      Tarjan(i);
  printf("%d\n",ans);
  return 0;
}

