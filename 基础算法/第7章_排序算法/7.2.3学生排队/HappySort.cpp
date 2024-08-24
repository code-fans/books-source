//学生排队
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

typedef struct
{
  int h;
  int angry;//该元素要交换的次数
} stu;
stu a[MAXN],temp[MAXN];

void Work(stu a[],stu temp[],int L,int Mid,int R)  //归并
{
  int i=L,j=Mid+1,t=L;
  while(i!=Mid+1 && j!=R+1)
    if(a[i].h>a[j].h)
    {
      a[j].angry+=Mid+1-i;//记录j前面比a[j].h大的个数
      temp[t++]=a[j++];
    }
    else
    {
      a[i].angry+=j-Mid-1;//记录i后面比a[i].h小的个数
      temp[t++]=a[i++];
    }
  while(i!=Mid+1)
  {
    a[i].angry+=R-Mid;//左边剩下的都是右边全部数的逆序对 
    temp[t++]=a[i++];
  }
  while(j!=R+1)
    temp[t++]=a[j++];
  for(i=L; i<=R; i++)
    a[i]=temp[i];
}

void MergeSort(stu a[],stu b[],int L,int R)
{
  if(L==R)
    return;
  int mid=(L+R)/2;
  MergeSort(a,b,L,mid);
  MergeSort(a,b,mid+1,R);
  Work(a,b,L,mid,R);
}

int main()
{
  freopen("HappySort.in","r",stdin);
  freopen("HappySort.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
    scanf("%d",&a[i].h);
  MergeSort(a,temp,0,n-1);
  long long  sum=0;
  for(int i=0; i<n; i++)
    sum+=(long long)(a[i].angry+1)*a[i].angry/2;
  printf("%lld\n",sum);
  return 0;
}
