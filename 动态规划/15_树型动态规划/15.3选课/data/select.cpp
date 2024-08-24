//ѡ��
#include <bits/stdc++.h>
using namespace std;

struct tree
{
  int l,r,v;
} node[301];
int f[301][301];

int DFS(int x,int y)
{
  if(y==0 || x<0)                              //�޿ο�ѡ����ݹ鵽0�ڵ�֮��
    return 0;
  if(x==0)
    return DFS(node[x].l,y);                  //���ڵ���û���ֵܵ�
  if(f[x][y]>=0)                              //���仯����
    return f[x][y];
  f[x][y]=DFS(node[x].r,y);                   //��ѡ��i�ſ�
  for(int i=1; i<=y; i++)                     //ѡ��i�ſΣ�ö����η�������
    f[x][y]=max(f[x][y],DFS(node[x].l,i-1)+node[x].v+DFS(node[x].r,y-i));
  return f[x][y];
}

int main()
{
  //freopen("select.in","r",stdin);
  //freopen("select.out","w",stdout);
  int M,N,a,b;
  scanf("%d %d\n",&N,&M);
  memset(node,-1,sizeof(node));
  memset(f,-1,sizeof(f));
  for(int i=1; i<=N; i++)
  {
    scanf("%d %d\n",&a,&b);
    node[i].r=node[a].l;                      //�����ת������
    node[a].l=i;
    node[i].v=b;
  }
  printf("%d\n",DFS(0,M));                   //��0�ڵ㿪ʼ����M�ſο�ѡ
  return 0;
}
