/*
** TRADE PROJECT, 2024
** trade
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "trade.h"

static void get_settings(trade_t *trade, char **array)
{
    if (strcmp(array[1], "timebank")  == 0)
        trade->timebank = atoi(array[2]);
    if (strcmp(array[1], "time_per_move") == 0)
        trade->time_per_move = atoi(array[2]);
    if (strcmp(array[1], "candle_interval") == 0)
        trade->candle_interval = atoi(array[2]);
    if (strcmp(array[1], "candle_format") == 0)
        trade->candle_format = strdup(array[2]);
    if (strcmp(array[1], "candles_total") == 0)
        trade->candles_total = atoi(array[2]);
    if (strcmp(array[1], "candles_given") == 0)
        trade->candles_given = atoi(array[2]);
    if (strcmp(array[1], "initial_stack") == 0)
        trade->initial_stack = atoi(array[2]);
    if (strcmp(array[1], "transaction_fee_percent") == 0)
        trade->transaction_fee = atof(array[2]);
    return;
}

int main(void)
{
    char *buffer = NULL;
    size_t size_buffer = 0;
    int i = 0;
    bool buy = false;
    trade_t *trade = malloc(sizeof(trade_t));

    if (trade == NULL)
        return FAILURE;
    memset(trade, 0, sizeof(trade_t));
    buffer = malloc(sizeof(char) * size_buffer);
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
        if (strncmp(buffer, "settings", 8) == 0) {
            char **array = word_array_delim(buffer, " ");
            get_settings(trade, array);
        }
        if (strcmp(buffer, "action order 2000\n") == 0 && i < 10) {
            fprintf(stdout, "buy USDT_BTC 0.014283751290179836\n");
            fflush(stdout);
            buy = true;
            i += 1;
        }
        if (!buy) {
            fprintf(stdout, "no_moves\n");
            fflush(stdout);
        }
    }
    return SUCCESS;
}
