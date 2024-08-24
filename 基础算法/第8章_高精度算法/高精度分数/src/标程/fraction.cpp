//高精度分数 - 朴素算法
#include <bits/stdc++.h>
using namespace std;

int Remainder[101];               // remainder:存放除法的余数
int quotient[101];                // quotient:依次存放商的每一位
int main()
{
  //freopen("fraction.in","r",stdin);
  //freopen("fraction.out","w",stdout);
  int m,n,i,j;
  scanf("%d/%d",&m,&n);           //输入被除数和除数
  cout<<m<<'/'<<n<<"=0.";
  for(i=1; i<=100; i++)           //i: 商的位数
  {
    Remainder[m]=i;               //m:除的余数remainder[m]:该余数对应的商的位数
    m*=10;                        //余数扩大10倍
    quotient[i]=m/n;              //商
    m=m%n;                        //求余数
    if(m==0)                      //余数为0 则表示是有限小数
    {
      for(j=1; j<=i; j++)
        cout<<quotient[j];        //输出商
      cout<<endl;
      break;                      //退出循环
    }
    if(Remainder[m]!=0)           //若该余数对应的位在前面已经出现过
    {
      for(j=1; j<=i; j++)
        cout<<quotient[j];        //则输出循环小数
      cout<<"\nfrom "<<Remainder[m]<<" to "<<i<<"\n";
      break;
    }
  }
}

