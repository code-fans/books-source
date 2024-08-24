//Ψһ���· ����С������2
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;

int n,m;
bool InMST[110][110];                   //InMST[i][j]��ʾ��(i,j)�Ƿ���MST��
int G[110][110],Max[110][110],dad[110],mincount[110];

int Prim()                              //Prim�㷨
{
  int ans=0,k;
  for(int i=1; i<=n; i++)
  {
    mincount[i]=G[1][i];
    dad[i]=1;                           //��ʼʱMST��ֻ�н��1
  }
  mincount[1]=0;                        //���1���뼯��
  for(int i=1; i<n; i++)
  {
    int Min=INF;
    for(int j=1; j<=n; j++)
      if(mincount[j] && mincount[j]<Min)//Ѱ�Ҽ�������С�ı�
      {
        k=j;
        Min=mincount[j];
      }
    mincount[k]=0;                      //k����뼯��
    ans+=Min;
    InMST[dad[k]][k]=InMST[k][dad[k]]=1;//�߼���MST
    for(int j=1; j<=n; j++)             //�������еĵ�,������㵽k�����Ȩֵ
      Max[j][k]=max(Min,Max[j][dad[k]]);//Max[j][k]:�±߻�j��k��������Ȩֵ
    for(int j=1; j<=n; j++)
      if(mincount[j]>G[k][j])           //�и�С�ļ�����k�㵽�������j�������
      {
        mincount[j]=G[k][j];            //����k�㵽����������СȨֵ
        dad[j]=k;                       //��Ǽ�����j���뼯���ڵ�k�����
      }
  }
  return ans;                           //������С��������Ȩֵ
}

int main()
{
  //freopen("OnePath.in","r",stdin);
  //freopen("OnePath.out","w",stdout);
  memset(G,INF,sizeof(G));              //�����б߳�ʼֵΪ�����
  scanf("%d %d",&n,&m);
  for(int u,v,w; m; m--)
  {
    scanf("%d %d %d",&u,&v,&w);
    G[u][v]=G[v][u]=w;
  }
  int mst=Prim();
  for(int i=1; i<=n; i++)               //��ȫ������ö�ٳ�����MST�ϵı����
    for(int j=1; j<=n; j++)
      if(!InMST[i][j] && G[i][j]!=INF && G[i][j]==Max[i][j])//��ɾ���ߵȼ�
      {
        printf("Not Unique!\n");        //��ӱߺ�ɾ���ߵȼۣ�MST��Ψһ
        exit(0);
      }
  printf("%d\n",mst);
  return 0;
}

