//����֮��
#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, long long> PLL;

PLL Cal(long long n, long long pos)
{
  if (n == 0)
    return make_pair(0LL, 0LL);  //0��,ֻ��һ������,����0,0
  long long len = 1LL<<(n-1);    //n-1�����еı߳�
  long long cnt = 1LL<<(2*n-2);  //n-1�����еĽ�����
  PLL now = Cal(n-1, pos%cnt);   //����һ���������ǵڼ����ڵ�
  long long x = now.first;
  long long y = now.second;
  cout<<n<<" "<<x<<' '<<y<<endl;
  int where = pos/cnt+1;         //where:�����pos�ڳ��е��Ĳ���
  if(where==1)                   //���ϲ���
    return make_pair(y, x);
  if(where==2)                   //���ϲ���
    return make_pair(x+len, y);
  if(where==3)                   //���²���
    return make_pair(x+len, y+len);
  if(where==4)                   //���²���
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
