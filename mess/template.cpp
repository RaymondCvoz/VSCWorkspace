#include <bits/stdc++.h>

namespace singly_linked_list //单链表
{
    struct Node //节点
    {
        int val;
        Node *next;
        Node(int val)
        {
            this->val = val;
            this->next = nullptr;
        }
    };

    void insert_in_head(Node *root, int val) //头插构造
    {
        Node *cnt = new Node(val);
        cnt->next = root->next;
        root->next = cnt;
        return;
    }

    void insert_in_rear(Node *rear, int val) //尾插构造
    {
        Node *cnt = new Node(val);
        rear->next->next = cnt;
        rear->next = cnt;
        cnt->next = nullptr;
        return;
    }

    int find_by_value(Node *node, int val) //按值查找
    {
        int total_found = 0;
        while (node->next != nullptr)
        {
            if (node->next->val == val)
            {
                total_found++;
            }
            node = node->next;
        }
        return total_found;
    }

    int delete_by_value(Node *node, int val) //按值删除
    {
        int total_deleted = 0;
        while (node->next != nullptr)
        {
            if (node->next->val == val)
            {
                Node *tmp = node->next->next;
                delete (node->next);
                node->next = tmp;
                total_deleted++;
            }
            node = node->next;
        }
        return total_deleted;
    }

    int get_size(Node *node) //求链表长度
    {
        int size = 0;
        while (node->next != nullptr)
        {
            size++;
            node = node->next;
        }
        return size;
    }

    void print_value(Node *root) //打印节点值
    {
        while (root->next != nullptr)
        {
            std::cout << root->next->val << " ";
            root = root->next;
        }
        std::cout << std::endl;
        return;
    }

    void destroy(Node *node) //递归销毁链表
    {
        if (node->next != nullptr)
        {
            destroy(node->next);
            delete (node);
        }
        return;
    }
} // namespace singly_linked_list

namespace double_linked_list //双链表
{
    struct Node
    {
        int val;
        Node *next, *prev;
        Node(int val)
        {
            this->val = val;
            this->prev = nullptr;
            this->next = nullptr;
        }
    };

    void insert_in_head(Node *root, int val) //头插构造
    {
        Node *cnt = new Node(val);
        root->next->prev = cnt;
        cnt->next = root->next;
        root->next = cnt;
        cnt->prev = root;
        return;
    }

    void insert_in_rear(Node *rear, int val) //尾插构造
    {
        Node *cnt = new Node(val);
        rear->prev->next = cnt;
        cnt->prev = rear->prev;
        rear->prev = cnt;
        cnt->next = rear;
        return;
    }

    int find_by_value(Node *node, Node *rear, int val) //按值查找
    {
        int total_found = 0;
        while (node->next != rear)
        {
            if (node->next->val == val)
            {
                total_found++;
            }
            node = node->next;
        }
        return total_found;
    }

    int delete_by_value(Node *node, Node *rear, int val) //按值删除
    {
        int total_deleted = 0;
        while (node->next != nullptr)
        {
            if (node->next->val == val)
            {
                node->next->next->prev = node;

                node->next = node->next->next;
                delete (node->next);
                total_deleted++;
            }
            node = node->next;
        }
        return total_deleted;
    }
} // namespace double_linked_list

int main()
{
    singly_linked_list::Node *root = new singly_linked_list::Node(-1);
    singly_linked_list::Node *rear = new singly_linked_list::Node(-1);
    rear->next = root;

    int n;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int val;
        std::cin >> val;
        singly_linked_list::insert_in_rear(rear, val);
    }
    singly_linked_list::print_value(root);
    singly_linked_list::delete_by_value(root, 5);
    singly_linked_list::print_value(root);
    return 0;
}