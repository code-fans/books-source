//�������1  - һά����dp
#include <bits/stdc++.h>
using namespace std;
#define MAX 0x3f3f3f3f             //����Ϊʲô��ȡ0x7fffffff�� 

int w[10005],l[10005],f[10005];
int sw;

int Opt(int x,int y)               //������������(x,y)�����߶�
{
  int weight=0,h=0;
  for(int i=x; i<=y; i++)
  {
    weight+=w[i];
    h=max(l[i],h) ;
  }
  return weight>sw ? MAX : h;      //���ܳ�������޶�
}

int main()
{
  freopen("book.in","r",stdin);
  freopen("book.out","w",stdout);
  int n,t;
  scanf("%d%d",&n,&sw);
  for(int i=1; i<=n; i++)
    scanf("%d%d",&w[i],&l[i]);
  for(int i=1; i<=n; i++)
  {
    f[i]=MAX;
    for(int j=0; j < i; j++)
      f[i]=min(f[i],f[j]+Opt(j+1,i));
  }
  printf("%d\n",f[n]);
  return 0;
}

