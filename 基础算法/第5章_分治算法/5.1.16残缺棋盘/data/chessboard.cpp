//��ȱ����
#include <bits/stdc++.h>
using namespace std;
int k=1,c[1024][1024];                  //���Ͻ�������Ϊ(1��1)

void Lt(int x1,int y1,int x2,int y2 )   //����
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=1;
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=1;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=1;    //���ͼ��1
}

void Rt(int x1,int y1,int x2,int y2 )   //����
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=2;
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=2;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=2;  //���ͼ��2
}

void Lb(int x1,int y1,int x2,int y2 )   //����
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2]=3;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=3;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=3;  //���ͼ��3
}

void Rb(int x1,int y1,int x2,int y2 )   //����
{
  c[x1+(x2-x1)/2][y1+(y2-y1)/2+1]=4;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2+1]=4;
  c[x1+(x2-x1)/2+1][y1+(y2-y1)/2]=4;    //���ͼ��4
}

void Out()                              //�������
{
  for(int i=1; i<=k; i++)
  {
    for(int j=1; j<=k; j++)
      cout<<c[i][j]<<' ';
    cout<<endl;
  }
}

void Work(int x1,int y1,int x2,int y2)  //�ݹ麯��
{
  int p,q;
  for(int i=x1; i<=x2; i++)             //���Ҹ÷���Ļ�����Ѹ��ǵĵ��ںδ�
    for(int j=y1; j<=y2; j++)
      if(c[i][j]!=0)
        p=i,q=j;
  if(p<=(x1+(x2-x1)/2))
    if( q<=(y1+(y2-y1)/2))              //��õ�λ�����Ͻ�
      Rb(x1,y1,x2,y2);
    else                                //��õ������Ͻ�
      Lb(x1,y1,x2,y2);
  if(p>(x1+(x2-x1)/2))
    if (q<=(y1+(y2-y1)/2))              //��õ�λ�����½�
      Rt(x1,y1,x2,y2);
    else                                //��õ������½�
      Lt(x1,y1,x2,y2);
  if(x2-x1!=1)
  {
    Work(x1,y1,(x1+(x2-x1)/2),(y1+(y2-y1)/2));  //ƽ��Ϊ�Ŀ��ݹ�
    Work((x1+(x2-x1)/2+1),y1,x2,(y1+(y2-y1)/2));
    Work(x1,(y1+(y2-y1)/2+1),(x1+(x2-x1)/2),y2);
    Work((x1+(x2-x1)/2+1),(y1+(y2-y1)/2+1),x2,y2);
  }
}

int main()
{
  //freopen("chessboard.in","r",stdin);
  //freopen("chessboard.out","w",stdout);
  int n,x,y;
  cin>>n>>x>>y;
  for(int i=1; i<=n; i++)
    k*=2;
  c[x][y]=7;                            //���廵������Ϊ7
  Work(1,1,k,k);                        //��������(1,1),��������(k,k)
  Out();
  return 0;
}

