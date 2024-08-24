//�߾��������Ը߾����� -��������
#include <bits/stdc++.h>
using namespace std;

string s1,s2,ans,test[10];

string Offzero(string ans,int len)//ɾ��ǰ��0,len���Ʊ���λ��
{
  for(; ans[0]=='0' && ans.size()>=len; ans.erase(0,1));
  return ans;
}

string Mul(string x,int k)        //�߾���x�˵;���k(0<=k<=9)
{
  string ans(x.size(),'0');       //�˻�ans��ʼΪ000...000
  int Remainder=0;                //������ʼΪ0
  for(int i=x.size()-1; i>=0; i--)//�Ӹ�λ��ʼ��λ��
  {
    Remainder=Remainder/10+(x[i]-'0')*k;
    ans[i]=Remainder%10+'0';
  }
  return Remainder>=10?ans.insert(0,1,Remainder/10+'0'):ans;
}

string Sub(string x,string y)     //����x[]��y[]�Ĳ�,x>y
{
  string ans(x.size(),'0');
  y.insert(0,x.size()-y.size(),'0');//ǰ�����0,ʹ���Ⱥ�xһ��
  for(int i=x.size()-1; i>=0; i--)
  {
    if(x[i]<y[i])                 //������С�ڼ����������λ��10
    {
      x[i-1]--;
      x[i]+=10;
    }
    ans[i]=(x[i]-y[i])+'0';
  }
  return Offzero(ans,1);          //ɾȥǰ��0�������ٱ�����λ��
}

bool Bigger(string x,string y)    //�ж�x�Ƿ���ڵ���y
{
  return (x.size()==y.size() && x>=y || x.size()>y.size());
}

string Div(string x,string y,int xlen)
{
  x.append(10101-x.size(),'0');     //�������������0
  string ans(y.size(),'0'),now=x.substr(0,y.size());
  for(int i=y.size(); i<=10100 && !(now.empty() && i>xlen);)
  {
    if(now.empty())                 //���ܵ�ǰ������Ϊ0
      ans+='0',now=Offzero(now+x[i++],0);
    else
    {
      int mid,k,l=0,r=9;
      while(l<=r )                  //���ֲ��Һ��ʵ���
      {
        mid=(l+r)>>1;
        if(test[mid]==now)
        {
          k=mid;
          break;
        }
        else if(Bigger(test[mid],now))
          r=mid-1;
        else
          k=mid,l=mid+1;            //mid���浽k,��Ϊmid���ܾ�����
      }
      ans+=k+'0';
      now=Offzero(Sub(now,test[k])+x[i++],0);//���������һλ����
    }
  }
  return Offzero(ans.insert(xlen+1,1,'.'),1);//ȥǰ��0�����С����
}

void Output(string x)             //���涨��ʽ�����
{
  if(x[0]=='.')
    x='0'+x;
  reverse(x.begin(),x.end());     //��תx
  string ans=Offzero(x,0);        //ɾ��ĩβ�����0
  if(ans[0]=='.')                 //�����������ɾ��С����
    ans.erase(0,1);
  reverse(ans.begin(),ans.end()); //�ٷ�ת����
  for(int i=0,j=0; i<ans.size() && j<5000; i++)
  {
    cout<<ans[i];
    if(ans[i]!='.')
      j++;
  }
  cout<<endl;
}

int main()
{
  //freopen("div.in","r",stdin);
  //freopen("div.out","w",stdout);
  cin>>s1>>s2;
  for(int i=0; i<=9; i++)
    test[i]=Offzero(Mul(s2,i),1);           //Ԥ�����s2*0~s2*9��ֵ
  if(s2.size()==1 && s2[0]=='0')
    cout<<"Divisor is 0"<<endl;
  else if(s1.size()==1 && s1[0]=='0')
    cout<<0<<endl;
  else
    Output(Div(s1,s2,s1.size()));
  return 0;
}

