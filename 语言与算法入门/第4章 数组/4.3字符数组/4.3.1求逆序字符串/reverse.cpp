//ÇóÄæĞò×Ö·û´®
#include <bits/stdc++.h>
using namespace std;
const int N=100;

int main()
{
  freopen("reverse.in","r",stdin);
  freopen("reverse.out","w",stdout);
  char str1[N],str2[N];
  cin.getline(str1,N-1);
  int len=strlen(str1);
  for(int i=len-1; i>=0; i--)
    str2[len-i-1]=str1[i];
  str2[len]='\0';
  puts(str2);
  return 0;
}

