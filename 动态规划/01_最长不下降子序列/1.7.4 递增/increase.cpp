//����
//ֱ��������������ǲ��Ե�,����2 3 4 4 4 5
//���������Ϊ2,3,4,5,ֻ��Ҫ�޸�2��,��ʵ��Ҫ�޸�3����
//�����ǽ�a[i]-i,������Ϊ2��2��2��1��0��0
//��ǵݼ�����,��Ϊa[i]<a[i+1]����a[i],a[i+1]����������
//������a[i+1]-1>=a[i]�������a[i+1]-(i+1)>=a[i]-i��(�����Ԫ��ֵ-�±�Ĳ�)
//����������i��λ������Ҫ��i+1��λ����1����i����Ҫ��i+2��λ����2��
//�����Ļ���ֱ�Ӵ���������е�λ�ù�ϵ
//��b[i]=a[i]-i����������b[i]������½������еĳ���len��
//�����n-len��Ϊ��Ҫ�ı�����ٵ�Ԫ�ظ�����
#include <bits/stdc++.h>
using namespace std;
const int N=1000005;

int T,n,m;
int a[N],b[N];
int cas=1;

int Solve(int n)
{
  int longest=1;
  b[0]=a[0];
  for(int i=1; i<n; i++)
    if(a[i]>=b[longest-1])
      b[longest++]=a[i];
    else
    {
      int pos=upper_bound(b,b+longest,a[i])-b;
      b[pos]=a[i];
    }
  return longest;
}

int main()
{
  freopen("increase.in","r",stdin);
  freopen("increase.out","w",stdout);
  for(scanf("%d",&T); T; T--)
  {
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
      scanf("%d",&a[i]);
      a[i]-=i;
    }
    printf("Case #%d:\n%d\n",cas++,n-Solve(n));
  }
  return 0;
}

