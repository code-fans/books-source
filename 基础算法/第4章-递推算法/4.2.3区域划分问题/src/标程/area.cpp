//区域划分问题
/*
由于给出了p条共点直线，考虑到共点直线的特殊性，我们可以先考虑p条相交于
一点的直线，然后再考虑剩下的n－p条直线。显然p条相交于一点的直线将平面
划分成的区域数为2p个，然后在平面上已经有k（k≥p）条直线的基础上，加一
条直线，由于新增加的直线最多可以与k条直线相交，而每次相交都会增加一个
区域，与最后一条直线相交后，由于直线可以无限延伸，还会增加一个区域，
设定f(m)为平面上m条直线最多能将平面分割区域的数目，则有
f(m)＝f(m－1)＋m （m＞p），这样就建立起了一个递推关系式。
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("area.in","r",stdin);
  freopen("area.out","w",stdout);
  int n,p,total;
  scanf("%d%d",&n,&p);
  total=2*p;
  for(int i=p+1; i<=n; i++)
    total=total+i;
  printf("%d\n",total);
  return 0;
}

