//���� - ����1
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("embattle.in","r",stdin);
  //freopen("embattle.out","w",stdout);
  long long n,fn=0;
  scanf("%d",&n);
  if(n==1)
    fn=3;                          //��ʼ����n=1��n=2ʱ���ٽ�����
  else if(n==2)
    fn=7;
  else
  {
    long long fn_1=7;
    long long fn_2=3;
    for(int i=3; i<=n; i++)
    {
      fn=2*fn_1+fn_2;              //��n>=3ʱfn��ͨʽ
      fn_2=fn_1;                   //����fn_1��fn_2��ֵ
      fn_1=fn;
    }
  }
  printf("%lld\n",fn);
  return 0;
}

