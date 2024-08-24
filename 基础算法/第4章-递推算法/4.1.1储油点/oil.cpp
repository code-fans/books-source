//储油点
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("oil.in","r",stdin);
  //freopen("oil.out","w",stdout);
  double oil[10],dis[10];
  dis[1]=500;                     //保存最后一个储油点距终点的距离
  oil[1]=500;                     //储油点1需储油500
  int d=500;                      //初始值为最后一个储油点到终点的距离
  int k=1;                        //储油点位置序号,即计数器
  while (d<=1000)                 //开始倒推
  {
    k++;
    d+=500/(2*k-1);               //每次都要多跑一个来回
    dis[k]=d;                     //确定储油点位置
    oil[k]=oil[k-1]+500;          //每次都要多装一次，所以加500
  }
  dis[k]=1000;                    //设置起始点到终点的距离值
  double d1=1000-dis[k-1];        //剩下的距离
  oil[k]=d1*(2*k-1)+oil[k-1];     //第一次来回跑了2k-1次的油耗加到起点处
  for(int i=0; i<k; i++)          //逐一输出当前储油点的距离和储油量
    printf("i=%d  dis=%.2f  oil=%.2f\n",i,1000-dis[k-i],oil[k-i]);
  return 0;
}

