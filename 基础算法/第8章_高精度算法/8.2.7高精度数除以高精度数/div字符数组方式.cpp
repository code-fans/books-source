//高精度数除高精度数，采用二分求商
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5500

int a[MAXN],b[MAXN],ans[MAXN];          //a[]被除数,b[]除数,ans[]答案
int now[MAXN];                        //now[]被除数正在被除的数
int dot=0;                           //小数点位置

int Bigger(int x[],int y[])          //比较x[]和y[]大小,返回值为1,-1,0
{
  if(x[0]>y[0])                      //若x[]位数比y[]位数多，返回1
    return 1;
  if(x[0]<y[0])                      //若x[]位数比y[]位数少，返回-1
    return -1;
  for(int i=x[0]; i>=1; i--)         //如果位数相等，则逐数字比较
    if(x[i]!=y[i])
      return x[i]>y[i]?1:-1;
  return 0;                          //如果相等，返回0
}

void Copy(int x[],int y[])           //将x[]复制给y[]
{
  memcpy(y,x,sizeof(int)*MAXN);
}

void Mul(int x[],int k)              //计算高精度x[]乘低精度k，其中0<=k<=9
{
  for(int i=1; i<=x[0]; i++)         //乘法运算
    x[i]*=k;
  for(int i=1; i<=x[0]; i++)           //对大于等于10的数组元素进行整理
    if(x[i]>=10)
      x[i+1]+=x[i]/10,x[i]%=10;
  for(x[0]++; x[x[0]]==0; x[0]--); //重新确定位数
}

void Sub(int x[],int y[])            //计算x[]－y[]的差
{
  for(int i=1; i<=y[0]; i++)
    x[i]-=y[i];
  for(int i=1; i<x[0]; i++)
    if(x[i]<0)
    {
      x[i]+=10;
      x[i+1]--;
    }
  for(; x[x[0]]==0 && x[0]>=1; x[0]--); //重新确定位数
}

void Div()
{
  int tmp[MAXN];
  int point=min(b[0],a[0]);              //point表示被除数已经除到第几位
  for(int k=a[0]-point+1,i=1; i<=point; i++,k++)
    now[i]=a[k];                     //获得准备要被除的数
  now[0]=point;
  while(ans[0]<5050 && !(now[0]==1 && now[1]==0 && point>=a[0]))//二分法
  {
    int mid,l=0,r=9,k;
    while(l<=r)
    {
      mid=(l+r)>>1;
      Copy(b,tmp);                   //此处较耗时
      Mul(tmp,mid);                  //计算tmp[]*mid的值
      int g=Bigger(now,tmp);         //比较试除后的大小
      if(g==1)
      {
        k=mid;
        l=mid+1;
      }
      else if(g==-1)
        r=mid-1;
      else
      {
        k=mid;
        break;
      }
    }
    Copy(b,tmp);
    Mul(tmp,k);   //找到K值后，计算商，并得到新余数
    Sub(now,tmp);                    //计算余数
    ans[++ans[0]]=k;                 //保存商

    //新余数扩大10倍
    ++now[0];                        //位数加1
    for(int i=now[0]; i>=2; i--)     //整体前移一位，即扩大10倍
      now[i]=now[i-1];
    if( point<a[0] )                 //被除数如还有数没有取完，则继续取下一位数
      now[1]=a[a[0]-point],point++;
    else
    {
      now[1]=0;
      if(dot==0 && !(now[0]==1 && now[1]==0))//如果被除数都用完且还被除完
        dot=ans[0];                  //确定小数点
    }
  }
}

void Output()                        //输出结果
{
  int k=1,i;
   if(dot!=0)                         //有小数
  {
    for(; ans[k]==0 && dot>k; k++);  //删去前导零
    for(i=k; i<=dot; i++)
      cout<<ans[i];
    for(cout<<"."; i<=ans[0] && i-k+1<=5000; i++) //控制输出位数为5000
      cout<<ans[i];
  }
  else                               //没有小数
  {
    for(; ans[k]==0 && ans[0]>k; k++);//删去前导零
    for(; k<=ans[0]; k++)
      cout<<ans[k];
  }
  cout<<endl;
}

void CheckZero()                     //除数或者被除数为零单独处理
{
  if(b[0]==1 && b[1]==0)
  {
    cout<<"Divisor is 0"<<endl;
    exit(0);
  }
  if(a[0]==1 && a[1]==0)
  {
    cout<<0<<endl;
    exit(0);
  }
}

void Init(string tmp,int a[])        //字符串转为整型数组
{
  a[0]=tmp.size();                   //第0位元素保存位数
  for(int i=a[0]-1; i>=0; i--)
    a[a[0]-i]=tmp[i]-'0';            //如1234560共7位数，保存为70654321000...000
}

int main()
{
  //freopen("div.in","r",stdin);
  //freopen("div.out","w",stdout);
  string s1,s2;
  cin>>s1>>s2;
  Init(s1,a);                        //字符串转数组
  Init(s2,b);
  CheckZero();                       //检查是否除数或被除数为0
  Div();                             //除法运算
  Output();
  return 0;
}

