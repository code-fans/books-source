//n�Ľ׳�
#include <bits/stdc++.h>
//typedefΪunsigned long long��������ΪULL
typedef unsigned long long ULL;
using namespace std;

ULL Factorial(int n)                //�˴���ULL��Ϊunsigned long long
{
  if(n<0)
    exit(0);                        //�˳�����
  else if(n==0 || n==1)
    return 1;
  else
    return Factorial(n-1)*n;
}

main()
{
  //freopen("factorial.in","r",stdin);
  //freopen("factorial.out","w",stdout);
  int n;
  scanf("%d",&n);
  printf("%d!=%llu\n",n,Factorial(n));//ע��unsigned long long�������ʽ
  return 0;
}

