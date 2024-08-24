//神族文字 —普通二分+快排
#include <bits/stdc++.h>
using namespace std;

struct node
{
  string s1,s2;
} a[100010];
string s;
int n;

int Cmp(node a,node b)
{
  return a.s2<b.s2;
}

int Bsearch(string s,int l,int r)                       //二分
{
  while(l<=r)
  {
    int mid = (l+r)>>1;
    if(s==a[mid].s2)
      return mid;
    s<a[mid].s2?r = mid-1:l = mid+1;
  }
  return -1;
}

int main()
{
  //freopen("dictionary.in","r",stdin);
  //freopen("dictionary.out","w",stdout);
  while(getline(cin,s))
  {
    if(s.size()==0)
      break;
    a[n].s1=s.substr(0,s.find(" "));
    a[n++].s2=s.erase(0,s.find(" ")+1);
  }
  sort(a,a+n,Cmp);
  while(getline(cin,s))
  {
    int k=Bsearch(s,0,n-1);
    cout<<(k==-1?"eh":a[k].s1)<<endl;
  }
  return 0;
}

