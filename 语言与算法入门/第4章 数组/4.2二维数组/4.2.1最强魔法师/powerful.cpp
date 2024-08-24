//最强魔法师
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("powerful.in","r",stdin);
  //freopen("powerful.out","w",stdout);
  int a[101][101];
  int m,n,row=0,colum=0;
  cin>>m>>n;
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
      cin>>a[i][j];
  int MaX=a[0][0];       //此处设最大值为a[0][0] 
  for(int i=0; i<m; i++)
    for(int j=0; j<n; j++)
      if(a[i][j]>MaX)
      {
        MaX=a[i][j];
        row=i;
        colum=j;
      }
  cout<<MaX<<" "<<row+1<<" "<<colum+1<<endl;
  return 0;
}
