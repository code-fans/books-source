//ÈýÊýÅÅÐò
#include <bits/stdc++.h>
using namespace std;

void swap(int *p1,int *p2)
{
  int temp;
  temp=*p1;
  *p1=*p2;
  *p2=temp;
}

void exchange(int *q1,int *q2,int *q3)
{
  if(*q1>*q2)swap(q1,q2);
  if(*q1>*q3)swap(q1,q3);
  if(*q2>*q3)swap(q2,q3);
}

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  int *_point1,*_point2,*_point3,a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  _point1=&a;
  _point2=&b;
  _point3=&c;
  exchange(_point1,_point2,_point3);
  printf("%d %d %d\n",a,b,c);
  return 0;
}

