/*
** TRADE PROJECT, 2024
** trade
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>

#include "trade.h"

int main(void)
{
    char *buffer;
    size_t size_buffer = 100;

    buffer = malloc(sizeof(char) * 4096);
    if (buffer == NULL) {
        fprintf(stderr, "malloc failed\n");
        return FAILURE;
    }
    while (1) {
        if (getline(&buffer, &size_buffer, stdin) == -1) {
            free(buffer);
            fprintf(stderr, "getline failed\n");
            return FAILURE;
        }
        fprintf(stderr, "line: %s\n", buffer);
    }
    return SUCCESS;
}
