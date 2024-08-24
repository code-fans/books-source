//������ - A*�㷨
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int state;                                 //��״̬�����ֱ���
  int cantor;                                //״̬�Ŀ���ֵ
  int zero;                                  //0��λ��
  int G,H;                                   //��ֵ����G(N)��H(N)
  int step;                                  //����
  bool operator<(const node &a) const        //����������
  {
    return a.G+a.H<G+H;                      //��G(N)+H(N)��С������
  }
} t;
priority_queue <node> Q;

int s[9],f[9]= {1,2,3,8,0,4,7,6,5};
bool visit[10000000];

int Cantor(int s[])                          //����ѹ��
{
  int ans = 0;
  int use[9] = {0};
  for (int i = 0; i <= 7; i++)
  {
    int no = 0;
    use[s[i]] = true;
    for (int j = 0; j < s[i]; j++)
      if (use[j])
        no++;
    ans = (ans + s[i] - no) * (8 - i);
  }
  return ans;
}

int ToDigit()
{
  int ans = 0;
  for (int i = 0; i < 9; i++)
    ans = ans * 10 + s[i];
  return ans;
}

int Difference()                             //����
{
  int ans = 0;
  for (int i = 0; i < 9; i++)
    if (s[i] != f[i] && s[i] != 0)
      ans++;
  return ans;
}

void GetState(int x)
{
  for (int i = 8; i >= 0; i--)
  {
    s[i] = x % 10;
    x /= 10;
  }
}

void Add(int nxt,node last)                  //��չ���
{
  swap(s[last.zero + nxt],s[last.zero]);
  int k = Cantor(s);
  node u;
  if (!visit[k])
  {
    visit[k] = true;
    u.state=ToDigit();
    u.cantor=k;
    u.zero=last.zero+nxt;
    u.G=last.G+1;
    u.H=Difference();
    u.step=last.step+1;
    Q.push(u);
  }
  swap(s[last.zero + nxt],s[last.zero]);     //��ԭ
}

void A_star()                                //A*�㷨
{
  while (!Q.empty())
  {
    if (Q.top().H == 0)                     //��Ŀ��״̬��ȫƥ��
    {
      printf("%d\n", Q.top().step);
      return;
    }
    t = Q.top();
    GetState(t.state);
    Q.pop();
    if (t.zero  > 2)
      Add(-3,t);
    if (t.zero < 6)
      Add(3,t);
    if (t.zero % 3)
      Add(-1,t);
    if ((t.zero % 3) < 2)
      Add(1,t);
  }
  printf("-1\n");
}

void Init()
{
  for (int i = 0; i < 9; i++)
  {
    scanf("%d", &s[i]);
    if (s[i] == 0)
      t.zero = i;
  }
  t.state=ToDigit();
  t.cantor=Cantor(s);
  t.G=0;
  t.H=Difference();
  t.step=0;
  Q.push(t);                                 //��ʼ״̬���
  visit[t.cantor]=true;
}

int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  Init();
  int final=Cantor(f);
  if (Q.top().cantor == final)
    printf("0\n");
  else
    A_star();
  return 0;
}

