//�ռ���ˮ
#include <bits/stdc++.h>
using namespace std;
int height[10005],n;
stack<int> st;                                 //����ջ

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
      int low = st.top();                      //����ջ���ǵ��ݴ�
      st.pop();
      if (st.empty())
        break;
      long long dist=i-st.top()-1;             //��������ұ߽����
      int h= min(height[st.top()],height[i]);  //���ұ߽���СֵΪˮ�ĸ߶�
      ans+=dist*(h-height[low]);               //height[low]Ϊ��ˮ����ʹ�
    }
    st.push(i);                                //��Ĳ��Ǹ߶ȣ��������ӵ�����
  }
  printf("%lld\n",ans);
  return 0;
}

