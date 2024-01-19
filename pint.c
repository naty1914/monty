#include "monty.h"
/**
 * f_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_pint(stack_t **head, unsigned int counter)
{

	 stack_t *current;

	current = *head;
        if (current == NULL)
        {
                fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
                free_stack(current);
                exit(EXIT_FAILURE);
        }
        printf("%d\n", (current)->n);
}

