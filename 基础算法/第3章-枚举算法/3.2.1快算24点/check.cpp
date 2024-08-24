//check
#include <bits/stdc++.h>
using namespace std;

int F(int x,int k, int y)
{
  if(k==1) return x+y;
  if(k==2) return max(x,y)-min(x,y);
  if(k==3) return x*y;
  return (y==0 || x<y || x%y!=0) ? -999999 : x/y;
}

bool Judge(int a[])
{
  sort(a+1,a+5);
  do
  {
    for (int i = 1; i <= 4; i++)
      for (int j = 1; j <= 4; j++)
        for (int k = 1; k <= 4; k++)
          if (F(F(F(a[1],i,a[2]),j,a[3]),k,a[4])==24)
            return 1;
          else if(F(F(a[1],i,a[2]),k,F(a[3],j,a[4]))==24)
            return 1;
  }
  while(next_permutation(a + 1, a + 5));
  return 0;
}

int main()
{
  freopen("24.in","r",stdin);       //Dev-C++���ܿ���ƽ̨��Ӵ˾�
  FILE *in1=fopen("24.out","r");    //�����������Ľ��,��һ�ֶ��ļ���д��
  FILE *in2=fopen("24.in","r");     //������������
  int a[5],hash[20000]= {0};
  int *h=&hash[10000];              //���±����飬��¼һ�����ֵ�ʹ�ô���
  int A,B,C;
  fscanf(in2,"%d%d%d%d",&a[1],&a[2],&a[3],&a[4]);//���������ļ�
  h[a[1]]++,h[a[2]]++,h[a[3]]++,h[a[4]]++;
  if(Judge(a)==0)                   //���ñ���ж��Ƿ��޽�
  {
    char t[100]="";
    fscanf(in1,"%s",t);
    if(strcmp(t,"No")==0)
      return 0;
    return 1;                       //���أ���ʾ���г���,�������������
  }
  for(int i=1; i<=3; i++)           //����𰸲���
  {
    char op1,op2;
    fscanf(in1,"%d%c%d%c%d",&A,&op1,&B,&op2,&C);
    h[A]--;
    h[B]--;
    h[C]++;                         //�����µ�����
    if(op2!='=' || A<B || C<0) return 1;
    if(h[A] < 0 || h[B] < 0)   return 1;//����ʹ�ó�����,��𰸴���
    if(op1=='+' && A + B != C) return 1;
    if(op1=='-' && A - B != C) return 1;
    if(op1=='*' && A * B != C) return 1;
    if(op1=='/' && (B==0 || A%B!=0 || A/B!=C)) return 1;
  }
  if(C!=24 ) return 1;
  printf("Right! ");
  fclose(in1);
  fclose(in2);
  return 0;
}

