#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("revelation.in","r",stdin);
  //freopen("revelation.out","w",stdout);
  long long f[210][5]= {1};
  for (int i=1; i<=20; i++)
  {
    f[i][0]=9LL* (f[i-1][0]+f[i-1][1]+f[i-1][2]);
    f[i][1]=f[i-1][0];
    f[i][2]=f[i-1][1];
    f[i][3]=f[i-1][2]+10LL*f[i-1][3];
  }
  int x,m, T;
  scanf("%d", &T);
  while (T--)
  {
    scanf("%d", &x);
    for(m=3; f[m][3]<x; m++);           //λ���ƽ���
    for (int i = m, k = 0; i > 0; i--)  //�ɸ��������iλ,k��ʾĩβ����k��6
      for (int j = 0; j <= 9; j++)      //���Ե�iλ����Ϊ0~9
      {
        long long cnt=f[i-1][3];        //�������i-1λ�ж����������������ħ���� 
        if (j == 6 || k == 3)           //����ǰo(0~2)��6��ͷ�ķ�ħ�������Ѿ����ֵ�3-o��6���ɵ�ħ��������
          for (int o=max(3-(j==6)-k, 0); o<3; o++)//oΪ���ϵ���С����
            cnt+=f[i-1][o];
        if (cnt<x)                      //С�ˣ���iλӦ��������
          x-=cnt;                       //��x��Ŀ�������
        else                            //��j������ħ����������Ҫ��ĸ���,�������
        {
          if (k<3)                      //����3����������6��û��Ҫ����ͳ������6�� 
            k=(j==6?k+1:0);             //���jΪ6,������1,��������Ϊ0 
          printf("%d", j);
          break;
        }
      }
    puts("");
  }
  return 0;
}
