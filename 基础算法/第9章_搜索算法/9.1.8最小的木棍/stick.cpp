#include<bits/stdc++.h>
using namespace std;

bool used[100];
int n,j[100],sum,tot,len;

int Cmp(int a,int b)
{
  return a>b;
}

bool DFS(int l,int k,int le)//已拼好的木棍数,拼到第k个木棍,剩余长度
{
  if(l==tot)
    return 1;
  if(le==0)
    if(DFS(l+1,1,len))
      return 1;
  for(int i=k; i<=n; i++)//尝试剩下的木棍
    if(used[i]==0 && j[i]<=le)
    {
      used[i]=1;
      if(DFS(l,i+1,le-j[i]))
        return 1;
      used[i]=0;
      if(le==j[i]||le==len)
        break;
      while(j[i+1]==j[i])
        i++;
    }
  return 0;
}

int main()
{
  //freopen("stick.in","r",stdin);
  //freopen("stick.out","w",stdout);
  scanf("%d",&n);
  while(n!=0)
  {
    memset(used,0,sizeof(used));
    sum=0;
    for(int i=1; i<=n; i++)
    {
      scanf("%d",&j[i]);
      sum+=j[i];
    }
    sort(j+1,j+n+1,Cmp);
    for(int i=j[1]; i<=sum; i++)//枚举可能的长度
      if(sum%i==0)              //如果能平分
      {
        len=i;                  //可能的木棍长度
        tot=sum/i;              //木棍数量
        if(DFS(0,1,len))
        {
          printf("%d\n",len);
          break;
        }
      }
    scanf("%d",&n);
  }
  return 0;
}
