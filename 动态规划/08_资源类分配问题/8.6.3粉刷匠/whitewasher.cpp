//��ˢ��
//����һ�� f[i][j]����������ʾǰi��ľ���ˢj�ε����������ȷ��ˢ����������
//����һ��g[i][j][k]����ʾ��i��ľ���Ϸ�ˢj��Ϳ��ǰk�����ӵ����������ȷ��ˢ����������
//��sum��������¼��ɫ������ ĳ������ĸ�������ȥ��ɫ���������Ƿ�ɫ����������ǰ׺������¼��
//Ҫ�������ĸ����� ��ô��Ҫ��һ��mʹ��
//  f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k][m])
//��һ����������
//������������g[i][j][k]̬ת�Ʒ����˻��Ǻܺ����
//ǰq�����ӷ�ˢ��ȷ������һ����ˢ��ȷ�ķ�ɫ���Ӷ໹����ɫ���Ӷ�
//��
//g[i][j][k]=max(g[i][j][k],g[i][j-1][q]+max(sum[i][k]-sum[i][q],k-q-sum[i][k]+sum[i][q]));
//����sum[i][k]-sum[i][q]��ɫ����
//k-q-sum[i][k]+sum[i][q]�öεķ�ɫ����
//��󿴿���ˢ���ٴ�ʱ������f[i][j]����ans��
#include<bits/stdc++.h>
using namespace std;

int f[51][2550],sum[51][2550];
int g[51][2550][51];
int n,m,t;
char s[150];

int main()
{
  //freopen("whitewasher.in","r",stdin);
  //freopen("whitewasher.out","w",stdout);
  cin>>n>>m>>t;
  for(int i=1; i<=n; i++)
  {
    cin>>s;
    sum[i][0]=0;
    for(int j=1; j<=m; j++)
    {
      if(s[j-1]=='1') sum[i][j]=sum[i][j-1]+1;
      else sum[i][j]=sum[i][j-1];
    }
  }
  for(int i=1; i<=n; i++)
    for(int j=1; j<=m; j++)
      for(int k=1; k<=m; k++)
        for(int q=j-1; q<k; q++)
          g[i][j][k]=max(g[i][j][k],g[i][j-1][q]+max(sum[i][k]-sum[i][q],k-q-sum[i][k]+sum[i][q]));
  for(int i=1; i<=n; i++)
    for(int j=1; j<=t; j++)
      for(int k=0; k<=min(j,m); k++)
        f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k][m]);
  int ans=0;
  for(int i=1; i<=t; i++)
    ans=max(ans,f[n][i]);
  cout<<ans<<endl;
}
