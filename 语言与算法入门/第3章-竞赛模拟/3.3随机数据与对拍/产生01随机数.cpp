//产生0~1之间的随机数
#include <bits/stdc++.h>
using namespace std;

int main()
{
  srand(time(0));
  for(int i=1; i<=5000; i++)
    cout<<rand() % (2)<<"  ";
  return 0;
}

