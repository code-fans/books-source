//快餐问题
#include<bits/stdc++.h>
using namespace std;

int a,b,c,p1,p2,p3,n,ans;
int f[11][101][101],t[11];

int main()
{
  freopen("FastFood.in","r",stdin);
  freopen("FastFood.out","w",stdout);
  cin>>a>>b>>c>>p1>>p2>>p3>>n;
  for(int i=1; i<=n; i++)
    cin>>t[i];
  int limit=min(100/a,min(100/b,100/c));                //最多生产套数
  memset(f,-1,sizeof(f));
  f[0][0][0]=0;
  for(int i=1; i<=n; i++)                               //枚举生产线
    for(int j=0; j<=limit*a; j++)
      for(int k=0; k<=limit*b; k++)
        for(int j1=0; j1<=j; j1++)
          for(int k1=0; k1<=k; k1++)
            if(f[i-1][j-j1][k-k1]!=-1 && t[i]>=j1*p1-k1*p2)//有值且有时间
              if(f[i][j][k] >= limit*c)                  //大于上限，退出循环
                j1=j+1;                                //退出第4重循环的设定
              else
                f[i][j][k]=max(f[i][j][k],f[i-1][j-j1][k-k1]+(t[i]-j1*p1-k1*p2)/p3);
  for(int i=0; i<=limit*a; i++)
    for(int j=0; j<=limit*b; j++)
      ans=max(ans,min(i/a,min(j/b,f[n][i][j]/c)));//取A,B.C最少的套数来比较
  cout<<ans<<endl;
}

