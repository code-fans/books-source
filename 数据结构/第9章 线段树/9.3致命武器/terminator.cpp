//��������
#include <bits/stdc++.h>
using namespace std;
#define lson l,m,pos<<1               //pos<<1�൱��pos*2 
#define rson m+1,r,pos<<1|1           //pos<<1|1�൱��pos*2+1 
#define N 100001

int st[N<<2];                         //st[]��¼������ǣ�0,1,2,3;����0������ɫ

void BuildTree(int l,int r,int pos,int Metal)
{
  st[pos]=Metal;
  if(l!=r)
  {
    int m=(l+r)>>1;                   //���ֵݹ������ӽ��
    BuildTree(lson,Metal);
    BuildTree(rson,Metal);
  }
}

void Updata(int L,int R,int l,int r,int pos,int Metal)//����L~R,��1~n,st[1]��ʼ
{
  if(L<=l && R>=r)                    //������²���ǡ�ñ�����
    st[pos]=Metal;                    //������һ�ζ�����Ϊ����ɫ
  else
  {
    if(st[pos])                       //����ý��Ϊ��ɫ,���޸Ĳ�������
    {
      st[pos<<1]=st[pos<<1|1]=st[pos];//������Ӻ��Ҷ��Ӿ���Ϊ����ɫ
      st[pos]=0;                      //st[pos]��Ϊ��ɫ
    }
    int m=(l+r)>>1;
    if(L<=m)
      Updata(L,R,lson,Metal);         //�ݹ���������
    if(R>m)
      Updata(L,R,rson,Metal);         //�ݹ�����Ҷ���
  }
}

int Query(int l,int r,int pos)
{
  if(st[pos])                         //st[pos]Ϊ��ɫʱ
    return st[pos]*(r-l+1);           //ֱ�ӷ��سɶ���˵Ľ��
  int m=(l+r)>>1;
  return Query(lson)+Query(rson);
}

int main()
{
  //freopen("terminator.in","r",stdin);
  //freopen("terminator.out","w",stdout);
  int T,L,R,n,q,Metal,Case=0;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d%d",&n,&q);
    BuildTree(1,n,1,1);
    while(q--)
    {
      scanf("%d%d%d",&L,&R,&Metal);
      Updata(L,R,1,n,1,Metal);
    }
    printf("Case %d: The total value of the hook is %d.\n",++Case,Query(1,n,1));
  }
  return 0;
}

