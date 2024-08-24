//������� ���ṹ���鷨ʵ��
#include <bits/stdc++.h>
using namespace std;
const int MAXN=32768;                  //2^15

int n;
struct tree
{
  int Left,Data,Right;
} tree[MAXN];

void Create(int *node,int len)
{
  for(int i=1; i<=len; i++)            //���������
  {
    tree[i].Data=node[i];              //Ԫ��ֵ������
    int pos=0,dir=0;
    while(dir==0)
    {
      if(node[i]<tree[pos].Data)       //�ж��Ƿ�Ϊ������
        if(tree[pos].Left!=-1)         //�����λ���ѱ�ռ��,����������
          pos=tree[pos].Left;
        else
          dir=1;                       //��Ϊ����
      else                             //�ж��Ƿ�Ϊ������
        if(tree[pos].Right!=-1)
          pos=tree[pos].Right;
        else
          dir=-1;                      //��Ϊ����
    }
    dir==1? tree[pos].Left=i:tree[pos].Right=i;
  }
}

void InOrder(int root)                //�������
{
  if(root!=-1)
  {
    InOrder(tree[root].Left);
    cout<<tree[root].Data<<' ';
    InOrder(tree[root].Right);
  }
}

int main()
{
  freopen("inorder.in","r",stdin);
  freopen("inorder.out","w",stdout);
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  for(int i=0; i<MAXN; i++)            //��ʼ��
  {
    tree[i].Left=-1;
    tree[i].Data=0;
    tree[i].Right=-1;
  }
  Create(node,n);
  InOrder(1);
  return 0;
}

