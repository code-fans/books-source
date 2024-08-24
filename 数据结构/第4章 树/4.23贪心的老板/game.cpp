//̰�ĵ��ϰ�
#include<bits/stdc++.h>
using namespace std;
const int MAXH=100000;
const int INF=0xffffff;

int n,heapsize;                      //�ѵĴ�С
int a[MAXH];                         //����Ԫ�ص�ֵ

void Maxheapify(int i)               //ά�������
{
  int largest;
  int l=i<<1;                        //�������±�
  int r=(i<<1)+1;                    //�������±�
  if(l<=heapsize && a[i]<a[l])
    largest=l;
  else
    largest=i;
  if(r<=heapsize && a[r]>a[largest])
    largest=r;
  if(largest != i)
  {
    swap(a[i],a[largest]);
    Maxheapify(largest);
  }
}

void BuildMaxHeap()                  //���������
{
  heapsize=n;
  for(int i=n/2; i>=1; i--)
    Maxheapify(i);
}

int ExtractMax(int a[])             //���������ض������Ԫ��
{
  int Max=a[1];
  a[1]=a[heapsize];
  a[heapsize]=-1;
  heapsize--;
  Maxheapify(1);                    //ά��������ѵ�����
  return Max;
}

void HeapIncreaseKey(int i,int key) //�ı��㵱ǰ��ֵ
{
  if(a[i]>key)                      //���ĵ�ֵ����Ҫ���ڵ�ǰ��ֵ
  {
    cout<<"-1\n";
    return;
  }
  a[i]=key;
  while(i>1 && a[i>>1]<a[i])        //��ת�����ֶѵ�����
  {
    swap(a[i],a[i>>1]);
    i=i>>1;
  }
}

void MaxHeapInsert(int key)         //�����в���һ��Ԫ��
{
  heapsize++;
  a[heapsize]=-INF;                 //��ʼ������Ԫ��Ϊ��Сֵ
  HeapIncreaseKey(heapsize,key);    //����Ԫ��
}

int main()                          //��ʾ����
{
  //freopen("game.in","r",stdin);
  //freopen("game.out","w",stdout);
  int i,key,v;
  cin>>n;
  for(i=1; i<=n; i++)
    cin>>a[i];
  BuildMaxHeap();                   //������
  while(1)
  {
    cin>>i;
    if(i==1)                        //��ʾ�������ֵ
      cout<<a[1]<<"\n";
    else if(i==2)                   //�������ֵ����
      cout<<ExtractMax(a)<<"\n";
    else if(i==3)                   //�ı�ĳԪ�ص�����ֵ
    {
      cin>>v>>key;
      HeapIncreaseKey(v,key);
    }
    else if(i==4)                   //�����µ�Ԫ��
    {
      cin>>key;
      MaxHeapInsert(key);
    }
    else                            //�˳�
      break;
    getchar();
  }
  return 0;
}

