//������� - ̰���㷨��
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("horse.in","r",stdin);
  //freopen("horse.out","w",stdout);
  int tian[1001], king[1001], n;
  while (scanf("%d", &n), n)
  {
    for (int i=0; i<n; i++)
      scanf("%d", &tian[i]);
    for (int j=0; j<n; j++)
      scanf("%d", &king[j]);
    sort(tian, tian+n);
    sort(king, king+n);
    bool visit1[1001]= {0};
    bool visit2[1001]= {0};
    int win=0, fail=0;                 //win:���Ӯ�Ĵ�����fail��δ����������
    for (int i=0; i<n; i++)
      for (int j=n-1; j>=0; j--)
        if (tian[i]>king[j] && !visit2[j])   //��ɵ����Ҿ�����Ķ��ֲ��һ�ʤ
        {
          win++;
          visit1[i]=visit2[j]=true;
          break;
        }
    for (int i=0; i<n; i++)
      if (!visit1[i])
      {
        for (int j=0; j<n; j++)
          if (!visit2[j] && tian[i]==king[j])//Ѱ��ƽ�ֵ���
          {
            visit1[i]=visit2[j]=true;
            break;
          }
        if(!visit1[i])
          fail++;
      }
    cout<<(win-fail)*200<<endl;
  }
  return 0;
}

