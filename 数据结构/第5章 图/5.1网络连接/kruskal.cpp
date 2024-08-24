//kruskal�㷨
#include <bits/stdc++.h>
using namespace std;
#define MAXN 2000

int n,e;                          //�����ͱ���
int x[MAXN],y[MAXN],w[MAXN];      //xΪ�ߵ���㣬yΪ�յ㣬wΪ�ߵ�Ȩֵ
int dad[MAXN];                    //ÿ��������ڵĸ��׼���

void Sort(int i,int j)            //���ţ�����Ȩ����
{
  if(i>=j)
    return ;
  int m=i,n=j;
  int k=w[(i+j)>>1];           //ȡ��ֵ
  while(m<=n)
  {
    while(w[m]<k)
      m++;
    while(w[n]>k)
      n--;
    if(m<=n)
    {
      swap(x[m],x[n]);
      swap(y[m],y[n]);
      swap(w[m],w[n]);
      m++;
      n--;
    }
  }
  Sort(i,n);
  Sort(m,j);
}

int Getfather(int x)                //���ҵ�x���ڵļ���
{
  return dad[x]==x?x:dad[x]=Getfather(dad[x]);
}

void Kruskal()
{
  for(int i=1; i<=n; i++)
    dad[i]=i;                      //��ʼ����ļ���
  int p=1,ans=0;//pΪ��������Ϊ�ӿ��ٶ�p����ʼ��Ϊ1�����Ե�p=nʱ��������
  for(int i=1; i<=e; i++)
    if(getfather(x[i])!=getfather(y[i]))  //��ߵ����㲻��ͬһ���ϣ���鲢
    {
      ans+=w[i];                                  //���������߲�ͳ����Ȩֵ
      dad[getfather(x[i])]=y[i];     //�ϲ�Ϊͬһ���׼���,�˴���ȡy[i]��ֵ
      p++;
      if(p == n)               //�����С�������еĶ���������ȫ�������� - 1
      {
        cout<<ans<<"\n";
        return ;
      }
    }
}

int main()
{
  freopen("Line.in","r",stdin);
  freopen("Line.out","w",stdout);
  cin>>n>>e;                          //���������ͱ���
  for(int i=1; i<=e; i++)
    cin>>x[i]>>y[i]>>w[i];
  Sort(1,e);                          //���߰�Ȩֵ��С����
  Kruskal();
  return 0;
}

