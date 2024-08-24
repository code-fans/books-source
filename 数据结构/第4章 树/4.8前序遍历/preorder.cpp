//ǰ����� ���ṹ���鷨ʵ��
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
    int index=0,dir=0;
    while(dir==0)
    {
      if(node[i]<tree[index].Data)       //�ж��Ƿ�Ϊ������
        if(tree[index].Left!=-1)         //�����λ���ѱ�ռ��,����������
          index=tree[index].Left;
        else
          dir=1;                       //��Ϊ����
      else                             //�ж��Ƿ�Ϊ������
        if(tree[index].Right!=-1)
          index=tree[index].Right;
        else
          dir=-1;                      //��Ϊ����
    }
    dir==1? tree[index].Left=i:tree[index].Right=i;
  }
}

void PreOrder(int root)                //ǰ�����
{
  if(root!=-1)
  {
    cout<<tree[root].Data<<' ';
    PreOrder(tree[root].Left);
    PreOrder(tree[root].Right);
  }
}

int main()
{
  //freopen("preorder.in","r",stdin);
  //freopen("preorder.out","w",stdout);
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
  PreOrder(1);
  cout<<endl;
  return 0;
}

