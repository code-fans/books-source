//ѭ������
#include <bits/stdc++.h>
using namespace std;

int a[32+1][32+1];

int main()
{
  freopen("competition.in","r",stdin);
  freopen("competition.out","w",stdout);
  int n,h=1;
  scanf("%d",&n);
  a[1][1]=1;
  int Person=pow(2,n);
  do
  {
    for(int i=1; i<=h; i++)
      for(int j=1; j<=h; j++)
      {
        a[i][j+h]=a[i][j]+h;              //�������ϽǷ���
        a[i+h][j]=a[i][j+h];              //�������½Ƿ���
        a[i+h][j+h]=a[i][j];              //�������½Ƿ���
      }
    h=h*2;
  }
  while(h!=Person);

  for(int i=1; i<=Person; i++)
  {
    for(int j=1; j<=Person; j++)
      if(i*j==Person*Person)
        printf("%d",a[i][j]);
      else
        printf("%-4d",a[i][j]);           //�������
    printf("\n");
  }
  return 0;
}

