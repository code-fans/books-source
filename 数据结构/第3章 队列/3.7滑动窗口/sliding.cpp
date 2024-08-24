//滑动窗口
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000000+10;
int n,k,maxh,minh,maxt,mint;
int maxq[MAXN],minq[MAXN],num[MAXN];
int maxans[MAXN],minans[MAXN];

int main()
{
  //freopen("sliding.in","r",stdin);
  //freopen("sliding.out","w",stdout);
  scanf("%d%d",&n,&k);
  int maxhead=0,minhead=0,maxtail=0,mintail=0;
  for (int i=0; i<n; i++)
  {
    /*删除下标超出范围的队首元素*/
    if (maxhead<maxtail && maxq[maxhead]<=i-k) maxhead++;
    if (minhead<mintail && minq[minhead]<=i-k) minhead++;

    /*删除队尾元素*/
    scanf("%d",&num[i]);
    while (maxhead<maxtail && num[maxq[maxtail-1]]<=num[i]) maxtail--;
    maxtail++;
    maxq[maxtail-1]=i;
    while (minhead<mintail && num[minq[mintail-1]]>=num[i]) mintail--;
    mintail++;
    minq[mintail-1]=i;
    maxans[i]=num[maxq[maxhead]];
    minans[i]=num[minq[minhead]];
  }
  for (int i=k-1; i<n; i++) cout<<minans[i]<<' ';
  cout<<endl;
  for (int i=k-1; i<n; i++) cout<<maxans[i]<<' ';
  cout<<endl;
  return 0;
}
