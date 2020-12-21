#include "SLL.hpp"

void print(LinkList &L)
{
    if (L->next != NULL)
    {
        print(L->next);
        std::cout << L->next->val << " ";
    }
}
int main()
{
    LinkList L;
    build_with_head_bi(L);
    print(L);
}