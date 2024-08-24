//���̡�BFS��DFS,���仯����Ҳ�ǿ��Եģ�
#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;

struct node
{
  int x,y,color,magic,cost;                 //xy����,��ɫ,�ܷ���ħ��,����
} cur;
queue <node> q;
int Map[MAXN][MAXN],Cost[MAXN][MAXN];
int n,m;

void Bfs(int x,int y)
{
  int cost;
  if(!(x<1||x>m||y<1||y>m))                    //δԽ�������
    if(Map[x][y]!=0)                           //��ǰ���겻����ɫʱ
    {
      cost=(Map[x][y]==cur.color)?cur.cost:cur.cost+1;
      if(cost<Cost[x][y])
        Cost[x][y]=cost,q.push(node {x,y,Map[x][y],1,cost});
    }
    else if(cur.magic!=0)                     //��ǰ������ɫ��ħ������
    {
      cost=cur.cost+2;                        //ʹ��ħ��
      if(cost<Cost[x][y])
        Cost[x][y]=cost,q.push(node {x,y,cur.color,0,cost});
    }
}

int main()
{
  //freopen("chess.in","r",stdin);
  //freopen("chess.out","w",stdout);
  cin>>m>>n;
  memset(Cost,127,sizeof(Cost));              //��ʼ��Ϊ0x7f7f7f7f
  for(int i=0; i<n; i++)
  {
    int x,y,c;
    cin>>x>>y>>c;
    Map[x][y]=c+1;                            //0������ɫ��1�����ɫ��2�����ɫ
  }
  Cost[1][1]=0;
  q.push(node {1,1,Map[1][1],1,0});
  while(!q.empty())
  {
    cur=q.front(),q.pop();
    Bfs(cur.x-1,cur.y);
    Bfs(cur.x+1,cur.y);
    Bfs(cur.x,cur.y-1);
    Bfs(cur.x,cur.y+1);
  }
  Cost[m][m]<100000 ? printf("%d\n",Cost[m][m]):puts("-1");
  return 0;
}
