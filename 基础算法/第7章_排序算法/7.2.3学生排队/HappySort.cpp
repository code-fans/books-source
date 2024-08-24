//ѧ���Ŷ�
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100010

typedef struct
{
  int h;
  int angry;//��Ԫ��Ҫ�����Ĵ���
} stu;
stu a[MAXN],temp[MAXN];

void Work(stu a[],stu temp[],int L,int Mid,int R)  //�鲢
{
  int i=L,j=Mid+1,t=L;
  while(i!=Mid+1 && j!=R+1)
    if(a[i].h>a[j].h)
    {
      a[j].angry+=Mid+1-i;//��¼jǰ���a[j].h��ĸ���
      temp[t++]=a[j++];
    }
    else
    {
      a[i].angry+=j-Mid-1;//��¼i�����a[i].hС�ĸ���
      temp[t++]=a[i++];
    }
  while(i!=Mid+1)
  {
    a[i].angry+=R-Mid;//���ʣ�µĶ����ұ�ȫ����������� 
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
