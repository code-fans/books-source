//è������
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ////freopen("catmouse.in","r",stdin);
  ////freopen("catmouse.out","w",stdout);
  int N,x,y,X,Y;                             //x,yΪ���������,X,YΪè������
  cin>>N;                                    //scanfҪע��س����Ĵ���
  for (int k = 0; k < N; k++)
  {
    int m=0,c=0,count=0;                     //mΪè�ķ���cΪ����ķ���
    string Map[10];                          //�����ͼ
    for (int j = 0; j < 10; j++)
      cin>>Map[j];                           //һ�ζ�һ��
    for (int i = 0; i < 10; i++)             //��ȡè�����ڵ�λ�ò����
      for (int j = 0; j < 10; j++)
        if (Map[i][j] == 'C')
        {
          X = i;
          Y = j;
        }
        else if (Map[i][j] == 'M')
        {
          x = i;
          y = j;
        }
    while (count < 100 && (X!=x || Y!=y))    //һ�ٲ�֮�ڻ���δ�ҵ��������
    {
      if (m==0 && x-1>=0 && Map[x-1][y]!='*')//ģ��������ƶ�
        x--;
      else if (m==1 && y+1<10 && Map[x][y+1]!='*')
        y++;
      else if (m==2 && x+1<10 && Map[x+1][y]!='*')
        x++;
      else if (m==3 && y-1>=0 && Map[x][y-1]!='*')
        y--;
      else
        m=(++m)%4;
      if (c==0 && X-1>=0 && Map[X-1][Y]!='*') //ģ��è���ƶ�
        X--;
      else if (c==1 && Y+1<10 && Map[X][Y+1]!='*')
        Y++;
      else if (c==2 && X+1<10 && Map[X+1][Y]!='*')
        X++;
      else if (c==3 && Y-1>=0 && Map[X][Y-1]!='*')
        Y--;
      else
        c=(++c)%4;
      ++count;
    }
    printf("%d\n",(X == x && Y == y)?count:-1);
  }
  return 0;
}

