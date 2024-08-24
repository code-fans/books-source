//高精度幂的优化算法
//所谓指针交换数组地址的方法可以使程序运行速度平均提高5倍，其原理是改变数组
//指针的指向而省略了数组与数组之间复制的过程。例如计算数组c[]＝数组c[]×数组
//x[]，通常做法是将数组c[]×数组x[]的结果先存入一临时数组temp[]，再将temp[]
//的值依次复制到数组c[]中以完成更新数组c[]的目的。而使用指针交换数组地址方法时，
//只需最后将指向数组c[]的指针改成指向临时数组temp[]的指针即可。
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000

int a[10001],x[10001],c[10001];
int b,*pa,*pc,*px;

int Mul(int &len_a,int &len_b,bool bj)
{
  int i,j,r=0;
  for(i=1; i<=len_a+len_b && i<=1000; i++)
    pc[i]=0;                                       //pc数组初始为0
  for(i=1; i<=len_a; i++)                          //高精度计算
    for(j=1; j<=len_b && i+j-1<=1000; j++)
      pc[i+j-1]+=(pa[i])*(bj?pa[j]:px[j]);
  for(int i=1; i<=len_a+len_b-1 && i<=1000; i++)   //整理
  {
    if(pc[i]+r>9)
    {
      pc[i]+=r;
      r=pc[i]/10;
      pc[i]%=10;
    }
    else
    {
      pc[i]+=r;
      r=0;
    }
  }
  if(i>1000)
    len_b=1000;
  else if(r)
  {
    pc[len_a+len_b]=r;
    len_b=len_b+len_a;
  }
  else
    len_b=len_b+len_a-1;
  int *change;                                     //交换地址
  if(!bj)
  {
    change=px;
    px=pc;
    pc=change;
  }
  else
  {
    change=pa;
    pa=pc;
    pc=change;
  }
}

int main()
{
  string s;
  int len_a=0,len_x=1;
  cin>>s>>b;
  int len=s.size();
  for(int i=1; i<=len; i++)                        //将字符数组转为整型数组
    a[i]=s[len-i]-'0';
  len_a=len;
  pa=a;                                            //pa指针指向a数组
  pc=c;                                            //pc指针指向c数组
  px=x;                                            //px指针指向x数组
  px[1]=1;                                         //px数组保存结果
  while(b>1)                                       //降幂算法
  {
    if(b%2==1)
      Mul(len_a,len_x,0);
    Mul(len_a,len_a,1);
    b=b>>1;                                        //b=b/2
  }
  Mul(len_a,len_x,0);
  for(int i=len_x; i>=1; i--)                      //输出答案
    cout<<px[i];
  cout<<endl;
  return 0;
}

