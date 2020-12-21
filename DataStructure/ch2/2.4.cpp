#include "SLL.hpp"

bool del(LinkList &L)
{
    if (L->next == NULL)
        return false;
    Node *ptr = L, *cnt = L;
    int x = L->next->val;
    while (cnt->next != NULL)
    {
        if (cnt->next->val < x)
        {
            ptr = cnt;
            x = cnt->next->val;
        }
        cnt = cnt->next;
    }

    Node *del = ptr->next;
    ptr->next = ptr->next->next;
    free(del);
    return L;
}

int main()
{
    LinkList L;
    build_with_head_bi(L);
    del(L);
    print_with_head(L);
}