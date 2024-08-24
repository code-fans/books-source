//骑士遍历 -优化算法
#include<bits/stdc++.h>
using namespace std;
int way[5][2]= {{0,0},{1,-2},{2,-1},{2,1},{1,2}};//增量数组
int step[1000]= {0,2};                  //第1步从方向2开始

int main()
{
  //freopen("knight.in","r",stdin);
  //freopen("knight.out","w",stdout);
  int x=1,y=1,X,Y,k=1;
  cin>>X>>Y;
  while(k>=1)
  {
    step[k]++;
    while(step[k]>4)
    {
      step[k]=0;
      k--;
      if(k==0)
      {
        cout<<-1<<endl;
        return 0;
      }
      x-=way[step[k]][0];//恢复到上一步
      y-=way[step[k]][1];
      step[k]++;
    }
    x+=way[step[k]][0];
    y+=way[step[k]][1];
    if(x==X && y==Y)
      break;
    if(x>X||x<1||y>Y||y<1||(Y-y)>(2*(X-x)))//优化
    {
      x-=way[step[k]][0];
      y-=way[step[k]][1];
    }
    else
      k++;
  }
  for(int i=1; i<k; ++i)
    cout<<step[i]<<" ";
  cout<<step[k]<<endl;
  return 0;
}
