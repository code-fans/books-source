//�߾��������Ե;�����2
#include <bits/stdc++.h>
using namespace std;
#define MAXN 100

int Remainder=0;                 //����,ע��Ҫ��Сд��ĸ�������
int a[MAXN+1],ans[MAXN+1];

void Division(string str,int b, int *ans)
{
  int len=str.size();
  for(int i=1; i<=len; ++i)      //��ʼ��Ϊ����
    a[i]=str[i-1]-'0';

  for (int i=1; i<=MAXN; i++ )   //�������
  {
    if(i==len+1)
      ans[0]=i;                  //��¼С����Ӧ���ֵ�λ��
    Remainder = Remainder * 10 + a[i];
    ans[i] = Remainder / b;
    Remainder = Remainder % b;
    if(Remainder==0 && i>len)    //����������������������ѱ�����
      break;
  }
}

void Output(int *ans,int len)
{
  int begin=1,end=MAXN ;
  while(!ans[begin])
    begin++;                     //�ҳ��ʼ��λ��
  if (begin>ans[0])              //�˴��Ƿ�ֹ����0.00000xxx���ʱ����ǰ���0����
    begin=ans[0];
  while(!ans[end])
    end--;                       //�ҳ���ĩβ����Чλ��
  if(end<len)
    end=len;                     //��ֹ����X000000000��ʱ�򣬽���Чλ0��ȥ
  if(ans[0]==begin)              //��ֹ����0.XXXXX ��ʱ��ǰ��û�м�0.
    cout<<'0';
  for(int i=begin; i<=end; i++)
  {
    if(i==ans[0])
      cout<<'.';
    cout<<ans[i];
  }
  cout<<","<<Remainder<<'\n';    //�������
}

int main()
{
  freopen("sample_div2.in","r",stdin);
  freopen("sample_div2.out","w",stdout);
  string str;
  int b;
  cin>>str;                      //����߾��ȱ�����
  cin>>b;                        //����;��ȳ���
  if(b==0)
    cout<<"Divisor is 0"<<'\n';
  else
  {
    Division(str,b,ans);
    Output(ans,str.size());
  }
  return 0;
}

