#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int INF = 2140000000;
int DelA, DelB;//ɾ���ߵ������ڵ�
bool looptree = false;//�ж��Ƿ������

struct map
{
  int c;
  int nxt;
  bool used;
} e[2*5010];
int head[5010];
bool visited[5010];
int minans[5010];//����С�ֵ���
int ans[5010];//����ǰ�������ֵ���
int cntans = 0, maxcntans = 0;//cntans:�������Ľ����
int cnt = 0;
int n, m;

bool better() //�Ƚ�ans�Ƿ����minans
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
  if (looptree && cntans <= maxcntans && !better())//��֦
    return;
  priority_queue <int, vector<int>, greater<int> >q;//���ȶ��д��ӽڵ�,��С����DFS����
  for (int i = head[sur]; i; i = e[i].nxt)
  {
    if (visited[e[i].c]||(e[i].c==DelB && sur==DelA)|| (e[i].c == DelA && sur == DelB))
      continue;       //���ѱ����ʹ������ѱ�ɾ�������
    q.push(e[i].c);
  }
  while (!q.empty())
  {
    DFS(q.top());
    q.pop();
  }
}

void AddE(int x, int y) //ǰ���Ǵ��
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
    AddE(x, y);//ǰ���Ǵ洢,vector�ᳬʱ
    AddE(y, x);
  }
  int sur = 1;
  if (m == n - 1)//���������
  {
    cntans = 0;
    DelA = -1;
    DelB = -1;
    DFS(1);
    for (int i = 1; i <= cntans; i++)
      i==cntans?printf("%d\n",ans[i]):printf("%d ",ans[i]);
  }
  else          //�����������
  {
    looptree = true;                  //��Ϊ������
    for (int i = 1; i <= 2*m; i+=2)
    {
      memset(visited, 0, sizeof(visited));
      cntans = 0;
      DelA = e[i+1].c;//ѡ��ɾ���ıߵĽ��1
      DelB = e[i].c;  //ѡ��ɾ���ıߵĽ��2
      DFS(sur);
      if (cntans>maxcntans || (cntans>=maxcntans && better()))//�������Ž�
      {
        memcpy(minans, ans, sizeof(ans));//����ans��minans
        maxcntans = cntans;
      }
    }
    for (int i = 1; i <= maxcntans; i++)
      i==maxcntans?printf("%d\n",minans[i]):printf("%d ",minans[i]);
  }
  return 0;
}
