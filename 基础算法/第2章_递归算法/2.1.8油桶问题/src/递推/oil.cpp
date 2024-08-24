//油桶问题－递推
#include <bits/stdc++.h>
using namespace std;

int a[100+1];//存放各油桶容积
bool b[60000+1]= {1};

int main()
{
  //freopen("oil.in","r",stdin);
  //freopen("oil.out","w",stdout);
  int m,n;
  cin>>n>>m;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  int MAX=0;
  for(int i=1; i<=n; i++)
  {
    for(int j=MAX; j>=0; j--)
      if(b[j])
      {
        b[j+a[i]]=1;
        if(j+a[i]==m)
        {
          puts("yes");
          return 0;
        }
      }
    MAX+=a[i];
  }
  cout<<(b[m]?"yes":"no")<<endl;
  return 0;
}
