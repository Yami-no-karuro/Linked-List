#include <stdio.h>
#include <stdlib.h>

#include "linked_list.h"

/**
 * Initializes a new list.
 *
 * @param val - The value of the first element of the list. 
 * @return - A pointer to the linked list head.
 */
ListNode *ll_init(int val)
{
    ListNode *head = NULL;
    head = (ListNode *)malloc(sizeof(ListNode));
    if (!head) {
        printf("Error: Unable to allocate memory for a new \"ListNode\".");
        exit(EXIT_FAILURE);
    }

    head->val = val;
    head->next = NULL;

    return head;
}

/**
 * Appends a new item to the start of the list.
 *
 * @param head - The list head. 
 * @param val - The value of the new node.
 */
void ll_prepend(ListNode **head, int val) {
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

/**
 * Appends a new item to the end of the list.
 *
 * @param head - The list head. 
 * @param val - The value of the new node.
 */
void ll_append(ListNode *head, int val)
{
    ListNode *current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = (ListNode *)malloc(sizeof(ListNode));
    current->next->val = val;
    current->next->next = NULL;
}

/**
 * Removes (and returns the stored value) the first item of the list.
 *
 * @param head - The list head. 
 * @return - The removed value.
 */
int ll_pop(ListNode **head)
{
    int value = -1;
    ListNode *next_node = NULL;
    if (*head == NULL)
        return value;

    next_node = (*head)->next;
    value = (*head)->val;

    free(*head);
    *head = next_node;

    return value;
}

/**
 * Removes (and returns the stored value) the last item of the list.
 *
 * @param head - The list head. 
 * @return - The removed value.
 */
int ll_popback(ListNode *head) 
{
    int value = 0;
    if (head->next == NULL) {
        value = head->val;

        free(head);
        return value;
    }

    ListNode *current = head;
    while (current->next->next != NULL)
        current = current->next;

    value = current->next->val;
    free(current->next);

    current->next = NULL;
    return value;
}

/**
 * Frees the entire linked list.
 *
 * @param head - The list head.
 */
void ll_free(ListNode *head)
{
    ListNode *current = head;
    ListNode *next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);

        current = next_node;
    }
}
