//破碎的项链
#include<bits/stdc++.h>
using namespace std;
int n, ans = -1;
string s;
int Calc(int pos)
{
  int i,Len = 2, L=(pos-1+n) % n, R = pos;           //l,r代表左右分割点的位置
  for(; (R + 1) % n != pos && s[R % n] == 'w'; R++, Len++);//跳过右边连续的w,确定R的位置
  for(i=1; i<n && (s[R%n]==s[(R+i)% n] || s[(R+i)%n]=='w'); i++,Len++);//向右
  for(i=2; i<n && (s[L]==s[(pos-i+n)%n] || s[(pos-i+n)%n]=='w'); i++,Len++);//向左
  return Len>n?n:Len;//处理可分割的全链相同: wwwrrrr 这种情况
}

int main()
{
  freopen("beads.in","r",stdin);
  freopen("beads.out","w",stdout);
  cin>>n>>s;
  for(int i = 0; i < n; i++)
    if(s[(i-1+n)%n]!=s[i] && s[(i-1+n)%n]!='w')
      ans = max(ans, Calc(i));
  cout<<(ans==-1 ? n:ans)<<endl;//-1表示无法分割，全部颜色相同
  return 0;
}
