//基数排序 - STL法
#include <bits/stdc++.h>
using namespace std;

int n,temp,IntMax=0;
queue  <int> que[10];                                //定义桶
vector <int> vec;                                    //存储数列
vector <int>::iterator point;                        //定义一个指向vector的指针

int Maxbit(int IntMax)                               //求最大位数
{
  int digit=1;
  for(; IntMax>0; IntMax/=10)
    digit++;
  return digit-1;
}

void VecToDeque(int power)                           //按某位数将数字入桶
{
  for(point=vec.begin(); point!=vec.end(); ++point)
  {
    int itor=(*point)/power%10;
    que[itor].push(*point);                          //数值入桶
  }
}

void Colect()                                        //将桶中排好的数输出到容器中
{
  int count=0;
  for(int i=0; i<10; i++)
    while(!que[i].empty())                           //如果不为空
    {
      vec[count++]=que[i].front();                   //取获队列第一个值
      que[i].pop();                                  //出列
    }
}

void RadixSort()                                     //基数排序
{
  int Power=1;
  for(int i=1; i<=Maxbit(IntMax); i++)
  {
    VecToDeque(Power);                               //依次按位分配到桶
    Colect();                                        //整理到数列
    Power*=10;
  }
}

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  scanf("%d",&n);
  for(int i=0; i<n; i++)
  {
    scanf("%d",&temp);
    vec.push_back(temp);                             //vector后端插入数
    IntMax=temp>IntMax?temp:IntMax;                  //找出最大值
  }
  RadixSort();
  for(point=vec.begin(); point!=vec.end(); ++point)
    printf("%d ",*point);
  return 0;
}

