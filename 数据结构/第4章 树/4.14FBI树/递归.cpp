#include<bits/stdc++.h>
using namespace std;

int n;
char s[1001];

void Build(int l,int r)
{
  int mid = (l+r)>>1;
  if(l!=r)
  {
    Build(l,mid);            //�ݹ�ǰ�벿��
    Build(mid+1,r);          //�ݹ��벿��
  }
  int a=0,b=0;
  for (int i = l; i<=r; i++) //ͳ��0��1���ֵĸ���
    s[i]=='0'? a++:b++;
  if(a && b)
    cout<<"F";               //��1Ҳ��0,F��
  else if(a)
    cout<<"B";               //ֻ��0,B��
  else
    cout<<"I";               //ֻ��1,I��
}

int main()
{
  freopen("fbi.in","r",stdin);
  freopen("fbi.out","w",stdout);
  cin>>n>>s;
  Build(0,pow(2,n)-1);
  cout<<endl;
  return 0;
}
