//����ͼ
//�Ӻ���ǰ���������£������������θ���
#include <bits/stdc++.h>
using namespace std;

int m,n,a[1001][1001],h;
int L[6]= {2,1,0,0,0,0};                  //ÿ�������ʼλ��
int R[6]= {6,6,6,6,5,4};                  //ÿ���ұ߽���λ��

char Map[1001][1001],Model[6][8] = {"  +---+",
                                    " /   /|",
                                    "+---+ |",
                                    "|   | +",
                                    "|   |/ ",
                                    "+---+  "
                                   };

void Block(int x,int y)
{
  for(int i=5; i>=0; i--)
    for(int j=L[i]; j<=R[i]; j++)         //����һ�е������ʼλ�õ��ұ߽���λ��
      Map[x+5-i][y+j]=Model[i][j];
}

int main()
{
  //freopen("drawing.in","r",stdin);
  //freopen("drawing.out","w",stdout);
  scanf("%d%d",&m,&n);
  for(int i=1; i<=m; i++)
    for(int j=0; j<n; j++)
    {
      scanf("%d",&a[i][j]);
      h=max(h,3*a[i][j]+3+(m-i)*2);        //hΪ����ͼ���߶�
    }
  for(int i=1; i<=m; i++)                  //�ӵ�һ�е���m��
    for(int j=0; j<n; j++)                 //��
      for(int k=0; k<a[i][j]; k++)         //��ǰλ�öѵĻ�ľ����
        Block(3*k+(m-i)*2+1,4*j+(m-i)*2+1);//�����������½ǿ�ʼ��
  for(int i=h,w=4*n+m*2+1; i>=1; i--)      //��������,wΪ����ͼ������
  {
    for(int j=1; j<=w; j++)                //�����������
      printf("%c",Map[i][j]==NULL?'.':Map[i][j]);
    printf("\n");
  }
  return 0;
}
