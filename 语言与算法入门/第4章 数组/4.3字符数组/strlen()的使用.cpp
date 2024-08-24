//strlen()µÄÊ¹ÓÃ
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a[300];
  cin.getline(a,299);
  int n=strlen(a);
  for(int i=0; i<n; ++i)
    cout<<a[i];
  return 0;
}

