//���Ӽ� - λ����
#include <bits/stdc++.h>
using namespace std;

int N;
set <string> s;

void Subset(int n)
{
  string str="(";
  for(int i=0; i<N; i++)
    if((1<<i) & n)                  //�����ǰλ��1
      str+=char(i+'a');
  s.insert(str+")");                //�������Ӽ�����set����,set���Զ�����
}

int main()
{
  freopen("Subset.in","r",stdin);
  freopen("Subset.out","w",stdout);
  cin>>N;
  for(int i=0; i<(1<<N); i++)       //ѭ��2^N�Σ�ö��i��000..000��111..111
    Subset(i);
  for(set<string>::iterator ii=s.begin(); ii!=s.end(); ii++)
    cout<<*ii<<endl;
  return 0;
}

