//��������
#include <bits/stdc++.h>
using namespace std;
const int N=10001;
int f[N],a[N];

int main()
{
  //freopen("missile.in","r",stdin);
  //freopen("missile.out","w",stdout);
  int n=1,ans1=0,ans2=0;
  for(; scanf("%d",&a[n])!=EOF; n++);
  for(int i=1; i<n; i++)                 //��һ�ʣ�����LIS
  {
    f[i]=1;
    for(int j=1; j<=i; j++)
      if(a[i]<a[j] && f[i]<f[j]+1)
        f[i]=f[j]+1;
    ans1=max(f[i],ans1);
  }
  memset(f,0,sizeof(f));                 //�����Ԫ�س�ʼ��Ϊ0
  for(int i=1; i<=n; i++)                //�ڶ���,LIS
  {
    f[i]=1;
    for(int j=1; j<=i; j++)
      if(a[i]>a[j] && f[i]<f[j]+1)
        f[i]=f[j]+1;
    ans2=max(f[i],ans2);
  }
  printf("%d %d\n",ans1,ans2);
  return 0;
}

