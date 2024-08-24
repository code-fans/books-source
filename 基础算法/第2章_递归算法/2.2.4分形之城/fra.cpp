//分形之城
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> PLL;

PLL Cal(long long n, long long pos)
{
  if (n == 0)
    return make_pair(0LL, 0LL);  //0级,只有一个街区,返回0,0
  long long len = 1LL<<(n-1);    //n-1级城市的边长
  long long cnt = 1LL<<(2*n-2);  //n-1级城市的街区数
  PLL now = Cal(n-1, pos%cnt);   //在下一级城市中是第几个节点
  long long x = now.first;
  long long y = now.second;
  cout<<n<<" "<<x<<' '<<y<<endl;
  int where = pos/cnt+1;         //where:计算出pos在城市的哪部分
  if(where==1)                   //左上部分
    return make_pair(y, x);
  if(where==2)                   //右上部分
    return make_pair(x+len, y);
  if(where==3)                   //左下部分
    return make_pair(x+len, y+len);
  if(where==4)                   //右下部分
    return make_pair(len-1-y,len+len-1-x);
}

int main()
{
//  //freopen("fra.in","r",stdin);
//  //freopen("fra.out","w",stdout);
  long long T,A,B,n,x,y;
  for(scanf("%lld", &T); T--;)
  {
    scanf("%lld %lld %lld", &n, &A, &B);
    PLL a = Cal(n, A-1);
    PLL b = Cal(n, B-1);
    x = a.first-b.first;
    y = a.second-b.second;
    printf("%.0lf\n",sqrt(x*x+y*y)*10);
  }
  return 0;
}
