//������ʽ
#include <bits/stdc++.h>
using namespace std;

string Exp[100];                               //�������ʽ,����д��exp
int t,top;                                     //tΪExp���±�

void PutExp()                                  //������ʽ
{
  for(int j=1; j<=t; j++)
    cout<<Exp[j]<<" ";
  cout<<endl;
}

void Trans()                                   //ת���ɺ�׺���ʽ
{
  char Stack[100];                             //��Ϊջʹ��,����д��stack
  string ch;
  cin>>ch;
  for(int i=0; i<ch.size(); i++)
    if(ch[i]>='0' && ch[i]<='9')               //���������������ַ���
    {
      Exp[++t]=ch[i];
      while(i+1<ch.size() && ch[i+1]>='0' && ch[i+1]<='9')//���Ϊ��λ��
        Exp[t]+=ch[++i];                       //��λ��������һ��string��
    }
    else if(ch[i]=='(')
      Stack[++top]=ch[i];                      //������������ջ
    else if(ch[i]==')')
    {
      for(; Stack[top]!='('; top--)            //������
        Exp[++t]=Stack[top];                   //��ջ��Expֱ��������
      top--;                                   //ɾ����ջ���������
    }
    else if(ch[i]=='+' || ch[i]=='-')          //����ǼӺźͼ���
    {
      for(; top!=0 && Stack[top]!='('; top--)  //ֱ������������
        Exp[++t]=Stack[top];                   //��ջ��������ʽ
      Stack[++top]=ch[i];                      //��ջ�в���'+'��'-'
    }
    else if(ch[i]=='*' || ch[i]=='/')          //����ǳ˺źͳ���
    {
      for(; Stack[top]=='*' || Stack[top]=='/'; top--)
        Exp[++t]=Stack[top];                   //��ջȫ��'*'��'/'
      Stack[++top]=ch[i];                      //ջ�в���˺Ż����
    }
  for(; top!=0; top--)                         //ȫ��ջԪ�طŵ�������ʽ
    Exp[++t]=Stack[top];
}

double Compvalue()                             //�����׺���ʽ��ֵ
{
  double stk[100];                             //��Ϊ����ջʹ��
  top=0;                                       //topΪstk�±�
  for(int i=1; i<=t; i++)
  {
    if(Exp[i]!="+" && Exp[i]!="-" && Exp[i]!="*" && Exp[i]!="/" )
    {
      double d=0;
      for(int j=0; j<Exp[i].size(); j++)       //�������ַ���תΪ����
        d=10*d+(Exp[i][j]-'0');
      stk[++top]=d;
    }
    else
    {
      if(Exp[i]=="+")
        stk[top-1]=stk[top-1]+stk[top];
      else if(Exp[i]=="-")
        stk[top-1]=stk[top-1]-stk[top];
      else if(Exp[i]=="*")
        stk[top-1]=stk[top-1]*stk[top];
      else if(Exp[i]=="/")
        stk[top-1]=stk[top-1]/stk[top];
      top--;
    }
  }
  return stk[top];
}

int main()
{
  //freopen("ReversePolish.in","r",stdin);
  //freopen("ReversePolish.out","w",stdout);
  Trans();                                     //ת�ɺ�׺���ʽ
  //PutExp();                                  //���������ʽ�Ĳ���
  printf("%0.2f\n",Compvalue());               //���������
  return 0;
}

