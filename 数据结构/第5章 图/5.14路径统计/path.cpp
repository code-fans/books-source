//·��ͳ��-Dijkstra
#include<bits/stdc++.h>
using namespace std;

const int N=2010;
int edg[N][N],dis[N],cnt[N];     //cnt[i]:��1��i�����·��������
bool visit[N];

int main()
{
  freopen("path.in","r",stdin);
  freopen("path.out","w",stdout);
  int n,m,x,y,z;
  scanf("%d%d", &n,&m);
  memset(edg,127,sizeof(edg));
  memset(dis,127,sizeof(dis));
  for(int i = 1; i <= m; i++)
  {
    scanf("%d%d%d", &x, &y, &z);
    edg[x][y]=min(edg[x][y], z); //�����ر�
  }
  dis[1]=0;                      //��1��1����̾���Ϊ0
  cnt[1]=1;
  for(int i=1; i<n; i++)
  {
    int MIN=0x7f7f7f,least;
    for(int j=1; j<=n; j++)
      if(dis[j]<MIN && !visit[j])//�ҳ�û�б�ǵ���̱�
        MIN=dis[j], least=j;
    visit[least]=1;
    for(int j=1; j<=n; j++)
      if(!visit[j] && dis[least]+edg[least][j]<dis[j])
      {
        dis[j]=dis[least]+edg[least][j];//��ĳ������·���ȱ�����
        cnt[j]=cnt[least];//�������·�������ڸ������ĵ�����·����
      }
      else if(dis[least]+edg[least][j]==dis[j])//�����������·�������
        cnt[j]+=cnt[least];//�ͰѸ��µĵ�����·�������ϣ��ӷ�ԭ��
  }
  dis[n]>=0x7f7f7f?cout<<"No answer\n":cout<<dis[n]<<' '<<cnt[n]<<endl;
  return 0;
}

