//͹��������ǻ���
#include <bits/stdc++.h>
using namespace std;

int p[51],f[51][51],mid[51][51];  //mid[][]�����и��
int n, cnt;

struct node
{
  int x, y, z;
} t[51];                          //�����и�õ�������

bool Cmp(node a, node b)
{
  return a.x==b.x? (a.y==b.y?a.z<b.z:a.y<b.y) : (a.x<b.x);
}

int Dp(int i, int j)              //�ݹ���̬ת�Ʒ���ֵ
{
  if (f[i][j] != 2139062143)      //�����ֵ��ֱ�ӷ���
    return f[i][j];
  if (j-i<=1)                     //ֻ��������
    return 0;
  if (j-i==2)                     //����������
  {
    f[i][j]=p[i]*p[i+1]*p[i+2];
    mid[i][j]=i+1;                //����и��
    return f[i][j];
  }
  for (int k=i+1; k<=j-1; k++)    //ö���и��
    if (f[i][j]>(Dp(i,k)+Dp(k,j)+p[i]*p[k]*p[j]))
    {
      f[i][j]=Dp(i,k)+Dp(k,j)+p[i]*p[k]*p[j];
      mid[i][j]=k;                //����и��
    }
  return f[i][j];
}

void GetTriangle(int l, int r)
{
  if (r-l<2)
    return;
  t[++cnt].x=l;
  t[cnt].y=mid[l][r];
  t[cnt].z=r;
  GetTriangle(l,mid[l][r]);
  GetTriangle(mid[l][r],r);
}

int main()
{
  freopen("Triangle.in", "r", stdin);
  freopen("Triangle.out", "w", stdout);
  scanf("%d", &n);
  for (int i=1; i<=n; i++)
    scanf("%d", &p[i]);
  memset(f,127,sizeof(f));        //��ʼֵ��Ϊ���ֵ2139062143
  printf("%d\n", Dp(1, n));
  GetTriangle(1, n);              //�����и������������
  sort(t+1, t+cnt+1, Cmp);        //�����и������������
  for (int i=1; i<=cnt; i++)
    printf("%d %d %d%c", t[i].x, t[i].y, t[i].z,i==cnt?'\n':',');
  return 0;
}
