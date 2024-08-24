//kruskal�㷨
#include <bits/stdc++.h>
using namespace std;
const int MAXN=2000;

int n,e;                          //�����ͱ���
int x[MAXN],y[MAXN],w[MAXN];      //xΪ�ߵ���㣬yΪ�յ㣬wΪ�ߵ�Ȩֵ
int dad[MAXN];                    //ÿ��������ڵĸ��׼���

void QuickSort(int i,int j)            //�Ա�Ȩ����,����STL���sort
{
  if(i>=j)
    return;
  int m=i,n=j;
  int k=w[(i+j)>>1];
  while(m<=n)
  {
    while(w[m]<k) m++;
    while(w[n]>k) n--;
    if(m<=n)
    {
      swap(x[m],x[n]);
      swap(y[m],y[n]);
      swap(w[m],w[n]);
      m++;
      n--;
    }
  }
  QuickSort(i,n);
  QuickSort(m,j);
}

int Getfather(int x)                //���ҵ�x���ڵļ���
{
  return dad[x]==x?x:dad[x]=Getfather(dad[x]);
}

void Kruskal()                      //Kruskal�㷨
{
  for(int i=1; i<=n; i++)
    dad[i]=i;                      //��ʼ����ļ���
  int count=1,ans=0;               //countΪ����Ķ�����,��Ϊ1
  for(int i=1; i<=e; i++)
    if(Getfather(x[i])!=Getfather(y[i]))//��ߵ����㲻��ͬһ���ϣ���鲢
    {
      ans+=w[i];                                  //���������߲�ͳ����Ȩֵ
      dad[Getfather(x[i])]=y[i];     //�ϲ�Ϊͬһ���׼���,�˴���ȡy[i]��ֵ
      count++;
      if(count==n)
      {
        cout<<ans<<"\n";
        return;
      }
    }
}

int main()
{
  //freopen("Line.in","r",stdin);
  //freopen("Line.out","w",stdout);
  cin>>n>>e;                          //���������ͱ���
  for(int i=1; i<=e; i++)
    cin>>x[i]>>y[i]>>w[i];
  QuickSort(1,e);                    //���߰�Ȩֵ��С����
  Kruskal();
  return 0;
}

