//�򵥸߾��ȼ���
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001

int a[MAXN],b[MAXN],ans[MAXN];

void Sub(int x[],int y[],int ans[],int len)
{
  for(int i=0; i<len; i++)
  {
    if(x[i]<y[i])                       //������С�ڼ���
    {
      x[i+1]--;
      x[i]+=10;                         //�����λ��10
    }
    ans[i]=x[i]-y[i];
  }
}

void OutPut(int x[],int len)
{
  for(; x[len-1]==0 && len-1>0; --len); //����ǰ���0
  for(int i=len-1; i>=0; --i)           //�����������
    printf("%d",x[i]);
  printf("\n");
}

void Init(int x[],string s,int len)     //�ַ�����ת��Ϊ��������
{
  for(int i=0; i<len; i++)
    x[len-1-i]=s[i]-'0';                //����ת��
}

int main()
{
  freopen("sub.in","r",stdin);
  freopen("sub.out","w",stdout);
  string str1,str2;
  cin>>str1>>str2;
  if((str1<str2 && str1.size()==str2.size()) || str1.size()<str2.size())
  {
    cout<<'-';
    swap(str1, str2);
  }
  int la=str1.size();
  int lb=str2.size();
  Init(a,str1,la);
  Init(b,str2,lb);
  Sub(a,b,ans,la);
  OutPut(ans,la);
  return 0;
}

