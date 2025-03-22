#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct ListNode {
    int val;
    struct ListNode * next;
} ListNode;

ListNode *ll_init(int val);
void ll_prepend(ListNode **head, int val);
void ll_append(ListNode *head, int val);
int ll_pop(ListNode **head);
int ll_popback(ListNode *head);
void ll_free(ListNode *head);

#endif
