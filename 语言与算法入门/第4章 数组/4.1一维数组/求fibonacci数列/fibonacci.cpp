//��������������Fibonacci��������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("fibonacci.in","r",stdin);
  //freopen("fibonacci.out","w",stdout);
  int f[20]= {1,1}; //a[0]=1,a[1]=1,���ࣱ����Ԫ���Զ���ֵΪ0
  for(int i=2; i<20; i++)
    f[i]=f[i-2]+f[i-1];//���ε���
  for(int i=0; i<20; i++)
    cout<<f[i]<<endl;
  return 0;
}
