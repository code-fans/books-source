//�˻���� - �Ǹ߾����㷨
#include <bits/stdc++.h>
using namespace std;

string s;
unsigned long long f[41][41];

unsigned long long g(int L,int R)
{
  int ans=s[L]-'0';
  for(int i=L+1; i<=R; i++)
    ans=ans*10+(s[i]-'0');
  return ans;
}

int main()
{
  //freopen("product.in","r",stdin);
  //freopen("product.out","w",stdout);
  int n,k;
  cin>>n>>k>>s;
  for(int i=0; i<n; i++)
    f[i][0]=g(0,i);
  for(int i=1; i<=k; i++)                  //ö�ٳ˺�
    for(int j=i; j<=n; j++)                //ö���ַ���
      for(int h=j; h>=i; h--)              //ö���и��
        f[j][i]=max(f[j][i],f[h-1][i-1]*g(h,j));
  cout<<f[n-1][k]<<endl;
  return 0;
}
