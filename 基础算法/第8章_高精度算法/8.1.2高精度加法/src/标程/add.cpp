//�򵥸߾��ȼӷ�
#include <bits/stdc++.h>
using namespace std;
#define MAXN 5001

void Add(int x[],int y[],int ans[],int len)
{
  for(int j=0; j<len; ++j)             //���±�0��ʼ��λ��ӵ�len-1
  {
    ans[j]+=x[j]+y[j];                 //��ӽ���浽ans[]
    for(int i=j; ans[i]>=10; ++i)
    {
      ans[i+1]++;                      //��д��ans[i+1]+=ans[i]/10���ٶ���
      ans[i]-=10;                      //��д��ans[i]%=10���ٶ���
    }
  }
}

void Init(int x[],string str, int len) //�ַ���תΪ��������
{
  for(int i=0; i<len; i++)
    x[len-i-1]=str[i]-'0';             //����ת��
}

void Output(int ans[])                 //�����ӵĽ��
{
  int i=MAXN-1;
  for(; ans[i]==0 && i>0; i--);        //����ǰ��0
  for(; i>=0; i--)
    printf("%d",ans[i]);
  printf("\n");
}

int main()
{
  ////freopen("add.in","r",stdin);
  ////freopen("add.out","w",stdout);
  int a[MAXN]= {0},b[MAXN]= {0},ans[MAXN]= {0};
  string str1,str2;
  cin>>str1>>str2;
  int la=str1.size();
  int lb=str2.size();
  Init(a,str1,la);                     //��ʼ��Ϊ��������
  Init(b,str2,lb);
  for(int i=0; i<=100; i++)
    cout<<a[i];
  return 0;
  Add(a,b,ans,la>=lb?la:lb);           //���ĸ�����Ϊla��lb�����ֵ
  Output(ans);
  return 0;
}

