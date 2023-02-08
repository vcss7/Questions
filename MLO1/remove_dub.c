#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head) return head;

    struct ListNode* current = head;
    struct ListNode* temp;

    while (current)
    {
        if (current->next && current->next->val == current->val)
        {
            temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else
        {
            current = current->next;
        }
    }

    return head;
}

void print_linked_list(struct ListNode* head)
{
    if(!head) return;

    struct ListNode* current = head;

    while (current)
    {
        printf("%d ", current->val);
        current = current->next;
    }

    printf("\n");
}

int main(int argc, char** argv)
{
    struct ListNode* head1 = (struct ListNode*) malloc(sizeof(struct ListNode));
    head1->val = 1;
    head1->next = NULL;

    struct ListNode* current = head1;
    for(int i = 0; i < 10; i++)
    {
        struct ListNode* newItem = (struct ListNode*) malloc(sizeof(struct ListNode));

        newItem->val = i;
        newItem->next = NULL;
        current->next = newItem;

        current = current->next;
        
        if (i % 2 == 0)
        {
            struct ListNode* newNewItem = (struct ListNode*) malloc(sizeof(struct ListNode));
        
            newNewItem->val = i;
            newNewItem->next = NULL;
            current->next = newNewItem;

            current = current->next;
        }
    }

    print_linked_list(head1);
    deleteDuplicates(head1);
    print_linked_list(head1);

    return 0;
}

