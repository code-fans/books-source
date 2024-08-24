//���������� - ˫����������ʾ
#include <bits/stdc++.h>
using namespace std;

struct node
{
  string str;                                 //�����ַ�����ʽ�İ�����
  int pre;                                    //������һ����λ��
};
vector <node> c[2];
int p1,p2,t1,t2;                              //p1,p2ָ�����,t1,t2ָ��β
int Step;                                     //StepΪ��������

void OutC1(int v)                             //�ݹ������������1
{
  Step++;
  if(v==0)
    cout<<c[0][v].str<<endl;
  else
  {
    OutC1(c[0][v].pre);
    cout<<c[0][v].str<<endl;
  }
}

void OutC2(int v)                             //�������2
{
  while(1)
  {
    Step++;
    if(c[1][v].str=="123804765")
    {
      cout<<"123804765\n";
      break;
    }
    cout<<c[1][v].str<<endl;
    v=c[1][v].pre;
  }
}

int Check(int idx,string str,int key)         //keyΪ0,�����ұ�����Ԫ��
{
  for(int i=0; i<c[idx].size(); i++)
    if(str==c[idx][i].str)
    {
      if(key==1)                              //keyΪ1
        idx==0? t1=i:t2=i;                    //ȷ����һ���е��غ�λ��
      return 1;
    }
  return 0;
}

void BFS(int idx,int &p,int O,int loc)
{
  string st=c[idx][p].str;
  swap(st[O],st[O+loc]);                      //��������
  if(Check(idx,st,0)==0)                      //���ұ������Ƿ�����ͬ
    c[idx].push_back(node {st,p});            //ע����C++11д��
  if(Check((idx+1)%2,st,1))                   //������һ�����Ƿ����غ�
  {
    idx==0?t1=c[0].size()-1:t2=c[1].size()-1; //ȷ����ǰ���еĶ�β
    OutC1(c[0][t1].pre);
    OutC2(t2);
    printf("%d\n",Step-1);
    exit(0);                                  //ֱ���˳����򣬷���0ֵ
  }
}

void Add(int idx,int &p)                      //��Ӷ���2
{
  int O=c[idx][p].str.find('0',0);            //�������봮��0��λ��
  if(O >= 3)                                  //��������
    BFS(idx,p,O,-3);                          //-3ΪҪ����λ�õ�ƫ����
  if(O < 6)
    BFS(idx,p,O,3);                           //��������
  if((O % 3) > 0)
    BFS(idx,p,O,-1);                          //��������
  if((O % 3) < 2)
    BFS(idx,p,O,1);                           //��������
  p++;                                        //����ָ����ƣ�������
}

int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  string star;
  for(int i=0,t; i<=8; i++)
  {
    scanf("%d",&t);
    star+=t+'0';
  }
  string goal="123804765";                    //Ŀ��״̬
  c[0].push_back(node {star,0});              //����1�����ʼֵ��C++11д��
  c[1].push_back(node {goal,0});              //����2����Ŀ��ֵ��C++11д��
  while(c[0].size()<5000 || c[1].size()<5000)
    c[0].size()<=c[1].size()?Add(0,p1):Add(1,p2); //������չ�̶���
  printf("-1\n");
  return 0;
}

