//��N��������ĸ��� - ����1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans=0,n,sum=1;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    sum*=i;
    while(sum%10==0)      //��������0����ȥ��0������
    {
      sum/=10;
      ans++;
    }
    sum%=1000;            //������λ������
  }
  printf("%d\n",ans);
  return 0;
}

