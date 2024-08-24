#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=20;

int n,k,a[N];
ll f[N][65555];
bool Map[N][N];

ll Dfs(int d,int state,int pre)
{
  if(f[pre][state])                     //���仯
    return f[pre][state];
  if(d==n)
    return 1;
  ll ans=0;
  for(int i=1; i<=n; i++)               //ö��ĩβ��i
    if(Map[pre][i] && (state&(1<<i))==0)//���ĩβ�ɼ�i����iδ��
    {
      f[i][state|(1<<i)]=Dfs(d+1,state|(1<<i),i);
      ans+=f[i][state|(1<<i)];
    }
  return ans;
}

int main()
{
  //freopen("emmm.in","r",stdin);
  //freopen("emmm.out","w",stdout);
  scanf("%d%d",&n,&k);
  for(int i=1; i<=n; i++)
    scanf("%d",a+i);
  for(int i=0; i<=n; i++)
    Map[0][i]=Map[i][0]=1;
  for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++)
      if(abs(a[i]-a[j])>k)
        Map[i][j]=1;
  printf("%lld\n",Dfs(0,0,0));
  return 0;
}

