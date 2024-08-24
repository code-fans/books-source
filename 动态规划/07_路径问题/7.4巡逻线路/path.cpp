//��Ϊ������Կ���һ������ͼ���������ǿ��Խ�·����Ϊȥ�ͻ�������
//Ȼ��ѻ�ȥ��·������������ͱ����������·���������е㲢�Ҳ�
//�ظ�������������㡣
//��dp[i][j]��ʾ��һ��·�������i���㣬�ڶ���·�������j����ʱ��
//���·��Ȼ������ÿ����i��j������ǰ����һ��k��ʾ��i�͵�j������ǰ�ߵ��������
//����kΪmax(i,j)+1;����
//Ϊ�˱�֤����ʱ������³�F[i][i](��һ������������)������ÿ���㶼����·���ϣ�
//����ÿ����F[i][j]ȥ���µ�max(i,j)+1��
//  dp[1][1]=0;
//ת�Ʒ���Ϊ��
//  dp[i][k]=min(dp[i][k],dp[i][j]+dis[j][k]);
//  dp[k][j]=min(dp[k][j],dp[i][j]+dis[i][k]);
//��������һ��·�������յ�ʱ
//dp[n][n]=min(dp[n][n],dp[i][j]+dis[i][n])
//dp[n][n]=min(dp[n][n],dp[i][j]+dis[j][n])

#include <bits/stdc++.h>
using namespace std;
#define N 1010
#define INF 0x3f3f3f3f

double x[N],y[N],dis[N][N],dp[N][N];

double Dis(double x1,double y1,double x2,double y2)
{
  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main()
{
  //freopen("path.in","r",stdin);
  //freopen("path.out","w",stdout);
  int n,b1,b2;
  scanf("%d%d%d",&n,&b1,&b2);
  b1++;
  b2++;
  for (int i=1; i<=n; i++)
    scanf("%lf%lf",&x[i],&y[i]);
  for (int i=1; i<n; i++)
    for (int j=i+1; j<=n; j++)
      dis[i][j]=dis[j][i]=Dis(x[i],y[i],x[j],y[j]);  //�������
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
      dp[i][j]=INF;                                  //��ʼ��
  dp[1][1]=0;
  for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    {
      if (i==j && i!=1)                              //����·�����ظ��Ҳ��ǵ�һ����
        continue;
      int k=max(i,j)+1;                              //i,j������ǰ
      if (k==n+1)                                    //�����յ�ʱ
      {
        if (i!=n)
          dp[n][n]=min(dp[n][n],dp[i][j]+dis[i][n]);
        if (j!=n)
          dp[n][n]=min(dp[n][n],dp[i][j]+dis[j][n]);
      }
      else                                           //û�е����յ�ʱ
      {
        if (k!=b1)                                   //��b1�ų��ڵڶ���·��
          dp[i][k]=min(dp[i][k],dp[i][j]+dis[j][k]);
        if (k!=b2)                                   //��b2�ų��ڵ�һ��·��
          dp[k][j]=min(dp[k][j],dp[i][j]+dis[i][k]);
      }
    }
  printf("%0.2lf\n",dp[n][n]);
  return 0;
}
