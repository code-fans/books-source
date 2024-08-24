//由于八数码的状态总共也就9!=362880,所以完全可以采用set判重,string存储状态,map存储到终态需要的步数
#include <bits/stdc++.h>
using namespace std;
short dy[4]= {-1,1,0,0};
short dx[4]= {0,0,-1,1};
string dir="durl";//这里方向和题中给的要反一下哦
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
    short a=h.pos/3;//模拟一下上下左右
    short b=h.pos%3;
    for(int i=0; i<4; i++)
    {
      short y=a+dy[i];
      short x=b+dx[i];
      if(y<0||y>2||x<0||x>2)//判断是否在范围内
        continue;
      short pos=3*y+x;
      swap(h.s[h.pos],h.s[pos]);
      if(f.find(h.s)==f.end()) //使用set进行判重
      {
        q.push(node(h.s,dir[i]+h.path,pos));
        f.insert(h.s);
        m[h.s]=dir[i]+h.path;
      }
      swap(h.s[h.pos],h.s[pos]);//这里在记录完后需要再转回来  假装什么都没发生
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  pre();
  char input;
  while(cin>>input) //由于输入间存在好几个空格,所以如果用scanf注意输入格式
  {
    string v="";
    v=v+input;
    for(short i=1; i<=8; i++)
    {
      cin>>input;
      v=v+input;
    }
    if(m[v]==""&&v!="12345678x")//由于给出状态即是最终态所以没有步数,需要与无解的情况分别一下
      cout<<"unsolvable"<<endl;
    else
      cout<<m[v]<<endl;
  }
  return 0;
}

