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
    ans+=i-now-1;                     //�ۼ��������
    v.insert(v.begin()+now,a[i]);     //��a[i]�嵽����λ��
  }
  printf("%d\n",ans);
  return 0;
}
