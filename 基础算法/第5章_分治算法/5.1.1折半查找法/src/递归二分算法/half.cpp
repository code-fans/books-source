//�ݹ���۰���ҷ�
#include <bits/stdc++.h>
using namespace std;
int a[10010],key,n;

int Search(int Left,int Right)  //��Left~Right��һ�β���
{
  if(Right>=Left)
  {
    int mid=(Left+Right)/2;     //ȡ�м�ֵmid����λ���㣨left+Right��>>1�ٶȸ���
    if(key==a[mid])             //������,���ӡ����
    {
      printf("%d\n",mid);
      return 0;
    }
    else if(key<a[mid])         //��keyС���м�ֵ,��ȡǰ���
      Search(Left,mid-1);
    else                        //��key�����м�ֵ,��ȡ����
      Search(mid+1,Right);
  }
  else
  {
    printf("-1\n");
    return 0;
  }
}

int main()
{
  //freopen("half.in","r",stdin);
  //freopen("half.out","w",stdout);
  cin>>n;
  for(int i=1; i<=n; ++i)       //���±�1��ʼ
    cin>>a[i];
  cin>>key;
  Search(1,n);
  return 0;
}

