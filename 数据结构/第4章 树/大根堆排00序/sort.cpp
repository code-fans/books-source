//���������sort.cpp��
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100000
int a[MAXN],n,heapsize;

void Maxheapify(int i)                //��������
{
  int largest;
  int l=i<<1;                         //����ý��������±�
  int r=(i<<1)+1;                     //����ý����Һ����±�
  if(l<=heapsize && a[i]<a[l])        //��¼���Ԫ�ص��±�
    largest=l;
  else
    largest=i;
  if(r<=heapsize && a[r]>a[largest])
    largest=r;
  if(largest != i)
  {
    swap(a[i],a[largest]);            //�������Ԫ����i��ֵ
    Maxheapify(largest);              //�ݹ��齻����Ľ���Ƿ�������������
  }
}

void BuildMaxHeap()                   //����
{
  heapsize=n;
  for(int i=n/2; i>=1; i--)
    Maxheapify(i);
}

void Heapsort()
{
  BuildMaxHeap();                    //��������
  for(int i=n; i>=2; i--)
  {
    swap(a[1],a[i]);                 //��a[i]��a[1]����
    --heapsize;                      //�޳��������Ԫ��a[i]
    Maxheapify(1);                   //ά����������
  }
}

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  Heapsort();
  for(int i=1; i<=n; i++)
    cout<<a[i]<<" ";
  return 0;
}

