//��ҩ���Ƕ�ҩ
//�ö�����������ʾ״̬��״̬ѹ������1��������0����������
//��ÿһ��ҩ���˵�Ӱ��ֱ�����������¼������
//�����β���������0�����β���1������Ӱ�죬�����뵱ǰ״̬��һ�� and���㣬�ͰѲ��κ�����
//���ڻ�����������1��������0������Ӱ�죬�����뵱ǰ״̬��һ�»� | ���㣬�ͰѲ���������
//��bfs������չ��ֱ���˵�״̬Ϊһ��0�Ϳ�������
#include <bits/stdc++.h>
using namespace std;

int n,m;
bool f[(1<<10)+10];
int ill[101],cure[101];

struct H
{
  int illnes,step;
} l,k;

int Bfs()
{
  int s=(1<<n)-1;
  queue <H> q;
  k.illnes=s;
  k.step=0;
  q.push(k);
  f[s]=1;
  while(!q.empty())
  {
    k=q.front();
    q.pop();
    if(k.illnes==0)
      return k.step;
    for(int i=1; i<=m; i++)
    {
      int x;
      x=(k.illnes&cure[i])|ill[i];
      if(!f[x])
      {
        if(x==0)
          return k.step+1;
        l.illnes=x;
        l.step=k.step+1;
        q.push(l);
        f[x]=1;
      }
    }
  }
  return -1;
}

int main()
{
  cin>>n;
  cout<<n<<' '<<~n;
  freopen("heal.in","r",stdin);
  freopen("heal.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=m; i++)
  {
    int D=0,Z=0;
    for(int x,j=1; j<=n; j++)
    {
      scanf("%d",&x);
      if(x==1)
        Z=Z+(1<<(j-1));
      if(x==-1)
        D=D+(1<<(j-1));
    }
    ill[i]=D;
    cure[i]=~Z;
  }
  int ans=Bfs();
  if(ans==-1)
    printf("The patient will be dead.\n");
  else
    printf("%d\n",ans);
  return 0;
}
