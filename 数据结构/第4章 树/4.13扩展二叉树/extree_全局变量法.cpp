//��չ������
#include <bits/stdc++.h>
using namespace std;

int Left[110],Right[110];                        //��������ӡ��Ҷ����±�
char Node[110];
int nn=1;//��Ϊȫ�ֱ����������ñ���Ч����һ���ģ������������ͼ��� 

char CreateTree()                          //����,iΪ���ñ���
{
  int cur=nn;                                     //��ǰλ��curȷ��Ϊi
  if(Node[cur]!='.')
  {
    nn++;
    Left[cur]=CreateTree();
    nn++;
    Right[cur]=CreateTree();
  }
  return cur;
}

void Inorder(int i)                              //�������
{
  if(Node[i]=='.')
    return;
  Inorder(Left[i]);
  printf("%c",Node[i]);
  Inorder(Right[i]);
}

void Postorder(int i)                            //�������
{
  if(Node[i]=='.')
    return;
  Postorder(Left[i]);
  Postorder(Right[i]);
  printf("%c",Node[i]);
}

int main()
{
  //freopen("extree.in","r",stdin);
  //freopen("extree.out","w",stdout);
  gets(Node+1);
  CreateTree();
  Inorder(1);
  printf("\n");
  Postorder(1);
  printf("\n");
  return 0;
}

