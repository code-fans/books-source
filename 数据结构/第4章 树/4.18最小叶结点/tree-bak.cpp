#include<bits/stdc++.h>
using namespace std;
const int MAXN = 10200;

int inorder[MAXN],postorder[MAXN];
int n,minn,Leaf;

void DFS(int L1,int R1,int L2,int R2,int value)
{
  int root;
  for(root=L1; inorder[root] != postorder[R2]; ++root); //�Ҹ��ڵ�
  if(L1 < root)
    DFS(L1,root-1,L2,L2+root-1-L1,value + postorder[R2]);//�������ݹ�
  if(R1>root)
    DFS(root+1,R1,L2+root-L1,R2-1,value + postorder[R2]);//�������ݹ�
  if (L2== R2)   //�ݹ����ÿ���ж���С��
  {
    if(minn > postorder[L2] + value)
    {
      minn = postorder[L2] + value;
      Leaf = postorder[L2];
    }
    else if(minn == postorder[L2] + value && Leaf > L2)//����Ϊ��С���
      Leaf =postorder[L2];
  }
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  char ch;
  while(~scanf("%d",&inorder[0]))          //��ȡʧ�ܷ���-1��-1ȡ��Ϊ0
  {
    n=1;
    minn=0x3f3f3f3f;
    Leaf=-1;
    while(getchar()!='\n')
      scanf("%d",&inorder[n++]);
    for(int i=0; i<n; i++)
      scanf("%d",&postorder[i]);
    DFS(0,n-1,0,n-1,0);                    //�������ұ߽磬�������ұ߽磬Ҷ�ӵ�����ֵ
    printf("%d\n",Leaf);
  }
  return 0;
}

