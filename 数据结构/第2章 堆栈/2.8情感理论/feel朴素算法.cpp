//���ض��ĳ���
#include <bits/stdc++.h>
#define LL long long
#define MAXN 100010
using namespace std;
LL n, num[MAXN], a[MAXN], b[MAXN], sum[MAXN];

int main()
{
  //freopen("feel.in","r",stdin);
  //freopen("feel.out","w",stdout);
  cin>>n;
  sum[0] = 0;
  for (int i = 1; i <= n; ++i)//��ǰ���к�
  {
    cin>>num[i];
    sum[i] = sum[i - 1] + num[i];
  }
  num[0] = num[n + 1] = -INT_MAX;//�������˾���ʼ��
  a[0] = -1;
  for (int i = 1; i <= n; ++i)//��ʼ����������˾���ʼΪ����
    a[i] = i;
  for (int i = 1; i <= n; ++i)//��a[i]��ֵ
    while (num[a[i] - 1] >= num[i])
      a[i] = a[a[i] - 1];
  b[n + 1] = -1;
  for (int i = 1; i <= n; ++i)//��ʼ���������Ҷ˾���ʼΪ����
    b[i] = i;
  for (int i = n; i >= 1; --i)//��b[i]��ֵ
    while (num[b[i] + 1] >= num[i])
      b[i] = b[b[i] + 1];
  LL max_res = 0;
  for (int i = 1; i <= n; ++i)
    max_res = max(max_res, (sum[b[i]] - sum[a[i] - 1]) * num[i]);
  cout<<max_res<<endl;
  for (int i = 1; i <= n; ++i)
    if ((sum[b[i]] - sum[a[i] - 1]) * num[i] == max_res)
    {
      cout<<a[i]<<" "<<b[i]<<endl;
      break;
    }
  return 0;
}

