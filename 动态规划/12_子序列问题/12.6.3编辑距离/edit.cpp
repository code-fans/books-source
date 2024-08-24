//��̬�滮˼�룬��Ŀ�ʵ����ַ���a���ַ���b�ı༭���롣��̬�滮������������ṹ��
//���������ʽ��ԭ����ṹ���ƣ��ҹ�ģ��С����ô�ڿ��������ʱ����ǰ��һ����
//
//������ַ���aǰalen-1���ַ��Ѿ���b��ͬ����ô��ǰa��b�ı༭�������1��ɾ�����һ����
//
//������ַ���a��b��ǰblen-1���ַ���ͬ����ô��ǰa��b�ľ���Ҳ��1�����һ����
//�����a��ǰalen-1���ַ���b��blen-1���ַ��Ѿ���ͬ�����a�����һ���ַ���b�����һ��
//�ַ���ͬ����ôa��b�ı༭����Ϊ0������Ϊ1���ı�һ�Σ�
//��״̬Ϊdp[i][j],��ʾ�ַ���a��ǰi���ַ����ַ���b��ǰj���ַ��ı༭���룬�����Ϸ�����
//����д����dp��״̬ת�Ʒ��̣�
//
//dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1])(a�ĵ�i���ַ���b�ĵ�j���ַ���ͬ)
//dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1)(a�ĵ�i���ַ���b�ĵ�j���ַ���ͬ)
#include<bits/stdc++.h>
using namespace std;
#define maxn 2010
int d[maxn][maxn];

int min(int a,int b,int c)
{
  if(a>b) swap(a,b);
  if(a>c) swap(a,c);
  return a;
}

int main()
{
  freopen("edit.in","r",stdin);
  freopen("edit.out","w",stdout);
  char a[maxn],b[maxn];
  cin>>a>>b;
  memset(d,0,sizeof(d));
  int len1=strlen(a);
  for(int i=1; i<=len1; i++)
    d[i][0]=i;
  int len2=strlen(b);
  for(int i=1; i<=len2; i++)
    d[0][i]=i;
  for(int i=1; i<=len1; i++)
    for(int j=1; j<=len2; j++)
      d[i][j]=min(d[i-1][j]+1,d[i][j-1]+1,d[i-1][j-1]+(a[i-1]==b[j-1]?0:1));
  cout<<d[len1][len2]<<endl;
  return 0;
}
