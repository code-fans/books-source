//������Ϸ - ��Ϲ�ʽ��
#include <bits/stdc++.h>
using namespace std;

int m, n,Sum;

int C(int m, int n)                //����C(m,i),��ʽΪC(m,n)=m!/(n!(m-n)!)
{
  if (n == 0)                      //���ֻȡһ����������Ϊ1
    return 1;
  int Ans = 1;
  /*
  for (int i=m; i>=m-n+1;i--)//��5ȡ3������ݳ˷�ԭ���ȼ���5*4*3��ֵ
    Ans = Ans * i;
  for (int i=n; i>=2;i--)//��ȥ��ͬ���У���123,132,321,312,213,231��һ��
    Ans = Ans / i;
  */
  int p1 = 2;
  for(int p2=m; p2>=m-n+1; p2--)   //m!��ȥ(m-n)!����ѭ����m-n+1
  {
    Ans *= p2;
    if (Ans % p1 == 0 && p1<=n)    //��������n!
      Ans/=p1++;
  }
  return Ans;
}

int main()
{
  freopen("ball.in","r",stdin);
  freopen("ball.out","w",stdout);
  scanf("%d%d",&n,&m);
  for (int i = 0; i <= m; i++)
  {
    int j = m - i;
    if (abs(j - i) % n == 0)       //������ܴ�����ʼ��
      Sum+=C(m, i);
  }
  printf("%d\n",Sum);
  return 0;
}

