//≥…º®¥¶¿Ì
#include <bits/stdc++.h>
using namespace std;

float Max=0,Min=0,ave,score[]= {0};

float fun(float array[],int n)
{
  float average,sum=array[0];
  Max=Min=array[0];
  for(int i=1; i<n; i++)
  {
    if(array[i]>Max)
      Max=array[i];
    else if(array[i]<Min)
      Min=array[i];
    sum=sum+array[i];

  }
  average=sum/n;
  return average;
}

int main()
{
  //freopen("score.in","r",stdin);
  //freopen("score.out","w",stdout);
  int q;
  cin>>q;
  for(int i=0; i<=q; i++)
    cin>>score[i];
  ave=fun(score,q);
  cout<<Max<<" "<<Min<<" ";
  cout<<setprecision(2)<<fixed<<ave<<endl;
  return 0;
}
