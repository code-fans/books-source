//蚯蚓
#include <bits/stdc++.h>
using namespace std;

int n,m,q,u,v,t,sum;
int a[100010];

struct queue  //手写队列
{
  int l,r,v[8000010];
  void push(int x)
  {
    v[++r]=x;
  }
  int front()
  {
    return v[l];
  }
  void pop()
  {
    l++;
  }
  bool empty()
  {
    return l>r?1:0;
  }
} p[3];

int Read(int Num=0)
{
  char C;
  for(; C<'0' || C>'9'; C=getchar());
  for(; C>='0' && C<='9'; C=getchar())
    Num=Num*10+C-'0';
  return Num;
}

int GetBig()//每次取3个队列中队首最大的元素进行切割
{
  for(int i=0; i<=2; i++)
  {
    if(p[i].empty())//如果当前队列空
      continue;
    if(i!=0 && !p[0].empty() && p[0].front()>p[i].front())
      continue;
    if(i!=1 && !p[1].empty() && p[1].front()>p[i].front())
      continue;
    if(i!=2 && !p[2].empty() && p[2].front()>p[i].front())
      continue;
    int x=p[i].front();
    p[i].pop();
    return x;
  }
}

int main()
{
  freopen("earthworm.in","r",stdin);
  freopen("earthworm.out","w",stdout);
  n=Read();
  m=Read();
  q=Read();
  u=Read();
  v=Read();
  t=Read();
  for(int i=1; i<=n; i++)
    a[i]=Read();
  sort(a+1,a+n+1);
  for(int i=n; i>=1; i--)
    p[0].push(a[i]);//初始队列p[0]由大到小排列
  p[0].l=p[1].l=p[2].l=1;//左边界为1
  for(int i=1; i<=m; i++) //m秒的操作
  {
    int x=GetBig();
    if(i%t==0)//输出1t,2t,3t时被切断的蚯蚓的长度
    {
      if(i!=t)
        printf(" ");
      printf("%d",x+sum);
    }
    p[1].push((long long)(x+sum)*u/v-sum-q);//砍成两段的前半段
    p[2].push((x+sum)-(long long)(x+sum)*u/v-sum-q);//砍成两段的后半段
    sum+=q;//累加增长的q,注意前面砍断的两段已经减过一次q
  }
  printf("\n");
  for(int i=1; !p[0].empty()||!p[1].empty()||!p[2].empty(); i++)
  {
    int x=GetBig();
    if(i%t==0)
    {
      if(i!=t)
        printf(" ");
      printf("%d",x+sum);
    }
  }
  printf("\n");
  return 0;
}

