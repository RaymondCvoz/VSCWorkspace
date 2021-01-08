#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

int cid[9][4] = {{-1, -1, 3, 1}, {-1, 0, 4, 2}, {-1, 1, 5, -1}, {0, -1, 6, 4}, {1, 3, 7, 5}, {2, 4, 8, -1}, {3, -1, -1, 7}, {4, 6, -1, 8}, {5, 7, -1, -1}};
; //0出现在0-8的位置后该和哪些位置交换

struct ST
{
    std::string status;
    int step, zero;
};

ST st;                           //st存储起始状态
std::string ed;                  //ed存储目标状态
std::map<std::string, bool> map; //string到bool的map存储某一状态是否被遍历过
std::queue<ST> q;
int bfs(ST st, int p)
{
    if (st.status == ed) //若初始状态和目标状态相等
    {
        return 0; //直接返回步数为0
    }
    map[st.status] = 1; //对于每一个状态使得此状态对应的map值为1
    q.push(st);         //将当前状态加入队列
    while (!q.empty())  //当队列非空，即还有未遍历的状态并且未找到目标状态
    {
        ST cnt = q.front(); //取出当前队头的状态
        int pos = cnt.zero; //取出当前状态中0的位置
        ST origin = cnt;
        for (int i = 0; i < 4; i++) //对当前状态的四个方向进行遍历
        {
            cnt = origin;          //保存当前状态
            int tgt = cid[pos][i]; //根据0的位置确定目标状态
            if (tgt != -1)
            {
                std::swap(cnt.status[pos], cnt.status[tgt]); //更改当前状态
                if (cnt.status == ed)                        //如果当前状态等于目标状态
                    return cnt.step + 1;                     //返回步数
                if (!map.count(cnt.status))                  //如果当前状态没有被遍历过
                {
                    cnt.zero = tgt; //修改
                    cnt.step += 1;
                    q.push(cnt); //将当前状态加入队列
                    map[cnt.status] = 1;
                }
                std::swap(cnt.status[pos], cnt.status[tgt]); //退回之前的状态，以进行下一次更改
            }
        }
        q.pop();
    }
    return -1; //表示本局面无解
}

int main()
{
    int pos = -1;
    std::cout << "Input inital Status:";
    std::cin >> st.status; //输入起始状态
    std::cout << "Input Target Status:";
    std::cin >> ed; //输入目标状态
    while (st.status[++pos] != '0')
        ;
    st.step = 0;
    st.zero = pos;
    int ans = bfs(st, pos);
    if (ans == -1) //bfs返回值为-1表示无解
    {
        std::cout << "No Solution";
    }
    else //输出总步数
    {
        std::cout << "Total Step : " << ans;
    }
    return 0;
}