//����ҵ
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
      for(j=c[i].day; j>0; j--)      //���������޿�ʼ����ǰ������û�б�����
      {
        if(flag[j]==0)               //�����j���п���
        {
          flag[j]=1;                 //��Ǹ��챻ʹ��
          break;
        }
      }
      if(j==0)                       //���һֱ��������û�п���ʱ�䣬ֻ�ܿ۷�
        sum+=c[i].num;
    }
    printf("%d\n",sum);
  }
  return 0;
}

