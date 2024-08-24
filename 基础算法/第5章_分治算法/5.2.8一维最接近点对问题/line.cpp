//一维最接近点对
#include <bits/stdc++.h>
using namespace std;

struct cpair
{
  float dist,d1,d2;                 //保存两点距离及两点坐标
};
float s[100];

float Max(float s[],int b,int e)    //返回s[b]到s[e]中的最大值
{
  float m1=s[b];
  for(int i=b+1; i<=e; i++)
    m1=max(m1,s[i]);
  return m1;
}

float Min(float s[],int b,int e)    //返回s[b]到s[e]中的最小值
{
  float m1=s[b];
  for(int i=b+1; i<=e; i++)
    m1=min(m1,s[i]);
  return m1;
}

cpair Calc(float s[],int n)         //返回s[]中最近距离的点对及其距离
{
  if(n<2)                           //当点个数不足2时,返回具有无穷大的dist值
    return cpair {1e9,0,0};         //此处使用了C++11标准,竞赛规则可能不支持
  float m1=Max(s,0,n-1);            //获取s[]的最大值
  float m2=Min(s,0,n-1);            //获取s[]的最小值
  float Mid=(m1+m2)/2;              //找出点的中间值
  float s1[n],s2[n];                //通过开辟左右数组保存元素
  int k1=0,k2=0;
  for(int i=0; i<n; i++)            //将各点按与Mid的大小关系分为s1和s2组
    s[i]<=Mid?s1[k1++]=s[i]:s2[k2++]=s[i];
  cpair d1=Calc(s1,k1);             //递归求s1组的最近距离
  cpair d2=Calc(s2,k2);             //递归求s2组的最近距离
  float p=Max(s1,0,k1-1);
  float q=Min(s2,0,k2-1);
  if((q-p)<min(d1.dist,d2.dist))
    return cpair {q-p,q,p};         //此处使用了C++11标准,竞赛规则可能不支持
  else
    return d1.dist<d2.dist?d1:d2;
}

int main()
{
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  int m;
  cin>>m;                           //输入点的个数
  for(int i=0; i<m; i++)            //输入各点坐标
    cin>>s[i];
  cout<<Calc(s,m).dist<<endl;
  return 0;
}

