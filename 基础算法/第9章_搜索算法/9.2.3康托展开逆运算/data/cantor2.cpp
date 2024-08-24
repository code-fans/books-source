//康托展开逆运算
#include <bits/stdc++.h>
using namespace std;

int fac[10]= {1,1,2,6,24,120,720,5040,40320,362880};   //阶乘
int Hash[10];

int Cantor(int m,int n)
{
  int num=0;
  int used,digit;
  m--;
  for(int i=n-1; i>0; i--)
  {
    used=0;
    digit=m/fac[i]+1;                               //计算有几个数比它小后+1
    m%=fac[i];                                      //更新m
    for(int j=1; j<=used+digit; j++)                //查之前有几数已用过
      if(Hash[j])
        used++;
    num+=(used+digit)*pow(10,i);
    Hash[used+digit]=1;                             //标记该数被使用过
  }
  for(int i=1; i<=n; i++)                           //取出最后的未使用的数
    if(Hash[i]==0)
      return num+i;
}

int main()
{
  //freopen("cantor2.in","r",stdin);
  //freopen("cantor2.out","w",stdout);
  int num,n;
  cin>>num>>n;
  printf("%d\n",Cantor(n,num));
  return 0;
}

