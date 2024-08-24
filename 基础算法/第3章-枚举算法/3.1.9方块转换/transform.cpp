//����ת��
#include <bits/stdc++.h>
using namespace std;
#define MAX 11

void Rotation_90(int n, char a[][MAX], char b[][MAX])//��ת90�㺯��
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      b[i][j] = a[n-1-j][i];
}

void Reflection(int n, char a[][MAX], char b[][MAX]) //ˮƽ��ת����
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n ; j++)
      b[i][j] = a[i][n-1-j];
}

int OK(int n,char a[][MAX],char b[][MAX]) //�ж��ַ������Ƿ����
{
  for(int i=0; i<n; i++)
    for(int j=0; j<n; j++)
      if(a[i][j]!=b[i][j])
        return 0;
  return 1;
}

int Try(int n, char a[][MAX], char b[][MAX])//����
{
  char c[MAX][MAX]= {0},d[MAX][MAX]= {0},e[MAX][MAX]= {0},t[MAX][MAX]= {0};
  Rotation_90(n,a,c);
  if(OK(n,c,b)) return 1;     //ת90��,����c���� ��a����ת90�㣩
  Rotation_90(n,c,d);
  if(OK(n,d,b)) return 2;     //ת180��,����d���飨c������ת90�㣩
  Rotation_90(n,d,e);
  if(OK(n,e,b)) return 3;     //ת270��,����e���飨d������ת90�㣩
  Reflection(n,a,t);
  if(OK(n,t,b)) return 4;     //ˮƽ��ת,����t����
  Rotation_90(n,t,c);
  if(OK(n,c,b)) return 5;     //ˮƽ��ת������ת90��,180��,270��
  Rotation_90(n,c,d);
  if(OK(n,d,b)) return 5;
  Rotation_90(n,d,e);
  if(OK(n,e,b)) return 5;
  if(OK(n,a,b)) return 6;
  return 7;                  //����������������������7
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
