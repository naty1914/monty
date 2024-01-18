#include "monty.h"
#include <ctype.h>

/**
 * push - Pushes an element onto the stack.
 * @value: The integer value to be pushed onto the stack.
 * @line_number: The line number in the file where the operation occurs.
 *
 * Description: If the value is not an integer or if there is no argument given
 * to push, it prints an error message and exits with EXIT_FAILURE.
 */

void push(int value, unsigned int line_number)
{
 stack_t *new_node;
    if (!isdigit(value))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }
new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = head;

    if (head != NULL)
    {
        head->prev = new_node;
    }

    head = new_node;
}

