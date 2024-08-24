//�򵥱��ʽ����
#include<bits/stdc++.h>
using namespace std;

char str[200];
int l[200],r[200];

int BuildTree(int i,int j)
{
  int k,posi;
  if(i==j)                              //��ֻ��һ���ַ�ʱ
  {
    l[i]=-1;                            //û�������
    r[i]=-1;                            //û���Ҷ���
    return i;
  }
  for(k=i; k<=j; k++)
    if(str[k]=='+' || str[k]=='-')      //����"+"��"-"
    {
      posi=k;                           //ȷ�������λ��
      break;
    }
  if(k>j)                               //��û��"+"��"-",�Ͳ���"*"��"/"
    for(int p=i; p<=j; p++)
      if(str[p]=='*' || str[p]=='/')    //����
      {
        posi=p;                         //ȷ�������λ��
        break;
      }
  l[posi]=BuildTree(i,posi-1);          //�����ǰһ��ݹ�
  r[posi]=BuildTree(posi+1,j);          //�������һ��ݹ�
  return posi;
}

void DispPre(int T)                     //��ӡǰ����ʽ
{
  if(T!=-1)
  {
    printf("%c",str[T]);
    DispPre(l[T]);
    DispPre(r[T]);
  }
}

void DispIn(int T)                      //��ӡ������ʽ
{
  if(T!=-1)
  {
    DispIn(l[T]);
    printf("%c",str[T]);
    DispIn(r[T]);
  }
}

void DispPost(int T)                    //��ӡ������ʽ
{
  if(T!=-1)
  {
    DispPost(l[T]);
    DispPost(r[T]);
    printf("%c",str[T]);
  }
}

int main()
{
  //freopen("calc.in","r",stdin);
  //freopen("calc.out","w",stdout);
  cin.getline(str,200);
  int root=BuildTree(0,strlen(str)-1);
  DispPre(root);
  cout<<endl;
  DispIn(root);
  cout<<endl;
  DispPost(root);
  cout<<endl;
  return 0;
}

