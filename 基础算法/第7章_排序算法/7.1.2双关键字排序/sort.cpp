//Ë«¹Ø¼ü×ÖÅÅÐò
#include <bits/stdc++.h>
using namespace std;

int a[100001],b[100001];

void QuickSort(int L,int R)
{
  int i=L,j=R;
  int temp=rand()%(R-L+1)+L;
  int mid1=a[temp];
  int mid2=b[temp];
  while(i<=j)
  {
    while(a[i]<mid1 || a[i]==mid1 && b[i]<mid2)  i++;
    while(a[j]>mid1 || a[j]==mid1 && b[j]>mid2)  j--;
    if(i<=j)
    {
      swap(a[i],a[j]);
      swap(b[i++],b[j--]);
    }
  }
  if(i<R)  QuickSort(i,R);
  if(j>L)  QuickSort(L,j);
}

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d%d",&a[i],&b[i]);
  srand(time(0));
  QuickSort(0,n-1);
  for(int i=0; i<n; i++)
    printf("%d %d\n",a[i],b[i]);
  return 0;
}

