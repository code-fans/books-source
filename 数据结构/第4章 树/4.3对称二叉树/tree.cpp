//对称二叉树
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000001;

int lson[MAXN],rson[MAXN],m,node[MAXN],ans=1;
bool OK=1;//标记结构是否对称

inline int Read()                         //快速读入整数
{
  int x=0,f=1;
  char ch=getchar();
  for(; ch<'0' || ch>'9'; ch=getchar())   //getchar比scanf大约快十倍
    if(ch=='-')
      f=-1;
  for(; ch>='0' && ch<='9'; ch=getchar())
    x=(x<<3)+(x<<1)+ch-'0';               //位运算优化即x*8+x*2=x*10
  return x*f;
}

int Dfs(int x,int y,int s)//找对称二叉树 s代表节点数 x,y为正在访问的节点标号
{
  if((x==-1 && y==-1)) //判断是否有节点
    return 0;
  if((x==-1||y==-1)  || node[x]!=node[y])//判断是否对称
  {
    OK=0;
    return 0;
  }
  return Dfs(lson[x],rson[y],2)+Dfs(rson[x],lson[y],2)+s; //递归：返回值为节点数
}

int main()
{
  //freopen("tree.in","r",stdin);
  //freopen("tree.out","w",stdout);
  m=Read();
  for(int i=1; i<=m; i++)
    node[i]=Read();
  for(int i=1; i<=m; i++)
    lson[i]=Read(),rson[i]=Read();
  for(int i=1; i<=m; i++)
  {
    int sum=Dfs(lson[i],rson[i],3);//直接从左孩子和右孩子开始,所以初始节点为三个
    if(sum>ans && OK)
      ans=sum;
    OK=1;
  }
  cout<<ans<<endl;
  return 0;
}

