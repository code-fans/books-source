//�Ŷ� - ö�ٷ�
#include <bits/stdc++.h>
using namespace std;
int a[30001],n,num;

int main()
{
  //freopen("queue.in","r",stdin);
  //freopen("queue.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&num);
    a[i]=a[i-1]+num-1;                    //a[i]��ʾ�ӵ�1����i���Ϊ2�Ĺ˿���
  }
  int minx=n;
  for(int i=0; i<=n; i++)                 //���i��λ��
    if(minx>a[i]+n-i-(a[n]-a[i]))         //ǰi���˿�ȫ��Ϊ1,��i+1~n��ȫ��Ϊ2
      minx=a[i]+n-i-(a[n]-a[i]);
  printf("%d\n",minx);
  return 0;
}

