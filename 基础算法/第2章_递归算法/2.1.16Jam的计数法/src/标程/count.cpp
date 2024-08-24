/*jam的计数法
//本题实际是在m个字母中选n个字母，不能重复选取，并且要按照字典序排列，显然是组合问题
生成组合大致算法流程如下：
（１） 从后向前找第一个未达到最大值的数a；
（２） a=a+1；
（３） 后面的数都等于前面数加1；
（４） 判断a[0]，若a[0]=1则结束，否则转1；*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("count.in","r",stdin);
  //freopen("count.out","w",stdout);
  int s,t,w;
  string str;
  cin>>s>>t>>w>>str;
  for(int p=0,q; p<5 && (str[0]-'a'<t-w); p++)       //最多只输出５个
  {
    for(q=w-1; q>=0 && (str[q]-'a'==t-w+q); q--); //第q位的最大值为 t-（w-q）
    if(q>=0)
    {
      str[q]++;                                   //找到第一个可以加1的位置
      for(int i=q+1; i<w; i++)                        //后面依次加1
        str[i]=str[i-1]+1;
      cout<<str<<endl;
    }
  }
  return 0;
}
