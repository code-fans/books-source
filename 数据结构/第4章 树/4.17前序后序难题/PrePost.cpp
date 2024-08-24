//前序后序难题
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30;

int C[MAXN][MAXN];
char pre[MAXN],post[MAXN];
int n,m;

void Init()                           //预处理C(m,n)的值
{
  for(int i=0; i<MAXN; i++)
    C[i][0] = 1;
  for(int i=1; i<MAXN; i++)
    for(int j=1; j<=i; j++)
      C[i][j] = C[i-1][j-1] + C[i-1][j];
}

long long DFS(int L1,int R1,int L2,int R2)
{
  if(L1==R1)
    return 1;
  int son=0;                          //统计有多少个子树
  long long ans=1;
  int root=L2;                        //子树根从L2开始寻找
  for(int l=L1+1; l<=R1;)             //L1+1是子树根
  {
    for(; root<R2; root++)            //扫描寻找子树的根
      if(pre[l]==post[root])          //找到了子树根
      {
        son++;
        break;
      }
    ans*= DFS(l, l+root-L2, L2, root);//递归找到的这一段子树
    l+=root-L2+1;                     //下一个子树根
    L2=++root;                        //下一个子树根从L2位置开始查找
  }
  return ans*C[m][son];
}

int main()
{
  //freopen("PrePost.in","r",stdin);
  //freopen("PrePost.out","w",stdout);
  Init();
  while(scanf("%d",&m) && m)
  {
    scanf("%s %s",pre,post);
    cout<<DFS(0,strlen(pre)-1,0,strlen(pre)-1)<<endl;
  }
  return 0;
}
