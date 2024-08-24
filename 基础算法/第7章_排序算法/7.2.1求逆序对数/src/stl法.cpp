#include<bits/stdc++.h>
using namespace std;

int n,ans,a[100001];
vector<int>v;

int main()
{
  freopen("reverse.in","r",stdin);
  freopen("reverse.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&a[i]);
    int now=upper_bound(v.begin(),v.end(),a[i])-v.begin();
    ans+=i-now-1;                     //累加逆序对数
    v.insert(v.begin()+now,a[i]);     //将a[i]插到合适位置
  }
  printf("%d\n",ans);
  return 0;
}
