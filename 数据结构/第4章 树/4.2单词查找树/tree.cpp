//���ʲ�����
#include <bits/stdc++.h>
using namespace std;

string a[10000];

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  int n=0;
  while(cin>>a[++n]);
  sort(a+1,a+1+n);
  int t=a[1].length();                  //���ۼӵ�һ�����ʵĳ���
  for(int i=2; i<=n; i++)
  {
    int j=0;
    while(a[i][j]==a[i-1][j] && j<a[i-1].length())
      j++;                              //������������Ȳ��ֵĳ���
    t+=a[i].length()-j;                 //�ۼ�
  }
  cout<<t+1<<endl;                      //ע�����Ҫ��һ
  return 0;
}

