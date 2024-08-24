//双塔问题 -非高精度算法
//单塔最少移动步数是2n－1（见本套书第一部），现在有2层，可以将2层看作1层，
//便回到了单塔问题上，每移动想象中的"单个盘子"需两步，故双塔＝单塔×2。
//递推公式：f(n)＝2n+1－2
#include <bits/stdc++.h>
using namespace std;

int a[31]= {1,1};               //a[0]存储最高位的下标，a[1]=1即初始值为1

int main()
{
  freopen("hanoi2.in","r",stdin);
  freopen("hanoi2.out","w",stdout);
  int n;
  cin>>n;
  cout<<int(pow(2,n+1))-2<<endl;
  return 0;
}

