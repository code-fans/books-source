//���ڰ������״̬�ܹ�Ҳ��9!=362880,������ȫ���Բ���set����,string�洢״̬,map�洢����̬��Ҫ�Ĳ���
#include <bits/stdc++.h>
using namespace std;
short dy[4]= {-1,1,0,0};
short dx[4]= {0,0,-1,1};
string dir="durl";//���﷽������и���Ҫ��һ��Ŷ
set<string> f;
map<string,string> m;

struct node
{
  string s;
  string path;
  int pos;
  node() {}
  node(string str,string pa,int Pos)
  {
    s=str;
    path=pa;
    pos=Pos;
  }
};

void pre()
{
  queue<node> q;
  q.push(node("12345678x","",8));
  m["12345678x"]="";
  f.insert("12345678x");
  while(!q.empty())
  {
    node h=q.front();
    q.pop();
    short a=h.pos/3;//ģ��һ����������
    short b=h.pos%3;
    for(int i=0; i<4; i++)
    {
      short y=a+dy[i];
      short x=b+dx[i];
      if(y<0||y>2||x<0||x>2)//�ж��Ƿ��ڷ�Χ��
        continue;
      short pos=3*y+x;
      swap(h.s[h.pos],h.s[pos]);
      if(f.find(h.s)==f.end()) //ʹ��set��������
      {
        q.push(node(h.s,dir[i]+h.path,pos));
        f.insert(h.s);
        m[h.s]=dir[i]+h.path;
      }
      swap(h.s[h.pos],h.s[pos]);//�����ڼ�¼�����Ҫ��ת����  ��װʲô��û����
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  pre();
  char input;
  while(cin>>input) //�����������ںü����ո�,���������scanfע�������ʽ
  {
    string v="";
    v=v+input;
    for(short i=1; i<=8; i++)
    {
      cin>>input;
      v=v+input;
    }
    if(m[v]==""&&v!="12345678x")//���ڸ���״̬��������̬����û�в���,��Ҫ���޽������ֱ�һ��
      cout<<"unsolvable"<<endl;
    else
      cout<<m[v]<<endl;
  }
  return 0;
}

