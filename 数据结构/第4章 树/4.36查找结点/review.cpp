//���������ֲ��ҷ�
#include <bits/stdc++.h>
using namespace std;
const int INF=1<<30;

struct BST
{
  int val,lson,rson;
} Tree[100];
int tot,root,n,locate;

int New(int val)                         //�����½��
{
  Tree[++tot].val=val;
  return tot;
}

void Build()                             //����
{
  New(-INF);
  New(INF);
  root=1;
  Tree[1].rson=2;
}

void Insert(int &p,int val)               //������val
{
  if(p==0)
  {
    p=New(val);
    return;
  }
  if(val<Tree[p].val)
    Insert(Tree[p].lson,val);
  else
    Insert(Tree[p].rson,val);
}

int Search(int p,int val)                  //����Ԫ��val
{
  if(p==0)
    return -1;
  if(val==Tree[p].val)
    return Tree[p].val;
  return val<Tree[p].val ? Search(Tree[p].lson,val) : Search(Tree[p].rson,val);
}


int GetPre(int &root,int val,int &fa,int &firstfa)
{
  while(root)
  {
    if(Tree[root].val==val)
      return root;

    fa = root;
    if(Tree[root].val>val)
      root=Tree[root].lson;
    else
    {
      firstfa = root;//�����ҹյ�
      root=Tree[root].rson;
    }
  }
  return 0;
}

int GetNext(int val)                    //���Һ��
{
  int ans=2;                            //������INF�Ľ��
  int p=root;
  while(p)
  {
    if(val==Tree[p].val)                  //����val�ɹ�
    {
      if(Tree[p].rson>0)                     //�����������
      {
        p=Tree[p].rson;
        while(Tree[p].lson>0)                //һֱ����������
          p=Tree[p].lson;
        ans=p;
      }
      break;
    }
    if(Tree[p].val>val && Tree[p].val<Tree[ans].val)//���Ը��º��
      ans=p;
    p=val<Tree[p].val ? Tree[p].lson : Tree[p].rson;//��������
  }
  return ans;
}

void Delete(int val)                            //ɾ��val
{
  int &p=root;   //pΪ����
  while(p)
  {
    if(val==Tree[p].val)
      break;
    p=val<Tree[p].val ?Tree[p].lson:Tree[p].rson;//���²���
  }
  if(p==0)
    return;
  if(Tree[p].lson==0)//���û��������
    p=Tree[p].rson;//����������p��λ��
  else if(Tree[p].rson==0)//���û��������
    p=Tree[p].lson;//����������p��λ��
  else         //��/����������
  {
    int next=Tree[p].rson;//����
    while(Tree[next].lson>0)
      next=Tree[next].lson;
    Delete(Tree[next].val);//���û����������ֱ��ɾ��
    Tree[next].lson=Tree[p].lson;//next����p��λ��
    Tree[next].rson=Tree[p].rson;
    p=next;
  }
}

int main()
{
//  //freopen("review.in","r",stdin);
//  //freopen("review.out","w",stdout);
  Build();
  scanf("%d",&n);
  for(int i=0,x; i<n; i++)
  {
    scanf("%d",&x);
    Insert(root,x);
  }
  while(1)
  {
    scanf("%d",&locate);
    cout<<GetPre(root,locate,root,root)<<endl;
  }
  scanf("%d",&locate);
  printf("%d\n",Search(root,locate));
  return 0;
}

