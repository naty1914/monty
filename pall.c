#include "monty.h"


void pall(stack_t **head, unsigned int counter){
    stack_t *current;
 (void)counter;
current = *head;
if (current == NULL)
{
return;
}

    while (current != NULL) {
        printf("%d\n", current->n);
        current = current->next;
    }
}
