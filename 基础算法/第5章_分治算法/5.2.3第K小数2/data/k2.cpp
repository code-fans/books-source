//��kС��2
#include <bits/stdc++.h>
using namespace std;

int A[100010], B[100010];

int Find(int s1, int e1, int s2, int e2, int kth)
{
  int idxA=(s1+e1)>>1;                      //ȡ�м�λ��
  int idxB=(s2+e2)>>1;
  int lenA=s1>e1 ? 0 : idxA-s1+1;           //A����ǰ��γ���
  int lenB=s2>e2 ? 0 : idxB-s2+1;           //B����ǰ��γ���
  int Len=lenA+lenB;                        //��������ǰ���֮��
  if(Len > kth)                             //ǰ���֮�ͳ�����k��Ԫ��
  {
    if(lenB && (!lenA || A[idxA]<=B[idxB])) //B�л���Ԫ��
      return Find(s1, e1, s2, idxB-1, kth); //�ص�B������һ��Ԫ��
    else
      return Find(s1, idxA-1, s2, e2, kth); //����ֻ�ܽ�ȡA�е�Ԫ��
  }
  else                                      //ǰ���֮�Ͳ���k��Ԫ��
  {
    if(kth==Len && lenA==0)                 //�������,����A[]Ϊ��
      return B[idxB];
    if(kth==Len && lenB==0)                 //�������,����B[]Ϊ��
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

