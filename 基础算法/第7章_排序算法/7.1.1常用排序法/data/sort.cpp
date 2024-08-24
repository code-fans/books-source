//πÈ≤¢≈≈–Ú
#include <bits/stdc++.h>
using namespace std;
int a[100000];
int b[100000];

void Mergesort(int L,int R)
{
  if(L>=R)
    return;
  int mid=(L+R)/2;
  Mergesort(L,mid);
  Mergesort(mid+1,R);
  for(int i=L; i<=R; i++)
    b[i]=a[i];
  int i=L,j=mid+1;
  for(int k=L; k<=R; k++)
    if(i<=mid &&((j>R)||b[i]<b[j]))
      a[k]=b[i++];
    else
      a[k]=b[j++];
}

int main()
{
  freopen("sort.in","r",stdin);
  freopen("sort.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; ++i)
    scanf("%d",&a[i]);
  Mergesort(0,n-1);
  for(int i=0; i<n; ++i)
    printf("%d ",a[i]);
  return 0;
}

