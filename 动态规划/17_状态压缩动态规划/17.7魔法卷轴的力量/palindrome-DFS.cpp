//��һ����������ȥ
#include<bits/stdc++.h>
using namespace std;
const int MAXN=16;
const int INF=1<<30;

char a[MAXN+1];
int cycle[1<<MAXN];            //�Ƿ��ǻ���
int dp[1<<MAXN];               //i״̬��Ҫ������ɾ������
int n;

int DFS(int x)
{
  if(dp[x]!=-1)                //���仯����
    return dp[x];
  int ans=INF;
  for(int i=x; i>=1; --i)      //ö�ٿ��ܵ�״̬
    if(cycle[i] && (x|i==x))   //iΪ����������i��x������
      ans=min(DFS(x-i)+1,ans);
  return dp[x]=ans;
}

int s(int x)
{
  for(int i=x; i>=1; (--i)&=x) //ö�ٿ��ܵ�״̬
    cout<<i<<' ';
}

bool Check(int x)
{
  char str[MAXN];
  int cnt=0;
  for(int i=0; i<n; i++)
    if(x>>i&1)
      str[cnt++]=a[n-i-1];
  for(int l=0,r=cnt-1; l<r; ++l,--r)
    if(str[l]!=str[r])
      return 0;
  return 1;
}

int main()
{

  int t;
  cin>>t;
  while(t--)
  {
    cin>>a;
    n=strlen(a);
    memset(cycle,0,sizeof(cycle));
    memset(dp,-1,sizeof(dp));
    for(int i=0; i<(1<<n); i++)
      if(Check(i))
      {
        cycle[i]=1;
        dp[i]=1;
      }
    dp[0]=0;
    printf("%d\n",DFS((1<<n)-1));
  }
  return 0;
}
