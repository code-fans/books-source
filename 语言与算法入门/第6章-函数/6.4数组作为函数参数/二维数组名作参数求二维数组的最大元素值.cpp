//二维数组名作参数求二维数组的最大元素值
# include <bits/stdc++.h>
using namespace std;

int Max(int a[][4]) //形参数组的列数不可为空
{
  int Max=a[0][0];
  for(int i=0; i<3; i++)
    for(int j=0; j<4; j++)
      if(a[i][j]>Max)
        Max=a[i][j];
  return Max;
}

int main()
{
  int a[][4]= {1,2,3,4,5,6,7,8,9,-1,-2,-3}; //此处可省略第一维数值大小
  printf("最大值为 %d\n",Max(a)); //数组名作参数
  return 0;
}

