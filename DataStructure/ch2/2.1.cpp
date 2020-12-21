#include "SLL.hpp"
void del(LinkList &L, int x)
{
    if (L == NULL)
    {
        return;
    }
    if (L->val == x)
    {
        Node *p = L;
        L = L->next;
        free(p);
        del(L, x);
        }
    else
    {
        del(L->next, x);
    }
}
int main()
{
    LinkList L;
    build_with_no_head_bi(L);
    del(L, 3);
    print_with_no_head(L);
}