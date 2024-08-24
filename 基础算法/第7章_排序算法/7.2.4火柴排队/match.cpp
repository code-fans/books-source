//»ð²ñÅÅ¶Ó
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int h,ord;
} A[100010],B[100010];
int a[100010],temp[100010],ans,n;

int Cmp(node x,node y)
{
  return x.h<y.h;
}

void MergeSort(int l,int r)
{
  if(l>=r)
    return;
  int mid=(l+r)>>1;
  MergeSort(l,mid);
  MergeSort(mid+1,r);
  int i=l,j=mid+1,k=l;
  while(i<=mid && j<=r)
    if(a[i]>a[j])
    {
      temp[k++]=a[j++];
      ans=(ans+mid-i+1)%99999997;
    }
    else
      temp[k++]=a[i++];
  while(i<=mid)
    temp[k++]=a[i++];
  while(j<=r)
    temp[k++]=a[j++];
  for(int i=l; i<=r; i++)
    a[i]=temp[i];
}

int main()
{
  freopen("match.in","r",stdin);
  freopen("match.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&A[i].h);
    A[i].ord=i;
  }
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&B[i].h);
    B[i].ord=i;
  }
  sort(A+1,A+n+1,Cmp);
  sort(B+1,B+n+1,Cmp);
  for(int i=1; i<=n; i++)
    a[A[i].ord]=B[i].ord;
  MergeSort(1,n);
  printf("%d\n",ans);
  return 0;
}
