//N皇后问题—位运算 
#include <bits/stdc++.h>
using namespace std;

int upperlim,sum,n;

void Test(int row,int ld,int rd)
{
  if(row!=upperlim)                     //未填满，即不为11111111时
  {
    int pos=upperlim & ~(row | ld | rd);//取反后得到所有可以放的位置
    while(pos!=0)
    {
      int p=pos & -pos;                 //取出最右边的1进行尝试
      pos-=p;                           //将该位置的P从pos中移除
      Test(row+p,(ld+p)<<1,(rd+p)>>1);
    }
  }
  else
    sum++;
}

int main()
{
  //freopen("queen.in","r",stdin);
  //freopen("queen.out","w",stdout);
  cin>>n;
  upperlim=(1 << n)-1;//结果为11111111
  Test(0,0,0);        //参数代表纵列，左对角线，右对角线是否被占用
  cout<<sum<<endl;
  return 0;
}

