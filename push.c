#include "monty.h"

/**
 * f_push - Add node to the stack.
 * @head: Stack head.
 * @counter: Line number.
 * Return: No return.
 */
void f_push(stack_t **head, unsigned int counter)
{
    stack_t *new_node;
    int n;

    if (bus.arg)
    {
        char *endptr;
      
        strtol(bus.arg, &endptr, 10);

     if (*endptr != '\0' || endptr == bus.arg)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    n = atoi(bus.arg);

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *head;

    if (*head != NULL)
    {
        (*head)->prev = new_node;
    }

    *head = new_node;
}

