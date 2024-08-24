//互质组-枚举
#include <bits/stdc++.h>
using namespace std;

int n,a[20],Group[20],Ans=1;

int GCD(int a,int b)
{
  return a%b==0 ? b : GCD(b,a%b);
}

int main()
{
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  for(int i=0; i<20; i++)
    Group[i]=1;
  scanf("%d",&n);
  for(int i=1; i<=n; i++)
    scanf("%d",&a[i]);
  Group[1]=a[1];
  for(int i=2,g; i<=n; i++)      //枚举每个数
  {
    for(g=1; g<=Ans; g++)        //枚举每一组，能加就加
      if(GCD(a[i],Group[g])==1)
      {
        Group[g]*=a[i];
        break;
      }
    if(g-1==Ans)                 //如果加不进去
      Group[++Ans]=a[i];         //自建一组
  }
  printf("%d\n",Ans);
  return 0;
}
