//互质组
#include<bits/stdc++.h>
using namespace std;

int n,Ans=0x3f3f3f3f;
bool flag;
int a[110],Group[110];         //a[]保存数,Group[i]保存a[i]分到哪一组

int GCD(int a,int b)
{
  return a%b==0?b:GCD(b,a%b);
}

void DFS(int now,int group)    //搜到了第now个数，现在有group个集合
{
  if(now>n)                    //搜索完成，取最小值，退出
  {
    Ans=min(Ans,group);
    return;
  }
  for(int g=1; g<=group; g++)  //尝试加到某一组里
  {
    flag=true;
    for(int j=1; j<now; j++)   //当前这个now和之前的集合一个个进行尝试
    {
      if(Group[j]==g)          //如果第j个数分在g组
        if(GCD(a[now],a[j])!=1)//那么就比较now是否和该组的数不为互质数
        {
          flag=false;          //不互质就没必要继续比下去了
          break;               //跳出
        }
    }
    if(flag)                   //如果可以加到g组
    {
      Group[now]=g;            //把第now个数保存到第g组
      DFS(now+1,group);        //搜索下一个数，组数不变
      Group[now]=0;            //回溯
    }
  }
  Group[now]=group+1;          //now不加到任何集合，另开一个集合
  DFS(now+1,group+1);          //进行下一次查找
  Group[now]=0;                //回溯
}

int main()
{
  freopen("prime.in","r",stdin);
  freopen("prime.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; i++)
    cin>>a[i];
  DFS(1,1);                     //从第一个数，只有一组开始
  cout<<Ans<<endl;
  return 0;
}

