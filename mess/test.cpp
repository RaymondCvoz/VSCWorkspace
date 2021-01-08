#include <cstdio>
#include <cstring>
#include <map>
#include <queue>
#include <algorithm>
#include <iostream>
std::map<int, bool> map;
int changeId[9][4] = {{-1, -1, 3, 1}, {-1, 0, 4, 2}, {-1, 1, 5, -1}, {0, -1, 6, 4}, {1, 3, 7, 5}, {2, 4, 8, -1}, {3, -1, -1, 7}, {4, 6, -1, 8}, {5, 7, -1, -1}}; //0出现在0->8的位置后该和哪些位置交换
const int M = 400000;                                                                                                                                            //9！=362800，因此数组开40W足够了
int des = 123804765;                                                                                                                                             //num存储所有排列，len表示排列的个数也就是9！，des为目的状态直接用整数表示便于比较
int que[M][3];
//0-->排列,1-->排列中0的位置,2-->步数
void swap(char *c, int a, int b)
{ //交换字符串中的两个位置
    char t = c[a];
    c[a] = c[b];
    c[b] = t;
}

int bfs(int n, int p)
{
    //int head = 0, tail = 1, temp; //head队头，tail队尾
    std::queue<int> status, zero, step;
    int temp;
    map[n] = 1;
    status.push(n);
    zero.push(p);
    step.push(0);
    //que[head][0] = n, que[head][1] = p, que[head][2] = head; //初始状态保存到对头，并设置当前步数为0
    while (!status.empty())
    {
        char cur[10];                         //用于保存当前状态的字符串
        int pos = zero.front();               //当前状态中0的位置
        sprintf(cur, "%09d", status.front()); //int-->char*这里的09d至关重要，否则算不出答案
        for (int i = 0; i < 4; i++)
        {                                  //扩展当前的状态，上下左右四个方向
            int swapTo = changeId[pos][i]; //将要和那个位置交换
            if (swapTo != -1)
            {                             //-1则不交换
                swap(cur, pos, swapTo);   //交换0的位置得到新状态
                sscanf(cur, "%d", &temp); //新状态转换为int保存到temp
                if (temp == des)
                    if (!step.empty()) //如果是目标状态则返回当前状态的步数+1
                        return step.front() + 1;
                    else
                        return -1;
                if (map.count(temp) == 0)
                { //如果 没有出现过，则将这个新状态进队
                    status.push(temp), zero.push(swapTo), step.push(step.front() + 1);
                    map[temp] = 1;
                }
                swap(cur, pos, swapTo); //一个新状态处理完了一定要记得将交换的0交换回来
            }
        }
        status.pop();
        zero.pop();
        step.pop();
        std::cout << status.size() << "\n";
        //   << zero.size() << "\n"
        //   << step.size() << "\n\n\n";
        //getchar();
    }
    // std::cout << status.size() << "\n"
    //     //   << zero.size() << "\n"
    //     //   << step.size() << "\n";
    return -1;
}

int main()
{
    char start[10];
    int n, i = -1, count = 0;
    scanf("%s", start); //输入初始状态
    while (start[++i] != '0')
        ;                    //查找初始状态0的位置
    sscanf(start, "%d", &n); //字符串转换为整数
    if (n != des)            //判断输入状态是否就是目的状态
        count = bfs(n, i);
    printf("%d", count);
    return 0;
}