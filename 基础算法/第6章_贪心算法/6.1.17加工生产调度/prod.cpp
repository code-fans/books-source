//�ӹ���������
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int a,b,ID;                //IDΪԭʼ���
} k[1005],q1[2005],q2[2005];

bool Cmp1(node x,node y)
{
  return (x.a==y.a ? x.ID<y.ID:x.a<y.a);
}

bool Cmp2(node x,node y)
{
  return (x.b==y.b ? x.ID<y.ID:x.b>y.b);
}

int main()
{
  freopen("prod.in","r",stdin);
  freopen("prod.out","w",stdout);
  int n,k1=0,k2=0,sum=0;
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>k[i].a;
  for(int i=0; i<n; i++)
  {
    cin>>k[i].b;
    k[i].ID=i+1;
    if(k[i].a<=k[i].b)
      q1[k1++]=k[i];
    else
      q2[k2++]=k[i];
  }
  sort(q1,q1+k1,Cmp1);
  sort(q2,q2+k2,Cmp2);
  for(int i = k1; i<k1+k2; ++i)        //�ϲ����Ӽ�
    q1[i] = q2[i-k1];
  int sum1[1001] = {0};
  for(int i=0; i<n; ++i)               //����M1���ѵ�ʱ��
    sum1[i+1] = sum1[i]+q1[i].a;
  for(int i=0; i<=n; ++i)              //����M2���ѵ�ʱ��
    if(sum<sum1[i+1])                  //Ҫ�ȵ�M1��ɲ��ܿ�ʼM2
      sum = sum1[i+1]+q1[i].b;
    else
      sum+=q1[i].b;
  printf("%d\n",sum);
  for(int i=0; i<n; i++)
    cout<<q1[i].ID<<(i==n-1?"\n":" ");
  return 0;
}
