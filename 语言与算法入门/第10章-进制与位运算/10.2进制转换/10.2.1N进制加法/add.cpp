//N�������ӷ�����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("add.in","r",stdin);
  //freopen("add.out","w",stdout);
  string w="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ",a,b;
  int N,x[100],y[100];
  cin>>N>>a>>b;
  while(a.length()<b.length())
    a='0'+a;
  while(b.length()<a.length())
    b='0'+b;
  a='0'+a;//ǰ����һλ�����ڽ�λ
  b='0'+b;
  for(int i=a.length()-1; i>=0; i--)
  {
    x[i]=w.find(a[i],0);//����a[i]��W�е�λ�û����ʵ������
    y[i]=w.find(b[i],0);//ת����x,y������׼�����
  }
  for(int i=a.length()-1; i>=0; i--) //��λ�ӷ�
  {
    x[i]=x[i]+y[i];
    if(x[i]>=N)
      for(int k=i; x[k]>=N; k--)
      {
        x[k]=x[k]-N;
        x[k-1]++;
      }
    a[i]=w[x[i]];
  }
  while(a[0]=='0')
    a.erase(0,1);  //ɾ��ǰ��0
  cout<<(a.length()==0?"0":a)<<endl;
  return 0;
}

