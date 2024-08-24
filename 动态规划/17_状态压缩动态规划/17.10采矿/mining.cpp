#include <bits/stdc++.h>
using namespace std;

const int maxn=11;
int n,m,tot,K,sx,sy,tx,ty,mx[4]= {-1,0,1,0},my[4]= {0,-1,0,1},tim[maxn],f[59100][maxn][maxn],pos[maxn];
char mp[maxn][maxn],nam[maxn][2];
struct node
{
  int sta,x,y;
};
queue<node>q;

bool jud(int x,int y)
{
  return x>=1&&x<=n&&y>=1&&y<=m;
}

void divi(int sta)
{
  register int cnt=0;
  for (register int i=1; i<=tot; i++)
    pos[i]=0;
  while (sta)
  {
    pos[++cnt]=sta%3;
    sta/=3;
  }
}

int calctime(int sta)
{
  register int i;
  divi(sta);
  sta=K;
  for (i=1; i<=tot; i++)
    if (pos[i]==1)
      sta+=tim[i];
  if (sta<1)
    sta=1;
  return sta;
}

int backup(int sta,int x,int y)
{
  register int id,i;
  for (id=1; id<=tot; id++)
    if (nam[id][0]==mp[x][y])
      break;
  divi(sta);
  if (pos[id])
    return 0;
  pos[id]=1;
  sta=0;
  for (i=tot; i>=1; i--)
    sta=sta*3+pos[i];
  return sta;
}

int putdown(int sta,bool con)
{
  register int i;
  divi(sta);
  for (i=1; i<=tot; i++)
    if (pos[i]==1&&(!con||con&&tim[i]>0))
      pos[i]=2;
  sta=0;
  for (i=tot; i>=1; i--)
    sta=sta*3+pos[i];
  return sta;
}

void bfs()
{
  register node u,v;
  register int i,val;
  f[0][sx][sy]=0;
  q.push((node)
  {
    0,sx,sy
  });
  while (!q.empty())
  {
    u=q.front();
    q.pop();
    val=calctime(u.sta);
    for (i=0; i<=3; i++)
    {
      v.x=u.x+mx[i],v.y=u.y+my[i];
      if (jud(v.x,v.y))
      {
        if (mp[v.x][v.y]^'#'&&f[u.sta][v.x][v.y]>f[u.sta][u.x][u.y]+val)
        {
          f[u.sta][v.x][v.y]=f[u.sta][u.x][u.y]+val;
          v.sta=u.sta;
          q.push(v);
        }
        if (mp[v.x][v.y]>='A'&&mp[v.x][v.y]<='Z')
        {
          v.sta=backup(u.sta,v.x,v.y);
          if (f[v.sta][v.x][v.y]>f[u.sta][u.x][u.y]+val)
          {
            f[v.sta][v.x][v.y]=f[u.sta][u.x][u.y]+val;
            q.push(v);
          }
        }
        if (mp[v.x][v.y]=='t')
        {
          v.sta=putdown(u.sta,0);
          if (f[v.sta][v.x][v.y]>f[u.sta][u.x][u.y]+val)
          {
            f[v.sta][v.x][v.y]=f[u.sta][u.x][u.y]+val;
            q.push(v);
          }
          v.sta=putdown(u.sta,1);
          if (f[v.sta][v.x][v.y]>f[u.sta][u.x][u.y]+val)
          {
            f[v.sta][v.x][v.y]=f[u.sta][u.x][u.y]+val;
            q.push(v);
          }
        }
      }
    }
  }
}

int main()
{
  freopen("mining.in","r",stdin);
  freopen("mining.out","w",stdout);
  register int i,j;
  scanf("%d%d%d",&n,&m,&K);
  for (i=1; i<=n; i++)
  {
    scanf("%s",mp[i]+1);
    for (j=1; j<=m; j++)
    {
      if (mp[i][j]=='s')
        sx=i,sy=j;
      else if (mp[i][j]=='t')
        tx=i,ty=j;
      else if (mp[i][j]>='A'&&mp[i][j]<='Z')
        ++tot;
    }
  }
  for (i=1; i<=tot; i++)
    scanf("%s%d",nam[i],&tim[i]);
  memset(f,0x3f,sizeof(f));
  bfs();
  j=1;
  for (i=1; i<=tot; i++)
    j*=3;
  j--;
  printf("%d\n",f[j][tx][ty]);
  return 0;
}
