//最长不下降子序列 - 贪心＋二分优化
#include<bits/stdc++.h>
using namespace std;

int a[100005],f[100005];

int main()
{
  freopen("LIS.in","r",stdin);
  freopen("LIS.out","w",stdout);
  int n,longest=0;
  memset(f,-1,sizeof(f));              //要初始化为-1
  cin>>n;
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
    if(f[longest]<=a[i])               //若插入的数≥f[longest]
      f[++longest]=a[i];               //将a[i]连接到最后
    else
    {
      int L=0,R=longest;
      while(L<=R)                      //二分查找合适的位置
      {
        int mid=(L+R)>>1;
        if(f[mid]<=a[i])
        {
          L=mid+1;
          if(f[L]>a[i])
            break;
        }
        else
          R=mid-1;
      }
      f[L]=a[i];                       //保存f[L]值
    }
  }
  cout<<longest<<endl;
  return 0;
}

