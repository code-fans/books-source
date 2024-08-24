//高精度数除以低精度数2
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

int Remainder=0;                 //余数,注意要大小写字母混合命名
int a[MAXN+1],ans[MAXN+1];

void Division(string str,int b, int *ans)
{
  int len=str.size();
  for(int i=1; i<=len; ++i)      //初始化为整数
    a[i]=str[i-1]-'0';

  for (int i=1; i<=MAXN; i++ )   //运算过程
  {
    if(i==len+1)
      ans[0]=i;                  //记录小数点应出现的位置
    Remainder = Remainder * 10 + a[i];
    ans[i] = Remainder / b;
    Remainder = Remainder % b;
    if(Remainder==0 && i>len)    //如果余数被整除并且整数已被除完
      break;
  }
}

void Output(int *ans,int len)
{
  int begin=1,end=MAXN ;
  while(!ans[begin])
    begin++;                     //找出最开始的位置
  if (begin>ans[0])              //此处是防止出现0.00000xxx情况时，误将前面的0跳过
    begin=ans[0];
  while(!ans[end])
    end--;                       //找出最末尾的有效位置
  if(end<len)
    end=len;                     //防止出现X000000000的时候，将有效位0消去
  if(ans[0]==begin)              //防止出现0.XXXXX 的时候，前面没有加0.
    cout<<'0';
  for(int i=begin; i<=end; i++)
  {
    if(i==ans[0])
      cout<<'.';
    cout<<ans[i];
  }
  cout<<","<<Remainder<<'\n';    //输出余数
}

int main()
{
  freopen("sample_div2.in","r",stdin);
  freopen("sample_div2.out","w",stdout);
  string str;
  int b;
  cin>>str;                      //输入高精度被除数
  cin>>b;                        //输入低精度除数
  if(b==0)
    cout<<"Divisor is 0"<<'\n';
  else
  {
    Division(str,b,ans);
    Output(ans,str.size());
  }
  return 0;
}

