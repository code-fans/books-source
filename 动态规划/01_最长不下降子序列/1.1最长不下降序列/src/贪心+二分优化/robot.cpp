//����½����� - �����Ż��㷨
#include <bits/stdc++.h>
using namespace std;

int a[100001];
int Link[100001];              //Linux����һ��link�ĺ�������Ҫͬ��
int Long[100001];

int Find(int key,int Max)      //���ֲ���
{
  int L=1,R=Max,mid;
  while(L<=R)
  {
    mid=(L+R)>>1;
    if(a[Long[mid]]<key)
      L=mid+1;
    else R=mid-1;
  }
  return L-1;
}

int main()
{
  freopen("robot.in","r",stdin);
  freopen("robot.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  int Max=1;                   //��ʼ������Ϊ1
  Long[Max]=1;                 //��ʼΪ��һ��Ԫ��
  Link[1]=1;                   //��ʼ��Ϊ��һ��Ԫ��
  for(int t=2; t<=n; ++t)
    if(a[t]>=a[Long[Max]])     //���ڼȶ�����֮��
    {
      Long[++Max]=t;
      Link[t]=Long[Max-1];
    }
    else                       //�ڼȶ������в���λ�ò�����
    {
      int j=Find(a[t],Max);
      Long[j+1]=t;
      Link[t]=Long[j];
    }
  printf("%d\n",Max);
  /*  �˶ο��������ĸ�Ԫ��
  int k=Max;
  int i=Long[Max];
  while(Max>0)
  {
    Long[Max]=a[i];            //��Ϊ Long[Max]=i ��������
    i=Link[i];
    Max--;
  }
  for(i=1; i<=k; i++)
    cout<<Long[i]<<' ';
  */
  return 0;
}

