//�������
#include<bits/stdc++.h>
using namespace std;

struct node
{
  int l,r;
} a[1001000]; //��¼ÿ���ڵ�����ҽڵ�
int Max=-1,n;

void DFS(int root,int step)
{
  if(root==0)
    return;//����ýڵ�Ϊ0������
  Max=max(Max,step);//��¼���ֵ
  DFS(a[root].l,step+1);//�������������
  DFS(a[root].r,step+1);//���������Ҷ���
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);

  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i].l>>a[i].r; //����ýڵ����ڵ���ҽڵ�
  DFS(1,1);              //��1�Žڵ㣬���Ϊ1��ʼ����
  cout<<Max<<endl;
  return 0;
}
