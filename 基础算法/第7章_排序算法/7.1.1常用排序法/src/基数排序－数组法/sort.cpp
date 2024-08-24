//基数排序 - 数组法
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100001

int N[10],n;
int Array[MAXN];                                //存放数序
int bucket[10][MAXN];                           //桶

int maxbit(int IntMax)                          //求最大位数
{
  int digit=1;
  while(IntMax>0)
  {
    digit++;
    IntMax/=10;
  }
  return digit-1;
}

void RadixSort(int *array,int Exp)              //基数排序
{
  int Where,m=0;
  memset(N,0,sizeof(int)*10);                   //将桶计数器清空
  for(int i=0; i<n; i++)                        //分配各数入桶
  {
    Where=array[i]/(int(pow(10,Exp)+0.001))%10; //取得该位的值并确定属于哪个桶
    bucket[Where][N[Where]++]=array[i];         //依次往后排
  }
  for(int i=0; i<10; i++)                       //顺序收集桶中的数到array[]
    for(int j=0; j<N[i]; j++)
      array[m++]=bucket[i][j];
}

int main()
{
  int IntMax=0;
  scanf("%d",&n);
  for(int i=0; i<n; i++)
  {
    scanf("%d",&Array[i]);
    if(Array[i]>IntMax)                         //找出最大数
      IntMax=Array[i];
  }
  int len=maxbit(IntMax);                       //算出最大数的位长
  for(int i=0; i<len; ++i)                      //依次对每一位进行基数排序
    RadixSort(Array,i);
  for(int i=0; i<n; i++)
    printf("%d ",Array[i]);
  return 0;
}

