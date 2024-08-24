//零和游戏－hash表
#include <bits/stdc++.h>
#define MAX 1000000000
#define size 20345677
#define key 745
using namespace std;

int n,a[4040],b[4040],c[4040],d[4040],ans;
int Hash[size],sum[size];

void Insert(int num)
{
  int tmp=num;
  num=(num+MAX)%size;
  while(Hash[num]!=MAX && Hash[num]!=tmp)     //寻找合适的存储位置
    num=(num+key)%size;
  Hash[num]=tmp;
  sum[num]++;
}

int Find(int num)
{
  int tmp=num;
  num=(num+MAX)%size;
  while(Hash[num]!=MAX && Hash[num]!=tmp)
    num=(num+key)%size;
  if(Hash[num]==MAX)
    return 0;
  else
    return sum[num];
}

int main()
{
  freopen("zero.in","r",stdin);
  freopen("zero.out","w",stdout);
  cin>>n;
  for(int i=0; i<n; i++)
    cin>>a[i]>>b[i]>>c[i]>>d[i];
  for(int i=0; i<size; i++)
    Hash[i]=MAX;
  for(int i=0; i<n; i++)                       //前两列的和
    for(int j=0; j<n; j++)
      Insert(a[i]+b[j]);
  for(int i=0; i<n; i++)                       //后两列和的相反数
    for(int j=0; j<n; j++)
      ans+=Find(-(c[i]+d[j]));
  cout<<ans<<endl;
  return 0;
}

