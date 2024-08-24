//排座椅
#include<bits/stdc++.h>
using namespace std;

struct node
{
  int id,count;
} x[1005],y[1005];

bool CMP1(node a,node b)   //按人数从小到大排序
{
  return a.count>b.count;
}

bool CMP2(node a,node b)   //按位置从小到大排序
{
  return a.id<b.id;
}

int main()
{
  //freopen("seat.in","r",stdin);
  //freopen("seat.out","w",stdout);
  int m,n,k,l,d;
  scanf("%d%d%d%d%d",&m,&n,&k,&l,&d);
  for(int i=1,x1,y1,x2,y2; i<=d; i++)
  {
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x1==x2)                     //同一行
    {
      y[min(y1,y2)].count++;       //则列数组统计
      y[min(y1,y2)].id=min(y1,y2);
    }
    else if(y1==y2)                //同一列
    {
      x[min(x1,x2)].count++;       //则行数组统计
      x[min(x1,x2)].id=min(x1,x2);
    }
  }
  sort(x+1,x+1+m,CMP1);            //按人数从大到小排
  sort(x+1,x+1+k,CMP2);            //按位置排好
  sort(y+1,y+1+n,CMP1);
  sort(y+1,y+1+l,CMP2);
  for(int i=1; i<k; i++)
    printf("%d ",x[i].id);
  printf("%d\n",x[k].id);
  for(int i=1; i<l; i++)
    printf("%d ",y[i].id);
  printf("%d\n",y[l].id);
  return 0;
}
