//康托展开
#include<bits/stdc++.h>
using namespace std;

int a[50];

long long Cantor(int s[],int n)            //康托展开
{
  bool used[50] = {0};
  long long ans = 0;
  for(int i = n; i >= 1; i--)
  {
    int NoUse = 0;
    used[s[n - i]] = true;
    for(int j = 0; j < s[n - i]; j++)      //查找是否有用过的数
      if(used[j])
        NoUse++;
    ans= (ans + s[n - i] - NoUse) * i;        //康托展开式计算
  }
  return ans+1;
}

int main()
{
  freopen("cantor.in","r",stdin);
  freopen("cantor.out","w",stdout);
  int N;
  cin>>N;
  for (int i=1; i<=N; i++)
    cin>>a[i];
  cout<<Cantor(a,N)<<endl;
  return 0;
}

