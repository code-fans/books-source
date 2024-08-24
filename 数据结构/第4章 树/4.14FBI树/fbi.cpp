//FBI��
#include <bits/stdc++.h>
using namespace std;

struct node
{
  char c;
  int value;
  int leftson,rightson;
} tree[2500];

char FBI(int left, int right)                 //ȷ���������
{
  if(tree[left].c=='B' && tree[right].c=='B')
    return 'B';
  else if(tree[left].c=='I' && tree[right].c=='I')
    return 'I';
  else
    return 'F';
}

void PostOrder(int root)                      //�������
{
  if(root!= -1)
  {
    PostOrder(tree[root].leftson);
    PostOrder(tree[root].rightson);
    printf("%c",tree[root].c);
  }
}

int main()
{
  freopen("fbi.in","r",stdin);
  freopen("fbi.out","w",stdout);
  int N;
  scanf("%d",&N);
  for(int i=(1<<N); i<(1<<(N+1)); i++)        //�ӽ����2^n~2^(n+1)
  {
    scanf("%1d",&tree[i].value);              //����Ҷ�ӽ�㸳ֵ
    tree[i].leftson = -1;
    tree[i].rightson = -1;
    tree[i].value?tree[i].c='I':tree[i].c = 'B';
  }
  int temp = N - 1 ;
  while(temp>=0)
  {
    for(int i=1<<temp; i<1<<(temp+1); i++)    //�ӵ����ڶ�������
    {
      tree[i].leftson=2*i;
      tree[i].rightson=2*i+1;
      tree[i].c=FBI(2*i,2*i+1);               //�����Ҷ���ȷ����������
    }
    temp--;
  }
  PostOrder(1);
  printf( "\n" );
  return 0;
}

