//赶作业
#include <bits/stdc++.h>
using namespace std;
#define MAX 1002

struct node
{
  int day,num;
} c[MAX];
int flag[MAX];

int Cmp(const node &a,const node &b)
{
  return (a.num!=b.num?b.num<a.num:a.day<b.day);
}

int main()
{
  freopen("homework.in","r",stdin);
  freopen("homework.out","w",stdout);
  int t,n,sum,i,j;
  scanf("%d",&t);
  while(t--)
  {
    int sum=0;
    memset(flag,0,sizeof(flag));
    scanf("%d",&n);
    for(i=0; i<n; i++)
      scanf("%d",&c[i].day);
    for(i=0; i<n; i++)
      scanf("%d",&c[i].num);
    sort(c,c+n,Cmp);
    for(i=0; i<n; i++)
    {
      for(j=c[i].day; j>0; j--)      //从最后的期限开始考虑前几天有没有被安排
      {
        if(flag[j]==0)               //如果第j天有空余
        {
          flag[j]=1;                 //标记该天被使用
          break;
        }
      }
      if(j==0)                       //如果一直到结束都没有空余时间，只能扣分
        sum+=c[i].num;
    }
    printf("%d\n",sum);
  }
  return 0;
}

