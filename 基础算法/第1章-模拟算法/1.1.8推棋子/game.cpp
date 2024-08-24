//������
#include <bits/stdc++.h>
using namespace std;

const int xx[] = {-1, 0, 1, 0};        //��������
const int yy[] = {0, -1, 0, 1};        //��������
const char u[] = {'^', '<', 'v', '>'};
char Map[10][10], o[10], p[10];

bool In(int x,int y)                   //�ж��Ƿ�Խ��
{
  return (1 <= x && x <= 8 && 1 <= y && y <= 8);
}

int main()
{
  //freopen("game.in","r",stdin);
  //freopen("game.out","w",stdout);
  int x, y, d, step;                   //x,yΪ�˵�λ�ã�dΪǰ������
  for (int i = 1; i <= 8; ++ i)
  {
    scanf("%s", Map[i]+1);
    for (int j = 1; j <= 8; ++j)
      for (int k = 0; k < 4; ++k)
        if (Map[i][j] == u[k])
          x = i, y = j, d = k;         //��ȡ�˵�����ͷ���
  }
  while (scanf("%s", o+1), o[1] != '#')//��ȡ���в���
  {
    if (o[1] == 'm')
    {
      int tx = x + xx[d];
      int ty = y + yy[d];
      for (scanf("%d", &step); step && In(tx, ty); --step) //������û���겢��ûԽ��ʱ
      {
        if (Map[tx][ty] != '.')                   //ǰ�����Ӳ��ǿյ�ʱ
        {
          int dx=tx+xx[d];
          int dy=ty+yy[d];
          while (In(dx, dy) && Map[dx][dy] != '.')//һֱ�ҵ��յأ������ƶ��ٸ�����
            dx += xx[d], dy += yy[d];           //����ֵһֱ�ۼ�
          while (dx != tx || dy != ty)          //ǰ�����ӵ�����һ������ǰ��
          {
            Map[dx][dy] = Map[dx-xx[d]][dy-yy[d]];
            dx -= xx[d];
            dy -= yy[d];
          }
        }
        Map[tx][ty] = Map[x][y];                    //��ǰ���ǿյصĲ���
        Map[x][y] = '.';                          //��֮ǰ��λ�ñ�Ϊ�յ�
        x = tx;                                 //�˵����µ�λ��x
        y = ty;                                 //�˵����µ�λ��y
        tx += xx[d];                            //������̽��һ��
        ty += yy[d];
      }
    }
    else
    {
      scanf("%s", p+1);
      if (p[1] == 'l')
        d = (d+1)%4;
      if (p[1] == 'r')
        d = (d+3)%4;
      if (p[1] =='b')
        d = (d+2)%4;
      Map[x][y] = u[d];                           //�˵ķ��򱻸ı�
    }
  }
  for (int i = 1; i <=8;  ++i)
  {
    for (int j = 1; j <= 8; ++j)
      printf("%c",Map[i][j]);
    printf("\n");
  }
  return 0;
}
