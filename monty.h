#ifndef MONTY_H
#define MONTY_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>
/**
 * struct stack_s - Doubly linked list representation of a stack
 * @n: Integer value stored in the node
 * @prev: Pointer to the previous node in the stack
 * @next: Pointer to the next node in the stack
 *
 * Description: Doubly linked list node structure for stack
 */
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

extern stack_t *head;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: The opcode (instruction)
 * @f: Function to handle the opcode
 *
 * Description: Opcode and its corresponding function for stack manipulation
 */
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(int value, unsigned int line_number);
void pall(stack_t **head, unsigned int counter);
void pint(stack_t **stack, unsigned int line_number);
void processFile(const char *filename);

#endif

