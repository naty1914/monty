#include "monty.h"


void processFile(const char *filename) {
    int value;
    unsigned int line_number = 1;
    char command[10];

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Can't open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", command) == 1) {
        if (strcmp(command, "push") == 0) {
            fscanf(file, "%d", &value);
            push(value, line_number);
        } else if (strcmp(command, "pall") == 0) {
            pall(&head, line_number);
        } else if (strcmp(command, "pint") == 0) {
            pint(&head, line_number);
        } else {
            fprintf(stderr, "Error: Unknown command '%s' at line %u\n", command, line_number);
            exit(EXIT_FAILURE);
        }

        line_number++;
    }

    fclose(file);
}

