//和谐俱乐部 - 二分优化
#include<bits/stdc++.h>
using namespace std;

struct node
{
  int a, b;
} man[100009];


bool Cmp (node x, node y)
{
  return (x.a!=y.a? x.a<y.a:x.b>y.b);
}

int f[100005];

int main()
{
  ////freopen("Beautiful.in","r",stdin);
  ////freopen("Beautiful.out","w",stdout);
  int n,longest=1;
  scanf("%d", &n);
  for(int i=1; i<=n; ++i)
    scanf("%d%d", &man[i].a,&man[i].b);
  sort (man+1, man+1+n, Cmp);
  f[1]=man[1].b;
  for(int i=2; i<=n; ++i)
  {
    if(f[longest]<man[i].b)
      f[++longest]=man[i].b;
    else
    {
      int L=0,R=longest;
      while(L<=R)                      //二分查找
      {
        int mid=(L+R)>>1;
        if(f[mid]<man[i].b)
        {
          L=mid+1;
          if(f[mid+1]>man[i].b)
            break;
        }
        else
          R=mid-1;
      }
      f[L]=man[i].b;
    }
  }
  printf("%d\n", longest);
  return 0;
}

