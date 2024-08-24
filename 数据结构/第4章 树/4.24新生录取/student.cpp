//新生录取
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int INF = 0x3f3f3f3f;
int lower[MAXN];   //lower[i]表示以第i人为中位数时小于中位数的人的补贴总和
int upper[MAXN];   //upper[i]表示以第i人为中位数时大于中位数的人的补贴总和
pair<int, int>people[MAXN];                   //保存每个人的分数和钱数

int main()
{
  freopen("student.in","r",stdin);
  freopen("student.out","w",stdout);
  int n,c,f;
  scanf("%d%d%d",&n,&c,&f);
  for(int i = 0; i < c; i++)
    scanf("%d%d",&people[i].first, &people[i].second);
  sort(people, people+c);                      //按分数从小到大排序

  int total = 0;
  int half = n/2;
  priority_queue<int>q;
  for(int i = 0; i < c; i++)                   //计算每个人左边n/2个人的学费和
  {
    lower[i] = (q.size() == half? total:INF);  //如果左边人数不是n/2就最大值
    q.push(people[i].second);
    total += people[i].second;                 //统计总钱数
    if(q.size() > half)                        //如果人数超过了n/2
    {
      total -= q.top();
      q.pop();                                 //弹出需要钱数最大的的人
    }
  }

  total = 0;
  priority_queue<int>q1;
  for(int i = c-1; i >= 0; i--)                //计算每个人右边n/2个人的学费和
  {
    upper[i] = (q1.size() == half? total:INF);
    q1.push(people[i].second);
    total += people[i].second;
    if(q1.size() > half)
    {
      total -= q1.top();
      q1.pop();
    }
  }
  int ans = -1;
  for(int i = c-1; i >= 0; i--)                //从右到右遍历所有可能
    if(lower[i]+people[i].second+upper[i] <= f)//如果没有超过总费用
    {
      ans = people[i].first;
      break;
    }
  printf("%d\n",ans);
  return 0;
}

