#include <bits/stdc++.h>
using namespace std;
const int MAXN =505;

bool w[MAXN][MAXN]; //w[i][j]代表i号摄像头能否看到j号摄像头
int camera[MAXN]; //camera[i]代表在i号位置上有没有摄像头
int ind[MAXN]; //ind[i]记录i号摄像头的入度（也就是有几个摄像头能看到i号摄像头）

int main()
{
  int n,k,s,x,ans=0;//ans记录可砸掉的摄像头个数
  cin >> n;
  for(int i=1; i<=n; i++)
  {
    cin >> s >> k;
    camera[s]=1;//标记a数组
    for(int j=1; j<=k; j++)
    {
      cin >> x;
      ind[x]++;//x号摄像头的入度++
      w[s][x]=1;
    }
  }
  for(int b=1; b<=100; b++)
    for(int i=1; i<=500; i++)
      if(camera[i]==1 && ind[i]==0)//如果i号摄像头入度为0
      {
        ans++;
        camera[i]=0;
        for(int j=1; j<=500; j++)
        {
          if(w[i][j])
            ind[j]--;
        }
      }
  ans==n? cout << "YES\n": cout << n-ans<<endl;
  return 0;
}
