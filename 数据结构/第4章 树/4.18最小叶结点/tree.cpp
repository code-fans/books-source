//最小叶结点,直接递归求值不如分开更直观和易于调试
#include <bits/stdc++.h>
using namespace std;
const int MAXN=10010;

int in_order[MAXN], post_order[MAXN], lch[MAXN], rch[MAXN];
int n,best_ID, best_sum;

int BuildTree(int L1, int R1, int L2, int R2)//建树
{
  if(L1>R1)
    return -1;                                //空树
  int root=post_order[R2];                   //后序最后一个是树根
  int p = L1;
  for(; in_order[p]!=root; p++);             //找到根在中序的位置
  int cnt=p-L1;                              //左子树的结点个数
  lch[root]=BuildTree(L1, p-1, L2, L2+cnt-1);//左子树递归
  rch[root]=BuildTree(p+1, R1, L2+cnt, R2-1);//右子树递归
  return root;                               //返回树根
}

void DFS(int u, int sum)
{
  sum += u;                                  //加该结点的权值
  if(lch[u]==-1 && rch[u]==-1)                     //如果是叶子
  {
    if(sum<best_sum || (sum == best_sum && u<best_ID))
    {
      best_ID=u;
      best_sum=sum;
    }
  }
  if(lch[u]!=-1)
    DFS(lch[u], sum);
  if(rch[u]!=-1)
    DFS(rch[u], sum);
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  while(~scanf("%d",&in_order[0]))          //读取失败返回-1，-1取反为0
  {
    n=1;
    memset(lch,-1,sizeof(lch));             //-1表示没有子结点，不能用0表示
    memset(rch,-1,sizeof(rch));             //否则会误把非叶子结点认为是叶结点
    while(getchar()!='\n')
      scanf("%d",&in_order[n++]);
    for(int i=0; i<n; i++)
      scanf("%d",&post_order[i]);
    BuildTree(0, n-1, 0, n-1);
    best_sum=0x3f3f3f3f;
    DFS(post_order[n-1], 0);
    cout<<best_ID<<"\n";
  }
  return 0;
}
