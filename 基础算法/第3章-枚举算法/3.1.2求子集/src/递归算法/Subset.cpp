//���Ӽ� - �ݹ��㷨
#include <bits/stdc++.h>
using namespace std;

int n;
int a[27];               //��01����ǣ�����Nλ01��Ӧ1��Nλ����������ö��
set <string> s;

void Subset()
{
  string str="(";
  for(int i=0; i<N; i++)
    if((1<<i)&n)
      str+=char(i+'a');
  s.insert(str+")");
}

void DFS(int digit)        //digit��ʾ��ǰλ�� 
{
  for(int i=0; i<=1; i++)  //������е�0��1���
  {
    a[digit]=i;
    if(digit==n)
      Subset();
    else
      DFS(digit+1);
  }
}

int main()
{
  //freopen("Subset.in","r",stdin);
  //freopen("Subset.out","w",stdout);
  scanf("%d",&n);
  DFS(1);
  for(set<string>::iterator ii=s.begin(); ii!=s.end(); ii++)
    cout<<*ii<<endl;
  return 0;
}

