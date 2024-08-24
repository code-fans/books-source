/*  种类并查集+离散化
由于数列中只有 0或1，那么使先开一个s数组表示前缀和，那么：
s[j]-s[i-1]是奇数时，则 [i..j]区间中的1的个数为奇数，反之，为偶数
对于区间[l,r]，如果说[l,r][l,r]有奇数个1，那么sum{l-1}和sum r的前缀和奇偶性必定不相等。
偶数同理
所以分为奇偶两个种类,
每遇到一个回答，我们先判断当前两个区间端点的奇偶性：
①对于“even”回答，若左端点在右端点“敌人”的集合中或右端点在左端点“敌人”的集合中，则回答错误
②对于“odd”回答，若左端点在右端点“朋友”的集合中或右端点在左端点“朋友”的集合中，则回答错误
如果回答是正确的，那我们就进行合并操作：
①对于“even”，我们将左端点和右端点的“朋友”、“敌人”集合分别合并
②对于“odd”，我们将左端点的“朋友”与右端点的“敌人”合并，将左端点的“敌人”与右端点的“朋友”合并
*/
#include <bits/stdc++.h>
using namespace std;
int n,m,tot,b[100010],father[100010];

struct node
{
  int u,v;
  string op;
} a[100010];

inline int Find(int x)
{
  return father[x]==x?x:father[x]=Find(father[x]);
}

int main()
{
  freopen("parity.in","r",stdin);
  freopen("parity.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1; i<=m; i++)
  {
    cin>>a[i].u>>a[i].v>>a[i].op;
    b[++tot]=a[i].u;                //离散化的准备
    b[++tot]=a[i].v;
  }
  sort(b+1,b+1+tot);                            //STL实现离散化的三部曲
  int size=unique(b+1,b+1+tot)-(b+1);           //unique返回最后一个元素地址
  for(int i=1; i<=m; i++)
  {
    a[i].u=lower_bound(b+1,b+1+size,a[i].u-1)-b;//找到它的位置
    a[i].v=lower_bound(b+1,b+1+size,a[i].v)-b;
  }
  for(int i=size<<1; i>=1; i--)                 //两倍并查集
    father[i]=i;
  for(int i=1; i<=m; i++)
    if(a[i].op=="even")                         //如果回答是偶数个
    {
      if(Find(a[i].u)==Find(a[i].v+size) || Find(a[i].u+size)==Find(a[i].v))//判断奇偶性
      {
        printf("%d\n",i-1);
        return 0;
      }
      father[Find(a[i].u)]=Find(a[i].v);
      father[Find(a[i].u+size)]=Find(a[i].v+size);
    }
    else
    {
      if(Find(a[i].u)==Find(a[i].v) || Find(a[i].u+size)==Find(a[i].v+size))
      {
        printf("%d\n",i-1);
        return 0;
      }
      father[Find(a[i].u)]=Find(a[i].v+size);
      father[Find(a[i].u+size)]=Find(a[i].v);
    }
  printf("%d\n",m);
  return 0;
}
