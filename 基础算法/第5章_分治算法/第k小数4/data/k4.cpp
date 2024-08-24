//第k小数4
#include <bits/stdc++.h>
using namespace std;

int A[100010], B[100010], C[1000010], Cptr, n;

bool Enough(int limit)                    //k3的原理,O(N)
{
  int Aptr, Bptr, sum = 0;
  for (Aptr = 0, Bptr = n - 1; Aptr < n; ++Aptr)
  {
    while (Bptr >=0 && A[Aptr] + B[Bptr] > limit)
      --Bptr;
    sum += Bptr + 1;
  }
  return sum >= n;                        //判断总数是否超过n
}

//找到第n大的数后，把所有比它小的数加入新数组，参见k3，O(N)
void Push(int limit)
{
  int Aptr, Bptr, i, sum = 0, ptr1, ptr2;
  for (Aptr = 0, Cptr = 0; Aptr < n; ++Aptr)
    for (Bptr=0; A[Aptr]+B[Bptr]<=limit && Bptr<n; ++Bptr)
      C[Cptr++] = A[Aptr] + B[Bptr];
  for (ptr1 = 0, ptr2 = 0; ptr1 < Cptr; ++ptr1)
    if (C[ptr1] != limit) C[ptr2++] = C[ptr1];
  while (ptr2 < n)
    C[ptr2++] = limit;
}

int Find(int left, int right, bool (*law)(int arg))  //参见k3, O(logN)
{
  while (left < right)
  {
    int mid = (left+right)/2;
    if (law(mid))
      right = mid;
    else
      left = mid + 1;
  }
  return left;
}

int main()
{
  //freopen("k4.in", "r",stdin);
  //freopen("k4.out", "w",stdout);
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> A[i];
  for (int i = 0; i < n; ++i)
    cin >> B[i];
  sort(A, A+n);                              //排序O(NlogN)
  sort(B, B+n);                              //排序O(NlogN)
  Push(Find(A[0]+B[0],A[n-1]+B[n-1],Enough));
  sort(C, C+n);                              //最后排序输出
  for (int i = 0; i < n; ++i)
    i==n-1?cout<<C[i]<<"\n":cout<<C[i]<<" ";
}
