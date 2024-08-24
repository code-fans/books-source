//后序中序求前序
#include <bits/stdc++.h>
using namespace std;
string s1,s2;

void Trans(int L1, int R1, int L2, int R2)
{
  if(L1<=R1)
  {
    putchar(s1[R1]);           //由于是求先序遍历，所以先输出根节点
    int k=s2.find(s1[R1]);
    Trans(L1,R1-R2+k-1,L2,k-1);//递归求左子树的先序遍历
    Trans(R1-R2+k,R1-1,k+1,R2);//递归求右子树的先序遍历
  }
}

int main()
{
  //freopen("tree2.in","r",stdin);
  //freopen("tree2.out","w",stdout);
  cin>>s1>>s2;
  Trans(0,s1.size()-1,0,s2.size()-1);
  puts("");
  return 0;
}
