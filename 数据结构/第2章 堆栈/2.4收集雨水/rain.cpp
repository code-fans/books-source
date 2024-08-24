//收集雨水
#include <bits/stdc++.h>
using namespace std;
int height[10005],n;
stack<int> st;                                 //单调栈

int main()
{
  freopen("rain.in","r",stdin);
  freopen("rain.out","w",stdout);
  scanf("%d",&n);
  for(int i = 0 ; i < n ; i++)
    cin >> height[i];
  long long ans = 0;
  for (int i = 0; i < n; i++)
  {
    while (!st.empty() && height[st.top()] < height[i])
    {
      int low = st.top();                      //弹出栈的是低洼处
      st.pop();
      if (st.empty())
        break;
      long long dist=i-st.top()-1;             //计算出左右边界距离
      int h= min(height[st.top()],height[i]);  //左右边界最小值为水的高度
      ans+=dist*(h-height[low]);               //height[low]为雨水的最低处
    }
    st.push(i);                                //存的不是高度，而是柱子的坐标
  }
  printf("%lld\n",ans);
  return 0;
}

