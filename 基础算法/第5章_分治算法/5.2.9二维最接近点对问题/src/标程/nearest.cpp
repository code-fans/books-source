//最接近点对问题
#include <bits/stdc++.h>
using namespace std;
const int INF=0x7fffffff;
int n,temp[1000001];

struct Point
{
  double x,y;
} S[1000001];

bool Cmp(const Point &a,const Point &b) //按x排序，若相等，按y排序
{
  return (a.x==b.x? a.y<b.y : a.x<b.x);
}

bool CmpY(const int &a,const int &b)    //按y从小到大排序
{
  return S[a].y<S[b].y;
}

double Dist(int i, int j)
{
  double x=(S[i].x-S[j].x)*(S[i].x-S[j].x);
  double y=(S[i].y-S[j].y)*(S[i].y-S[j].y);
  return sqrt(x+y);
}

double Find(int L,int R)                  //找到L到R之间最小距离
{
  if(L==R)                                //若左右边界重合
    return INF;
  if(L+1==R)                              //若左右边界差值为１即只有两个点
    return Dist(L,R);
  int mid=(L+R)>>1;                       //从中间划分
  double d=min(Find(L,mid),Find(mid+1,R));//递归求出最小值d
  int  k=0;
  for(int i=L; i<=R; ++i)                 //找出d范围内的点存入temp[]
    if(fabs(S[mid].x-S[i].x)<=d)
      temp[k++]=i;
  sort(temp,temp+k,CmpY);                 //按y坐标排序
  for(int i=0; i<k; ++i)                  //穷举存入temp[]内的这些点
    for(int j=i+1; j<k && S[temp[j]].y-S[temp[i]].y<d; ++j) //找出最近(p,q)
      d=min(d,Dist(temp[i],temp[j]));
  return d;
}

int main()
{
  //freopen("nearest.in","r",stdin);
  //freopen("nearest.out","w",stdout);
  scanf("%d",&n);
  for(int i=0; i<n; ++i)
    scanf("%lf%lf",&S[i].x,&S[i].y) ;
  sort(S,S+n,Cmp);                        //点按x坐标由小到大排序
  printf("%.2lf\n",Find(0,n-1)/2);        //注意输出是两倍
  return 0 ;
}

