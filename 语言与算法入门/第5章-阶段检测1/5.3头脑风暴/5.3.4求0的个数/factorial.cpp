//��N��������ĸ��� - ����3����log5(N)��ѭ��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans=0,n;
  scanf("%d",&n);
  for(int i=n; i>=5; ans+=i)
    i/=5;
  printf("%d\n",ans);
  return 0;
}

