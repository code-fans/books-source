//����ָ�����ȵ�����ַ���
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int i,n,m;//���n��m���ַ�������ַ���
  string str;
  cin>>n>>m;
  srand(time(0));
  for(i=1; i<=n; i++)
  {
    str="";//����ַ���
    for(int j=1; j<=m; j++)
    {
      int temp=rand()%2;//������������д��Сд��ĸ
      if (temp)//�൱��temp==1
        str+=(char)(rand()%(26)+1+64);//������ɴ�д�ַ���ӵ�str��ĩβ
      else
        str+=(char)(rand()%(26)+1+96);//�������Сд�ַ���ӵ�str��ĩβ
    }
    cout<<str<<endl;
  }
  return 0;
}

