#include "SLL.hpp"

void del(LinkList &L, int x)
{
    if (L->next == NULL)
        return;
    if (L->next->val == x)
    {
        Node *p = L->next;
        L->next = L->next->next;
        free(p);
        del(L, x);
    }
    else
        del(L->next, x);
}

int main()
{

}