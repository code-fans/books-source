//ѡ���ջ - �Ż��㷨2
#include <bits/stdc++.h>
using namespace std;
const int K = 60;
int n, k, price, c, v, Ans, later;
int hotel[K], fit[K], last[K];

int main()
{
  //freopen("hotel.in","r",stdin);
  //freopen("hotel.out","w",stdout);
  scanf("%d %d %d", &n, &k, &price);
  for(int i=1; i<=n; i++)
  {
    scanf("%d %d", &c, &v);
    if(v <= price)                       //��÷�������������
      later = i;                         //�������Ҫ��Ŀ�ջlater=�ÿ�ջ
    if(later >= last[c])                 //��later>=�洢��һ����ɫΪc�Ŀ�ջ
      fit[c] = hotel[c];                 //��ɫc�ҷ������ѵĿ�ջ��fit[c]=������ɫΪc�Ŀ�ջ��hotel[c]
    Ans += fit[c];
    hotel[c]++;                          //��ɫΪ c �Ŀ�ջ����һ
    last[c] = i;                         //���´洢��һ����ɫΪ c �Ŀ�ջ���
  }
  printf("%d\n", Ans);
  return 0;
}

