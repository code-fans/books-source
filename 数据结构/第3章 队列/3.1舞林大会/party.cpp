//舞林大会
#include <bits/stdc++.h>
using namespace std;
const int MAX=1005;
int a[MAX],b[MAX];                            //男选手队列及女选手队列

int main()
{
  //freopen("party.in","r",stdin);
  //freopen("party.out","w",stdout);
  int n,m,k;
  cin>>m>>n>>k;
  int front1=0,real1=m-1,front2=0,real2=n-1;
  for(int i=0; i<m; ++i)                      //初始化编号
    a[i]=i+1;
  for(int i=0; i<n; ++i)
    b[i]=i+1;
  for(int i=1; i<k; ++i)
  {
    a[++real1%MAX]=a[front1++%MAX];           //队首出列后排到队尾去
    b[++real2%MAX]=b[front2++%MAX];
  }
  cout<<a[front1%MAX]<<" "<<b[front2%MAX]<<endl;
  return 0;
}

