//f[i]����ѡ���i��Ա�����ܻ�õ����ֵ��
//�� f[i] = max(f[i],f[j]+sum[i]-sum[j+1]);
//���Է���sum[i]�ǲ���ģ�ֻҪ��f[j]-sum[j+1]�����ֵ�Ϳ�����
//����Ϳ����õ����������Ż�
#include<bits/stdc++.h>
using namespace std;
const int N = 100000;

long long f[N],sum[N],ans;
int a[N],n,m,k,q[N];

int main()
{
  //freopen("grass.in","r",stdin);
  //freopen("grass.out","w",stdout);
  scanf("%d%d",&n,&k);
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d",&a[i]);
    sum[i] = sum[i-1] + a[i];
  }
  int l=0, r=0;               //���е���߽���ұ߽� 
  for (int i = 1; i <= n; ++i)
  {
    if (q[l] < i-k-1)         //ά�������� 
      l++;
    if (i<=k)                 //��ǰ�˵ı�Ż�����k 
      f[i]=sum[i];
    else
      f[i]=max(f[i],f[q[l]]-sum[q[l]+1]+sum[i]);
    while(l<=r && (f[i]-sum[i+1]>=f[q[r]]-sum[q[r]+1]))
      r--;                    //ά�������� 
    q[++r]=i;
    ans=max(ans,f[i]);
  }
  printf("%lld\n",ans);
  return 0;
}
