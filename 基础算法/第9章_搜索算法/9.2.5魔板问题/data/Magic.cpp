//魔板问题-STL
#include<bits/stdc++.h>
using namespace std;

string goal;
map<string,string>m;
queue<string>q;

void A(string x)
{
  string t=x;
  for(int i=0; i<4; i++)
    swap(x[i],x[7-i]);
  if(!m.count(x)) //没有出现过
  {
    q.push(x);
    m[x]=m[t]+'A';
  }
}

void B(string x)
{
  string t=x;
  x[0]=t[3],x[1]=t[0],x[2]=t[1],x[3]=t[2],x[4]=t[5],x[5]=t[6],x[6]=t[7],x[7]=t[4];
  if(!m.count(x))
  {
    q.push(x);
    m[x]=m[t]+'B';
  }
}

void C(string x)
{
  string t=x;
  x[1]=t[6],x[2]=t[1],x[5]=t[2],x[6]=t[5];
  if(!m.count(x))
  {
    q.push(x);
    m[x]=m[t]+'C';
  }
}

int main()
{
  //freopen("Magic.in","r",stdin);
  //freopen("Magic.out","w",stdout);
  char c;
  for(int i=0; i<8; i++)
  {
    cin>>c;
    goal+=c;
    getchar();
  }
  q.push("12345678");
  m["12345678"]="";
  while(!q.empty())
  {
    A(q.front());
    B(q.front());
    C(q.front());
    if(m.count(goal)!=0)
      break;
    q.pop();
  }
  cout<<m[goal].size()<<endl<<m[goal]<<endl;
  return 0;
}
