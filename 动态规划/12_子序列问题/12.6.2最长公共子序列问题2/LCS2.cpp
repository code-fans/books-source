//������Ӵ�2
//3 2 1 4 5 ���ǰ������ 1 2 3 4 5 �൱����ɢ����:3-1��2-2��1-3��4-4��5-5��
//�ڶ���1 2 3 4 5 ��������ɢ���ı�ʾ��3 2 1 4 5
//����ͱ������һ������½�����
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;

int n,len;
int t[MAXN],a[MAXN],b[MAXN],lis[MAXN];

inline int Read(int &x)                  //���ַ�����ʽ�������ֿ�����
{
  char c=getchar();
  for(; c<'0'  || c>'9';  c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    x=(x<<3)+(x<<1)+c-'0';               //λ�����Ż���x*8+x*2=x*10
}

int main()
{
//  freopen("LCS2.in","r",stdin);
//  freopen("LCS2.out","w",stdout);
  Read(n);
  for (int i=1; i<=n; i++)
  {
    Read(a[i]);
    t[a[i]]=i;
  }
  for (int i=1; i<=n; i++)
  {
    Read(b[i]);
    b[i]=t[b[i]];
  }
  for (int i=1; i<=n; i++)               //������������м���
  {
    int pos=lower_bound(lis+1, lis+len+1, b[i])-lis;
    lis[pos]=b[i];
    len=max(len,pos);
  }
  cout<<len<<'\n';
  getchar();
  return 0;
}
