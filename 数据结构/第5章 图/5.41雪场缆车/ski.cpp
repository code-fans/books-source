#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 505;
const int MAXN = 250005;

typedef struct _node
{
  int v, next;
} N;
N edge[MAXN * 4];
int farm[MAX][MAX];
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dfn[MAXN], low[MAXN], step;
int inS[MAXN], id[MAXN], scc, myS[MAXN], top;
int in[MAXN], out[MAXN], cntEdge, head[MAXN];

void init()
{
  cntEdge = step = scc = top = 0;
  for(int i = 0; i < MAXN; i++)
  {
    head[i] = -1;
    dfn[i] = low[i] = -1;
    id[i] = -1;
    in[i] = out[i] = 0;
    inS[i] = 0;
  }
}

void tarjan(int n)
{
  dfn[n] = low[n] = ++step;
  myS[top++] = n;
  inS[n] = 1;
  for(int f = head[n]; f != -1; f = edge[f].next)
  {
    int son = edge[f].v;
    if(dfn[son] == -1)
    {
      tarjan(son);
      low[n] = min(low[n], low[son]);
    }
    else if(inS[son] != 0)
      low[n] = min(low[n], dfn[son]);
  }

  if(low[n] == dfn[n])
  {
    int tmp;
    do
    {
      tmp = myS[--top];
      inS[tmp] = 0;
      id[tmp] = scc;
    }
    while(myS[top] != n);
    scc++;
  }
}

void addEdge(int u, int v)
{
  edge[cntEdge].v = v;
  edge[cntEdge].next = head[u];
  head[u] = cntEdge++;
}

void bulid(int w, int l)
{
  int u, v;
  for(int i = 0; i < l; i++)
    for(int j = 0; j < w; j++)
    {
      for(int k = 0; k < 4; k++)
      {
        int ni, nj;
        ni = i + dir[k][0];
        nj = j + dir[k][1];
        if(ni >= 0 && ni < l && nj >= 0 && nj < w)
        {
          if(farm[i][j] >= farm[ni][nj])
          {
            u = i * w + j;
            v = ni * w + nj;
            addEdge(u, v);
          }
        }
      }
    }
}

int main(void)
{
  //freopen("ski5.in", "r", stdin);
  //freopen("ski5.ans", "w", stdout);
  int w, l;
  while(scanf("%d %d", &w, &l) == 2)
  {
    init();
    for(int i = 0; i < l; i++)
      for(int j = 0; j < w; j++)
        scanf("%d", &farm[i][j]);
    bulid(w, l);
    int n = w * l;

    for(int i = 0; i < n; i++)
    {
      if(dfn[i] == -1)
        tarjan(i);
    }
    int u, v;
    for(int i = 0; i < n; i++)
    {
      for(int j = head[i]; j != -1; j = edge[j].next)
      {
        u = i, v = edge[j].v;
        if(id[u] == id[v])
          continue;
        else
        {
          in[id[v]]++;
          out[id[u]]++;
        }
      }
    }
    int inNum = 0, outNum = 0;
    for(int i = 0; i < scc; i++)
    {
      if(!in[i])
        inNum++;
      if(!out[i])
        outNum++;
    }
    if(scc >= 2)
      printf("%d\n", max(inNum, outNum));
    else
      printf("0\n");
  }
  return 0;
}
