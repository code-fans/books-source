//��������������
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;

unsigned long long Pow(unsigned long long X,unsigned long long n)
{
  if(n==1)
    return X;
  else if(n==0)
    return 1;
  else
  {
    unsigned long long c=Pow(X,n/2);//�ݹ����X^(n/2)
    return n%2?c*c*X:c*c;//(X^(n/2))^2��ΪX^n����nΪ�������ٳ�X
  }
}

int main()
{
  freopen("power.in","r",stdin);
  freopen("power.out","w",stdout);
  int X,n;
  cin>>X>>n;
  cout<<Pow(X,n)<<endl;
  return 0;
}
