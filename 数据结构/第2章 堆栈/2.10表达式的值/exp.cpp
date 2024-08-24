#include <bits/stdc++.h>
using namespace std;
const int inf=0x7fffffff;

struct dps
{
  int a[2];                            //����0��1�ķ�����
} dp[100005];
char opt[100005];

inline void Calc(char op, dps &a, dps &b)
{
  if (op=='+')
  {
    a.a[1]=(a.a[1]*(b.a[0]+b.a[1])+a.a[0]*b.a[1])%10007;
    a.a[0]=a.a[0]*b.a[0]%10007;
  }
  else                                 //�����"*"
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
  opt[1]='(';                //Ϊ���㣬�ȸ�һ��������
  str+=')';                  //Ϊ���㣬ĩβ�ȸ�һ��������
  dp[1]=dps {1,1};         //(��,1)��ʾ���ķ���һ�������ķ���һ������Ϊ����һ�ֿ���
  for (int i=0; i<=len; i++) //������ɨ����ʽ
    if (str[i] == '(')       //���Ϊ������
      opt[++Opti] = '(';     //��Ӧ���ʽҲΪ������
    else if (str[i] == ')')  //���Ϊ������
    {
      for (; opt[Opti] != '('; --Opti, --Dpi)//һֱ�����ҵ���ƥ���������
        Calc(opt[Opti], dp[Dpi-1], dp[Dpi]);//����Ϊ���������ṹ��ǰһ��ֵ�ͺ�һ��ֵ
      --Opti;                //����������
    }
    else                     //����������Ҳ���������ţ��Ǿ��������
    {
      //�������ҵ����ȼ���ߵ��������������
      for (; (opt[Opti] <= str[i]) && (opt[Opti] != '('); --Opti, --Dpi)//*:42,+:43
        Calc(opt[Opti], dp[Dpi-1], dp[Dpi]);//����
      opt[++Opti] = str[i];
      dp[++Dpi] = dps {1,1};
    }
  cout<<dp[1].a[0]<<endl;
  return 0;
}

