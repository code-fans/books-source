// ͳ�������
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1001

int n,ans;
int a[MAXN],temp[MAXN];

void MergeSort(int i,int j)      //�鲢�����������
{
  if(i>=j)
    return;
  int mid=(i+j)>>1;
  MergeSort(i,mid);
  MergeSort(mid+1,j);
  int l=i,r=mid+1;               //lΪ������е�ָ�룬rΪ�ұ����е�ָ��
  for(int k=i; k<=j; k++)
  {
    if(l>mid)                    //���������е�����ȫ��ȡ��
      temp[k]=a[r++];            //���ұ����е�����
    else if(r>j)                 //����ұ����е�����ȫ��ȡ��
      temp[k]=a[l++];            //��������е�����
    else if(a[l]<=a[r])          //�����������������
      temp[k]=a[l++];            //������
    else                         //�������С������
    {
      temp[k]=a[r++];            //������
      ans+=mid-l+1;              //ͳ���������
    }
  }
  for(int k=i; k<=j; k++)
    a[k]=temp[k];                //��������temp��a
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

