//���ֵ����Сֵ
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int a[MAXN],b[MAXN],ans[MAXN];

bool Comp(string s1,string s2)
{
  return (s1.size()>s2.size() || s1.size()==s2.size() && s1>s2);
}

void Init(int x[],string str, int len) //�ַ���תΪ��������
{
  for(int i=0; i<len; i++)
    x[len-i-1]=str[i]-'0';             //����ת��
}

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

int main()
{
  freopen("sub.in","r",stdin);
  freopen("sub.out","w",stdout);
  int n;
  cin>>n;
  string ma,mi,s;
  for(int i=0; i<MAXN; i++)//����СֵΪ���ֵ
    mi+="9";
  for(int i=0; i<n; i++)
  {
    cin>>s;
    if(Comp(s,ma))//�ҳ����ֵ
      ma=s;
    if(Comp(mi,s))//�ҳ���Сֵ
      mi=s;
  }
  int la=ma.size();
  int lb=mi.size();
  Init(a,ma,la);
  Init(b,mi,lb);
  Sub(a,b,ans,la);
  OutPut(ans,la);
  return 0;
}

