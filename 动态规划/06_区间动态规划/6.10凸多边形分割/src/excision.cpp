//͹����ηָ�
#include <bits/stdc++.h>
using namespace std;

double x[50],y[50],D[50][50],f[50][50]; //x[i]��ź����꣬y[i]��������꣬d1[i][j]����룬c[i][j]��ʾ��j�Ŷ��㿪ʼ��i���ε�Snp

double Dist(int i,int j) //��ȡ�����ľ���
{
  return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}

int main()
{
  freopen("excision.in","r",stdin);
  freopen("excision.out","w",stdout);
  int n;
  cin>>n;
  for(int i=0; i<=n-1; i++)
    cin>>x[i]>>y[i];
  for(int i=0; i<=n-1; i++)
    for(int j=0; j<=n-1; j++)
      if((fabs(i-j)==1)||(fabs(i-j)==n-1)) //�����������
        D[i][j]=0;
      else
        D[i][j]=Dist(i,j);

  for (int s=4; s<=n; s++) //�ı��ε�ͼ����ʼ��Ϊ����
    for (int i=0; i<=n-1; i++)
      f[s][i]=0x3f3f3f;
  for(int s=4; s<=n; s++) //���ı��ο�ʼ
    for(int i=0; i<=n-1; i++)
      for(int k=1; k<=s-2; k++)
        f[s][i]=min(f[s][i],f[k+1][i]+f[s-k][i+k]+D[i%n][(i+k)%n]+D[(i+k)%n][(i+s-1)%n]);
  cout<<fixed<<setprecision(2)<<f[n][0]<<endl;
  return 0;
}
