//八数码 - 宽搜
#include <bits/stdc++.h>
using namespace std;

const int MAXN=370000;
int final;
int Queue[MAXN], Deep[MAXN];
bool visit[MAXN];                        //该状态是否已经出现过
int s[9]= {1,2,3,8,0,4,7,6,5};           //保存当前八数码的状态
int front = 1,rear = 1;                  //队列首尾

int To_Digit()                           //转换成数字
{
  int ans = 0;
  for(int i = 0; i < 9; i++)
    ans = (ans<<3)+(ans<<1) + s[i];
  return ans;
}

int Cantor()                             //康托展开
{
  bool used[9] = {0};
  int ans = 0;
  for(int i = 8; i >= 1; i--)
  {
    int no = 0;
    used[s[8 - i]] = true;
    for(int j = 0; j < s[8 - i]; j++)    //查找是否有用过的数
      if(used[j])
        no++;
    ans = (ans + s[8 - i] - no) * i;     //康托展开式计算
  }
  return ans;
}

void Ucan(int num)                       //将队列中的数字num展开到s[]
{
  for(int i = 8; i >= 0; i--)
  {
    s[i] = num % 10;
    num /= 10;
  }
}

int Findzero()                           //找到0的位置
{
  for(int i = 0; i < 9; i++)
    if(s[i] == 0)
      return i;
}

void BFS(int c,int p)
{
  swap(s[p],s[p+c]);                     //交换数码
  int num = Cantor();
  if(!visit[num])
  {
    Queue[++rear] = To_Digit();          //换成数字
    visit[num] = true;
    Deep[rear] = Deep[front] + 1;
    if(num == final)                     //得到答案
      printf("%d\n",Deep[rear]),exit(0);
  }
  swap(s[p],s[p+c]);                     //恢复
}

int main()
{
  freopen("Puzzle8.in","r",stdin);
  freopen("Puzzle8.out","w",stdout);
  final = Cantor();                      //将目标状态存入final
  for(int i = 0; i < 9; i++)             //初状态转为9位数存入n
    scanf("%d", &s[i]);
  Queue[1] = To_Digit();                 //初始状态存入队列
  visit[Cantor()] = true;                //该状态被标记为已存在
  if(visit[final] == true)               //初状态即末状态
  {
    printf("0\n");
    return 0;
  }
  while(front <= rear)
  {
    Ucan(Queue[front]);                  //将队首的排列还原到s[]方阵
    int p = Findzero();                  //查找0的位置
    if(p >= 3)                           //向上搜索
      BFS(-3,p);
    if(p < 6)
      BFS(3,p);                          //向下搜索
    if((p % 3) > 0)
      BFS(-1,p);                         //向左搜索
    if((p % 3) < 2)
      BFS(1,p);                          //向右搜索
    front++;                             //队首元素出队
  }
  printf("-1\n");
  return 0;
}

