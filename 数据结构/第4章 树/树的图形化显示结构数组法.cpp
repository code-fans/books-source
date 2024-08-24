//����ͼ�λ���ʾ
#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
const int MAXN=32768;                  //2^15

int n;
struct tree
{
  int Left,Data,Right;
} tree[MAXN];

void Create(int *node,int len)
{
  for(int i=1; i<=len; i++)            //���������
  {
    tree[i].Data=node[i];              //Ԫ��ֵ������
    int pos=0,dir=0;
    while(dir==0)
    {
      if(node[i]<tree[pos].Data)       //�ж��Ƿ�Ϊ������
        if(tree[pos].Left!=-1)         //�����λ���ѱ�ռ��,����������
          pos=tree[pos].Left;
        else
          dir=1;                       //��Ϊ����
      else                             //�ж��Ƿ�Ϊ������
        if(tree[pos].Right!=-1)
          pos=tree[pos].Right;
        else
          dir=-1;                      //��Ϊ����
    }
    dir==1? tree[pos].Left=i:tree[pos].Right=i;
  }
}
//���ڳ�����ʼλ�ü���#include <windows.h>
//�β���x,yΪ���������꣬k��0��1��2������Ϊ�������ӡ����ӣ�space�����������
void GraphiShow(int root,int x,int y,int k,int space)//ͼ�λ�
{
  if(root!=-1)
  {
    //�˶δ������ڶ�λ��꣬������䣬�ճ�ֱ����������
    HANDLE hOutput;
    COORD location;
    location.X=x;
    location.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);       //�����Ļ���
    SetConsoleCursorPosition(hOutput,location);    //��λ��굽���꣨x,y����
    if(k==1)
      cout<<tree[root].Data<<"/";                       //�����ʾ������
    else if(k==2)
      cout<<"\\"<<tree[root].Data;                      //�����ʾ������
    else
      cout<<tree[root].Data;                            //��������
    GraphiShow (tree[root].Left,x-space,y+1,1,space/2);
    GraphiShow (tree[root].Right,x+space,y+1,2,space/2);
  }
}


int main()
{
  cin>>n;
  int node[n+1];
  for(int i=1; i<=n; i++)
    cin>>node[i];
  for(int i=0; i<MAXN; i++)
  {
    tree[i].Left=-1;
    tree[i].Data=0;
    tree[i].Right=-1;
  }
  Create(node,n);
  GraphiShow (1,20,3,0,20);
  return 0;
}

