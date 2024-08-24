//盒子与球
//设f[i,j]表示将前i个球放入j个盒子中
//将前i-1个球放入j-1个盒子里，再把第i个球单独放入一个盒子里
//将前i-1个球放入j个盒子里，再把第i个球任意放入一个盒子里
//得递推式f[i,j]=f[i-1,j-1]+j*f[i-1,j]
//这实际上是第二类stirling数
#include <bits/stdc++.h>
using namespace std;

string f[102][102];
const int MAXN=1005;

string Add(string x,string y)
{
  string ans;
  int a[MAXN]= {0},b[MAXN]= {0};
  int la=x.size();
  int lb=y.size();
  for(int i=0; i<la; i++)
    a[la-1-i]=x[i]-'0';
  for(int i=0; i<lb; i++)
    b[lb-1-i]=y[i]-'0';
  int len=max(la,lb);
  for(int i=0; i<len; i++)
  {
    a[i]+=b[i];
    a[i+1]+=a[i]/10;
    a[i]%=10;
  }
  for(; a[len]; len++);
  for(int i=len-1; i>=0; i--)
    ans+=a[i]+'0';
  return ans;
}

string Times(string x,int y)
{
  string ans;
  int la=x.size();
  int cur[MAXN]= {0};
  for(int i=la-1; i>=0; i--)
    cur[la-i-1]=x[i]-'0';
  int w=0;
  for(int i=0; i<la; i++)
  {
    cur[i]=cur[i]*y+w;
    w=cur[i]/10;
    cur[i]=cur[i]%10;
  }
  while(w)
    cur[la++]=w%10,w/=10;
  la--;
  while(la>=0)
    ans+=cur[la--]+'0';
  return ans;
}

int main()
{
  //freopen("ball.in","r",stdin);
  //freopen("ball.out","w",stdout);
  f[0][0]="1";
  f[1][0]="0";
  f[1][1]="1";
  for(int i=2; i<=100; i++)
    for(int j=1; j<=i; j++)
      f[i][j]=Add(f[i-1][j-1],Times(f[i-1][j],j));
  for(int i=0,m,n; cin>>m>>n; i++)
    cout<<(m<n? "0":f[m][n])<<"\n";
  return 0;
}
