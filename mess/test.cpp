#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <queue>

std::map<std::string, bool> map;
int changeId[9][4] = {{-1, -1, 3, 1}, {-1, 0, 4, 2}, {-1, 1, 5, -1}, {0, -1, 6, 4}, {1, 3, 7, 5}, {2, 4, 8, -1}, {3, -1, -1, 7}, {4, 6, -1, 8}, {5, 7, -1, -1}}; //0出现在0->8的位置后该和哪些位置交换
std::string st;                                                                                                                                                  //9！=362800，因此数组开40W足够了
std::string des;                                                                                                                                                 //num存储所有排列，len表示排列的个数也就是9！，des为目的状态直接用整数表示便于比较
//0-->排列,1-->排列中0的位置,2-->步数
std::queue<std::string> status;
std::queue<int> zero, step;

int bfs(std::string n, int p)
{
    map[n] = 1;
    //que[head][0] = n, que[head][1] = p, que[head][2] = head; //初始状态保存到对头，并设置当前步数为0
    status.push(n);
    zero.push(p);
    step.push(0);
    while (!status.empty())
    { //队列不为空则继续搜索
        //char cur[10];                     //用于保存当前状态的字符串
        int pos = zero.front();           //当前状态中0的位置
        std::string cur = status.front(); //int-->char*这里的09d至关重要，否则算不出答案
        for (int i = 0; i < 4; i++)
        {                                  //扩展当前的状态，上下左右四个方向
            int swapTo = changeId[pos][i]; //将要和那个位置交换
            if (swapTo != -1)
            {
                std::swap(cur[pos], cur[swapTo]); //-1则不交换
                //swap(cur, pos, swapTo);           //交换0的位置得到新状态
                //sscanf(cur, "%d", &temp);         //新状态转换为int保存到temp
                if (cur == des) //如果是目标状态则返回当前状态的步数+1
                    return step.front() + 1;
                if (map.count(cur) == 0)
                { //如果 没有出现过，则将这个新状态进队
                    status.push(cur), zero.push(swapTo), step.push(step.front() + 1);
                    //tail++;
                    map[cur] = 1;
                }
                std::swap(cur[pos], cur[swapTo]); //一个新状态处理完了一定要记得将交换的0交换回来
            }
        }
        //head++;
        status.pop();
        zero.pop();
        step.pop();
    }
}

int main()
{
    int pos = -1;
    std::cin >> st;
    des = "123804765";
    while (st[++pos] != '0')
        ;
    if (st != des)
    {
        std::cout << bfs(st, pos);
    }
    return 0;
}