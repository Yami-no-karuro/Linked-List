#include <stdio.h>

#include "./lib/linked_list.h"

void ll_print(ListNode *head)
{
    ListNode *current = head;
    while (current != NULL) {
        printf("%d\n", current->val);
        current = current->next;
    }
}

int main(void) 
{
    ListNode *head = ll_init(1);

    ll_append(head, 2);
    ll_append(head, 3);
    ll_append(head, 4);

    ll_prepend(&head, 0);

    printf("====\n");
    ll_print(head);
    printf("====\n");

    int first = ll_pop(&head);
    int last = ll_popback(head);

    printf("First: %d, Last: %d\n", first, last);

    printf("====\n");
    ll_print(head);
    printf("====\n");

    ll_free(head);
    return 0;
}
