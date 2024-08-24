#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int INF = 2140000000;
int DelA, DelB;//删除边的两个节点
bool looptree = false;//判断是否基环树

struct map
{
  int c;
  int nxt;
  bool used;
} e[2*5010];
int head[5010];
bool visited[5010];
int minans[5010];//即最小字典序
int ans[5010];//即当前搜索的字典序
int cntans = 0, maxcntans = 0;//cntans:搜索到的结点数
int cnt = 0;
int n, m;

bool better() //比较ans是否大于minans
{
  for (int i = 1; i <= cntans; i++)
  {
    if (ans[i] > minans[i])
      return false;
    if (ans[i] < minans[i])
      return true;
  }
  return true;
}

void DFS(int sur)
{
  visited[sur] = true;
  ans[++cntans] = sur;
  if (looptree && cntans <= maxcntans && !better())//剪枝
    return;
  priority_queue <int, vector<int>, greater<int> >q;//优先队列存子节点,从小到大DFS深搜
  for (int i = head[sur]; i; i = e[i].nxt)
  {
    if (visited[e[i].c]||(e[i].c==DelB && sur==DelA)|| (e[i].c == DelA && sur == DelB))
      continue;       //边已被访问过或者已被删除则忽略
    q.push(e[i].c);
  }
  while (!q.empty())
  {
    DFS(q.top());
    q.pop();
  }
}

void AddE(int x, int y) //前向星存边
{
  cnt++;
  e[cnt].c = y;
  e[cnt].nxt = head[x];
  head[x] = cnt;
}

int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  int x, y;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++)
  {
    scanf("%d%d", &x, &y);
    AddE(x, y);//前向星存储,vector会超时
    AddE(y, x);
  }
  int sur = 1;
  if (m == n - 1)//是树的情况
  {
    cntans = 0;
    DelA = -1;
    DelB = -1;
    DFS(1);
    for (int i = 1; i <= cntans; i++)
      i==cntans?printf("%d\n",ans[i]):printf("%d ",ans[i]);
  }
  else          //基环树的情况
  {
    looptree = true;                  //设为基环树
    for (int i = 1; i <= 2*m; i+=2)
    {
      memset(visited, 0, sizeof(visited));
      cntans = 0;
      DelA = e[i+1].c;//选出删除的边的结点1
      DelB = e[i].c;  //选出删除的边的结点2
      DFS(sur);
      if (cntans>maxcntans || (cntans>=maxcntans && better()))//更新最优解
      {
        memcpy(minans, ans, sizeof(ans));//复制ans到minans
        maxcntans = cntans;
      }
    }
    for (int i = 1; i <= maxcntans; i++)
      i==maxcntans?printf("%d\n",minans[i]):printf("%d ",minans[i]);
  }
  return 0;
}
