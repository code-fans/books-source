//������������ - ̰���㷨
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("stock.in","r",stdin);
  freopen("stock.out","w",stdout);
  int n;
  double money=1,v[2];                       //��������
  scanf("%d %lf",&n,&v[0]);
  for(int i=1; i<n; i++)                     //ע���һ������������
  {
    scanf("%lf",&v[i&1]);
    if(v[i&1]>v[i-1&1])
      money*=v[i&1]/v[i-1&1];
  }
  printf("%.4lf\n",money);
  return 0;
}

