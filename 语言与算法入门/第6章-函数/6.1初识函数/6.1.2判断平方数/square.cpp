//�ж�ƽ����
#include <bits/stdc++.h>
using namespace std;

void Square(int x);      //���Ӻ���������

int main()
{
  freopen("square.in","r",stdin);
  freopen("square.out","w",stdout);
  int x;
  while(cin>>x)
    Square(x);
  return 0;
}

void Square(int n)       //void��ʾ�����޷���ֵ
{
  for(int i=1; n>0; i+=2)//��1+1��1+3��1+3+5...Ϊƽ�����Ƶ�����
    n-=i;
  cout<<(n==0?1:0)<<endl;//ֱ����������������returnֵ
}
