//��СҶ���,ֱ�ӵݹ���ֵ����ֿ���ֱ�ۺ����ڵ���
#include <bits/stdc++.h>
using namespace std;
const int MAXN=10010;

int in_order[MAXN], post_order[MAXN], lch[MAXN], rch[MAXN];
int n,best_ID, best_sum;

int BuildTree(int L1, int R1, int L2, int R2)//����
{
  if(L1>R1)
    return -1;                                //����
  int root=post_order[R2];                   //�������һ��������
  int p = L1;
  for(; in_order[p]!=root; p++);             //�ҵ����������λ��
  int cnt=p-L1;                              //�������Ľ�����
  lch[root]=BuildTree(L1, p-1, L2, L2+cnt-1);//�������ݹ�
  rch[root]=BuildTree(p+1, R1, L2+cnt, R2-1);//�������ݹ�
  return root;                               //��������
}

void DFS(int u, int sum)
{
  sum += u;                                  //�Ӹý���Ȩֵ
  if(lch[u]==-1 && rch[u]==-1)                     //�����Ҷ��
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
  while(~scanf("%d",&in_order[0]))          //��ȡʧ�ܷ���-1��-1ȡ��Ϊ0
  {
    n=1;
    memset(lch,-1,sizeof(lch));             //-1��ʾû���ӽ�㣬������0��ʾ
    memset(rch,-1,sizeof(rch));             //�������ѷ�Ҷ�ӽ����Ϊ��Ҷ���
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
