#include <bits/stdc++.h>
using namespace std;

struct node
{
  int s,e;
} qu[40010];

bool Cmp(node a,node b)
{
  return a.e<b.e;
}

int main()
{
  //freopen("ClosedInterval.in","r",stdin);
  //freopen("ClosedInterval.out","w",stdout);
  int n;
  while(scanf("%d",&n)==1)
  {
    for(int i=0; i<n; i++)
    {
      scanf("%d%d",&qu[i].s,&qu[i].e);
      if(qu[i].s>qu[i].e)
        swap(qu[i].s,qu[i].e);
    }
    sort(qu,qu+n,Cmp);
    int ans=0;
    int cur=qu[0].e;
    for(int i=1; i<n; i++)
      if(qu[i].s<=cur)  //ע����Ŀ�ʵ���ȥ���������ٵ�������ʹ���ཻ
        ans++;          //�����ཻ�ľ�ɾ��
      else
        cur=qu[i].e;
    printf("%d\n",ans);
  }
  return 0;
}

