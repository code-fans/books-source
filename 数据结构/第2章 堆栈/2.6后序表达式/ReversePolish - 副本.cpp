//������ʽ
#include <bits/stdc++.h>
using namespace std;

char Exp[100];                            //�洢��׺���ʽ,ע�ⲻ��д��exp
char Stack[100];                          //��Ϊջʹ��,ע�ⲻ��д��stack
int t,top;                                //tΪExp���±�,topΪStack���±�

void PutExp()                             //������ʽ
{
  for (int j=1; j<t; j++)
    printf("%c",Exp[j]=='#' ? ' ':Exp[j]);
  cout<<endl;
}

void Trans()                                   //ת���ɺ�׺���ʽ
{
  char ch;
  do
  {
    scanf("%c",&ch);
    if(ch>='0' && ch<='9')                     //����һ����������
    {
      while(ch>='0' && ch<='9')
        Exp[++t]=ch,scanf("%c",&ch);
      Exp[++t]='#';
    }
    switch(ch)
    {
      case '(':
        Stack[++top]=ch;                //������������ջ
        break;
      case ')':
        while(Stack[top]!='(')          //������
          Exp[++t]=Stack[top],top--;     //��ջ��Expֱ��������
        top--;                          //ɾ����ջ���������
        break;
      case '+':                                //����ǼӺźͼ���
      case '-':
        while (top!=0 && Stack[top]!='(')//ֱ������������
          Exp[++t]=Stack[top],top--;    //��ջ��������ʽ
        Stack[++top]=ch;                //��ջ�в���'+'��'-'
        break;
      case '*':                                //����ǳ˺źͳ���
      case '/':
        while (Stack[top]=='*' || Stack[top]=='/')
          Exp[++t]=Stack[top],top--;    //��ջȫ��'*'��'/'
        Stack[++top]=ch;                //ջ�в���˺Ż����
        break;
    }
  }
  while(ch!='#');
  while (top!=0)                               //ȫ��ջԪ�طŵ�������ʽ
    Exp[++t]=Stack[top],top--;
  Exp[++t]='#';
}

double Compvalue()                             //�����׺���ʽ��ֵ
{
  double stk[100];                             //��Ϊ����ջʹ��
  t=1,top=0;                               //tΪExp�±�,topΪstk�±�
  char ch=Exp[t++];
  while (ch!='#')
  {
    switch (ch)
    {
      case '+':
        stk[top-1]=stk[top-1]+stk[top];
        top--;
        break;
      case '-':
        stk[top-1]=stk[top-1]-stk[top];
        top--;
        break;
      case '*':
        stk[top-1]=stk[top-1]*stk[top];
        top--;
        break;
      case '/':
        if (stk[top]!=0)
          stk[top-1]=stk[top-1]/stk[top];
        else
          printf("-1\n"),exit(0);       //�쳣�˳�
        top--;
        break;
      default:
        int d=0;
        while (ch>='0' && ch<='9')      //�ж�Ϊ�����ַ�
        {
          d=10*d+ch-'0';                //�������ַ�ת���ɶ�Ӧ��ֵ
          ch=Exp[t++];
        }
        stk[++top]=d;
    }
    ch=Exp[t++];
  }
  return stk[top];
}

int main()
{
  //freopen("ReversePolish.in","r",stdin);
  //freopen("ReversePolish.out","w",stdout);

  Trans();                                     //ת�ɺ�׺���ʽ
  //PutExp();                                  //���������ʽ
  printf("%0.2f\n",Compvalue());               //���������
  return 0;
}

