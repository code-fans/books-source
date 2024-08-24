//Ⱦɫ����-DFS�㷨
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10020;
vector <int> G[MAXN];
int color[MAXN];
int V, E;

bool Dfs(int v, int c)
{
  color[v] = c;                               //����Ⱦ��c
  for (int i = 0; i < G[v].size(); i++)
  {
    if(color[G[v][i]]==c)                     //������ڵ�ͬɫ�򷵻�false
      return false;
    if(color[G[v][i]]==0 && !Dfs(G[v][i],-c)) //�����ڵ�ûȾɫ������Ⱦ-cʧ��
      return false;
  }
  return true;                                //�����Ⱦɫ���ͷ���true
}

int main()
{
  freopen("color.in","r",stdin);
  freopen("color.out","w",stdout);
  int t;
  cin>>t;
  while(t--)
  {
    memset(color,0,sizeof(color));
    for(int i=0; i<MAXN; i++)
      G[i].clear();
    cin>>V>>E;                                  //���������ͱ���
    for (int i = 0; i < E; i++)
    {
      int s, t;
      cin >> s >> t;
      G[s].push_back(t);
      G[t].push_back(s);                        //����ͼ��ʡ�Դ˾�
    }
    int flag=0;
    for (int i = 0; i < V; i++)
      if (color[i] == 0)
        if (!Dfs(i, 1))                         //���Ⱦɫʧ��
        {
          flag=1;
          cout << "No" << endl;
          break;
        }
    if(flag==0)
      cout << "Yes" << endl;
  }
  return 0;
}

