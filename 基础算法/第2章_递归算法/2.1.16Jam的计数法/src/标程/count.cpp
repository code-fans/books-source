/*jam�ļ�����
//����ʵ������m����ĸ��ѡn����ĸ�������ظ�ѡȡ������Ҫ�����ֵ������У���Ȼ���������
������ϴ����㷨�������£�
������ �Ӻ���ǰ�ҵ�һ��δ�ﵽ���ֵ����a��
������ a=a+1��
������ �������������ǰ������1��
������ �ж�a[0]����a[0]=1�����������ת1��*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
  //freopen("count.in","r",stdin);
  //freopen("count.out","w",stdout);
  int s,t,w;
  string str;
  cin>>s>>t>>w>>str;
  for(int p=0,q; p<5 && (str[0]-'a'<t-w); p++)       //���ֻ�������
  {
    for(q=w-1; q>=0 && (str[q]-'a'==t-w+q); q--); //��qλ�����ֵΪ t-��w-q��
    if(q>=0)
    {
      str[q]++;                                   //�ҵ���һ�����Լ�1��λ��
      for(int i=q+1; i<w; i++)                        //�������μ�1
        str[i]=str[i-1]+1;
      cout<<str<<endl;
    }
  }
  return 0;
}
