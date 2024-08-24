#include<bits/stdc++.h>
using namespace std;

static const int MAXN=999*999;
int a[MAXN+10],temp[MAXN+10];
int cnt;

void MergeSort(int l,int r)
{
  if(l>=r)
    return;
  int mid=(l+r)>>1;
  MergeSort(l,mid);
  MergeSort(mid+1,r);
  int i=l,j=mid+1;
  for(int k=l; k<=r; k++)
    if(j>r || i<=mid && a[i]<=a[j])
      temp[k]=a[i++];
    else
    {
      temp[k]=a[j++];
      cnt+=mid-i+1;
    }
  for(int k=l; k<=r; k++)
    a[k]=temp[k];
}

int main()
{
  //freopen("mnPuzzle.in","r",stdin);
  //freopen("mnPuzzle.out","w",stdout);
  int n,m,zero,s;
  while(cin>>n>>m && !(n==0 && m==0))
  {
    int k = 0;
    cnt=0;
    for(int i = 0; i < m; ++i)
      for(int j = 0; j < n; ++j)
      {
        scanf("%d",&s);
        if(s == 0)
          zero = m - i - 1;//0移到最下一行的距离 
        else
          a[k++] = s;
      }
    MergeSort(0,n*m-2);
    if(n & 1)
      zero = 0;
    printf(zero % 2 == cnt % 2? "YES\n" : "NO\n");
  }
  return 0;
}

