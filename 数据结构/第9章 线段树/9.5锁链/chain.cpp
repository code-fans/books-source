//����
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int left,right,color;                 //color������������ɫ
  int lazy;                             //����Ƿ����
  int mid()
  {
    return (left+right)>>1;
  }
} E[100005<<2];                         //��С��Ϊ4��

void BuildTree(int root,int l,int r)
{
  E[root].left=l;
  E[root].right=r;
  E[root].color=1;
  E[root].lazy=0;                       //��ʼΪδ���
  if(l!=r)
  {
    int mid=E[root].mid();
    BuildTree(root<<1,l,mid);
    BuildTree(root<<1|1,mid+1,r);
  }
}

void Update(int pos,int l,int r,int c)  //lazy˼�룬�ӳٸ���
{
  if(E[pos].left==l && E[pos].right==r) //ǡ��Ϊ�ö�
  {
    E[pos].color=c;
    if(l^r)                            //Ҷ�ӽ�㲻�ܱ��lazy
      E[pos].lazy=1;                   //�������
  }
  else
  {
    if(E[pos].lazy==1)                  //����������
    {
      E[pos<<1].lazy=E[pos<<1|1].lazy=1;//���ӽ��Ҳ�����
      E[pos<<1].color=E[pos<<1|1].color=E[pos].color;//����Ϊ�������ɫ
      E[pos].lazy=0;                    //�������
    }
    int mid=E[pos].mid();
    if(r<=mid)
      Update(pos<<1,l,r,c);             //��������
    else if(l>mid)
      Update(pos<<1|1,l,r,c);           //�����ҽ��
    else
    {
      Update(pos<<1,l,mid,c);
      Update(pos<<1|1,mid+1,r,c);
    }
    E[pos].color=E[pos<<1].color|E[pos<<1|1].color;//λ������
  }
}

int Query(int pos,int l,int r)
{
  if((E[pos].left==l && E[pos].right==r) || E[pos].lazy==1)
    return E[pos].color;
  else
  {
    int mid=E[pos].mid();
    if(r<=mid)
      return Query(pos<<1,l,r);         //�ݹ�����
    else if(l>mid)
      return Query(pos<<1|1,l,r);       //�ݹ��ҽ��
    else
      return Query(pos<<1,l,mid)|Query(pos<<1|1,mid+1,r);//���εĺϲ�
  }
}

int Code(int x)                         //��xת��Ϊ��������
{
  return 1<<(x-1);                      //����x=7,����64,��������1000000
}

int Ucode(int x,int t=0)                //��������Ƶ�x���ж��ٸ�1
{
  for (; x; x>>=1)
    t+= x&1;                            //�����ǰλΪ1
  return t;
}

int main()
{
  int L,m,t,st,en,a,b,c;
  char opt;
  while(~scanf("%d%d%d",&L,&t,&m))
  {
    BuildTree(1,1,L);
    for(int i=0; i<m; i++)
    {
      scanf(" %c",&opt);
      if(opt=='C')
      {
        scanf("%d%d%d",&a,&b,&c);
        c=Code(c);                      //����ɫתΪ������
        a<b?Update(1,a,b,c):Update(1,b,a,c);
      }
      if(opt=='P')
      {
        scanf("%d%d",&st,&en);
        printf("%d\n",st<en?Ucode(Query(1,st,en)):Ucode(Query(1,en,st)));
      }
    }
  }
  return 0;
}

