//雷达问题
#include <bits/stdc++.h>
using namespace std;

struct coordinate                           //坐标结构体(x,y)
{
  int x,y;
} p[1001];

struct island                               //区间结构体[a,b]
{
  double a,b;
} b[1001];

int Cmp(island x,island y)
{
  return x.b<y.b ;
}

double Limit(int y,int d)            //找出所给坐标对应的圆心允许范围
{
  return sqrt(d*d-y*y);                 //用到勾股定理
}

int main()
{
  freopen("radar.in","r",stdin);
  freopen("radar.out","w",stdout);
  int n,d,k,x,y;
  for(int Case=1; cin>>n>>d,n; Case++)      //n为0则退出
  {
    int Ok=1;
    for(k=0; k<n; ++k)
    {
      cin>>x>>y;
      if(abs(y)>d)                     //坐标垂直距离超过d,无解
        Ok=0;                               //不能直接退出，否则数据会乱
      b[k].a=x-Limit(y,d);          //计算点在x轴的左边界
      b[k].b=x+Limit(y,d);          //计算点在x轴的右边界
    }
    if(Ok==0)
      cout<<"Case "<< Case<<": "<<-1<<endl;
    else
    {
      int last=0;
      int radar=1;
      sort(b,b+n,Cmp);                      //将区间按右边界从小到大排序
      for(int i=0; i<n; ++i)
        if(b[i].a>b[last].b)                //对包含区间取最右端的点
        {
          ++radar;                          //若左界大于前区间的右界，则加雷达
          last=i;
        }
      cout<<"Case "<<Case<<": "<<radar<<endl;
    }
  }
  return 0;
}

