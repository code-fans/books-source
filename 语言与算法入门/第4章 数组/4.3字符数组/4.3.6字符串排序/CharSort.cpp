//×Ö·û´®ÅÅÐò
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("CharSort.in","r",stdin);
  //freopen("CharSort.out","w",stdout);
  char a[10][21];
  for(int i=0; i<=9; ++i)
  {
    cin.getline(a[i],20);
    for(int j=0; j<strlen(a[i]); j++)
      if(a[i][j]>='a' && a[i][j]<='z')
        a[i][j]-=32;
  }
  for(int i=0; i<9; ++i)
    for(int j=0; j<9-i; ++j)
      if(strcmp(a[j],a[j+1])>0)
        swap(a[j],a[j+1]);
  for(int i=0; i<=9; ++i)
    puts(a[i]);
  return 0;
}

