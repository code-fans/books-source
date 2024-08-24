//音乐会
#include <bits/stdc++.h>
using namespace std;
const int N=500050;

int H[N],Stack[N];                   //H[]保存身高,Stack[]为单调栈
long long Ans;                       //不能取int
int top;                             //top指向单调栈顶

inline int Read(int ans=0,int f=0)
{
  char c=getchar();
  for(; c<'0'  || c>'9'; f^=(c=='-'),c=getchar());
  for(; c<='9' && c>='0'; c=getchar())
    ans=(ans<<3)+(ans<<1)+(c^48);
  return f? -ans : ans;
}

void Calc(int x)                     //部分评测网站例如洛谷需二分优化
{
  int L=0,R=top,pos=0;
  while(L<=R)                        //因单调栈是递减的，所以可以二分查找
  {
    int mid=(L+R)>>1;
    if(H[Stack[mid]]>x)
      pos=mid,L=mid+1;                //查找pos，即x左边第一个比x高的人
    else R=mid-1;
  }
  !pos? Ans+=top:Ans+=top-pos+1;     //!pos表示没找到比x高的人
}

int main()
{
  //freopen("patrik.in","r",stdin);
  //freopen("patrik.out","w",stdout);
  int n=Read();
  for(int i=1; i<=n; ++i)
    H[i]=Read();
  for(int i=1; i<=n; ++i)
  {
    Calc(H[i]);
    while(top>0 && H[i]>H[Stack[top]])//维护单调递减栈
      --top;
    Stack[++top]=i;                   //当前元素入栈,存的是排序号,不是身高
  }
  printf("%lld\n",Ans);
  return 0;
}

