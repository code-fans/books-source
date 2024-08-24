//预算
//考虑到每个主件最多只有2个附件,所以可以考虑用01背包的方法
//枚举主件,那么转移状态的时候就有这几种情况:
//1.只选主件和不选
//2.选一个主件的同时选一个附件
//3.选一个主件的同时选另外一个附件
//4.选一个主件的同时选两个附件
#include <bits/stdc++.h>
using namespace std;

int mv[40000],mvp[40000],fv[40000][3],fvp[40000][3],f[40000];

int main()
{
  //freopen("budget.in","r",stdin);
  //freopen("budget.out","w",stdout);
  int m,n;
  cin>>n>>m;
  for(int i=1,v,p,q; i<=m; i++)
  {
    cin>>v>>p>>q;
    if(!q)                             //如果是主件
    {
      mv[i]=v;
      mvp[i]=v*p;                      //主件价值与重要度乘积
    }
    else                               //如果是附件
    {
      fv[q][++fv[q][0]]=v;             //fv[q][0]统计附件个数
      fvp[q][fv[q][0]]=v*p;
    }
  }
  for(int i=1; i<=m; i++)              //枚举物品
    for(int j=n; j>=mv[i]; j--)        //01背包优化模板
    {
      f[j]=max(f[j],f[j-mv[i]]+mvp[i]);//情况1：只要主件和不要主件
      if(j>=mv[i]+fv[i][1])            //情况2：主件和附件1和上面选出的较大值比较
        f[j]=max(f[j],f[j-mv[i]-fv[i][1]]+mvp[i]+fvp[i][1]);
      if(j>=mv[i]+fv[i][2])            //情况3：主件和附件2和上面选出的较大值比较
        f[j]=max(f[j],f[j-mv[i]-fv[i][2]]+mvp[i]+fvp[i][2]);
      if(j>=mv[i]+fv[i][1]+fv[i][2])   //情况4：全部都要
        f[j]=max(f[j],f[j-mv[i]-fv[i][1]-fv[i][2]]+mvp[i]+fvp[i][1]+fvp[i][2]);
    }
  cout<<f[n]<<endl;                    //输出在价值为n时能得到的最大值
  return 0;
}
