//�Ϲ�����
//��һ�������ŵ�һ�����꣬Ȼ�����ö�پ���󲻶ϳ��Է����������Ƿ�����Ҫ��
#include<bits/stdc++.h>
using namespace std;

int U[1000005];
int n,p;

bool Check(int x)
{
  int num=0;
  int l=U[1];             //l��¼��һ������λ�ã���һ�������ȷ��ڵ�һ������
  for(int i=2; i<=n; i++) //����ö��ÿ������
  {
    if(U[i]-l<x)
      num++;              //���˾��벻���㵱ǰ�𰸣��ѵ�ǰ�����ŵ���һ������
    else
      l=U[i];             //����͸�����һ�ε�����λ��
    if(num>n-p)           //����Ҫ�����������������������������
      return false;       //�˴𰸲�����
  }
  return true;            //��֮���𰸿���
}

int main()
{
  freopen("danger.in","r",stdin);
  freopen("danger.out","w",stdout);
  scanf("%d%d",&n,&p);
  for(int i=1; i<=n; i++)
    scanf("%d",&U[i]);
  sort(U+1,U+n+1);
  int l=1;
  int r=U[n]-U[1];
  while(l+1<r)
  {
    int mid=(l+r)>>1;
    Check(mid)?l=mid:r=mid;
  }
  printf("%d\n",Check(r)?r:l);
  return 0;
}
