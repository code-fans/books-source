//ËÄÉ«µØÍ¼
#include<bits/stdc++.h>
using namespace std;
#define N 1001

int m;
vector <bool> Map[N];
int Color[N];

inline bool IsNumber(char c)
{
  return (c>='0' && c<='9');
}

int Try(int k)
{
  for(int i=0; i<Map[k].size(); i++)
    if(Color[Map[k][i]]==Color[k] && k!=i)
      return 0;
  return 1;
}

int main()
{
//  //freopen("map.in","r",stdin);
//  //freopen("map.out","w",stdout);
  cin>>m;
  char c;
  getchar();
  for(int i=1; i<=m; i++)
  {
    do
    {
      int num=0;
      while(IsNumber(c=getchar()))
        num=(num<<3)+(num<<1)+(c^48);
      //Map[i][num]=Map[num][i]=1;
      Map[i].push_back(num);
      Map[num].push_back(i);
    }
    while(c!='\n');
  }
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

