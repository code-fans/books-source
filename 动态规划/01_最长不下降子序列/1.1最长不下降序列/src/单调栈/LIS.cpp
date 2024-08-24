//最长不下降序列 - 非动规算法
#include <bits/stdc++.h>
using namespace std;

int Stack[100001]= {1e-9};              //防止第一个元素太小

int main()
{
  //freopen("LIS.in","r",stdin);
  //freopen("LIS.out","w",stdout);
  int n,temp,longest=0;
  scanf("%d",&n);
  for (int i=0; i<n; i++)
  {
    scanf("%d",&temp);
    if (temp>=Stack[longest])           //比栈顶元素大数就入栈
      Stack[++longest]=temp;
    else
    {
      int j=upper_bound(Stack,Stack+longest,temp)-Stack;
      Stack[j]=temp;
    }
  }
  printf("%d\n",longest);               //最长序列数就是栈的大小
  return 0;
}

