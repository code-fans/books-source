//˫������ -�Ǹ߾����㷨
//���������ƶ�������2n��1�����������һ������������2�㣬���Խ�2�㿴��1�㣬
//��ص��˵��������ϣ�ÿ�ƶ������е�"��������"����������˫����������2��
//���ƹ�ʽ��f(n)��2n+1��2
#include <bits/stdc++.h>
using namespace std;

int a[31]= {1,1};               //a[0]�洢���λ���±꣬a[1]=1����ʼֵΪ1

int main()
{
  freopen("hanoi2.in","r",stdin);
  freopen("hanoi2.out","w",stdout);
  int n;
  cin>>n;
  cout<<int(pow(2,n+1))-2<<endl;
  return 0;
}

