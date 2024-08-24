/*并查集优化
这题不能用dp来做。因为最晚销售时间是明天的物品也可以放在今天来卖，而且题目中的最晚销售时间可以是断续的，所以会浪费很多计算而且十分复杂。
如果购买不冲突，那么全部买下来就可以了。存在冲突，就需要取舍。显然在冲突的时候
我们选择价格高的更优，如此就可以用贪心的算法按照获利p从大到小排序。
处理的时候选择最后的一个不冲突点。因为每次卖一个，时间上不能有冲突
建立一个关于“天数”的并查集
起初每一天各自构成一个集合。对于每个商品，若它在d天之后过期，就在并查集中查询d的树根，
标记为d。如果d大于0，则把该商品安排在第d天卖出，合并d和d-1，答案累加该商品的利润。
用并查集实现链表的作用，在O(1)的时间快速找到不冲突点
而1到t时间段内空闲时间用并查集来维护
坑点：不一定非要等到在最后期限才能卖出去， 可以提前卖。（但是能晚卖就晚卖）
例如： （用f[i] = i 初始化） 给出两组数据 30 5, 20 5 一开始先遇到30 5 这组数据
（因为30大 ， 在前面）此时 5的祖先是5 > 0 所以这个可以获得， 并且令5的祖先减一，
 也就是4。 然后看第二组数据， 此时5的祖先是4 > 0所以也可以获得。
*/
#include <bits/stdc++.h>
using namespace std;
const int MAXN=10010;
int father[MAXN];//保存在0到i内还剩的空余时间

struct Node
{
  int p,d;
} node[MAXN];

bool Cmp(Node a,Node b)//按p从大到小排序。d没有关系
{
  return a.p>b.p;
}

int Find(int x)
{
  return father[x]==-1?x:father[x]=Find(father[x]);
}

int main()
{
  freopen("supermarket.in","r",stdin);
  freopen("supermarket.out","w",stdout);
  int n;
  while(scanf("%d",&n)==1)
  {
    memset(father,-1,sizeof(father));
    for(int i=0; i<n; i++)
      scanf("%d%d",&node[i].p,&node[i].d);
    sort(node,node+n,Cmp);                  //按价值由大到小排序
    int ans=0;
    for(int i=0; i<n; i++)
    {
      int t=Find(node[i].d);                //当前商品还剩下的时间
      if(t>0)                               //如果还有空闲时间
      {
        ans+=node[i].p;
        father[t]=t-1;                      //空闲时间减1,即链到上一天
      }
    }
    printf("%d\n",ans);
  }
  return 0;
}
