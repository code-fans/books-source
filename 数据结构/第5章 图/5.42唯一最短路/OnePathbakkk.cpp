//Ψһ���· ����С������2
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int MAXN=105;

bool Tlink[MAXN][MAXN],vis[MAXN];//Tlink��¼���Ƿ���MST��,vis[i]:i���Ƿ���MST
int w[MAXN][MAXN];               //w[i][j]Ϊi��j�ıߵ�Ȩֵ
int lowc[MAXN], pre[MAXN];
int Max[MAXN][MAXN];             //Max[i,j]ΪMST������i,jΨһ·������Ȩֵ
int n, m;

int Prim()
{
  int p;
  int minc, res = 0;
  memset( vis, false, sizeof(vis));
  memset( pre, 0, sizeof(pre));
  memset( Max, 0, sizeof(Max));
  vis[1] = 1;                    //�ӵ�һ����㿪ʼ
  pre[1] = 1;                    //ǰ���ǽ�㣱
  for(int i = 2; i <= n; i ++)   //��ʼ��
  {
    lowc[i] = w[1][i];
    pre[i] = 1;
  }

  for(int i = 2; i <= n; i ++)   //Prim�㷨
  {
    minc = INF;
    p = -1;
    for(int j = 1; j <= n; j ++)
    {
      if( !vis[j] && lowc[j] < minc)//�ҳ����û�б�����MST����СȨֵ��
      {
        minc = lowc[j];
        p = j;
      }
    }
    vis[p] = true;               //�ý�����MST
    res += minc;                 //��С��Ȩֵ�ۼ�
    Max[ pre[p] ][p] = minc;
    Tlink[ pre[p] ][p] = true;   //�������߱��Ϊ��С���ı�
    Tlink[p][ pre[p] ] = true;   //�������߱��Ϊ��С���ı�
    for(int k = 1; k <= n; k ++)
      Max[k][p] = max( Max[ pre[p] ][p], Max[k][p]);//�������Ӹñߵ����ֵ
    for(int j = 1; j <= n; j ++)              //����p�㵽j�����С��Ȩֵ
      if( !vis[j] && lowc[j] > w[p][j])
      {
        lowc[j] = w[p][j];
        pre[j] = p;              //ȷ��ǰ�����
      }
  }
  return res;
}

int main()
{
  //freopen("OnePath.in","r",stdin);
  //freopen("OnePath.out","w",stdout);
  int s, e, t, Ans, ans;
  cin>>n>>m;
  memset(w,63,sizeof(w));//��Ϊ�����,63=127/2
  memset( Tlink, false, sizeof Tlink);
  for( int i = 1; i <= m; i ++)
  {
    cin>>s>>e>>t;
    w[s][e] = t;         //�����ڽӱ� 
    w[e][s] = t;
  }
  Ans = Prim();                  //Prim�㷨�����С������Ȩֵ
  for( int i = 1; i <= n; i ++)
  {
    for( int j = 1; j <= n; j ++)
    {
      if( w[i][j] == INF || Tlink[i][j])//����õ�����С�����������ޱ������
        continue;
      ans = Ans + w[i][j] - Max[i][j];//Max[i,j]:MST������i,j������Ȩֵ
      if( Ans == ans)    //������ּӷ���С����һ���ߺ�Ȩֵ��ԭ��С��Ȩֵ���
      {
        printf( "Not Unique!\n");
        exit(0);
      }
    }
  }
  printf( "%d\n", Ans);
  return 0;
}

