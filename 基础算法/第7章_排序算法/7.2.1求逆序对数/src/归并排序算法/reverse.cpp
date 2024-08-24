// 统计逆序对
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int n,ans;
int a[MAXN],temp[MAXN];

void MergeSort(int i,int j)      //归并排序求逆序对
{
  if(i>=j)
    return;
  int mid=(i+j)>>1;
  MergeSort(i,mid);
  MergeSort(mid+1,j);
  int l=i,r=mid+1;               //l为左边序列的指针，r为右边序列的指针
  for(int k=i; k<=j; k++)
  {
    if(l>mid)                    //如果左边序列的数已全部取完
      temp[k]=a[r++];            //加右边序列的数字
    else if(r>j)                 //如果右边序列的数已全部取完
      temp[k]=a[l++];            //加左边序列的数字
    else if(a[l]<=a[r])          //如果左数不大于右数
      temp[k]=a[l++];            //加左数
    else                         //如果右数小于左数
    {
      temp[k]=a[r++];            //加右数
      ans+=mid-l+1;              //统计逆序对数
    }
  }
  for(int k=i; k<=j; k++)
    a[k]=temp[k];                //复制数组temp到a
}

int main()
{
  freopen("reverse.in","r",stdin);
  freopen("reverse.out","w",stdout);
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&a[i]);
  MergeSort(0,n-1);
  printf("%d\n",ans);
  return 0;
}

