//N�ʺ� - �ݹ��㷨1
#include <bits/stdc++.h>
using namespace std;

int n,board[21];

void Print()                //��ӡ���Ӳ���
{
  for(int i=1; i<=n; i++)
    printf("%d",board[i]);
  puts("");
}

void PrintGraph()           //ͼ�λ���ӡ����,���ڵ���
{
  for(int i=1; i<=n; ++i)
  {
    for(int j=1; j<=n; ++j)
      if(board[i]==j)
        printf("��");       //������ſ���word�����Ĳ��������Ѱ��
      else
        printf("��");
    puts("");
  }
  puts("");
}

int Try(int x,int y)        //����x��y�пɷ�ڷ�����,�ɹ�����1�����򷵻�0
{
  for(int j=1; j<x; j++)    //���������ѷźõ����Ƚ�
    if((board[j]==y)||(abs(x-j)==abs(board[j]-y)))
      return 0;
  return 1;
}

void Place(int x)           //�ݹ麯��
{
  if(x>n)                   //���ӵ�n���Ѱںã����ӡ�ɹ�����
  {
    Print();
    //PrintGraph();         //��ʹ�ø���䣬��ͼ�λ���ӡ����
  }
  else
    for(int y=1; y<=n; ++y) //�����������δ���������
      if(Try(x,y))          //������԰ڷ�
      {
        board[x]=y;         //��a[x]��ֵ
        Place(x+1);         //������һ�еĵݹ�
      }
}

int main()
{
  scanf("%d",&n);
  Place(1);                 //�ӵ�1�п�ʼ�ݹ�
  return 0;
}

