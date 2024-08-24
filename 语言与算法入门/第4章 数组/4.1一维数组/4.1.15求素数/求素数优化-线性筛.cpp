//欧拉线性筛
#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100001;

bool a[MAXN];                   //a[i]=0表示i是质数
int prime[MAXN/3], Count;       //prime[N]保存质数,Count:找到的质数个数

int main()
{
  for(int i=2; i<MAXN; i++)
  {
    if(a[i]==0)
      prime[Count++] = i;       //质数依次存起来
    for(int j=0; j<Count && i*prime[j]<MAXN; j++)
    {
      a[i*prime[j]]=1;
      if(i%prime[j] == 0)       //此处是优化的关键
        break;                  //保证每个合数被它最小的质因数筛去
    }
  }
  for(int i=0; i<Count-1; i++)
    cout<<prime[i]<<' ';
  cout<<prime[Count-1]<<endl;
  return 0;
}
