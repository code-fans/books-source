//һ���򵥵Ķ��������������,������ģ��������Ľṹ,ʹ��ջ�Ż�
#include <bits/stdc++.h>
#include <windows.h>                   //��ʽ������Ҫ�����ͷ�ļ� 
#define MAX 1000000                    //�����������
using namespace std;

//dataΪ�������,lc,rcΪ�������Һ���
int data[MAX],p[MAX],lc[MAX],rc[MAX];
int root = -1;
int Stack[MAX];                        //�����ṩ�����λ��ջ
int top = 0;

//��������ֵΪk�Ľ�㣬���������������е�λ�ã���������ڣ��򷵻�-1
int tree_search(int R,int k)
{
  while(R != -1 && data[R] != k)
    k<data[R] ? R = lc[R]:R = rc[R];
  return R;
}

void tree_insert(int z)//������z���ý����pre_insert()�������Ѿ���ֵ
{
  int x = root, y = -1;
  while(x != -1)
  {
    y = x;
    if(data[z] < data[x])
      x = lc[x];
    else
      x = rc[x];
  }
  p[z] = y;
  if(y == -1)                        //������ǿյ�
    root = z;                        //z��������
  else if (data[z] < data[y])
    lc[y] = z;
  else
    rc[y] = z;
}

void pre_insert(int ins_data)        //�������뵽����
{
  int z = Stack[top++];
  data[z] = ins_data;
  tree_insert(z);
}

int tree_minimum(int x)              //�����ϵ���Сֵ
{
  while(lc[x] != -1 )
    x = lc[x];
  return x;
}

int tree_successor(int x)            //��ĳ���ĺ��
{
  if(rc[x] != -1)         //���ý���������������Ѱ����������������
    return tree_minimum(rc[x]);
  //���������������ȣ�����ֱ������ĳ��������丸�������ӽ��Ϊֹ
  int y = p[x];
  while(y != -1 && x == rc[y])
  {
    x = y;
    y = p[y];
  }
  return y;
}

void tree_delete(int z)         //ɾ������zλ���ϵĽ��
{
  int Son,y;
  //���������������һ�����ӣ���ɾ���ý��
  if(lc[z] == -1 || rc[z] == -1)
    y = z;
  else                          //����Ѱ������
    y = tree_successor(z);

  if(lc[y] != -1)               //��xָ��y�����ӻ��Һ���(����еĻ�)
    Son = lc[y];
  else
    Son = rc[y];

  //���y�к��ӣ���ô�������沽����ָ�����ĺ��ӵĸ����ָ��y�ĸ����
  if(Son != -1)
    p[Son] = p[y];

  if(p[y] == -1)                   //ɾ���Ľ��Ϊ�����
    root = Son;
  else if(y == lc[p[y]])           //ɾ���Ľ��yΪy������
    lc[p[y]] = Son;
  else                             //ɾ���Ľ��yΪy���Һ���
    rc[p[y]] = Son;

  if(y != z)                       //��y��ֵ����z
    data[z] = data[y];

  //ɾ����� y
  data[y] = -1;
  lc[y] = -1;
  rc[y] = -1;
  p[y] = -1;
  Stack[--top] = y;
}

void pre_delete(int data)                      //ɾ������
{
  int k = tree_search(root,data);              //���ֲ��ҵ�k��λ��
  if(k != -1)
    tree_delete(k);
}

void init()                                    //��ʼ�����н�㣬Ĭ�Ͽ�ֵΪ-1
{
  for(int i = 0 ; i < MAX; ++ i)
  {
    data[i] = rc[i] = lc[i] = p[i] = -1;
    Stack[i] = i;
  }
}

void Display(int x)                            //����������ķ�ʽ��ʾ
{
  if(x == -1) return ;
  if(lc[x] != -1)
    Display(lc[x]);
  cout<<data[x]<<" left:"<<lc[x]<<" right:"<<rc[x]<<" parent:"<<p[x]<<"\n";
  if(rc[x] != -1)
    Display(rc[x]);
}

void GraphiShow(int root,int x,int y,int k,int space)//ͼ�λ������
{
  if(root!=-1)
  {
    HANDLE hOutput;
    COORD location;
    location.X=x;
    location.Y=y;
    hOutput=GetStdHandle(STD_OUTPUT_HANDLE);        //�����Ļ���
    SetConsoleCursorPosition(hOutput,location);     //��λ��굽���꣨x,y����
    if(k==1)
      cout<<data[root]<<"/";                        //�����ʾ������
    else if(k==2)
      cout<<"\\"<<data[root];                       //�����ʾ������
    else
      cout<<data[root];                             //��������
    GraphiShow (lc[root],x-space,y+1,1,space/2);
    GraphiShow (rc[root],x+space,y+1,2,space/2);
  }
}

int main()
{
  int ins,tmp;
  cout<<"1.����һ��ֵ\n";
  cout<<"2.ɾ��һ��ֵ\n";
  cout<<"3.ͼ�λ����\n";
  init();
  while(cin>>ins)
  {
    switch(ins)
    {
      case 1:
        cin>>tmp;
        pre_insert(tmp);
        Display(root);                              //�������
        break;
      case 2:
        cin>>tmp;
        pre_delete(tmp);
        Display(root);
        break;
      case 3:
        system("cls");
        GraphiShow(root,40,1,0,20);
        break;
      default:
        return 0;
    }
  }
  return 0;
}

