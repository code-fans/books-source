//��N��������ĸ��� - ����2��N/5��ѭ��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int ans=0,n;
  scanf("%d",&n);
  for(int j=5; j<=n; j+=5)          //��5��ʼ������Ϊ5
    for(int i=j; i%5==0; ans++)     //i�ܱ�5��������˵��������5
      i/=5;
  printf("%d\n",ans);
  return 0;
}

