//�����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int grade;//ע��˴�������
  cin>>grade;
  switch(grade)  //�Ƚ�gradeֵ��gradeֵΪһ������
  {
    case 5:
      cout<<"A\n";
      break;
    case 4:
      cout<<"B\n";
      break;
    case 3:
      cout<<"C\n";
      break;
    case 2:
      cout<<"D\n";
      break;
    default:
      cout<<"E\n"; // �˴����Բ���break���
  }
  return 0;
}

