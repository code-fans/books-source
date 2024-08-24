//派对灯
#include<bits/stdc++.h>
using namespace std;

int result[110],lamp[110];
set<string> ans;

int main()
{
  //freopen("lamps.in","r",stdin);
  //freopen("lamps.out","w",stdout);
  int n,C;
  scanf("%d%d",&n,&C);
  memset(result,-1,sizeof(result));
  for(int k; scanf("%d",&k) && k!=-1; result[k]=1);//读入最后开着灯的状态
  for(int k; scanf("%d",&k) && k!=-1; result[k]=0);//读入最后关着灯的状态
  for(int key1=0; key1<=1; key1++)        //要么不按，要么按一次，按偶数次等于没按
    for(int key2=0; key2<=1; key2++)
      for(int key3=0; key3<=1; key3++)
        for(int key4=0,t; key4<=1; key4++) //枚举每一种选择
          if((key1+key2+key3+key4)%2==C%2 && key1+key2+key3+key4<=C)//奇偶性不同，一定按不出c
          {
            //找不到这规律也没关系，set会去重
            for(t=1; t<=n; t++)           //初始所有灯都亮
              lamp[t]=1;
            if(key1)                      //按钮1
              for(t=1; t<=n; t++)         //按灯的先后顺序无关结果
                lamp[t]=1-lamp[t];
            if(key2)                      //按钮2
              for(t=1; t<=n; t+=2)
                lamp[t]=1-lamp[t];
            if(key3)                      //按钮3
              for(t=2; t<=n; t+=2)
                lamp[t]=1-lamp[t];
            if(key4)                      //按钮4
              for(t=1; t<=n; t+=3)
                lamp[t]=1-lamp[t];
            for(t=1; t<=n; t++)       //比较
              if((lamp[t]!=result[t]) && result[t]!=-1)
                break;
            if(t>n)                      //成功则添加到set中
            {
              string temp;
              for(int t=1; t<=n; t++)
                temp+=lamp[t]+'0';
              ans.insert(temp);           //会自动排序
            }
          }
  if(ans.empty())
    printf("IMPOSSIBLE\n");
  else
    for(set<string>::iterator it = ans.begin(); it != ans.end(); it++)
      cout << *it << endl;//输出结果是6个一循环，所以还可以优化
  return 0;
}
