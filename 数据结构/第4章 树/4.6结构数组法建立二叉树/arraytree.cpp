//�������ṹ�����ʾ��
#include <bits/stdc++.h>
using namespace std;
#define MAXN 32768                      //2^15
int n;
struct tree
{
  int Left;
  int Date;
  int Right;
} b_tree[MAXN];

void create(int *node,int len)
{
  int level;
  int position;                        //����-1,����1
  for(int i=1; i<=len; i++)            //���ν����������
  {
    b_tree[i].Date=node[i];            //Ԫ��ֵ������
    level=0;                           //����Ϊ0
    position=0;
    while(position==0)
    {
      if(node[i]>b_tree[level].Date)   //�ж��Ƿ�Ϊ������
        if(b_tree[level].Right!=-1)    //�����λ���ѱ�ռ��,����������
          level=b_tree[level].Right;
        else
          position=-1;                 //��Ϊ����
      else                             //�ж��Ƿ�Ϊ������
        if(b_tree[level].Left!=-1)
          level=b_tree[level].Left;
        else
          position=1;                  //��Ϊ����
    }
    if(position==1)
      b_tree[level].Left=i;            //����������
    else
      b_tree[level].Right=i;           //����������
  }
}

void print()
{
  for(int i=1; i<=n; i++)
    cout<<b_tree[i].Left<<' '<<b_tree[i].Date<<' '<<b_tree[i].Right<<'\n';
}

int main()
{
  freopen("arraytree.in","r",stdin);
  freopen("arraytree.out","w",stdout);
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  for(int i=0; i<MAXN; i++)            //��ʼ��
  {
    b_tree[i].Left=-1;
    b_tree[i].Date=0;
    b_tree[i].Right=-1;
  }
  create(node,n);
  print();
  return 0;
}

