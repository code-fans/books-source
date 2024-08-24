#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=5050;
struct node
{
  int v;
  int next;
} Edg[MAXN<<1];                   //����ͼ
int Stack[MAXN],top;
int dfn[MAXN],low[MAXN],index;//index���ڼ�¼������
bool vis[MAXN];
int st[MAXN],cnt;
int color[MAXN],s[MAXN],num;  //Ⱦɫ����¼��ɫ����

void build(int a,int b)
{
  Edg[++cnt].v=b;
  Edg[cnt].next=st[a];
  st[a]=cnt;
}//��ͼ

void tarjan(int x)
{
  dfn[x]=++index;
  low[x]=index;
  vis[x]=true;
  Stack[++top]=x;//��ǰ����ջ
  int i;
  for(i=st[x]; i!=0; i=Edg[i].next) //ö���Ե�ǰ��Ϊ���ı�
  {
    int t=Edg[i].v;//��ǰ��ö�ٱߵ��յ�
    if(!dfn[t])//�����ǰ���յ�δ������
    {
      tarjan(t);
      low[x]=min(low[x],low[t]);
    }
    else if(vis[t])low[x]=min(low[x],dfn[t]);
  }
  if(dfn[x]==low[x])
  {
    vis[x]=false;
    color[x]=++num;//����ǰǿ��ͨ����Ⱦ������ɫ
    s[num]++;//����ǰǿ��ͨ������ĵ�Ⱦɫ
    while(Stack[top]!=x)//ջ��Ԫ�����γ�ջ
    {
      s[num]++;
      color[Stack[top]]=num;
      vis[Stack[top--]]=false;
    }
    top--;
  }
}

int main()
{
  freopen("teacher.in","r",stdin);
  freopen("teacher.out","w",stdout);
  int n,m,t,f;
  scanf("%d%d",&n,&m);
  int a,b;
  for(int i=1; i<=m; i++)
  {
    scanf("%d%d%d",&a,&b,&t);
    build(a,b);
    if(t-1)build(b,a);
  }
  for(int i=1; i<=n; i++)
    if(!dfn[i])
      tarjan(i);
  int ans=0;
  for(int i=1; i<=n; i++)
    if(s[color[i]]>ans)
    {
      ans=s[color[i]];
      f=i;
    }
  printf("%d\n",ans);
  for(int i=1; i<=n; i++)
    if(color[i]==color[f])
      printf("%d ",i);
  return 0;
}

