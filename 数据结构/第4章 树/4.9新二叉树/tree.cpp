//ÐÂ¶þ²æÊ÷
#include<bits/stdc++.h>
using namespace std;

int n;
char a[30][3];

void Fun(char x)     //µÝ¹é
{
  if(x!='*')
  {
    cout<<x;
    for(int i=1; i<=n; i++)
      if(a[i][0]==x)
      {
        Fun(a[i][1]);
        Fun(a[i][2]);
      }
  }
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i][0]>>a[i][1]>>a[i][2];
  Fun(a[1][0]);
  return 0;
}
