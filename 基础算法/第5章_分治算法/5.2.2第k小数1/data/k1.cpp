//��kС�� - ������
#include <bits/stdc++.h>
using namespace std;

struct st
{
  int val,ID;
} a[100001];
int i,j,m,k;

int CMP(st a, st b)                  //�Խṹ������ıȽϺ���
{
  return a.val<b.val;
}

void Swap(int i,int j)               //������ָ�뽻��
{
  swap(a[i].val,a[j].val);
  swap(a[i].ID,a[j].ID);
}

int Find(int START,int END)
{
  i=START;
  j=END;
  while(i!=j)
  {
    if(i<j)
      if(a[i].val>a[j].val)
        Swap(i,j),  swap(i,j);       //�˴�ָ�뽻��
      else
        --j;
    else if(a[i].val<a[j].val)
      Swap(i,j),  swap(i,j);
    else
      ++j;
  }
  if(i==k)
    return a[i].ID;
  else if(i<k)
    Find(i+1,END);
  else
    Find(START,i-1);
}

int main()
{
  //freopen("k1.in","r",stdin);
  //freopen("k1.out","w",stdout);
  scanf("%d%d",&m,&k);
  for(i=1; i<=m; i++)
  {
    scanf("%d",&a[i].val);
    a[i].ID=i;
  }
  for(i=6; i<=m+1; i+=5)             //ÿ���Ԫ�ؽ�����������
    sort(a+i-5,a+i,CMP);
  for(i=1; i<=m/5; i++)              //��ÿ�����λ������������ǰ��
    Swap(i,i*5-2);
  sort(a+1,a+i,CMP);                 //���ŵ�ǰ���������λ������
  Swap(1,i/2);                       //����λ���е���λ����Ϊ��׼
  cout<<Find(1,m)<<endl;
  return 0;
}

