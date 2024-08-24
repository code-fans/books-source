//最大矩形面积
#include<bits/stdc++.h>
using namespace std;

long long a[500001],n,Stack[500001],l,r;

int main()
{
  //freopen("rectangle.in","r",stdin);
  //freopen("rectangle.out","w",stdout);
  while(cin>>n && n)
  {
    for(int i=1; i<=n; i++)
      cin>>a[i];
    a[n+1]=-1;
    int top=0,ans=0;
    memset(Stack,0,sizeof(Stack));
    for(long long i=1; i<=n+1; i++)
    {
      for(; top!=0 && a[Stack[top]]>=a[i]; top--)  //宽度为L-R+1
      {
        long long tmp=((i-1)-Stack[top-1])*a[Stack[top]];//右边界是i-1，因为i是右边第一个比它小的数
        if(tmp>ans)                                      //左边界是top,因为堆栈里它的左边是第一个比它小的数
          ans=tmp;
      }
      Stack[++top]=i;
    }
    cout<<ans<<endl;
  }
  return 0;
}

