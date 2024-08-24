//Ñ¡¾Ù
#include <bits/stdc++.h>
using namespace std;

struct person
{
  char name[150];
  int count;
} leader[200];

int main()
{
  //freopen("kind.in","r",stdin);
  //freopen("kind.out","w",stdout);
  int n,m;
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>leader[i].name;
    leader[i].count=0;
  }
  cin>>m;
  char name[m];
  for(int i=1; i<=m; i++)
  {
    cin>>name;
    for(int j=0; j<n; j++)
      if(strcmp(name,leader[j].name)==0)
        leader[j].count++;
  }
  for(int i=0; i<n; i++)
    cout<<leader[i].name<<" "<<leader[i].count<<endl;
  return 0;
}
