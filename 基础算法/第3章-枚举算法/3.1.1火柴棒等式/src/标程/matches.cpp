//������ʽ
#include <bits/stdc++.h>
using namespace std;

int Need[]= {6,2,5,5,4,5,6,3,7,6}; //����ʮ������ʹ�õĻ����
int M[2000];

int Match(int cur)                 //����curʹ�õĻ����
{
  int ans=0;
  if(cur==0)
    return 6;
  while(cur>0)
  {
    ans+= Need[cur%10];
    cur/=10;
  }
  return ans;
}

void GetMatch()                   //���Ƚ���0~1999ʹ�õĻ�����浽Match[]
{
  for(int i=0; i<=1999; ++i)
    M[i]=Match(i);
}

int main()
{
  //freopen("matches.in","r",stdin);
  //freopen("matches.out","w",stdout);
  int ans=0,n;
  scanf("%d",&n);
  GetMatch();
  for(int i=0; i<=1000; ++i)
    for(int j=i; j<=1000; ++j)   //�˴��и�С�Ż�
    {
      int a=M[i];
      int b=M[j];
      if(a+b>n-6)                //�ұ�������Ҫ������񣬣���+����Ҫ�ĸ����
        continue;
      if(a+b+M[i+j]+4==n)
        i==j?ans++:ans+=2;
    }
  printf("%d\n",ans);
  return 0;
}

