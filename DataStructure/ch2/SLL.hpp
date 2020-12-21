#include "CPPLIB.hpp"

typedef struct Node
{
    int val;
    Node *next;
} * LinkList, LNode;

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