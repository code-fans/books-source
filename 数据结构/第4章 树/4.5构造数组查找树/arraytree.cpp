// 构造数组查找树
#include <bits/stdc++.h>
using namespace std;
const int MAXN=32768;                    //2^15

int tree[MAXN];                          //数组下标从1开始

int Create(int *node,int len)
{
  int MAX=1,index;
  tree[1]=node[1];
  for(int i=2; i<=len; i++)
  {
    index=1;
    while(tree[index]!=0)                //判断当前位置是否有值
    {
      if(node[i]<tree[index])
        index=index*2;
      else
        index=index*2+1;
      MAX=max(MAX,index);                //判断最后一个元素占数组的下标
    }
    tree[index]=node[i];
  }
  return MAX;
}

int main()
{
  //freopen("arraytree.in","r",stdin);
  //freopen("arraytree.out","w",stdout);
  int n;
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  int num=Create(node,n);
  for(int i=1; i<=num; i++)
    cout<<tree[i]<<(i!=num?' ':'\n');
  return 0;
}

