//���������
#include <bits/stdc++.h>
using namespace std;
int a[22], b[22], p[22];
bool vis[22];
int n,k,sum,ans;

bool Isprime(int n)                     //�ж�����
{
  if (n<=1)
    return false;
  for (int i=sqrt(n); i>=2; i--)
    if (n%i==0)
      return false;
  return true;
}

void Dfs(int index)
{
  if (index==k+1)
  {
    if (Isprime(sum))
      ans++;                            //���Ƿ������������
    return ;
  }
  for (int i=1; i<=n; i++)
    if (vis[i]==false  &&  i>p[index-1])//��֤Ԫ����С�������У���ֹ�ظ�
    {
      p[index] = i;
      vis[i] = true;
      sum+=a[i];
      Dfs(index+1);
      vis[i] = false;
      sum-=a[i];//�ָ�
    }
}

int main()
{
  //freopen("c.in","r",stdin);
  //freopen("c.out","w",stdout);
  cin>>n>>k;
  for (int i=1; i<=n; i++)
    cin>>a[i],p[i]=i;
  Dfs(1);
  cout<<ans<<endl;
  return 0;
}

