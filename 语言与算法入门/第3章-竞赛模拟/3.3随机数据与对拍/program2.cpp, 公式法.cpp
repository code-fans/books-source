//program2.cpp, ��ʽ��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("in.txt","r",stdin); //��ȡ���ļ�����ͬ����in.txt
  freopen("out2.txt","w",stdout);//ע��˴�Ϊout2.txt
  long long a,b,c;
  cin>>a>>b>>c;
  cout<<(a%c*b%c)%c<<endl;
  return 0;
}

