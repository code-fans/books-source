//多重背包 —单调队列优化
#include<bits/stdc++.h>
using namespace std;

int f[210],q[210],k[210];

int main()
{
  //freopen("Mbag.in","r",stdin);
  //freopen("Mbag.out","w",stdout);
  int N,V,head,tail,v,w,c;
  scanf("%d%d",&V,&N);
  for(int i=1; i<=N; i++)
  {
    scanf("%d%d%d",&v,&w,&c);
    int a=c>V/v?V/v:c;                     //能取的最多个数
    for(int b=0; b<v; b++)                 //枚举余数
    {
      head=tail=1;
      for(int t=0; t<=(V-b)/v; t++)//枚举t,考虑将(V-b)/v改为V/v或者a是否可行
      {
        int tmp=f[b+t*v]-t*w;
        while(head<tail && q[tail-1]<=tmp)
          tail--;
        q[tail]=tmp;
        k[tail++]=t;
        while(head<tail && t-k[head]>a)    //滑动区间长度不大于a
          head++;
        f[t*v+b]=max(f[b+t*v],q[head]+t*w);//q[]存的是f[t*v+b]-t*w,所以+t*w
      }
    }
  }
  printf("%d\n",f[V]);
  return 0;
}

