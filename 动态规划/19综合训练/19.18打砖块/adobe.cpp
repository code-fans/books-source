#include <bits/stdc++.h>
using namespace std;
const int maxn=255;
#define M(a) memset(a,0,sizeof a)
const int mxn = 205;
int n, m, p, ans;
char ch;
int a[mxn][mxn], whe[mxn], res[mxn][mxn];
int dp[mxn][mxn][2], ci[mxn][mxn], now[mxn][mxn];  //0:����Ҫ�裬1:��Ҫ��
bool b[mxn][mxn];
int main()
{
  freopen("adobe.in","r",stdin);
  freopen("adobe.ans","w",stdout);

  int i, j, k;
  cin>>n>>m>>p;
  //�ӵ�Ϊ0��ֱ�����
  if (p == 0)
  {
    cout<<"0\n";
    return 0;
  }
  //a[i][j]��ʾ�����i��j��λ�õ�ש��ĵ÷�
  //b[i][j] = 1��ʾ�����i��j��λ�õ�ש����Խ���һ���ӵ�
  //�����ݵ�ʱ���з�ת�ˣ��������·�ת��
  for (i = n; i >= 1; i--)
    for(j=1; j<=m; j++)
    {
      cin>>a[i][j]>>ch;
      b[i][j]= ch == 'Y' ? 1:0;
    }
  //̰�Ĵ�����²��Y ,��Ϊ�������·�ת�ˣ����Դ�������ϲ��
  for(j=1; j<=m; j++) //j��
  {
    for(i=1; i<=n; i++) //i��
    {
      if (!b[i][j])
        break;
      ans += a[i][j];
    }
    //��Ϊ���·�ת�ˣ�whe[j]=i��ʾ��j�е�һ��N��λ��Ϊi
    //��ʵҲ����̰�Ĵ�����²��Y֮��ʣ�µ�N
    whe[j] = i;
  }
  //now[j][i]�����j������Ҫ���i��ש����Եõ��ķ�����ע�⣬�����i��ש������Y��Ҫ��YҲ�ӵ�now����
  //res[j][i]������Ǹ�ǰ׺�ͣ���ʾ��j������Ҫ���i��ש��ĵ÷�(�����now�������������iש��������YҲ���ӽ�ȥ)
  for(j=1; j<=m; j++)
    for(i=whe[j]; i<=n; i++)
      res[j][i] = res[j][i - 1] + a[i][j];
  for(j=1; j<=m; j++)
    for(i=whe[j]; i<=n; i++)
      now[j][i] = res[j][i];
  //ci[j][i]��ʾ��j������Ҫ���i��ש����Ҫ�����ӵ�
  //����now[j][i]��������ci[j][i]����
  for(j=1; j<=m; j++)
  {
    ci[j][whe[j]] = 1;//ÿ�еĵ�һ��N�϶�Ҫ���
    for(i=whe[j]; i<=n; i++)
    {
      int tmp = i;
      //b[i + 1][j]��Ӧ��ΪY
      //�ⲿ�������Ի���Сͼ
      while (b[i + 1][j])
        i++;
      now[j][tmp] = res[j][i];
      ci[j][i + 1] = ci[j][tmp] + 1;
    }
  }
  //��ʼֵ ǰj���ڲ����ӵ����������0���ӵ���
  for(j=0; j<=m; j++)
    dp[j][0][0] = -1e8;

  for(j=1; j<=m; j++)
    for(k=1; k<=p; k++)
    {
      dp[j][k][0] = max(dp[j][k][0], dp[j - 1][k][0]);
      dp[j][k][1] = max(dp[j][k][1], dp[j - 1][k][1]);
      for(i=whe[j]; i<=n; i++)
        if (!b[i][j] && k >= ci[j][i])//û�����ӵ�����û�����ӵ���
        {
          dp[j][k][0] = max(dp[j][k][0], max(dp[j - 1][k - ci[j][i]][1], dp[j - 1][k - ci[j][i]][0]) + res[j][i]);
          dp[j][k][0] = max(dp[j][k][0], dp[j - 1][k - ci[j][i]][0] + now[j][i]);
          dp[j][k][1] = max(dp[j][k][1], dp[j - 1][k - ci[j][i]][1] + now[j][i]);
        }
    }
  printf("%d\n", dp[m][p][0] + ans);//���������ǲ�Ƿ�ӵ��ģ�����Ƿ�ӵ������������
  return 0;
}

