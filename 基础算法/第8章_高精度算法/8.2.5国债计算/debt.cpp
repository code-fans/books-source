//国债计算—使用string处理高精度
//删除小数点后进行计算，计算后加回小数点就行，其位置为乘数的小数位数和
#include <bits/stdc++.h>
using namespace std;

string Mul(string a, string b)       //计算a*b
{
  string ans(b.size()+a.size(),'0'); //初始化结果字符串
  for (int i=0; i<b.size(); i++)
  {
    int now = 0;
    for (int j=0; j<a.size(); j++)
    {
      now=(a[j]-'0')*(b[i]-'0')+(ans[i+j]-'0')+now/10;
      ans[i+j]=now%10+'0';
      if (j==a.size()-1)
        ans[i+j+1]=now/10+'0';      //最高位进位
    }
  }
  if (ans[b.size()+a.size()-1]=='0')//可能最高位没有进位
    ans.erase(b.size()+a.size()-1,1);
  return ans;
}

string Expo(string R, int n)        //快速幂
{
  if (n == 1)
    return R;
  string ans = "1", base = R;
  for(; n != 0; n>>=1)
  {
    if (n & 1)
      ans = Mul(ans, base);         //结束前还要执行一次
    base = Mul(base, base);
  }
  return ans;
}

int main()
{
  freopen("debt.in","r",stdin);
  freopen("debt.out","w",stdout);
  string R, Ans;
  int n;
  while (cin>>R>>n)
  {
    if (n!=0)
    {
      for (int i=0; R[i]!='.' && R[i]=='0'; R.erase(i,1));//处理小数点前多余的0
      reverse(R.begin(), R.end());
      for(int i=0; R[0]=='0'; R.erase(0,1));//处理小数点末尾多余的0
      int pos = R.find('.');              //重新计算小数点位置
      R.erase(pos, 1);                //去除小数点
      Ans=Expo(R, n);                 //计算结果，倒序存放在ans字符串中
      int len = pos*n;                //确定小数的位数
      if (len>=Ans.size())            //如果小数位数超过结果位数
      {
        int O=len-Ans.size();
        while(O--)
          Ans+='0';                   //补充0
        Ans+='.';
      }
      else
        Ans.insert(len,1,'.');        //插入小数点
      if (Ans[0]=='.')                //如果是整数
        Ans.erase(0,1);               //删除小数点
      reverse(Ans.begin(), Ans.end());
      cout<<(Ans.size()==0?"0":Ans)<<endl;
    }
    else
      cout<<"1\n";
  }
  return 0;
}
