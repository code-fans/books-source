//�����˰�����
#include <bits/stdc++.h>
using namespace std;

const int N = 55;
const int dx[] = {0,0,-1,1};//face=0(��),1(��),2(��),3(��)ʱ�ķ���ֵ,���Һ�����
const int dy[] = {-1,1,0,0};
const int turnLeft[] =  {3,2,0,1};//face=0,1,2,3ʱ����ת��Ϊ3,2,0,1
const int turnRight[] = {2,3,1,0};

struct node
{
  int x,y,face,step;//λ�� ��Եķ��򣬲���
} st,en,now,nx; //��� �յ� ��ǰ�� ��һ��
bool Map[N][N],vis[N][N][4];//�Թ���ͼ,״̬�������(λ�ú�4����Եķ���)
int n,m,ans=-1;

void BFS()
{
  queue<node> q;
  vis[st.x][st.y][st.face] = 1;
  q.push(st);
  while(!q.empty())
  {
    now = q.front(),q.pop();
    if(now.x==en.x&&now.y==en.y)//�ߵ��յ�
    {
      ans = now.step;
      return;
    }
    nx=now;//׼��ֱ��
    for(int i = 1; i <= 3; i++) //���ŵ�ǰ������i��
    {
      nx.x += dx[now.face],nx.y += dy[now.face];
      if(nx.x<1||nx.y<1||nx.x>=n||nx.y>=m||Map[nx.x][nx.y])//�߽紦������(0~n�� 0~m��)...
        break;
      if(vis[nx.x][nx.y][nx.face]) continue;//��״̬��չ����
      vis[nx.x][nx.y][nx.face] = 1;
      nx.step = now.step + 1;//��һ��
      q.push(nx);
    }
    nx=now, nx.step = now.step + 1;//׼��ת������
    nx.face = turnLeft[now.face];//��ת
    if(!vis[nx.x][nx.y][nx.face])
    {
      vis[nx.x][nx.y][nx.face] = 1;
      q.push(nx);
    }
    nx.face = turnRight[now.face];//��ת
    if(!vis[nx.x][nx.y][nx.face])
    {
      vis[nx.x][nx.y][nx.face] = 1;
      q.push(nx);
    }
  }
}

int main()
{
  //freopen("robot.in","r",stdin);
  //freopen("robot.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i = 1,a; i <= n; i++)//������ӵ�ֵ
    for(int j = 1; j <= m; j++)
    {
      scanf("%d",&a);
      if(a) //��Ϊ�ϰ�(i,j��Ϊ�������½�����)�����ϰ����ĸ����������
        Map[i][j]=Map[i-1][j-1]=Map[i-1][j]=Map[i][j-1] = 1;
    }
  scanf("%d%d%d%d %c",&st.x,&st.y,&en.x,&en.y,&st.face);
  st.face = (st.face=='W'?0:(st.face=='E'?1:(st.face=='N'?2:3)));
  st.step =0;
  BFS();
  printf("%d\n",ans==-1?-1:ans);
  return 0;
}
