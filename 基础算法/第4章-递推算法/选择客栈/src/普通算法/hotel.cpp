//ѡ���ջ - �����㷨
#include <bits/stdc++.h>
using namespace std;

const int N = 200010;
int n, k, price, Ans, c[N], v[N];

int main()
{
  freopen("hotel.in","r",stdin);
  freopen("hotel.out","w",stdout);
  scanf("%d %d %d", &n, &k, &price);
  for(int i=1; i<=n; i++)
    scanf("%d %d", c+i, v+i);                //��������Ԫ��c[i]
  for(int i=1; i<n; i++)
  {
    int m = v[i];
    for(int j=i+1; j<=n; j++)
    {
      if(m > v[j])                           //�ҳ���������ֵ��С�ķ���
        m = v[j];
      Ans += (c[i] == c[j] && m <= price);   //�������������1
    }
  }
  printf("%d\n", Ans);
  return 0;
}

