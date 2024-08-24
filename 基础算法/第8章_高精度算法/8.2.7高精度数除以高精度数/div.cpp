//高精度数除以高精度数 -二分求商
#include <bits/stdc++.h>
using namespace std;

string s1,s2,ans,test[10];

string Offzero(string ans,int len)//删除前导0,len控制保留位数
{
  for(; ans[0]=='0' && ans.size()>=len; ans.erase(0,1));
  return ans;
}

string Mul(string x,int k)        //高精度x乘低精度k(0<=k<=9)
{
  string ans(x.size(),'0');       //乘积ans初始为000...000
  int Remainder=0;                //余数初始为0
  for(int i=x.size()-1; i>=0; i--)//从个位开始逐位乘
  {
    Remainder=Remainder/10+(x[i]-'0')*k;
    ans[i]=Remainder%10+'0';
  }
  return Remainder>=10?ans.insert(0,1,Remainder/10+'0'):ans;
}

string Sub(string x,string y)     //计算x[]－y[]的差,x>y
{
  string ans(x.size(),'0');
  y.insert(0,x.size()-y.size(),'0');//前面添加0,使长度和x一样
  for(int i=x.size()-1; i>=0; i--)
  {
    if(x[i]<y[i])                 //被减数小于减数，则向高位借10
    {
      x[i-1]--;
      x[i]+=10;
    }
    ans[i]=(x[i]-y[i])+'0';
  }
  return Offzero(ans,1);          //删去前导0，但至少保留个位数
}

bool Bigger(string x,string y)    //判断x是否大于等于y
{
  return (x.size()==y.size() && x>=y || x.size()>y.size());
}

string Div(string x,string y,int xlen)
{
  x.append(10101-x.size(),'0');     //被除数后面添加0
  string ans(y.size(),'0'),now=x.substr(0,y.size());
  for(int i=y.size(); i<=10100 && !(now.empty() && i>xlen);)
  {
    if(now.empty())                 //可能当前的余数为0
      ans+='0',now=Offzero(now+x[i++],0);
    else
    {
      int mid,k,l=0,r=9;
      while(l<=r )                  //二分查找合适的商
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
          k=mid,l=mid+1;            //mid保存到k,因为mid可能就是商
      }
      ans+=k+'0';
      now=Offzero(Sub(now,test[k])+x[i++],0);//余数向后扩一位更新
    }
  }
  return Offzero(ans.insert(xlen+1,1,'.'),1);//去前导0，添加小数点
}

void Output(string x)             //按规定格式输出答案
{
  if(x[0]=='.')
    x='0'+x;
  reverse(x.begin(),x.end());     //翻转x
  string ans=Offzero(x,0);        //删除末尾多余的0
  if(ans[0]=='.')                 //如果是整数，删除小数点
    ans.erase(0,1);
  reverse(ans.begin(),ans.end()); //再翻转回来
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
    test[i]=Offzero(Mul(s2,i),1);           //预先算出s2*0~s2*9的值
  if(s2.size()==1 && s2[0]=='0')
    cout<<"Divisor is 0"<<endl;
  else if(s1.size()==1 && s1[0]=='0')
    cout<<0<<endl;
  else
    Output(Div(s1,s2,s1.size()));
  return 0;
}

