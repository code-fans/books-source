//·��ͳ�ơ�SPFA�㷨
#include<bits/stdc++.h>
using namespace std;

const int N=2010;
int Edg[N][N],d[N],cnt[N];
bool in[N];//�ж��Ƿ��ڶ���
int n,m,x,y,z;
queue<int>Q;

void SPFA(int S,int E)
{
  Q.push(S);
  d[S]=0;
  cnt[S]=1;
  while(!Q.empty())
  {
    int x=Q.front();
    Q.pop();
    in[x]=0;
    if(x==E)continue;//���������ı��յ�Ϊn������
    for(int k=1; k<=n; k++)
    {
      if(d[x]+Edg[x][k]==d[k])
        cnt[k]+=cnt[x];
      if(d[x]+Edg[x][k]<d[k])
      {
        d[k]=d[x]+Edg[x][k];
        cnt[k]=cnt[x];
      }
      if(cnt[k] && !in[k])
        in[k]=1,Q.push(k);
    }
    cnt[x]=0;    //·������0����Ȼ������ظ�ͳ��
  }
}

int main()
{
  freopen("path.in","r",stdin);
  freopen("path.out","w",stdout);
  memset(Edg,63,sizeof(Edg));
  memset(d,63,sizeof d);
  scanf("%d%d",&n,&m);
  while(m--)
  {
    scanf("%d%d%d",&x,&y,&z);
    Edg[x][y]=min(Edg[x][y],z);
  }
  SPFA(1,n);
  d[n]==Edg[0][0]?cout<<"No answer\n":cout<<d[n]<<' '<<cnt[n]<<endl;
  return 0;
}
