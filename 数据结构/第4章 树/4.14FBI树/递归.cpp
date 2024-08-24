#include<bits/stdc++.h>
using namespace std;

int n;
char s[1001];

void Build(int l,int r)
{
  int mid = (l+r)>>1;
  if(l!=r)
  {
    Build(l,mid);            //递归前半部分
    Build(mid+1,r);          //递归后半部分
  }
  int a=0,b=0;
  for (int i = l; i<=r; i++) //统计0，1出现的个数
    s[i]=='0'? a++:b++;
  if(a && b)
    cout<<"F";               //有1也有0,F树
  else if(a)
    cout<<"B";               //只有0,B树
  else
    cout<<"I";               //只有1,I树
}

int main()
{
  freopen("fbi.in","r",stdin);
  freopen("fbi.out","w",stdout);
  cin>>n>>s;
  Build(0,pow(2,n)-1);
  cout<<endl;
  return 0;
}
