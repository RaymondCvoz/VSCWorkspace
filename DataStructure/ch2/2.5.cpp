#include "SLL.hpp"

bool rev(LinkList &L)
{
    if (L->next == NULL)
        return false;
    if (L->next->next == NULL)
        return true;
    Node *pre = L->next, *cnt = L->next->next;
    pre->next = NULL;
    while (cnt != NULL)
    {
        Node *x = cnt->next;
        cnt->next = pre;
        pre = cnt;
        cnt = x;
    }
    L->next = pre;
    return true;
}

int main()
{
    LinkList L;
    build_with_head_bi(L);
    rev(L);
    print_with_head(L);
}