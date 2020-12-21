#include <bits/stdc++.h>

namespace Singly_linked_list
{
    typedef struct Node
    {
        int val;
        Node *next;
    } * LinkList, LNode;

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

    void del2(LinkList &L, int x)
    {
        if (L->next == NULL)
            return;
        if (L->next->val == x)
        {
            Node *p = L->next;
            L->next = L->next->next;
            free(p);
            del2(L, x);
        }
        else
            del2(L->next, x);
    }

    void print_with_no_head(LinkList &L)
    {
        while (L != NULL)
        {
            std::cout << L->val << " ";
            L = L->next;
        }
    }

    void print_with_head(LinkList &L)
    {
        while (L->next != NULL)
        {
            std::cout << L->next->val << " ";
            L = L->next;
        }
    }
    LinkList build_with_no_head_bi(LinkList &L)
    {
        int n;
        std::cin >> n;
        L = NULL;
        Node *cnt = NULL;
        for (int i = 1; i <= n; i++)
        {
            int x;
            std::cin >> x;
            cnt = (Node *)malloc(sizeof(Node));
            cnt->val = x;
            cnt->next = L;
            L = cnt;
        }
        return L;
    }

    LinkList build_with_head_bi(LinkList &L)
    {
        L = (Node *)malloc(sizeof(Node));
        L->next = NULL;
        int n;
        Node *cnt = NULL;
        std::cin >> n;
        for (int i = 1; i <= n; i++)
        {
            int x;
            std::cin >> x;
            cnt = (Node *)malloc(sizeof(Node));
            cnt->next = L->next;
            cnt->val = x;
            L->next = cnt;
        }
        return L;
    }
} // namespace Singly_linked_list

int main()
{
}