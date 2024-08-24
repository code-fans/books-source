/*
程序名称：USACO1.1.4 Broken Necklace
程序说明：直接搜索法，两个同样的珠子相连，从左至右一趟扫描，找出最大的a+b 
程序作者：ZXH (2010-7-27)
程序备注：注意ans>n情况的出现,白珠子的处理，及a与b的交换 
*/
#include <fstream>
using namespace std;
 
int main()
{
  ifstream fin("beads.in");
  ofstream fout("beads.out");
  char s[700],color=0;//color为前颜色，初始非任何颜色 
  int n,i,a=0,b=0;//a为上一段珠子数,b为本段珠子数
  int w=0,ans=0;//w记录至目前为止白珠子数(可接前后两端),ans为Max(a+b)
    
  fin>>n>>s;
  memcpy(s+n,s,n);
  for (i=0;i<n<<1;i++) //n<<1相当于n*2
    if (s[i]=='w')
      b++,w++;
    else if (s[i]==color)//如为相同颜色 
      b++,w=0;
    else  //遇到不同颜色的珠子 
    {
      if (a+b>ans)
        ans=a+b;
      a=b-w;//颜色变换时操作各记录数据
      b=w+1;//疑问：为何不是a=b,b=w 
      w=0;
      color=s[i];
    }
	  
  if (a+b>ans) 
    ans=a+b;
  fout<<(ans>n?n:ans)<<endl;//若ans>n表示所有珠子皆可取出
  return 0;
}
