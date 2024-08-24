//���ӱ��ʽ����
#include <bits/stdc++.h>
using namespace std;

char str[1000];
char op[1000];                          //���������
int Num[1000],lch[1000], rch[1000];
int Index=0;                            //��д��index��Linux���޷�ͨ��

int BuildTree(char *st, int L, int R)   //��������
{
  int flag=1;
  for(int i=L; i<R; i++)
  {
    if(!(st[i]>='0' && st[i]<='9'))     //�ж��Ƿ��в�����
    {
      flag=0;
      break;
    }
  }
  if(flag)                              //���ȫ������,����󷵻�
  {
    int sum=0;
    int j=1;
    for(int i=R-1; i>=L; i--)
    {
      sum+=(st[i]-'0')*j;
      j*=10;
    }
    int u=++Index;                      //�±��1��ʼ
    lch[u]=0;
    rch[u]=0;
    Num[u]=sum;
    return u;
  }
  int c1=-1;                            //��ǼӼ��Ĳ�����
  int c2=-1;                            //��ǳ˳��Ĳ�����
  int p=0;                              //������ŵ�ƥ����
  for(int i=L; i<R; i++)
  {
    if(st[i]=='(')
      p++;
    if(st[i]==')')
      p--;
    if(st[i]=='+' || st[i]=='-')
      if(p==0)                          //����������
        c1=i;
    if(st[i]=='*' || st[i]=='/')
      if(p==0)
        c2=i;
  }
  if(c1<0)                              //���û�мӼ�
    c1=c2;                              //��ô�ͳ˳�
  if(c1<0)                              //�����Ȼû�������
    return BuildTree(str,L+1, R-1);     //ȥ���˵����ź�ݹ�
  int u=++Index;
  lch[u]=BuildTree(st, L, c1);          //����Ϊʲô����c1-1����c1
  rch[u]=BuildTree(st, c1+1, R);
  op[u]=st[c1];
  return u;                             //�ݹ鲻�ܷ���Index,����ֵ����
}

double Cal(int i)                       //�����������ʽ�ı��ʽֵ
{
  if(lch[i]==0 && rch[i]== 0)
    return Num[i];
  else  if(op[i]=='+')
    return Cal(lch[i]) + Cal(rch[i]);
  else if(op[i]=='-')
    return Cal(lch[i]) - Cal(rch[i]);
  else if(op[i]=='*')
    return Cal(lch[i]) * Cal(rch[i]);
  else if(op[i]=='/')
    return Cal(lch[i]) / Cal(rch[i]);
  return 0;
}

int main()
{
  freopen("cal.in","r",stdin);
  freopen("cal.out","w",stdout);
  while(cin>>str)
  {
    Index=0;                            //����±�����ʼΪ0
    BuildTree(str, 0, strlen(str));
    printf("%.2f\n", Cal(1));
  }
  return 0;
}

