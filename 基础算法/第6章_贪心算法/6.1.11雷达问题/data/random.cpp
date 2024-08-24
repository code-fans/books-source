//雷达问题
#include <bits/stdc++.h>
using namespace std;
struct node
{
  int xx,yy;
  bool operator<(const node& a) const
  {
    if(this->xx < a.yy)
      return true;   //自定义排序规则
    return false;
  }
};

int main()
{
  //freopen("radar.in","r",stdin);
  freopen("radar.in","w",stdout);
  srand(time(0));
  int T,n,d;
  cin>>T>>n;
  for(int i=1; i<=T; i++)
  {
    set <node> s;
    int d=rand()%10000+1;
    cout<<n<<" "<<d<<endl;
    while(s.size()!=n)
    {
      int x=pow(-1,rand()%2)*(rand()%10000)+1;
      int y=pow(-1,rand()%2)*(rand()%4000)+1;
      node no;
      no.xx=x;
      no.yy=y;
      s.insert(no);
    }
    for(set<node>::iterator i=s.begin(); i!=s.end(); i++)
      cout<<(*i).xx<<" "<<(*i).yy<<endl;
    cout<<"\n";
  }
  cout<<'0'<<" "<<'0'<<endl;
  return 0;
}

