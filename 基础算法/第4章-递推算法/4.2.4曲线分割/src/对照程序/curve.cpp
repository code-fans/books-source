//���߷ָ�
//��n-1��Բʱ��������Ϊf(n-1)
//��ô��n��Բ�ͱ�����ǰn-1��Բ�ཻ�����n��Բ����Ϊ2��n-1�����߶Σ�
//������2��n-1��������
//�ʣ� f(n)=f(n-1)+2(n-1) ���ƹ�ʽ
//            ......
//         =f(1)+2+4+����+2(n-1)
//         =2+2*(1+2+...+n-1)
//         =n^2-n+2
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("curve.in","r",stdin);
  //freopen("curve.out","w",stdout);
  int n;
  cin>>n;
  cout<<n*n-n+2<<endl;
  return 0;
}
