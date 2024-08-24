//第k小数2
#include <bits/stdc++.h>
using namespace std;

int A[100010], B[100010];

int Find(int s1, int e1, int s2, int e2, int kth)
{
  int idxA=(s1+e1)>>1;                      //取中间位置
  int idxB=(s2+e2)>>1;
  int lenA=s1>e1 ? 0 : idxA-s1+1;           //A数组前半段长度
  int lenB=s2>e2 ? 0 : idxB-s2+1;           //B数组前半段长度
  int Len=lenA+lenB;                        //两数组中前半段之和
  if(Len > kth)                             //前半段之和超过了k个元素
  {
    if(lenB && (!lenA || A[idxA]<=B[idxB])) //B中还有元素
      return Find(s1, e1, s2, idxB-1, kth); //截掉B数组中一半元素
    else
      return Find(s1, idxA-1, s2, e2, kth); //否则只能截取A中的元素
  }
  else                                      //前半段之和不够k个元素
  {
    if(kth==Len && lenA==0)                 //正好相等,并且A[]为空
      return B[idxB];
    if(kth==Len && lenB==0)                 //正好相等,并且B[]为空
      return A[idxA];
    if(lenA && (!lenB || A[idxA]<=B[idxB]))
      return Find(idxA + 1, e1, s2, e2, kth-lenA);
    else
      return Find(s1, e1, idxB + 1, e2, kth -lenB);
  }
}

int main()
{
  //freopen("k2.in","r",stdin);
  //freopen("k2.out","w",stdout);
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for(int i = 0; i < n; ++ i)
    cin>>A[i];
  for(int i = 0; i < m; ++ i)
    cin>>B[i];
  printf("%d\n", Find(0, n - 1, 0, m - 1, k));
  return 0;
}

