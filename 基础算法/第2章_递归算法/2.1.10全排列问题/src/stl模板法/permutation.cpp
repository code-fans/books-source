//全排列问题－ＳＴＬ模板
#include<bits/stdc++.h>
using namespace std;

int n,total=0;
int a[20]= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};

void Print()
{
  for(int i=0; i<n; i++)
    cout<<a[i];
  cout<<"\n";
  total++;
}

int main()
{
  freopen("permutation.in","r",stdin);
  freopen("permutation.out","w",stdout);
  cin>>n;
  Print();
  while(next_permutation(a,a+n))//产生下一个排列
    Print();
  cout<<total<<'\n';
  return 0;
}
