//��չ������
#include <bits/stdc++.h>
using namespace std;

int Left[110],Right[110];                        //��������ӡ��Ҷ����±�
char Node[110];

char CreateTree(int& i)                          //����,iΪ���ñ���
{
  int cur=i;                                     //��ǰλ��curȷ��Ϊi
  if(Node[cur]!='.')
  {
    i++;
    Left[cur]=CreateTree(i);
    i++;
    Right[cur]=CreateTree(i);
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
  freopen("extree.in","r",stdin);
  freopen("extree.out","w",stdout);
  cin.getline(Node+1,110);
  int n=1;
  CreateTree(n);                                 //������n��Ϊ��������
  Inorder(1);
  printf("\n");
  Postorder(1);
  printf("\n");
  return 0;
}

