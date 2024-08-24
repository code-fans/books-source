#include <bits/stdc++.h>
using namespace std;

int c[33][33];

void Init()//��������
{
  c[0][0]=1;
  for(int i=1; i<33; i++)
  {
    c[i][0]=1;
    for(int j=1; j<=i; j++)
      c[i][j]=c[i-1][j]+c[i-1][j-1];
  }
}

int Count(int n)              //Ѱ�ұ�nС������������
{
  int len=0,zero=0,ans=0;
  bool m[33]= {0};
  for(; n; n>>=1)             // ת��Ϊ�����Ʊ��浽m[]
    m[++len]=n%2;
  for(int i=2; i<len; i++) //���������λ��С��len�������λ��Ϊ1���������� 
    for(int j=(i+1)/2; j<i; j++)//ö��ȡ0�ĸ��� 
      ans+=c[i-1][j];
  for(int i=len-1; i>=1; i--) //���������λ������len�����
    if(m[i])                 //�����ǰλ��1 
      for(int j=(len+1)/2-(zero+1); j<i; j++) //����ÿ��С�ڵ����
        ans+=c[i-1][j];
    else                     //�����ǰλ��0,ֱ��zero+1 
      zero++;
  return ans;
}

int main()
{
  //freopen("round.in","r",stdin);
  //freopen("round.out","w",stdout);
  int s,e;
  Init();
  while(cin>>s>>e)
    cout<<Count(e+1)-Count(s)<<endl;
  return 0;
}
