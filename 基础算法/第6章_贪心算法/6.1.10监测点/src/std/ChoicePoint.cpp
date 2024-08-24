//监测点
#include <bits/stdc++.h>
using namespace std;

struct node
{
  int a,b;
} pot[110];

bool Cmp(const node &x,const node &y)
{
  return x.b<y.b;
}

int main()
{
  //freopen("ChoicePoint.in","r",stdin);
  //freopen("ChoicePoint.out","w",stdout);
  int T,n;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d",&n);
    for(int i=0; i<n; i++)
      scanf("%d %d",&pot[i].a,&pot[i].b);
    sort(pot,pot+n,Cmp);           //按结束点从小到大排序 
    int cnt=1;
    int end=pot[0].b;
    for(int i=1; i<n; i++)
      if(end<pot[i].a)
      {
        end=pot[i].b;
        cnt++;
      }
    cout<<cnt<<endl;
  }
  return 0;
}

