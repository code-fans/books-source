//ËÄÉ«µØÍ¼
#include<iostream>
#include<set>
using namespace std;
#define N 101

int m;
set <int> Map[N];
int Color[N];

int Try(int k)
{
  for(set<int>::iterator i=Map[k].begin(); i!=Map[k].end(); i++)
    if(Color[(*i)]==Color[k] && k!=*i)
      return 0;
  return 1;
}

int main()
{
//  freopen("map.in","r",stdin);
//  freopen("map.out","w",stdout);
  cin>>m;
  char c;
  getchar();
  for(int i=1; i<=m; i++)
    do
    {
      int num=0;
      for(c=getchar(); c>='0' && c<='9'; c=getchar())
        num=(num<<3)+(num<<1)+(c^48);
      Map[i].insert(num);
      Map[num].insert(i);
    }
    while(c!='\n');
  for(int k=1; k<=m;)
  {
    do
      Color[k]++;
    while((Color[k]<=4)&&(!Try(k)));
    if(Color[k]>4)
      k--;
    else
      Color[++k]=0;
  }
  for(int i=1; i<=m; i++)
    printf("%d%c",Color[i],(i==m?'\n':' '));
  return 0;
}

