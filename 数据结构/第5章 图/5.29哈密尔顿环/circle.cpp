//���ܶ��ٻ�
#include <bits/stdc++.h>
using namespace std;
const int MAXN=1005;

int start,lent,g[MAXN][MAXN],num[MAXN],ans[MAXN];
bool val[MAXN],visit[MAXN];

void Out(int len)
{
  for(int i=1; i<=len; i++)
    printf("%d%c",ans[i],i==len?'\n':' ');
}

void Dfs(int last, int cur,int len)   //last:�ϴη��ʵĵ�,cur:�����ʵĵ�
{
  visit[cur]=true;                    //��ǰ������Ϊ�ѷ��ʹ�
  ans[++len]=cur;                     //���õ�ӵ�����,lenthΪ���ĳ���
  for(int i=1; i<=num[cur]; i++)      //Ѱ��i�����ӵ����б�
  {
    if(g[cur][i]==start && g[cur][i]!=last)//�ص�����Ҳ��ǵڶ����㼴�ǻ�
    {
      ans[++len]=g[cur][i];
      Out(len--);                     //����𰸺�len--
      //break;                        //�˴���Ҫbreak,��ΪҪ�����л�
    }
    if(!visit[g[cur][i]] && g[cur][i]>cur)//������i������δ���ʵ�
      Dfs(cur,g[cur][i],len);         //g[cur][i]>cur��֤�������ִ���ǰ��Ų��ظ�
  }
  visit[cur]=false;                   //����
}

int main()
{
  //freopen("circle.in","r",stdin);
  //freopen("circle.out","w",stdout);

  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1,u,v; i<=m; i++)
  {
    scanf("%d%d",&u,&v);
    g[u][++num[u]]=v;                 //num[u]ͳ��u������ӱ���
    g[v][++num[v]]=u;
  }
  for(start=1; start<=n; start++)     //����ÿһ������Ϊ��ʼ��
    Dfs(0,start,0);
  return 0;
}

