//ͨ�ŷ���
#include <bits/stdc++.h>
using namespace std;
const int N=2e4+10;            //2e4��20000
const int M=50000;
int n,tim=0;
int DfsNode[N],Father[N];
vector<int>edg[N];
bool s[N],Set[N];              //s[]Ϊ���ǵ�,Set[]Ϊ֧�伯��ע��Set����Сд

void Dfs(int u,int father)
{
  DfsNode[tim++]=u;
  for(int i=0; i<edg[u].size(); i++)
  {
    int v=edg[u][i];
    if(v!=father)
    {
      Father[v]=u;
      Dfs(v,u);
    }
  }
}

int Greedy()
{
  int ans=0;
  for(int i=n-1; i>=0; i--)       //����DFS
  {
    int t=DfsNode[i];
    if(!s[t])//��ǰ��δ�����ǣ�����������֧�伯��Ҳ����֧�伯�еĵ�����
    {
      if(!Set[Father[t]])         //��ǰ��ĸ��׽�㲻����֧�伯
      {
        Set[Father[t]]=true;      //����������֧�伯
        ans++;                    //֧�伯��Ŀ��һ
      }
      s[t]=true;                  //��ǵ�ǰ��㱻����
      s[Father[t]]=true;          //��ǵ�ǰ���ĸ���㱻����
      s[Father[Father[t]]]=true;  //��ǵ�ǰ���ĸ����ĸ���㱻����
    }
  }
  return ans;
}

int main()
{
  freopen("comm6.in","r",stdin);
  freopen("comm6.ans","w",stdout);
  scanf("%d",&n);
  int u,v;
  for(int i=1; i<n; i++)
  {
    scanf("%d%d",&u,&v);
    edg[u].push_back(v);
    edg[v].push_back(u);
  }
  Dfs(1,0);
  printf("%d\n",Greedy());
  return 0;
}

