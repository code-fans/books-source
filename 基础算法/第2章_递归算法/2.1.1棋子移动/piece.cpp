//Æå×ÓÒÆ¶¯
#include <bits/stdc++.h>
using namespace std;

void Move(int k)
{
  if(k==4)
  {
    printf("4,5-->9,10\n");
    printf("8,9-->4,5\n");
    printf("2,3-->8,9\n");
    printf("7,8-->2,3\n");
    printf("1,2-->7,8\n");
  }
  else
  {
    cout<<k<<','<<k+1<<"-->"<<2*k+1<<','<<2*k+2<<endl;
    cout<<2*k-1<<','<<2*k<<"-->"<<k<<','<<k+1<<endl;
    Move(k-1);
  }
}

int main()
{
  freopen("piece.in","r",stdin);
  freopen("piece.out","w",stdout);
  int N;
  cin>>N;
  Move(N);
  return 0;
}
