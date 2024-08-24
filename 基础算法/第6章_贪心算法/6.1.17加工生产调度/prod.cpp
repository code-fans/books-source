//加工生产调度
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int a,b,ID;                //ID为原始编号
} k[1005],q1[2005],q2[2005];

bool Cmp1(node x,node y)
{
  return (x.a==y.a ? x.ID<y.ID:x.a<y.a);
}

bool Cmp2(node x,node y)
{
  return (x.b==y.b ? x.ID<y.ID:x.b>y.b);
}

int main()
{
  freopen("prod.in","r",stdin);
  freopen("prod.out","w",stdout);
  int n,k1=0,k2=0,sum=0;
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>k[i].a;
  for(int i=0; i<n; i++)
  {
    cin>>k[i].b;
    k[i].ID=i+1;
    if(k[i].a<=k[i].b)
      q1[k1++]=k[i];
    else
      q2[k2++]=k[i];
  }
  sort(q1,q1+k1,Cmp1);
  sort(q2,q2+k2,Cmp2);
  for(int i = k1; i<k1+k2; ++i)        //合并两子集
    q1[i] = q2[i-k1];
  int sum1[1001] = {0};
  for(int i=0; i<n; ++i)               //计算M1花费的时间
    sum1[i+1] = sum1[i]+q1[i].a;
  for(int i=0; i<=n; ++i)              //计算M2花费的时间
    if(sum<sum1[i+1])                  //要等到M1完成才能开始M2
      sum = sum1[i+1]+q1[i].b;
    else
      sum+=q1[i].b;
  printf("%d\n",sum);
  for(int i=0; i<n; i++)
    cout<<q1[i].ID<<(i==n-1?"\n":" ");
  return 0;
}
