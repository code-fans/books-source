#include <bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;

struct dps
{
  int a[2];                            //保存0或1的方案数
} dp[100005];
char opt[100005];

inline void Calc(char op, dps &a, dps &b)
{
  if (op=='+')
  {
    a.a[1]=(a.a[1]*(b.a[0]+b.a[1])+a.a[0]*b.a[1])%10007;
    a.a[0]=a.a[0]*b.a[0]%10007;
  }
  else                                 //如果是"*"
  {
    a.a[0]=(a.a[0]*(b.a[0]+b.a[1])+a.a[1]*b.a[0])%10007;
    a.a[1]=a.a[1]*b.a[1]%10007;
  }
}

int main()
{
  //freopen("exp.in" ,"r", stdin);
  //freopen("exp.out", "w", stdout);
  int len, Opti=1, Dpi=1;
  string str;
  cin>>len>>str;
  opt[1]='(';                //为方便，先给一个左括号
  str+=')';                  //为方便，末尾先给一个右括号
  dp[1]=dps {1,1};         //(１,1)表示０的方案一个，１的方案一个，因为都有一种可能
  for (int i=0; i<=len; i++) //从左到右扫描表达式
    if (str[i] == '(')       //如果为左括号
      opt[++Opti] = '(';     //相应表达式也为左括号
    else if (str[i] == ')')  //如果为右括号
    {
      for (; opt[Opti] != '('; --Opti, --Dpi)//一直往回找到相匹配的左括号
        Calc(opt[Opti], dp[Dpi-1], dp[Dpi]);//参数为操作符，结构体前一个值和后一个值
      --Opti;                //弹出操作符
    }
    else                     //不是左括号也不是右括号，那就是运算符
    {
      //括号内找到优先级别高的运算符进行运算
      for (; (opt[Opti] <= str[i]) && (opt[Opti] != '('); --Opti, --Dpi)//*:42,+:43
        Calc(opt[Opti], dp[Dpi-1], dp[Dpi]);//动规
      opt[++Opti] = str[i];
      dp[++Dpi] = dps {1,1};
    }
  cout<<dp[1].a[0]<<endl;
  return 0;
}

