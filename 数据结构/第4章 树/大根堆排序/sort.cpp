//���������sort.cpp��
#include <bits/stdc++.h>
using namespace std;
const int N=100000;

int a[N+1];

void Adjust_down(int i,int m)                //����
{
  while(i*2<=m)                              //�������ӽ��ʱ
  {
    i<<=1;                                   //��i=i*2,�ҵ����ӽ���±�
    if(i<m && a[i+1]>a[i])                   //������ӽ������ӽ�����
      i++;                                   //��iָ�����ӽ��
    if(a[i]>a[i/2])                          //�ӽ��ȸ�������
      swap(a[i/2],a[i]);                     //����ӽ���븸��㽻��
    else                                     //���ӽ���޽������������
      break;                                 //��Ϊ�����������ϵ�����
  }
}

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  int n;
  cin>>n;
  for(int i=1; i<=n; i++)                    //˳�������
    cin>>a[i];
  for(int i=n/2; i>=1; i--)                  //��n/2��ʼ����
    Adjust_down(i,n);                        //����
  for(int i=n; i>=2; i--)                    //����
  {
    swap(a[i],a[1]);                         //ÿ�ν������ֵ�����
    Adjust_down(1,i-1);
  }
  for(int i=1; i<n; i++)                    //��С�������
    cout<<a[i]<<' ';
  cout<<a[n]<<endl;
  return 0;
}

