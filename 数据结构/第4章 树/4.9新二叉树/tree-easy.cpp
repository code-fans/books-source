//ÐÂ¶þ²æÊ÷
#include<bits/stdc++.h>
using namespace std;

int n,root;

struct tree
{
  int left,right;
} tree[30];

void  Fun(int node)
{
  cout<<(char)node;
  if(tree[node].left)
    Fun(tree[node].left);
  if(tree[node].right)
    Fun(tree[node].right);
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  cin>>n;
  char X,L,R;
  for(int i=1; i<=n; i++)
  {
    cin>>X>>L>>R;
    if(L!='*')
      tree[(int)X].left=(int)L;
    if(R!='*')
      tree[(int)X].right=(int)R;
    if(i==1)
      root=(int)X;
  }
  Fun(root);
  cout<<endl;
  return 0;
}
