//������� - ̰���㷨
#include <bits/stdc++.h>
using namespace std;

int main()
{
  freopen("horse.in","r",stdin);
  freopen("horse.out","w",stdout);
  int n,tian[1010],king[1010];
  while (scanf("%d", &n) && n)
  {
    for(int i=0; i<n; ++i)
      scanf("%d", &tian[i]);
    for(int i=0; i<n; ++i)
      scanf("%d", &king[i]);
    sort(tian, tian+n);
    sort(king, king+n);
    int ans=0,max1=n-1,max2=n-1,min1=0,min2=0,cnt=0;
    while((cnt++)<n)
    {
      if(tian[max1]>king[max2])          //�������������������
      {
        ans+=200;                        //ֱ�ӱ�
        max1--;
        max2--;
      }
      else if(tian[max1]<king[max2])     //��������������������
      {
        ans-=200;
        min1++;                          //��������������
        max2--;
      }
      else
      {
        if(tian[min1]>king[min2])        //���������������������
        {
          ans+=200;                      //ֱ�ӱ�
          min1++;
          min2++;
        }
        else
        {
          if(tian[min1]<king[max2])      //���������������������
            ans-=200;
          min1++;                        //��������������
          max2--;
        }
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}

