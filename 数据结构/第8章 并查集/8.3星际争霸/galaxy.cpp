//星际争霸
#include<bits/stdc++.h>
using namespace std;
const int MAX=30010;
int p[MAX],sum[MAX],cnt[MAX];     //sum[i]:i到根的长度前缀和,cnt[]:队列战舰数

int Father(int x)
{
  if(p[x]==x)
    return x;
  int px=Father(p[x]);            //先找到根(它的祖先),否则长度计算会错误
  sum[x]+=sum[p[x]];              //维护x到根的长度前缀和：+它祖先到根结点的距离
  return p[x]=px;                 //路径压缩并返回父结点即p[x]
}

void Union(int i,int j)
{
  int RootI=Father(i);
  int RootJ=Father(j);
  if(RootI==RootJ)
    return;
  p[RootI]=RootJ;                 //i队列指向j队列的根(路径压缩)
  sum[RootI]+=cnt[RootJ];         //计算i队列首到根结点的距离
  cnt[RootJ]+=cnt[RootI];         //队列合并，战舰数增加
}

int main()
{
  //freopen("galaxy.in","r",stdin);
  //freopen("galaxy.out","w",stdout);
  int N,x,y;
  scanf("%d\n",&N);
  for(int i=1; i<=30000; i++)
    p[i]=i,cnt[i]=1;              //每列根结点初始是它自己，战舰数为1
  while(N--)
  {
    char s;
    scanf("%c%d %d%*c",&s,&x,&y);
    if(s=='M')
      Union(x,y);
    else
      printf("%d\n",Father(x)^Father(y)?-1:abs(sum[x]-sum[y])-1);
  }
  return 0;
}

