//奶牛的命运
#include <bits/stdc++.h>
using namespace std;


int main()
{
  freopen("poorcow10.in","r",stdin);
  freopen("poorcow10.in","w",stdout);
  srand(time(0));
  int t=500,num=1000;
  //cin>>t>>num;
  cout<<t<<endl;//组
  for(int i=0; i<t; i++)
  {
    cout<<num<<endl;//牛数
    for(int j=0; j<num; j++)
    {
      int x=rand()%10+1;
      cout<<x<<" ";
      for(int k=0; k<x; k++)
      {
        int cyc=rand()%250+1;
        cout<<cyc<<' ';
      }
      cout<<endl;
    }
  }
  return 0;
}
