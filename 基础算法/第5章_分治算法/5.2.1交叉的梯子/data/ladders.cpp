//���������
#include <bits/stdc++.h>
using namespace std;

double x,y,c;

bool Judge(double t)
{
  double h1=sqrt(x*x-t*t);
  double h2=sqrt(y*y-t*t);
  return c*(h1+h2)-h1*h2>0?1:0;
}

int main()
{
  freopen("ladders.in","r",stdin);
  freopen("ladders.out","w",stdout);
  while(scanf("%lf%lf%lf",&x,&y,&c)==3)
  {
    double low=0,mid;             //�½�Ϊ0
    double high=min(x,y);         //�Ͻ�Ϊx,y�еĽ�С��
    while(low<=high)
    {
      mid=(low+high)/2;
      Judge(mid)? high=mid-0.0001:low=mid+0.0001;
    }
    printf("%.3lf\n",low);
  }
  return 0;
}
