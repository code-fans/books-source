//��kС��1
#include <bits/stdc++.h>
using namespace std;

struct st
{
  int val,ID;                           //ID����ԭʼλ��
} a[100001];
int m,k;

void Swap(int &i,int &j)               //����i,j
{
  swap(a[i].val,a[j].val);             //��Ԫ�ػ���
  swap(a[i].ID,a[j].ID);
  swap(i,j);                           //ָ�뻥��
}

int Find(int START,int END)
{
  int i=START;
  int j=END;
  while(i!=j)                          //��ָ��δ�غ�ʱ
  {
    if(i<j)                            //��iָ����jָ����
      if(a[i].val>a[j].val)
        Swap(i,j);
      else
        --j;                           //jָ������
    else                               //��iָ����jָ���ң�ָ���ѻ�����
      if(a[i].val<a[j].val)
        Swap(i,j);
      else
        ++j;                           //jָ������
  }
  if(i==k)                             //�����ҵ���kС��
    return a[i].ID;                    //����𰸼�ԭλ��
  else if(i<k)                         //��ʱi��j���غ�
    Find(i+1,END);                     //ȡ�ұ�����ݹ����
  else
    Find(START,i-1);                   //ȡ�������ݹ����
}

int main()
{
  //freopen("k1.in","r",stdin);
  //freopen("k1.out","w",stdout);
  scanf("%d%d",&m,&k);
  for(int i=1; i<=m; i++)
  {
    scanf("%d",&a[i].val);
    a[i].ID=i;
  }
  cout<<Find(1,m)<<endl;               //��1~m֮�俪ʼ���ֲ���
  return 0;
}

