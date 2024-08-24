//方块转换
#include <bits/stdc++.h>
using namespace std;
#define MAX 11

void Rotation_90(int n, char a[][MAX], char b[][MAX])//旋转90°函数
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      b[i][j] = a[n-1-j][i];
}

void Reflection(int n, char a[][MAX], char b[][MAX]) //水平翻转函数
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n ; j++)
      b[i][j] = a[i][n-1-j];
}

int OK(int n,char a[][MAX],char b[][MAX]) //判断字符数组是否相等
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(a[i][j]!=b[i][j])
        return 0;
  return 1;
}

int Try(int n, char a[][MAX], char b[][MAX])//尝试
{
  char c[MAX][MAX]= {0},d[MAX][MAX]= {0},e[MAX][MAX]= {0},t[MAX][MAX]= {0};
  Rotation_90(n,a,c);
  if(OK(n,c,b)) return 1;     //转90°,存在c数组 （a数组转90°）
  Rotation_90(n,c,d);
  if(OK(n,d,b)) return 2;     //转180°,存在d数组（c数组再转90°）
  Rotation_90(n,d,e);
  if(OK(n,e,b)) return 3;     //转270°,存在e数组（d数组再转90°）
  Reflection(n,a,t);
  if(OK(n,t,b)) return 4;     //水平翻转,存在t数组
  Rotation_90(n,t,c);
  if(OK(n,c,b)) return 5;     //水平翻转后再旋转90°,180°,270°
  Rotation_90(n,c,d);
  if(OK(n,d,b)) return 5;
  Rotation_90(n,d,e);
  if(OK(n,e,b)) return 5;
  if(OK(n,a,b)) return 6;
  return 7;                  //都不满足以上条件，返回7
}

int Init(int n,char a[][MAX])
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      cin>>a[i][j];
}

int main()
{
  freopen("transform.in", "r", stdin);
  freopen("transform.out", "w",stdout);
  int N;
  char a[MAX][MAX], b[MAX][MAX];
  scanf("%d\n",&N);
  Init(N,a);
  Init(N,b);
  cout<<Try(N,a,b)<<endl;
  return 0;
}
