//烽火传递普通排序法
#include <bits/stdc++.h>
using namespace std;
int *v,*Line,*Pos,*head;

void sort(int i,int j)                 //快排
{
  int n=i,m=j,k=head[(i+j)/2],t;
  while(n<=m)
  {
    while(n<j && head[n]>k)n++;
    while(m>i && head[m]<k)m--;
    if(n<=m)
    {
      t=head[n];
      head[n]=head[m];
      head[m]=t;
      t=Pos[Line[n]];
      Pos[Line[n]]=Pos[Line[m]];
      Pos[Line[m]]=t;
      t=Line[m];
      Line[m]=Line[n];
      Line[n]=t;
      n++;
      m--;
    }
  }
  if(n<j)
    sort(n,j);
  if(m>i)
    sort(i,m);
}

int main()
{
  int n,m,i;
  cin>>n>>m;
  v=new int[n+2];
  Line=new int [m+2];
  Pos=new int [n+2];
  head=new int [m+2];
  for(i=1; i<=n; i++)
  {
    cin>>v[i];
    Pos[i]=i;
  }
  for(i=1; i<=m; i++)
  {
    head[i]=v[i];
    Pos[i]=i;
    Line[i]=i;
  }
  head[m+1]=0;
  sort(1,m);
  for(i=m+1; i<=n; i++)
  {
    v[i]+=head[m];
    Pos[i]=m+1;
    head[m+1]=v[i];
    head[Pos[i-m]]=0;
    Line[m+1]=i;
    sort(1,m+1);
  }
  cout<<head[m]<<endl;
  return 0;
}

