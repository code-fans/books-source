//凸多边形三角划分－高精度
#include <bits/stdc++.h>
using namespace std;

int n,cnt;
int mid[51][51];
string a[51],f[51][51];
struct node
{
  int x,y,z;
} t[51];

bool Cmp(node a,node b)
{
  return a.x==b.x? (a.y==b.y?a.z<b.z:a.y<b.y) : (a.x<b.x);
}

bool Bigger(string x,string y)    //判断x是否大于等于y
{
  return (x.size()==y.size() && x>=y || x.size()>y.size());
}

string Add(string a,string b)
{
  string ans(max(a.size(),b.size())+1,'0');
  for(int i=ans.size()-1,l1=a.size(),l2=b.size(); i>=0; i--)
  {
    int t=(ans[i]-'0')+(l1<1?0:a[--l1]-'0')+(l2<1?0:b[--l2]-'0');
    ans[i]=t%10+'0';
    ans[i-1]=(ans[i-1]-'0'+t/10)+'0';
  }
  for(; ans[0]=='0' && ans.size()>1; ans.erase(0,1));
  return ans;
}

string Mul(string a,string b)
{
  string ans(a.size()+b.size(),'0');
  for(int i=b.size()-1; i>=0; i--)
    for(int j=a.size()-1; j>=0; j--)
    {
      int t=(ans[i+j+1]-'0')+(b[i]-'0')*(a[j]-'0');
      ans[i+j+1]=t%10+'0';
      ans[i+j]=(ans[i+j]-'0'+t/10)+'0';
    }
  for(; ans[0]=='0' && ans.size()>=1; ans.erase(0,1));
  return ans;
}

string Dp()
{
  for(int i=n-2; i>=1; i--)
    for(int j=i+2; j<=n; j++)
      for(int k=i+1; k<j; k++)
      {
        string A=Add(f[i][k],f[k][j]);
        string B=Mul(a[i],a[j]);
        string C=Mul(B,a[k]);
        string D=Add(A,C);
        if(Bigger(f[i][j],D) || f[i][j]=="0")
        {
          f[i][j]=D;
          mid[i][j]=k;
        }
      }
  return f[1][n];
}

void GetTriangle(int l, int r)
{
  if (r-l<2)
    return;
  t[++cnt].x=l;
  t[cnt].y=mid[l][r];
  t[cnt].z=r;
  GetTriangle(l,mid[l][r]);
  GetTriangle(mid[l][r],r);
}

int main()
{
  //freopen("Triangle.in","r",stdin);
  //freopen("Triangle.out","w",stdout);
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    cin>>a[i];
  for(int i=0; i<=50; i++)
    for(int j=0; j<=50; j++)
      f[i][j]="0";
  cout<<Dp()<<endl;
  GetTriangle(1, n);
  sort(t+1, t+cnt+1, Cmp);
  for (int i=1; i<=cnt; i++)
    printf("%d %d %d%c", t[i].x, t[i].y, t[i].z,i==cnt?'\n':',');
  return 0;
}
