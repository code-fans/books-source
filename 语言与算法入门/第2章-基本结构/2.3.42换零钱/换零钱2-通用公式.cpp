//����Ǯ2-ͨ�ù�ʽ
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,a,b,c,sum;
  cin>>n;
  a=n/10;
  c=n%10;
  if(c<=5)//���ʣ�µ�Ǯ����һ��5Ԫ��һ��1Ԫ
    a--;
  b=(n-10)/5;
  c=(n-10)%5;
  if(c<1)
    b--;
  sum=a*(b-a+1);
  cout<<sum<<endl;
  return 0;
}
