//���������������
//��ÿ������˵,��ߵ���Ҫ���ұߵ�������С2,�����ſ���ƴ�ϳ�һ����
//���������������ӵ����,�ұߵ��������ӵ����,ƴ��������ֵ
//���ֱ������±�iԪ��Ϊ��ʼ��ͽ�����ĵ��������г��ȡ�
//�Ƚ��±�i-1��i+1λ�õ�Ԫ�ز�ֵ�Ƿ����2���������2��ƴ�ӳ��ȡ�
#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100005;
int f[MaxN], a[MaxN], g[MaxN], ans, n;

inline void ReadIn(int& x)
{
  static char ch;
  while (!isdigit(ch=getchar()));
  for (x=ch-48; isdigit(ch=getchar()); (x*=10)+=ch-48);
}

int main()
{
  freopen("sum.in","r",stdin);
  freopen("sum.out","w",stdout);
  ReadIn(n);
  for (int i=0; i<n; ReadIn(a[++i]));
  for (int i=1; i<=n; ++i)                //��������������
    f[i]=(a[i-1]<a[i]) ? f[i-1]+1 : 1;
  for (int i=n; i>=1; --i)                //�������½�����(���������������)
    g[i]=(a[i]<a[i+1]) ? g[i+1]+1 : 1;
  for (int i=1; i<=n; ++i)                //ƴ��֮������ֵ
    (a[i+1]>=a[i-1]+2) ? ans=max(ans,f[i-1]+g[i+1]+1) : 1;//���Ҳ�ֵΪ2
  printf("%d\n", ans);
  return 0;
}

