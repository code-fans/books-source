//ǰ�����������
#include <bits/stdc++.h>
using namespace std;
string s1,s2;

void Trans(int L1,int R1,int L2,int R2)
{
  int k=s2.find(s1[L1]);                   //���Ҹ���s2��λ��
  if(k>L2)
    Trans(L1+1,L1+k-L2,L2,k-1);            //s2����벿��
  if(k<R2)
    Trans(L1+k-L2+1,R1,k+1,R2);            //s2���Ұ벿��
  cout<<s1[L1];                            //�ݹ���������
}

int main()
{
  freopen("tree.in","r",stdin);
  freopen("tree.out","w",stdout);
  cin>>s1>>s2;
  Trans(0,s1.size()-1,0,s2.size()-1);
  cout<<endl;
  return 0;
}

