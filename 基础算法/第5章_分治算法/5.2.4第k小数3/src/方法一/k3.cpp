//��kС��3 - ����1
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;                   //��long long �ı���ΪLL

LL A[100005], B[100005];

LL Cal(LL m,LL n,LL Mid)                //����Midֵ���������е�������
{
  LL Cnt = 0;
  for (int i=0,j=n-1; i<m; ++i)
  {
    while (j>=0 && A[i]+B[j]>Mid)       //��λB��������ӱ�MidС��λ��
      --j;
    Cnt += (j+1);                       //�ۼ�
  }
  return Cnt;
}

LL FindKth(LL m,LL n,LL k)
{
  LL Min = A[0] + B[0];
  LL Max = A[m-1] + B[n-1];
  while (Min <= Max)                    //����
  {
    LL Mid = (Max + Min) >> 1;
    if (k <= Cal (m, n, Mid))
      Max = Mid - 1;
    else
      Min = Mid + 1;
  }
  return Min;
}

int main()
{
  freopen("k3.in","r",stdin);
  freopen("k3.out","w",stdout);
  LL m,n,k;
  while(scanf ("%lld%lld%lld", &m, &n, &k) != EOF)
  {
    for (int i=0; i<m; ++i)
      scanf ("%lld", &A[i]);
    for (int i=0; i<n; ++i)
      scanf ("%lld", &B[i]);
    printf ("%lld\n", FindKth (m, n, k));
  }
  return 0;
}

