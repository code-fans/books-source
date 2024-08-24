//哈夫曼编码
#include <bits/stdc++.h>
using namespace std;

char str[110];
int Letter[260];

int main()
{
  //freopen("entropy.in","r",stdin);
  //freopen("entropy.out","w",stdout);
  while(scanf("%s",str),strcmp(str,"END")!=0)
  {
    memset(Letter,0,sizeof(Letter));
    int len = strlen(str);
    for(int i=0; i<len; i++)
      Letter[str[i]]++;                           //统计字符出现频率
    priority_queue<int,vector<int>,greater<int> > Q;
    for(int i=0; i<256; i++)
      if(Letter[i])
        Q.push(Letter[i]);
    int sum = 0;
    while(Q.size()>1)                             //优先队列每次取最小的两个
    {
      int a=Q.top();
      Q.pop();
      int b=Q.top();
      Q.pop();
      sum+=a+b;                   //越小频数的字符反复多加，前缀码的设计思想
      Q.push(a+b);
    }
    if(sum==0)                    //只有一种字母
      sum =len;
    printf("%d %d %.1f\n",len*8,sum,double(8*len)/sum);
  }
  return 0;
}
