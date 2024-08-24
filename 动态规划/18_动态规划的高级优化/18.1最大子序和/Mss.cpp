//最大子序和
#include <bits/stdc++.h>
using namespace std;

long long s[300005];                  //前序和数组
list<int> Q;                           //此处使用STL里的list做单调队列

int main()
{
  freopen("Mss.in","r",stdin);
  freopen("Mss.out","w",stdout);
  Q.push_front(0);
  int n,m;
  cin>>n>>m;
  for (int i=1; i<=n; i++)
  {
    cin>>s[i];
    s[i]+=s[i-1];                         //计算前缀和
  }
  long long maxx=s[1];
  for (int i=1; i<=n; i++)
  {
    while(!Q.empty() && s[Q.front()]>s[i])//注意此处front为队尾
      Q.pop_front();                      //删除保持单调性
    Q.push_front(i);                      //插入当前数据
    while(!Q.empty() && i-m>Q.back())     //保证i-m>=queue.back()
      Q.pop_back();                       //删除队首元素(back为队首)以维护区间大小
    maxx=max(maxx,s[i]-s[Q.back()]);    //更新最值
  }
  cout<<maxx<<endl;
  return 0;
}

