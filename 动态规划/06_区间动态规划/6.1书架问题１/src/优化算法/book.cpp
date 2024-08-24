//书架 
#include <bits/stdc++.h>
using namespace std;
#define MAX 0x3f3f3f3f                    //想想为什么不取0x7fffffff？ 

int w[10005],l[10005],F[10005],sum[10005];//w为书宽度，l为书高度
int n,t,sw;

int Opt(int L,int R)                      //计算书在区间(L,R)的最大高度
{
  int W=0,h=0;
  for(int i=L; i<=R; i++)
    h=max(l[i],h) ;
  return sum[R]-sum[L-1]>sw ? MAX : h;    //总宽度不能超出宽度限定
}

int main()
{
  //freopen("book.in","r",stdin);
  //freopen("book.out","w",stdout);
  scanf("%d%d",&n,&sw);
  for(int i = 1; i <= n; i++)
  {
    scanf("%d%d",&w[i],&l[i]);
    sum[i]=sum[i-1]+w[i];                 //前缀和统计区间书的宽度
  }
  for(int i = 1; i <= n; i++)             //逐一处理每一本书
  {
    F[i] = MAX;
    for(int j = i-1; j>=0; j--)
    {
      if(Opt(j+1,i)>sw)
        break;
      F[i]=min(F[i],F[j]+Opt(j+1,i));
    }
  }
  printf("%d\n",F[n]);
  return 0;
}

