//һά��ӽ����
#include <bits/stdc++.h>
using namespace std;

struct cpair
{
  float dist,d1,d2;                 //����������뼰��������
};
float s[100];

float Max(float s[],int b,int e)    //����s[b]��s[e]�е����ֵ
{
  float m1=s[b];
  for(int i=b+1; i<=e; i++)
    m1=max(m1,s[i]);
  return m1;
}

float Min(float s[],int b,int e)    //����s[b]��s[e]�е���Сֵ
{
  float m1=s[b];
  for(int i=b+1; i<=e; i++)
    m1=min(m1,s[i]);
  return m1;
}

cpair Calc(float s[],int n)         //����s[]���������ĵ�Լ������
{
  if(n<2)                           //�����������2ʱ,���ؾ���������distֵ
    return cpair {1e9,0,0};         //�˴�ʹ����C++11��׼,����������ܲ�֧��
  float m1=Max(s,0,n-1);            //��ȡs[]�����ֵ
  float m2=Min(s,0,n-1);            //��ȡs[]����Сֵ
  float Mid=(m1+m2)/2;              //�ҳ�����м�ֵ
  float s1[n],s2[n];                //ͨ�������������鱣��Ԫ��
  int k1=0,k2=0;
  for(int i=0; i<n; i++)            //�����㰴��Mid�Ĵ�С��ϵ��Ϊs1��s2��
    s[i]<=Mid?s1[k1++]=s[i]:s2[k2++]=s[i];
  cpair d1=Calc(s1,k1);             //�ݹ���s1����������
  cpair d2=Calc(s2,k2);             //�ݹ���s2����������
  float p=Max(s1,0,k1-1);
  float q=Min(s2,0,k2-1);
  if((q-p)<min(d1.dist,d2.dist))
    return cpair {q-p,q,p};         //�˴�ʹ����C++11��׼,����������ܲ�֧��
  else
    return d1.dist<d2.dist?d1:d2;
}

int main()
{
  freopen("line.in","r",stdin);
  freopen("line.out","w",stdout);
  int m;
  cin>>m;                           //�����ĸ���
  for(int i=0; i<m; i++)            //�����������
    cin>>s[i];
  cout<<Calc(s,m).dist<<endl;
  return 0;
}

