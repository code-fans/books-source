//�ȼ�����
#include <bits/stdc++.h>
using namespace std;

int main()
{
  char grade;//ע��˴����ַ���
  cin>>grade;
  switch(grade)  //�Ƚ�gradeֵ��gradeֵΪһ���ַ�
  {
    case 'A':
      cout<<"Very good!\n";
      break;
    case 'B':
      cout<<"Good!\n";
      break;
    case 'C':
      cout<<"OK!\n";
      break;
    case 'D':
      cout<<"Bad!\n";
      break;
    default:
      cout<<"Too bad!\n"; // �˴����Բ���break���
  }
  return 0;
}

