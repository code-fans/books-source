//�������� - STL��
#include <bits/stdc++.h>
using namespace std;

int n,temp,IntMax=0;
queue  <int> que[10];                                //����Ͱ
vector <int> vec;                                    //�洢����
vector <int>::iterator point;                        //����һ��ָ��vector��ָ��

int Maxbit(int IntMax)                               //�����λ��
{
  int digit=1;
  for(; IntMax>0; IntMax/=10)
    digit++;
  return digit-1;
}

void VecToDeque(int power)                           //��ĳλ����������Ͱ
{
  for(point=vec.begin(); point!=vec.end(); ++point)
  {
    int itor=(*point)/power%10;
    que[itor].push(*point);                          //��ֵ��Ͱ
  }
}

void Colect()                                        //��Ͱ���źõ��������������
{
  int count=0;
  for(int i=0; i<10; i++)
    while(!que[i].empty())                           //�����Ϊ��
    {
      vec[count++]=que[i].front();                   //ȡ����е�һ��ֵ
      que[i].pop();                                  //����
    }
}

void RadixSort()                                     //��������
{
  int Power=1;
  for(int i=1; i<=Maxbit(IntMax); i++)
  {
    VecToDeque(Power);                               //���ΰ�λ���䵽Ͱ
    Colect();                                        //��������
    Power*=10;
  }
}

int main()
{
  //freopen("sort.in","r",stdin);
  //freopen("sort.out","w",stdout);
  scanf("%d",&n);
  for(int i=0; i<n; i++)
  {
    scanf("%d",&temp);
    vec.push_back(temp);                             //vector��˲�����
    IntMax=temp>IntMax?temp:IntMax;                  //�ҳ����ֵ
  }
  RadixSort();
  for(point=vec.begin(); point!=vec.end(); ++point)
    printf("%d ",*point);
  return 0;
}

