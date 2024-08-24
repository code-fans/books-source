//宝藏
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int x, y;
} s[100005];

int Stack[100001]= {1e-9};

int Cmp(node a, node b)              //按x值从小到大排,相等则按y从小到大排
{
  return (a.x==b.x ? a.y<b.y : a.x<b.x);
}

int main()
{
  //freopen("Treasure_map.in","r",stdin);
  //freopen("Treasure_map.out","w",stdout);
  int n,m,p,longest=0;
  scanf("%d%d%d", &n, &m, &p);
//  vector <int> v;                    //此处vector当堆栈使用
  for(int i = 0; i < p; i++)
    scanf("%d%d", &s[i].x, &s[i].y);
  sort(s, s+p, Cmp);
//  for(int i = 0; i < p; i++)
//  {
//    vector<int>::iterator it=upper_bound(v.begin(),v.end(),s[i].y);
//    if(it != v.begin())              //如果不是头元素
//      *--it=s[i].y;                  //把该位置的值替换为s[i].y
//    else                             //如果s[i].y>头元素,则直接插入
//      v.insert(v.begin(), s[i].y);
//  }
  for (int i = 0; i<p; i++)
  {
    if (s[i].y>Stack[longest])                     //比栈顶元素大数就入栈
      Stack[++longest]=s[i].y;
    else
    {
      int j=upper_bound(Stack,Stack+longest,s[i].y)-Stack;
      Stack[j]=s[i].y;
    }
  }
  printf("%d\n", longest);
  return 0;
}

