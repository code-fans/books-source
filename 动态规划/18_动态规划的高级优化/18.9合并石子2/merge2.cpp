//合并石子2 - 四边形不等式优化
#include <bits/stdc++.h>
using namespace std;
#define N 2005

int n,Num,a[N],sum[N];
int S[N][N],Fmin[N][N],Fmax[N][N];

void Init()
{
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
  {
    scanf("%d",&a[i]);
    a[n+i]=a[i];                                   //环转成双倍长的链
    sum[i]=sum[i-1]+a[i];                          //计算前序和
    S[i][i]=i;
    S[n+i][n+i]=n+i;
  }
  Num= n<<1;                                       //即2*n
  for(int i=n+1; i<=Num; i++)                      //计算后半段链的前序和
    sum[i]=sum[i-1]+a[i];
}

int main()
{
  freopen("merge2.in","r",stdin);
  freopen("merge2.out","w",stdout);
  Init();
  for(int i=Num-1; i>0; i--)
    for(int j=i+1; j<=Num; j++)
    {
      int t=0x3fffffff,Min=0;
      Fmax[i][j]=max(Fmax[i][j-1],Fmax[i+1][j])+sum[j]-sum[i-1];
      for(int k=S[i][j-1]; k<=S[i+1][j]; k++)      //缩小取值范围求最小值
      {
        int temp=Fmin[i][k]+Fmin[k+1][j]+(sum[j]-sum[i-1]);
        if(temp<t)
        {
          t=temp;
          Min=k;
        }
      }
      S[i][j]=Min;
      Fmin[i][j]=t;
    }
  int Ans1=0,Ans2=0x3fffffff;
  for(int i=1; i<=n; i++)
  {
    Ans1=max(Ans1,Fmax[i][i+n-1]);
    Ans2=min(Ans2,Fmin[i][i+n-1]);
  }
  printf("%d\n%d\n",Ans2,Ans1);
  return 0;
}

