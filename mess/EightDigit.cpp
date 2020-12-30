#include <map>
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>

std::map<std::string, bool> map;
int cid[9][4] = {{-1, -1, 3, 1}, {-1, 0, 4, 2}, {-1, 1, 5, -1}, {0, -1, 6, 4}, {1, 3, 7, 5}, {2, 4, 8, -1}, {3, -1, -1, 7}, {4, 6, -1, 8}, {5, 7, -1, -1}};
;
std::string st, ed = "123804765";
std::queue<std::string> status;
std::queue<int> zero, step;

int bfs(std::string init, int p)
{
    map[init] = 1;
    status.push(init);
    zero.push(p);
    step.push(0);
    while (!status.empty())
    {
        std::string cnt = status.front();
        int pos = zero.front();

        for (int i = 0; i < 4; i++)
        {
            int tgt = cid[pos][i];
            if (tgt != -1)
            {
                std::swap(cnt[pos], cnt[tgt]);
                if (cnt == ed)
                    return step.front() + 1;
                if (!map.count(cnt))
                {
                    status.push(cnt);
                    zero.push(tgt);
                    step.push(step.front() + 1);
                    map[cnt] = 1;
                }
                std::swap(cnt[pos], cnt[tgt]);
            }
        }
        status.pop();
        zero.pop();
        step.pop();
    }
}

int main()
{
    int pos = -1;
    std::cin >> st;
    while (st[++pos] != '0')
        ;
    if (st != ed)
    {
        std::cout << bfs(st, pos);
    }
    return 0;
}