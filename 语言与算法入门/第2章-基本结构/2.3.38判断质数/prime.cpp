//�ж�����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int number,i;
  cin>>number;
  int k=sqrt(number); //kΪ��������ƽ����,��һ��Ϊʲô��
  for(i=2; i<=k; i++) //ö������2��k
    if(number%i==0)
      break;          //ֻҪ�ܱ�������������forѭ��
  cout<<(i>k?"Yes\n":"No\n");
  return 0;
}

