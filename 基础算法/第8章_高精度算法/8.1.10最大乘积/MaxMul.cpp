//最大乘积
//乘积最大就应尽可能将n更多的拆分，1肯定不行，从2开始
//即2，3，4，5，6...如果超过n,减去多余的数即可，再高精乘
#include<bits/stdc++.h>
using namespace std;

int len=1,sum,num,n;
int a[10001],ans[10001]= {0,1};//高精度数组初始为1

void Mul(int x)
{
  for(int i=1; i<=len; i++)
    ans[i]=ans[i]*x;
  for(int i=1; i<=len; i++)
    if(ans[i]>=10)
    {
      ans[i+1]+=ans[i]/10;
      ans[i]=ans[i]%10;
      len=max(i+1,len);
    }
}

int main()
{
  freopen("MaxMul.in","r",stdin);
  freopen("MaxMul.out","w",stdout);
  cin>>n;
  for(int i=2; n>a[num]; i++)
  {
    a[++num]=i;
    n-=i;
  }
  if(n==a[num])           //如果剩下的数和最后一个数组元素值相等
    a[num]++;             //最后一个数组元素值+1
  for(int i=0; i<n; i++)  //剩下的数逆序给每个数组元素+1
    a[num-i]++;
  for(int i=1; i<=num; i++)
    if(a[i])
    {
      cout<<a[i]<<(i==num?'\n':' ');
      Mul(a[i]);
    }
  for(int i=len; i>=1; i--)
    cout<<ans[i];
  cout<<endl;
  return 0;
}
