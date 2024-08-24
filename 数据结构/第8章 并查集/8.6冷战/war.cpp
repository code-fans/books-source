#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500001;

int N,M,opt,x,y,lastans;
int fa[MAXN], deep[MAXN], mx[MAXN],siz[MAXN];

int Find(int x)//����·��ѹ��������Ҫ�õ�����·����
{
  if(x == fa[x])
    return x;
  else
  {
    int f = Find(fa[x]);       //Ҫ�ȱ���һ��
    deep[x] = deep[fa[x]] + 1;
    return f;
  }
}

void Union(int x, int y, int tim)
{
  int fx = Find(x), fy = Find(y);
  if(fx == fy)
    return;
  if(siz[fx] > siz[fy])//��
    swap(fx, fy);
  fa[fx] = fy;        //���߶ȴ�� �������ߺϲ�����������ֻ��logn
  siz[fy] += siz[fx];
  mx[fx] = tim;       //�޽�ʱ���
}

int Query(int x, int y)
{
  int ans = 0;
  while(x != y)
  {
    if(deep[x] < deep[y])
      swap(x, y);
    ans = max(ans, mx[x]);//��·���ϵ����ʱ���
    x = fa[x];
  }
  return ans;
}

int main()
{
  //freopen("war.in","r",stdin);
  //freopen("war.out","w",stdout);
  cin>>N>>M;
  for(int i = 1; i <= N; i++)
    fa[i] = i, siz[i] = 1;
  int tim = 0;
  for(int i = 1; i <= M; i++)
  {
    cin>>opt>>x>>y;
    x^=lastans, y^=lastans;
    if(opt)
      printf("%d\n",lastans=Find(x)^Find(y) ? 0:Query(x, y));
    else
      Union(x, y, ++tim);
  }
  return 0;
}
