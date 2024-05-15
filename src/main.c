/*
** TRADE PROJECT, 2024
** trade
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>

#include "trade.h"

static int error_handling(int argc, char * const *argv)
{
    size_t i = 0;

    if (argc != 2)
        return FAILURE;
    while (argv[i] != NULL) {
        i +=1;
    }
    if (i < 2)
        return FAILURE;
    return SUCCESS;
}

int main(int argc, char * const *argv)
{
    char *buffer;
    size_t size_buffer = 100;

    buffer = malloc(sizeof(char) * 4096);
    if (buffer == NULL)
        return FAILURE;
    error_handling(argc, argv);
    while (1) {
        if (getline(&buffer, &size_buffer, stdin) == -1) {
            free(buffer);
            return FAILURE;
        }
        fprintf(stderr, "line: %s\n", buffer);
    }
    return SUCCESS;
}
