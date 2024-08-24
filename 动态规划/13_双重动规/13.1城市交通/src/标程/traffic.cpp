//���н�ͨ
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 60;
const int U = 1061109567;

double f[11][MAXN][MAXN];
int d[11][MAXN][MAXN],l[11][MAXN][MAXN],r[11][MAXN][MAXN];

struct Que
{
  int x, y, t;
} q[MAXN];
int cnt;

void PushQue(int x, int y, int t)        //��·����ṹ������
{
  q[++cnt]= {x,y,t};                     //c++11֧�ֵ��﷨
  if(q[cnt].x>q[cnt].y)
    swap(q[cnt].x,q[cnt].y);
}

int Cmp (struct Que a, struct Que b)     //��·���Ⱥ�˳������
{
  return a.x == b.x? a.y<b.y : a.x<b.x;
}

bool Dfs(const int &m,const int &i, const int &j)//DFS�ҳ����ӵ���·
{
  if (d[m][i][j])                        //��i,j���н�㣬�����
  {
    // ����ֵ��ʾ�Ƿ�������һ�������߶Σ�ֻ���ܲ����
    if (l[m][i][j] && Dfs(l[m][i][j], i, d[m][i][j]))
      PushQue(i,d[m][i][j],l[m][i][j]);
    if (r[m][i][j] && Dfs(r[m][i][j], d[m][i][j], j))
      PushQue(d[m][i][j],j,r[m][i][j]);
    return 0;
  }
  return 1;
}

int main()
{
  freopen("traffic.in","r",stdin);
  freopen("traffic.out","w",stdout);
  memset(f,0x7f,sizeof(f));              //�������鲻����0x3f�����ֵ
  int n,M,x, y,w;
  scanf("%d %d", &n, &M);
  while (scanf("%d%d%d", &x,&y,&w)==3 && x|y|w!=0)
    f[0][x][y]=f[0][y][x]=w;
  for (int i=1; i<=n; ++i)               //��ʼ��
    for (int j=1; j<=n; ++j)
      if (f[0][i][j]<=U)                 //�����·
        for (int m=1; m<=M; ++m)
          f[m][i][j]=f[m][j][i]=f[m-1][i][j]/2;
  if (M==0)                              //���0�����У���floyd
  {
    for (int k=1; k<=n; ++k)             //kҪ���������ѭ��
      for (int i=1; i<=n; ++i)
        for (int j=1; j<=n; ++j)
          if(f[0][i][k]!=U && f[0][k][j]!=U && f[0][i][j]>f[0][i][k]+f[0][k][j])
            f[0][i][j]=min(f[0][i][j],f[0][i][k]+f[0][k][j]);
  }
  else
    for (int m=1; m<=M; ++m)             //���M������·��
      for (int t=1; t<=m; ++t)           //��ӵĹ�����·�ָ������
        for (int k=1; k<=n; ++k)         //ö���м�ڵ�k
          for (int i=1; i<=n; ++i)       //ö�ٽ���i
            for (int j=1; j<=n; ++j)     //ö�ٽ���j
              if(f[m-t][i][k]!=U && f[t][k][j]!=U)
                if(f[m][i][j]>f[m-t][i][k]+f[t][k][j])//��������ֵ
                {
                  f[m][i][j]=min(f[m][i][j],f[m-t][i][k]+f[t][k][j]);
                  d[m][i][j]=k;//d[m][i][j]����i��j�����m��·���м���k
                  l[m][i][j]=m-t;        //l[m][i][j]:i��k����ӵ�·����
                  r[m][i][j]=t;          //r[m][i][j]:k��j����ӵ�·����
                }
  printf("%.2f\n", f[M][1][n]);
  if (M)
  {
    Dfs(M, 1, n);                        //M>1ʱ������������ӵ�·��
    sort(q+1, q+1+cnt,Cmp);
    for (int i=1; i<=cnt; ++i)
      for (int j=1; j<=q[i].t; ++j)      //������Ӳ�ֹ1��·��
        printf("%d %d\n", q[i].x, q[i].y);
  }
  return 0;
}

