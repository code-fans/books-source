//������Ϸ ��stringд�ĸ߾���
#include<bits/stdc++.h>
using namespace std;

struct data
{
  int a,b;
} man[10005];

string ToString(int num, string ans="")//����תstring
{
  for(; num; num/=10)
    ans=char(num%10+'0')+ans;
  return ans;
}

bool Bigger(string x,string y)         //�ж�x�Ƿ���ڵ���y
{
  return (x.size()==y.size() && x>=y || x.size()>y.size());
}

string Mul(string x,int b,string ans="")//�߾���x*�;���b=ans
{
  int Remainder=0;                     //������ʼΪ0
  for(int i=x.size()-1; i>=0; i--)     //�Ӹ�λ��ʼ��λ��
  {
    ans=char((Remainder+(x[i]-'0')*b)%10+'0')+ans;
    Remainder=(Remainder+(x[i]-'0')*b)/10;
  }
  return ToString(Remainder)+ans;
}

int CMP(data x,data y)
{
  return x.a*x.b<y.a*y.b;
}

string Div(string str,int b,string ans="")//����߾���str/b
{
  for(int i=0,x=0; i<str.size(); ++i)
  {
    ans+=((x*10+(str[i]-'0'))/b)+'0';  //ģ�������ע��x��ʼʱΪ��
    x=(x*10+(str[i]-'0'))%b;           //��������10���ۼƵ�x
  }
  for(; ans[0]=='0' && ans.size()>0; ans.erase(0,1)); //ɾ��ǰ��0
  return ans;
}

int main()
{
  freopen("game.in","r",stdin);
  freopen("game.out","w",stdout);
  int n;
  scanf("%d",&n);
  for(int i=0; i<=n; i++)
    cin>>man[i].a>>man[i].b;
  sort(man+1,man+n+1,CMP);             //�Ժ���Ĵ󳼰�a*b����
  string ans="0";
  string Allmul=ToString(man[0].a);
  for(int i=1; i<=n; i++)
  {
    string temp=Div(Allmul,man[i].b);
    ans=Bigger(ans,temp)?ans:temp;
    Allmul=Mul(Allmul,man[i].a);
  }
  cout<<ans<<endl;
  return 0;
}
