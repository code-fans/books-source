//����·��
//�����뵽f[i][j][k][l]��ʾ�����Ͻ��ߵ�(i,j)�������½��ߵ�(k,l)��
//��·��������ȵ�����£�������·����ͬ�ķ�������Ȼ�󶯹淽���Զ��׼���
//����������Ȼ�ᱬʱ�䣬���ǽ�ά��ʵ����ֻҪö���߹��Ĳ���������
//�����ڵ��������Ϳ����Ƴ����ǵ�λ�ã����f[i][j][k]��ʾ��һ�����ڵ�i�У�
//��2�����ڵ�j�У�������k���ķ�����������ʱ�临�Ӷ�ΪO(n^3)��ԭ��ʱ��2s��
//����������1sӦ��û���⡣
//Ȼ���ǿռ䣬��д����ά״̬��ת�Ʒ��̣�
//f[i][j][k]=(f[i-1][j][k-1]+f[i][j][k-1]+f[i][j+1][k-1]+f[i-1][j+1][k-1])%mod;
//����Ȼ����֮����һ��״̬�й�ϵ�����Կ����ù��������Ż���
//f[i][j][now]=(f[i-1][j][pre]+f[i][j][pre]+f[i][j+1][pre]+f[i-1][j+1][pre])%mod;
#include <bits/stdc++.h>
using namespace std;

const int N=505;
const int MOD=1000000007;

int n,f[2][N][N];
char s[N][N];

int main()
{
//  freopen("path.in","r",stdin);
//  freopen("path.out","w",stdout);

  scanf("%d",&n);
  for (int i=1; i<=n; i++) scanf("%s",s[i]+1);
  if (s[1][1]==s[n][n]) f[0][0][0]=1;
  int now=0;
  for (int i=1; i<n; i++)
  {
    now^=1;
    for (int j=0; j<=i; j++)
      for (int k=0; k<=i; k++)
        f[now][j][k]=0;
    for (int j=0; j<i; j++)
      for (int k=0; k<i; k++)
        if (f[now^1][j][k])
        {
          int x1=j+1,y1=i-j,x2=n-k,y2=n-i+1+k;
          if (s[x1+1][y1]==s[x2-1][y2]) (f[now][j+1][k+1]+=f[now^1][j][k])%=MOD;
          if (s[x1][y1+1]==s[x2-1][y2]) (f[now][j][k+1]+=f[now^1][j][k])%=MOD;
          if (s[x1+1][y1]==s[x2][y2-1]) (f[now][j+1][k]+=f[now^1][j][k])%=MOD;
          if (s[x1][y1+1]==s[x2][y2-1]) (f[now][j][k]+=f[now^1][j][k])%=MOD;
        }
  }
  int ans=0;
  for (int i=0; i<n; i++)
    (ans+=f[now][i][n-1-i])%=MOD;
  printf("%d\n",ans);
  return 0;
}
