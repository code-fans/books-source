//�������2
#include <bits/stdc++.h>
using namespace std;

int i=1,temp;
int node[100000];

void InOrder(int index)                                  //�������
{
  if(node[index]!=0)
  {
    InOrder(index*2);
    cout<<node[index]<<' ';
    InOrder(index*2+1);
  }
}

int main()
{
  freopen("order.in","r",stdin);
  freopen("order2.out","w",stdout);
  while(cin>>temp)
    node[i++]=temp;
  InOrder(1);
  cout<<endl;
  return 0;
}

