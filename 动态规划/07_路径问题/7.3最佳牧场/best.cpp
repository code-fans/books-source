#include<bits/stdc++.h>
const int inf=0x3fffffff;
using namespace std;
int n,m,p,like[501];//n���㣬m���ߣ�p��ϲ���ĵ㣨��Ϊ����ϰ�ߣ�����Ŀ��������ͬ��
int ans,mi=inf,f[501][501];
int main()
{
  int i,j,k,u,v,c,sum;
  cin>>n>>p>>m;
  for(i=1; i<=n; i++) //��ʼ��
  {
    for(j=1; j<=n; j++) f[i][j]=inf;
    f[i][i]=0;//��i����i����С����Ϊ0
  }
  for(i=1; i<=p; i++) cin>>like[i];
  for(i=1; i<=m; i++)
  {
    cin>>u>>v>>c;
    f[u][v]=c;//���������ڽӾ���ķ�ʽ����
    f[v][u]=c;
  }
  for(k=1; k<=n; k++)
    for(i=1; i<=n; i++)
      for(j=1; j<=n; j++)
        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);//DP��̬ת�Ʒ���
  for(i=1; i<=n; i++)
  {
    sum=0;
    for(j=1; j<=p; j++) sum+=f[i][like[j]]; //�ۼӾ����
    if(sum<mi)
    {
      mi=sum;  //���´�
      ans=i;
    }
  }
  cout<<ans<<endl;
  return 0;
}
